jQuery(document).ready(function(){
//	jQuery('.image-preview').wrapAll('<div class="preview_box"></div>');
	jQuery(".navbar-toggle-open").click(function(){
		jQuery(".sidebar-navber").css("width","300px");
	});
	jQuery(".navbar-toggle-close").click(function(){
		jQuery(".sidebar-navber").css("width", "0px");
	});
	//jQuery('.views-row .views-field-body, .read-more-text').readmore();
	jQuery(window).scroll(function(){
	  if (jQuery(window).scrollTop() >= 300) {
	    jQuery('.navbar').addClass('whiteHeader');
	   }
	   else {
	    jQuery('.navbar ').removeClass('whiteHeader');
	   }
	});
	jQuery(".toggle-control-open .glyphicon").click(function(){
		jQuery(".content_highlight").slideDown(1000);;
	});
	jQuery(".toggle-control-close .glyphicon").click(function(){
		jQuery(".content_highlight").slideUp(1000);;
	});
	jQuery('.container').each(function() {
		if (jQuery.trim(jQuery(this).html()) == '')
		jQuery(this).parents('.wrapper-box').hide();
	});
	jQuery('.form-radio').change(function () {
  jQuery('.form-radio').parent('.control-label').removeClass('highlight');
	    jQuery(this).parent(".control-label").addClass('highlight');
	});
	jQuery('input[type="checkbox"]').click(function(){
	    jQuery(this).parents(".control-label").toggleClass('highlight');
	});
});


jQuery(window).on('load resize', function () {
  jQuery('.views-row .views-field-body').ellipsis({ lines: 3, responsive: true });
});
