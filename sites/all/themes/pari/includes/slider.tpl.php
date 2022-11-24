<div class="container">
	<div id="slider">
		<ul id="js-rotating">
		<?php if (theme_get_setting('slider_code') !== '') {
			echo theme_get_setting('slider_code');
		} else { ?>
			<li>
				<h1>Rolosa - Tecnología y Servicios</h1>
				<p>Empresa encargada de brindarle servicios de Tecnología a la compañía de Toyota Costa Rica</p>
				<a class="button" href="http://localhost:8080/drupal/sobreNosotros">Iniciar</a>
			</li>
			<li>
				<h1>Marvin Joel Vargas Rodríguez</h1>
				<p>Pasante de la empresa Rolosa</p>
				<a class="button" href="http://localhost:8080/drupal/sobreNosotros">Iniciar</a>
			</li>
		<?php } ?>
		</ul>
	</div><!--/#slider -->
</div><!--/.container -->