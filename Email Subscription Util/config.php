<?php
	
	define ('PENDING_VERIFICATION',0);
	define ('ACTIVE',1);
	define ('UNSUBSCRIBED',2);
	
	define ('DAILY',0);
	define ('WEEKLY',1);
	define ('MONTHLY',2);
	
	define ('MAXFEEDBACKLENGTH',2048);
	define ('MAXEMAILLENGTH',255);
	
	$USERNAME = 'sapan';
	$PASSWORD = 'sapan';
	$DATABASE = 'diffen';
	$SENDERID = 'diwakar.sapan@gmail.com';
	$SENDERPASSWD = 'XXXXXXXXXXXXXXXX';
	$subject = 'Diffen.com Registration';
	$homePageURL = 'http://www.diffen.com';
	$body1 = "Welcome to diffen.com!\r\rYou, or someone using your email address, has completed registration at Diffen.com. You can complete registration by clicking the following link:\r";
	$body2 = "\r\rIf this is an error, ignore this email and you will be removed from our mailing list.\r\rRegards,\rDiffen.com Team";
	$errorstr = "Error:";

?>