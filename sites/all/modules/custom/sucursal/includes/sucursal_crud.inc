<?php

//  *   Hook_Permissions
function empleado_permission () {
    return array (
        'administer my module' => array (
            'title' => t('CRUD Empleado'),
            'description' => t('Permisos para el Crud'),
        ),
    );
}

//  *   Hook_Menu
function empleado_menu () {
    $items = array ();

    // ? CRUD
    $items['crud'] = array (
        'title' => t('CRUD Empleado'),
        'page callback' => 'drupal_get_form',
        'page arguments' => array ('fcrud'),
        'access arguments' => array ('Permisos Crud'),
        'type' => MENU_CALLBACK,
    );

    // ? LISTA
    $items['lista'] = array (
        'title' => t('Lista'),
        'page callback' => array ('lista_resultados'),
        'access arguments' => array ('Permisos Crud'),
        'type' => MENU_CALLBACK,
    );

    // ? BORRAR
    $items['borrar/%'] = array (
        'title' => t('Borrar Registro'),
        'page callback' => array ('borrar_registros'),
        'page arguments' => array (1), 
        'access arguments' => array ('Permisos Crud'), 
    );

    // ? EDITAR
    $items['editar/%'] = array (
        'title' => t('Editar Registro'),
        'page callback' => array ('editar_registros'),
        'page arguments' => array (1), 
        'access arguments' => array ('Permisos Crud'), 
    );

    // ? Return
    return $items;
}

//  *   FCRUD
function fcrud ($form, &$form_state) {
    $form = array ();

    // ? Nombre
    $form['nombre'] = array (
        '#title' => t('Nombre del Empleado'),
        '#type' => 'textfield',
        '#description' => t(''),
        '#required' => TRUE,
        '#default_value' => '',
        '#size' => 30,
    );

    // ? Apellido
    $form['ap'] = array (
        '#title' => t('Apellidos del Empleado'),
        '#type' => 'textfield',
        '#description' => t(''),
        '#required' => TRUE,
        '#default_value' => '',
        '#size' => 30,
    );

    // ! ----------------OJO-------------------------------------------------

    // ? Edad
    $form['edad'] = array (
        '#title' => t('Edad del Empleado'),
        '#type' => 'int',
        '#description' => t(''),
        '#required' => TRUE,
        '#size' => 'medium',
    );
    // ! ----------------OJO-------------------------------------------------

    // ? Submit
    $form['submit'] = array (
        '#type' => 'submit',
        '#value' => 'Enviar',
    );

    // ? Return
    return $form;
}

//  *   Formulario Subtmit
function fcrud_submit ($form, &$form_state) {
    $consulta = db_insert('empleado')
        -> fields(array(
            'nombre' => $form_state['values']['nombre'],
            'ap' => $form_state['values']['ap'],
            'edad' => $form_state['values']['edad'],
        ))
        -> execute();
    drupal_set_message('Envio Exitoso!');
}

//  *   Lista Resultados 
function lista_resultados () {
    $salida = "";
    $salida.=l('Agregar un nuevo registro','crud');

    $header = array(t('ID'),t('NOMBRE'),t('APELLIDO'),t('EDAD'),t('EDITAR'),t('BORRAR'));
    $query = db_select('empleado', 'base');
    $query -> fields('base', array('id','nombre','ap','edad'))
        -> range(0,5) // numero de resultados
        -> orderBy('base.id');
    $r = $query -> execute();

    $rows = array();
    foreach ($r as $res) {
        $rows[] = array(
            check_plain($res -> id),
            check_plain($res -> nombre),
            check_plain($res -> ap),
            check_plain($res -> edad),
            l('Editar','editar/' . $res -> id),
            l('Borrar','borrar/' . $res -> id),
        );
    }

    $salida.=theme('table',array('header' => $header, 'rows' => $rows));

    // ? Return
    return ($salida);
}

//  *   Borrar Registros 
function borrar_registros ($x) {
    db_delete('empleado')
    -> condition('id',$x)
    -> execute();
    drupal_set_message('Registro Borrado Exitosamente');
    drupal_goto('lista');
}

//  *   Editar Registros
function editar_registros ($x) {
    $salida = "";
    $salida.=l('Regresar a la lista','lista');
    return $salida.=drupal_render(drupal_get_form('editar_formulario'));
}

//  *   Editar Formulario
function editar_formulario ($form, &$form_state) {
    $query = db_select("empleado", "b")
        -> fields ("b")
        -> condition ('id', arg(1), '=');
    $query = $query -> execute() -> fetchAssoc();

    $form = array ();

    // ? Nombre
    $form['nombre'] = array (
        '#title' => t('Nombre del Empleado'),
        '#type' => 'textfield',
        '#description' => t(''),
        '#required' => TRUE,
        '#value' => $query['nombre'],
        '#size' => 30,
    );

    // ? Apellido
    $form['ap'] = array (
        '#title' => t('Apellidos del Empleado'),
        '#type' => 'textfield',
        '#description' => t(''),
        '#required' => TRUE,
        '#value' => $query['ap'],
        '#size' => 30,
    );

    // ! ----------------OJO-------------------------------------------------
    // ? Edad
    $form['edad'] = array (
        '#title' => t('Edad del Empleado'),
        '#type' => 'int',
        '#description' => t(''),
        '#required' => TRUE,
        '#value' => $query['edad'],
        '#size' => 'medium',
    );

    // ! ----------------OJO-------------------------------------------------

    // ? Submit
    $form['submit'] = array (
        '#type' => 'submit',
        '#value' => 'Actualizar',
    );

    // ? Return
    return $form;
}

//  *   Se actualiza la info
function editar_formulario_submit ($form, &$form_state) {
    db_update('empleado')
        -> fields(array('nombre' => $form_state['input']['nombre'], 'ap' => $form_state['input']['ap'],
        'edad' => $form_state['input']['edad'])) //!ojo
        -> condition('id',arg(1),'=')
        -> execute();
        drupal_set_message('Registro Actualizado Exitosamente');
        drupal_goto('lista');
}

