(function ($) {
  Drupal.behaviors.superLoginPWBehavior = {
    attach: function (context, settings) {
        var showMessages = drupalSettings.show_messages;
        if (!showMessages) {
            $(".messages").prependTo("#user-login-form");
            $(".alert").prependTo("#user-login-form");
        }     
    }
  };
})(jQuery);