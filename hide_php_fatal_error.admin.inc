<?php

/**
 * @file
 * Administrative functions for PHP fatal error module.
 */

/**
 * Form builder; settings form.
 *
 * @see hide_php_fatal_error_settings_form_validate()
 * @ingroup forms
 */
function hide_php_fatal_error_settings_form($form, &$form_state) {
  $form['hide_php_fatal_error_page'] = array(
    '#type' => 'textfield',
    '#title' => t('Error page'),
    '#size' => 40,
    '#default_value' => config_get('hide_php_fatal_error.settings', 'hide_php_fatal_error_page'),
    '#description' => t('Specify an internal path to which the user is redirected when a PHP fatal error occurs.'),
    '#field_prefix' => url(NULL, array('absolute' => TRUE)) . (config_get('hide_php_fatal_error.settings', 'clean_url', 0) ? '' : '?q='),
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Form validation handler; validate settings form.
 *
 * @see hide_php_fatal_error_settings_form()
 */
function hide_php_fatal_error_settings_form_validate($form, &$form_state) {
  $path = empty($form_state['values']['hide_php_fatal_error_page']) ? 'site-error' : backdrop_get_normal_path($form_state['values']['hide_php_fatal_error_page']);
  form_set_value($form['hide_php_fatal_error_page'], $path, $form_state);

  // Validate path.
  if (!backdrop_valid_path($form_state['values']['hide_php_fatal_error_page'])) {
    form_set_error('hide_php_fatal_error_page', t("The path '%path' is either invalid or you do not have access to it.", array('%path' => $path)));
  }
}

/**
 * Implements hook_submit().
 */
function hide_php_fatal_error_settings_form_submit($form, &$form_state) {
  $config = config('hide_php_fatal_error.settings');
  $config->set('hide_php_fatal_error_page', $form_state['values']['hide_php_fatal_error_page']);
  $config->save();
}
