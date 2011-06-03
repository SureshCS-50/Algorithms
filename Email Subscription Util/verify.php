<?php
	include_once('validateEmail.php');
	include_once('IP.php');
	include_once('config.php');
	include_once('sendMail.php');
	
	$ip = getRealIpAddr();

	mysql_connect("localhost", $USERNAME, $PASSWORD) or die ("$errorstr Couldn't execute required action. Try again later.");
	mysql_select_db($DATABASE) or die ("$errorstr Couldn't execute required action. Try again later.");
	
	if (isset($_POST['subscribe'])) {
		
		$email = mysql_real_escape_string($_POST['email']);
		$frequency = mysql_real_escape_string($_POST['frequency']);
		
		if ($email == "") {
			echo $errorstr . " Enter the E-mail address.";
			exit;
		} else if (strlen ($email) > MAXEMAILLENGTH) {
			die($errorstr . "Length of email must be less than 255 characters.");
		}

		$activationKey =  sha1(mt_rand(1,10000000) . 'RANDOM_SALT');//mt_rand() . mt_rand() . mt_rand() . mt_rand() . mt_rand();
		
		if (validEmail($_POST['email'])) {
			if ($frequency == 'daily') {
				$frequency = DAILY;
			} else if ($frequency == 'weekly') {
				$frequency = WEEKLY;
			} else if ($frequency == 'monthly') {
				$frequency = MONTHLY;
			} else {
				echo ($errorstr . "Choose valid Subscription duration");
				return false;
			}
			
			$sql_check_duplicate = "SELECT * FROM subscribers WHERE email=\"$email\"";
			$result_check_duplicate = mysql_query($sql_check_duplicate) or die ("$errorstr Couldn't execute required action. Try again later.");
			
			if(mysql_num_rows($result_check_duplicate)!=0) {
				$row = mysql_fetch_array($result_check_duplicate);
				if ($row['status'] == ACTIVE) {
					die ("$errorstr You are already registered");
				} else if ($row['status'] == PENDING_VERIFICATION) {
					$activationKey = $row['activationkey'];
					echo "You are already registered but have not yet activated your account. <br \>";
				}
				$isDuplicate = true;
				$sql="UPDATE subscribers SET activationkey=\"$activationKey\", IP=\"$ip\", status=" . PENDING_VERIFICATION . ", signupTime=NOW() WHERE email=\"$email\"";
			} else {  
				$isDuplicate = false;
				$sql="INSERT INTO subscribers (email, activationkey, frequency, IP, status, signupTime) VALUES ('$email', '$activationKey', $frequency, '$ip', " . PENDING_VERIFICATION . ", NOW())";
			}
			if (!mysql_query($sql)) {
				die ("$errorstr Couldn't execute required action. Try again later.");
			}

				
			##Send activation Email
			$body_link = "http://localhost/diffen/verify.php?activationkey=$activationKey";
			$bodyManage = "\r\rYou can manage your Subscription or Unsubscribe through this link: http://localhost/diffen/manageSubscription.php?activationkey=$activationKey";
			$body = $body1 . $body_link . $bodyManage . $body2;

			if (sendMail($email, $activationKey, $body, $SENDERID, $SENDERPASSWD)) {
				echo "An email has been sent to $_POST[email] with an activation key. Please check your mail to complete registration.";
			} else {
				echo ($errorstr . "Could not send the mail. Please try again later.");
				if ($isDuplicate == false) {
					$sql="DELETE FROM subscribers WHERE email=\"$email\"";
					if (!mysql_query($sql)) {
						die ("$errorstr Couldn't execute required action. Try again later.");
					}
				}
			}
		} else {
			echo ($errorstr . "You entered an invalid E-Mail id.");
		}
	} else {
		## No value found, user must be activating their account!
		$queryString = mysql_real_escape_string($_GET['activationkey']);
		$query = "SELECT * FROM subscribers WHERE activationkey=\"$queryString\"";
		$result = mysql_query($query) or die ("$errorstr Couldn't execute required action. Try again later.");
		if(mysql_num_rows($result)==0) {
			echo "Error: Invalid Activation Key.";
		} else {
			while($row = mysql_fetch_array($result)) {
				if ($queryString == $row['activationkey']) {
				   echo "You have successfuly validated your e-mail and start recieving updates as per your request.";
				   $sql="UPDATE subscribers SET status=". ACTIVE . ", activationTime=NOW() WHERE (id = $row[id])";
				   if (!mysql_query($sql)) {
						die ("$errorstr Couldn't execute required action. Try again later.");
					}
				}
			}
		}
	}
?>