<?php 


function golden_dust_preprocess_page(&$vars) {
   $header = drupal_get_http_header("status"); 
  if($header == "404 Not Found") {     
    $vars['theme_hook_suggestions'][] = 'page__404';
  }
  if($header == "403 Forbidden") {     
    $vars['theme_hook_suggestions'][] = 'page__403';
  }
} 