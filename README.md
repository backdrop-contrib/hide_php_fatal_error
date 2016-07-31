Hide PHP Fatal Error
====================

This module redirects the user to an error page when a PHP fatal error is thrown in [Backdrop](https://backdropcms.org/). The error is logged using watchdog.

Note: this module does not handle errors that are not thrown by PHP, like Apache/Nginx 500 errors (e.g. after a redirect loop). Moreover, it only handles FATAL errors, because all other errors can be caught properly by a try/catch block and are natively handled by Backdrop core.

Security benefits
-----------------

The [Open Web Application Security Project](https://www.owasp.org/index.php/Main_Page) publishes a Top 10 list of the most common vulnerabilities for web applications. In 2007, they listed [information leakage and improper error handling](https://www.owasp.org/index.php/Top_10_2007-A6) in the Top 10 list. Their recommendations for protecting sensitive data noted the following in **bold**.

> **It is worthwhile creating a default error handler which returns an
> appropriately sanitized error message for most users in production for
> all error paths.**

While Backdrop has configuration has configuration for selecting which error messages to display, those settings do not apply to sanitize PHP fatal errors in the inevitable occasion you upload buggy code to your
website. This module provides another layer of error sanitizing not provided by Backdrop.

Current Maintainer
------------------

- David Norman (https://github.com/deekayen)

Maintainers
-----------

- Originally written for Drupal by B-Prod (https://www.drupal.org/u/b-prod)
- Ported to Backdrop by David Norman (https://github.com/deekayen)

License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.
