<?php
	
	function sendMail($email, $activationKey, $body, $SENDERID, $SENDERPASSWD)
	{
		##Send activation Email
		//include_once('config.php');

		require_once 'lib/swift_required.php';
		
		//Create the Transport
		$transport = @Swift_SmtpTransport::newInstance('smtp.gmail.com', 465, 'ssl')		// SMTP Settings
		  ->setUsername($SENDERID)										// Username
		  ->setPassword($SENDERPASSWD)												// Password 
		  ;

		try {
			//Create the Mailer using your created Transport
			$mailer = @Swift_Mailer::newInstance($transport);
			
			//Create a message
			$message = @Swift_Message::newInstance('Your registration on Diffen')		// Subject
			  ->setFrom(array('no-reply@diffen.com' => 'Diffen'))						// From address and name
			  ->setTo(array($email => ''))													// To address and name
			  ->setBody($body)														// Message body
			  ;

			//Send the message
			$result = @$mailer->send($message);
		} catch(Exception $e) {
			return false;
			//die('Error: ' . $e);
		}
		return true;
	}
?>