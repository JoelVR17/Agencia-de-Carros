<footer class="footer">
  <div class="footer_top">
    <div class="container">     
        <?php print render($page['footer_top']); ?>
    </div>
  </div>
  <div class="footer_col">      
      <div class="container">
        <div class="row">
          <div class="col-sm-3"><?php print render($page['footer1']); ?></div>
          <div class="col-sm-3"><?php print render($page['footer2']); ?></div>
          <div class="col-sm-3"><?php print render($page['footer3']); ?></div>
          <div class="col-sm-3">
            <h2 class="block-title">Social Media</h2>
            <ul class="social_list">
              <li><a href=""><img class="img-responsive" src="/sites/all/themes/golden_dust/images/facebook.png"></a></li>
              <li><a href=""><img class="img-responsive" src="/sites/all/themes/golden_dust/images/twitter.png"></a></li>
              <li><a href=""><img class="img-responsive" src="/sites/all/themes/golden_dust/images/google-plus.png"></a></li>
            </ul>    
          </div>
        </div>
      </div>
      <div class="footer_full_width">     
          <div class="container">
            <?php print render($page['footer1']); ?>
            <?php print render($page['footer']); ?>
          </div>
      </div>
      
  </div>
  
  <!-- <div class="footer_bottom"> 
    <?php //print render($page['footer']); ?>
  </div>  -->
</footer>