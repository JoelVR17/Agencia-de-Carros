<div class="toggle-control-open toggle-control"><span class="glyphicon glyphicon-plus"></span></div>
<div class="content_highlight wrapper-box">     
    <div class="container">
      <?php print render($page['post_content_bg']); ?>
    </div>
   <div class="toggle-control-close"><span class="glyphicon glyphicon-minus"></span></div>
 </div>
<header id="navbar" role="banner" class="navbar navbar-default">
   <div class="container">
      <div class="navbar-header">
         <?php if ($logo): ?>
         <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
         <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
         </a>
         <?php endif; ?>
         <?php if (!empty($site_name)): ?>
         <a class="name navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php // print $site_name; ?></a>
         <?php endif; ?>
         <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
         <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#navbar-collapse">
         <span class="sr-only"><?php print t('Toggle navigation'); ?></span>
         <span class="icon-bar"></span>
         <span class="icon-bar"></span>
         <span class="icon-bar"></span>
         </button>
         <?php endif; ?>
      </div>
      <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
      <div class="navbar-collapse collapse" id="navbar-collapse">
         <nav role="navigation" class="navigation-left">
            <?php if (!empty($primary_nav)): ?>
               <?php print render($primary_nav); ?>
               <?php endif; ?>
            <?php if (!empty($secondary_nav)): ?>
            <?php print render($secondary_nav); ?>
            <?php endif; ?>
            <?php if (!empty($page['navigation'])): ?>
            <?php print render($page['navigation']); ?>
            <?php endif; ?>
         </nav>
      </div>
      <?php endif; ?>
   </div>
</header>
<script>
   window.onscroll = function() {myFunction()};
   
   var header = document.getElementById("navbar");
   var sticky = header.offsetTop;
   
   function myFunction() {
     if (window.pageYOffset > sticky) {
       header.classList.add("sticky");
     } else {
       header.classList.remove("sticky");
     }
   }
</script>