<?php

namespace Drupal\Tests\super_login\Functional;

use Drupal\Core\Url;
use Drupal\Tests\BrowserTestBase;

/**
 * Test settings form and config.
 */
class SettingsFormTest extends BrowserTestBase {

  /**
   * {@inheritdoc}
   */
  protected static $modules = ['super_login'];

  /**
   * {@inheritdoc}
   */
  protected $defaultTheme = 'stable';

  /**
   * Test that configuration form can be submitted and functions correctly.
   */
  public function testSettingForm() {
    $this->drupalGet(Url::fromRoute('super_login.settings'));
    $this->assertSession()->statusCodeEquals(403);
    // Yikes...
    $account = $this->createUser(['administer site configuration']);
    $this->drupalLogin($account);
    $this->drupalGet(Url::fromRoute('super_login.settings'));
    $this->assertSession()->statusCodeEquals(200);
    $settings = [
      'login_title' => 'Test Log In Title',
    ];
    $this->submitForm($settings, 'Save configuration');
    foreach ($settings as $name => $value) {
      $this->assertSession()->fieldValueEquals($name, $value);
    }
  }

}
