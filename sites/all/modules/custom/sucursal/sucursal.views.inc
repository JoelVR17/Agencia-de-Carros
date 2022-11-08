<?php

function sucursal_views_default_views() {
    $export = array();


    $view = new view();
    $view->name = 'lista_sucursal';
    $view->description = '';
    $view->tag = 'default';
    $view->base_table = 'node';
    $view->human_name = 'Lista Sucursal';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'Lista Sucursal';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restablecer';
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = '10';
    $handler->display->display_options['pager']['options']['tags']['first'] = '« primero';
    $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
    $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
    $handler->display->display_options['pager']['options']['tags']['last'] = 'último »';
    $handler->display->display_options['style_plugin'] = 'table';
    /* Campo: Contenido: Título */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
    $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
    /* Campo: Contenido: Canton */
    $handler->display->display_options['fields']['sucursal_canton']['id'] = 'sucursal_canton';
    $handler->display->display_options['fields']['sucursal_canton']['table'] = 'field_data_sucursal_canton';
    $handler->display->display_options['fields']['sucursal_canton']['field'] = 'sucursal_canton';
    /* Campo: Contenido: Direccion */
    $handler->display->display_options['fields']['sucursal_direccion']['id'] = 'sucursal_direccion';
    $handler->display->display_options['fields']['sucursal_direccion']['table'] = 'field_data_sucursal_direccion';
    $handler->display->display_options['fields']['sucursal_direccion']['field'] = 'sucursal_direccion';
    /* Campo: Contenido: Distrito */
    $handler->display->display_options['fields']['sucursal_distrito']['id'] = 'sucursal_distrito';
    $handler->display->display_options['fields']['sucursal_distrito']['table'] = 'field_data_sucursal_distrito';
    $handler->display->display_options['fields']['sucursal_distrito']['field'] = 'sucursal_distrito';
    /* Campo: Contenido: Provincia */
    $handler->display->display_options['fields']['sucursal_provincia']['id'] = 'sucursal_provincia';
    $handler->display->display_options['fields']['sucursal_provincia']['table'] = 'field_data_sucursal_provincia';
    $handler->display->display_options['fields']['sucursal_provincia']['field'] = 'sucursal_provincia';
    /* Sort criterion: Contenido: Post date */
    $handler->display->display_options['sorts']['created']['id'] = 'created';
    $handler->display->display_options['sorts']['created']['table'] = 'node';
    $handler->display->display_options['sorts']['created']['field'] = 'created';
    $handler->display->display_options['sorts']['created']['order'] = 'DESC';
    /* Filter criterion: Contenido: Published status */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = 1;
    $handler->display->display_options['filters']['status']['group'] = 1;
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter criterion: Contenido: Tipo */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
    'sucursal' => 'sucursal',
    );

    /* Display: Page */
    $handler = $view->new_display('page', 'Page', 'page');
    $handler->display->display_options['path'] = 'lista-sucursal';
    $handler->display->display_options['menu']['type'] = 'normal';
    $handler->display->display_options['menu']['title'] = 'Lista Sucursal';
    $handler->display->display_options['menu']['name'] = 'menu-carros';

    /* Display: Data export */
    $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
    $handler->display->display_options['style_options']['provide_file'] = 1;
    $handler->display->display_options['style_options']['parent_sort'] = 0;
    $handler->display->display_options['path'] = 'export-sucursal';
    $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
    );
    $translatables['lista_sucursal'] = array(
    t('Master'),
    t('Lista Sucursal'),
    t('more'),
    t('Apply'),
    t('Restablecer'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« primero'),
    t('<- anterior'),
    t('siguiente ->'),
    t('último »'),
    t('Título'),
    t('Canton'),
    t('Direccion'),
    t('Distrito'),
    t('Provincia'),
    t('Page'),
    t('Data export'),
    );

    $export['lista_sucursal'] = $view;

    return $export;
}