<?php

	$code = null;

	if ($_SERVER["REQUEST_METHOD"] == "POST") {
		//global $code = $_POST['codeeditor']; 
		echo $_POST['text'];
		//echo $code;
	}
	
?>