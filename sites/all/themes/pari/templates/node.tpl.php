<?php if (!$page): ?>
	<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<?php endif; ?>

<?php if ($display_submitted || !$page): ?>
    <?php if (!$page): ?>
		<header>
	<?php endif; ?>
		<?php print render($title_prefix); ?>
		<?php if (!$page): ?>
			<h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
		<?php endif; ?>
		<?php print render($title_suffix); ?>
  
		<?php if ($display_submitted): ?>
			<div class="submitted"><span class="node-date"><?php print $date ?></span><i class="icon-user"></i><span class="node-user"><?php print $name ?></span><?php if (!empty($content['field_tags'])): ?><i class="icon-tags"></i><span class="node-tags"><?php print render($content['field_tags']); endif; ?></span></div>
		<?php endif; ?>

    <?php if (!$page): ?>
		</header>
	<?php endif; ?>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // Hide comments, tags, and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_tags']);
      print render($content);
    ?>
  </div>

  <?php if (!empty($content['links'])): ?>
    <footer>
      <div class="node-links"><?php print render($content['links']); ?></div>
    </footer>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

<?php if (!$page): ?>
  </article> <!-- /.node -->
<?php endif; ?>
