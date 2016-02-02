<?php

class Layout {

	/**
	 * sets the layout for every page, 3 string options: 'admin', 'user', and 'public'
	 * @param  string $context [3 different options]
	 * @return [includes function]          [returns the site path to the different layouts]
	 */
	public static function include_header_layout($context='public') {
		if($context == 'admin') {
			include(SITE_ROOT.DS.'admin'.DS.'layouts'.DS.'admin_header.php');
		} elseif ($context == 'user') {
			include(SITE_ROOT.DS.'public'.DS.'layouts'.DS.'user_header.php');
		} else {
			include(SITE_ROOT.DS.'public'.DS.'layouts'.DS.'header.php');
		}
	}

	public static function include_footer_layout($context='public') {
		if($context == 'admin') {
			include(SITE_ROOT.DS.'admin'.DS.'layouts'.DS.'admin_footer.php');
		} elseif ($context == 'user') {
			include(SITE_ROOT.DS.'public'.DS.'layouts'.DS.'user_footer.php');
		} else {
			include(SITE_ROOT.DS.'public'.DS.'layouts'.DS.'footer.php');
		}
	}

}