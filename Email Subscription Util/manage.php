<?php
	include_once('validateEmail.php');
	include_once('IP.php');
	include_once('config.php');
	
	$ip = getRealIpAddr();

	mysql_connect("localhost", $USERNAME, $PASSWORD) or die ("$errorstr Couldn't execute required action. Try again later.");
	
	mysql_select_db($DATABASE) or die ("$errorstr Couldn't execute required action. Try again later.");//die(mysql_error());
	
	if (!isset($_POST['unsubscribe'])) {
		
		$activationKey =  mysql_real_escape_string($_POST['activationkey']);
		
		$frequency = mysql_real_escape_string($_POST['frequency']);
		
		if($frequency=='daily'|| $frequency=='weekly' || $frequency=='monthly') {
			if ($frequency == 'daily') {
				$frequency = DAILY;
			} else if ($frequency == 'weekly') {
				$frequency = WEEKLY;
			} else {
				$frequency = MONTHLY;
			}
				
			$sql_check_duplicate = "SELECT * FROM subscribers WHERE activationkey=\"$activationKey\"";
			$result_check_duplicate = mysql_query($sql_check_duplicate) or die ("$errorstr Couldn't execute required action. Try again later.");
			
			if(mysql_num_rows($result_check_duplicate)!=0) {
				$row = mysql_fetch_array($result_check_duplicate);
				if ($row['status'] == ACTIVE) {
					$sql="UPDATE subscribers SET frequency=$frequency, IP=\"$ip\" WHERE activationkey=\"$activationKey\"";
				}
			} else {  
				echo ($errorstr . "Invalid Activation Key");
			}
			
			if (!mysql_query($sql)) {
				echo "$errorstr Couldn't execute required action. Try again later.";
				return;
			  //die($errorstr . mysql_error());
			}
			echo "Done! Your E-Mail prefrence has been saved.";
		} else {
			echo ($errorstr . "Choose valid Subscription duration");
		}
	} else {
	    $activationKey =  mysql_real_escape_string($_POST['activationkey']);
		$feedback = mysql_real_escape_string($_POST['feedback']);
		if (strlen($feedback) > MAXFEEDBACKLENGTH) {
			$trim_feedback = substr($feedback, 0, MAXFEEDBACKLENGTH-1);
			$sql="UPDATE subscribers SET unsubscribeTime=NOW(), status=" . UNSUBSCRIBED . ", feedback='$trim_feedback' WHERE activationkey=\"$activationKey\"";
			//echo($errorstr . " Length of feedback must be less than 2048 characters.");
			//return;
		} else {
			$sql="UPDATE subscribers SET unsubscribeTime=NOW(), status=" . UNSUBSCRIBED . ", feedback=\"$feedback\" WHERE activationkey=\"$activationKey\"";
		}
	   
		if (!mysql_query($sql)) {
			echo "$errorstr Couldn't execute required action. Try again later.";
			return;
			//die($errorstr . mysql_error());
		}
		echo "Done! You will not receive any more emails.";
		
	}
?>