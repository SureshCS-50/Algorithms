<?php 
	
	include_once('config.php');
	include_once('IP.php');
	include_once('sendMail.php');	
	
	$ip = getRealIpAddr();

	mysql_connect("localhost", $USERNAME, $PASSWORD) or die ("$errorstr Couldn't execute required action. Try again later.";return;}
	
	mysql_select_db($DATABASE) or die ("$errorstr Couldn't execute required action. Try again later.";return;}

	$activationKey = mysql_real_escape_string($_GET['activationkey']);
	
	$query = "SELECT * FROM subscribers WHERE activationkey=\"$activationKey\"";
	$result = mysql_query($query) or die ("$errorstr Couldn't execute required action. Try again later.";return;}
	if(mysql_num_rows($result)==0) {
		echo "Error: Invalid Activation Key.";
		$flag = false;
	} else {
		while($row = mysql_fetch_array($result)) {
			if ($activationKey == $row['activationkey']) {
				if ($row['status'] == PENDING_VERIFICATION) {
					
					$email = $row['email'];
					
					echo "<b>Hello, " . $email . "<br /><br /></b>";
					##Send activation Email
					$body_link = "http://localhost/diffen/verify.php?activationkey=$activationKey";
					$bodyManage = "\r\rYou can manage your Subscription or Unsubscribe through this link: http://localhost/diffen/manageSubscription.php?activationkey=$activationKey";
					$body = $body1 . $body_link . $bodyManage . $body2;
					
					if (sendMail($email, $activationKey, $body, $SENDERID, $SENDERPASSWD)) {	
						echo "An email has been sent to $email with an activation key. Please check your mail to complete registration.";
					} else {
						echo ($errorstr . " Could not send the mail. Please try again later. <br \>");
						#die('Error: ' . $e);
					}
					
					echo "<br \>Visit <a href=\"http://www.diffen.com\">homepage</a>. <br \>";
				}
				break;
			}

		}
	}
?>