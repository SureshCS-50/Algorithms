<html>
<head>
<title>Submit Feedback</title>

</head>
<body>
<?php
	include_once('config.php');
	
	mysql_connect("localhost", $USERNAME, $PASSWORD) or die ("$errorstr Couldn't execute required action. Try again later.");
	mysql_select_db($DATABASE) or die ("$errorstr Couldn't execute required action. Try again later.");
	$queryString = mysql_real_escape_string($_POST['activationkey']);
	$query = "SELECT * FROM subscribers WHERE activationkey=\"$queryString\"";
	$result = mysql_query($query) or die ("$errorstr Couldn't execute required action. Try again later.");
	if(mysql_num_rows($result)==0) {
		echo "Error: Invalid Activation Key.";
	} else {
		while($row = mysql_fetch_array($result)) {
			if ($queryString == $row['activationkey']) {
				$email = $row['email'];

				echo "<b>Hello, " . $email . "<br /><br />";
				if (!isset($_POST['unsubscribe'])) {
					echo "<font color=\"red\">You must agree to unsubscribe by ticking the checkbox.</font><br/>";
					return;
				}
			}
		}
	}
?>

<div class="unsubscriber" >
<div class="feedbackError"></div>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Are you sure you want to unsubscribe? <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Optional: Please share your feedback and reason for unsubscribing. <br />
	<form name="feedbackform" id="feedbackform" method="post" action="manage.php">
	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<textarea name="feedback" id="feedback" cols="45" rows="5"></textarea><br /><br />
	  <input type="hidden" name="activationkey" value="<?php echo $queryString?>">
	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<button type="submit" name="unsubscribe" class="button negative"> Yes, I'm sure. Unsubscribe me. </button>
	</form>
</div>

<div class="loading" style="display:none;"><img src="loading.gif" border="0" alt="Loading, please wait..." /></div>
<div class="success" style="display:none;"></div>

</body>
</html>
