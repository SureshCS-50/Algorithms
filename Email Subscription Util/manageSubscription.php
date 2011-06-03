<html>
<head>
<title>Subscribe</title>
</head>
<body>


<?php
	include_once('config.php');
	
	mysql_connect("localhost", $USERNAME, $PASSWORD) or die ("$errorstr Couldn't execute required action. Try again later.");
	mysql_select_db($DATABASE) or die ("$errorstr Couldn't execute required action. Try again later.");
	
	if(isset($_GET['activationkey'])) {
		$queryString = mysql_real_escape_string($_GET['activationkey']); 
	} else {
		echo "<meta http-equiv=\"refresh\" content=\"5; URL=$homePageURL\">";	
		die ("You have reached an incorrect link and will be redirected to www.diffen.com in 5 seconds.");
	}
?>

<?php
	
	$query = "SELECT * FROM subscribers WHERE activationkey=\"$queryString\"";
	$result = mysql_query($query) or die ("$errorstr Couldn't execute required action. Try again later.");
	if(mysql_num_rows($result)==0) {
		echo "Error: Invalid Activation Key.";
		$flag = false;
	} else {
		while($row = mysql_fetch_array($result)) {
			if ($queryString == $row['activationkey']) {
				if ($row['status'] != ACTIVE) {
					$flag = false;
					if ($row['status'] == PENDING_VERIFICATION) {
						echo "You have not yet activated your subscription. Please check your mail to activate your account. <br \>";////header ("Location: http://www.google.com");
						echo "To recieve the activation mail again, please click <a href=\"resendActivation.php?activationkey=$queryString\"> here </a>. <br \>";
						echo "<br \>Visit <a href=\"$homePageURL\">homepage</a>. <br \>";
						break;
					} else if ($row['status'] == UNSUBSCRIBED) {
						echo "You have reached an incorrect link and will be redirected to www.diffen.com in 5 seconds.";
						echo "<meta http-equiv=\"refresh\" content=\"5; URL=$homePageURL\">";
						break;
					}
				} 
				
				$flag = true;
				$email = $row['email'];

				echo "<b>Hello, " . $email . "<br /><br />";
				echo "<div id=\"wrap\" class=\"wrap\">";
				echo "Manage your email alerts:<br /><br />";
				echo "Update E-Mail frequency<br /> </b>";
			}
		}
	}
	
	if ($flag == true) {
?>
<form id="subscribeform" method="post" name="subscribeform" action="manage.php">
	<div class="error" style="display:none;"></div>
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		<input name="frequency" type="radio" id="frequency_0" value="daily" checked>
		Daily</label>	
		<label>
		<input type="radio" name="frequency" value="weekly" id="frequency_1">
		Weekly</label>
		<label>
		<input type="radio" name="frequency" value="monthly" id="frequency_2">
		Monthly</label>&nbsp;&nbsp;&nbsp;
		<input type="hidden" name="activationkey" value="<?php echo $queryString?>">
		<button type="submit" class="button positive"> Update </button>
</form>

<b>Unsubscribe</b>
<div class="error1" style="display:none;"></div>

<form name="unsubscribeform" id="unsubscribeform" method="post" action="feedbackWithoutJS.php">
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;	<input type="checkbox" name="unsubscribe" id="unsubscribe">
  <input type="hidden" name="activationkey" value="<?php echo $queryString?>">
  <label for="unsubscribe"> I wan't to unsubscribe for now!</label>&nbsp;&nbsp;
  <button type="submit" class="button negative"> Unsubscribe </button>
</form>

</div>

<div class="unsubscriber" style="display:none;">
<div class="feedbackError"></div>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Are you sure you want to unsubscribe? <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Optional: Please share your feedback and reason for unsubscribing. <br />
	<form name="feedbackform" id="feedbackform" method="post" action="manage.php">
	<input type="hidden" name="activationkey" value="<?php echo $queryString?>">
	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<textarea name="feedback" id="feedback" cols="45" rows="5"></textarea><br /><br />
	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<button type="submit" class="button negative"> Yes, I'm sure. Unsubscribe me. </button>
	</form>
</div>

<div class="loading" style="display:none;"><img src="loading.gif" border="0" alt="Loading, please wait..." /></div>
<div class="success" style="display:none;"></div>
<?php 
	}		//if closing bracket
?>

<script type="text/javascript" src="jquery.js"></script>
<script type="text/javascript">
	$(document).ready(function(){
		$("form#subscribeform").submit(function() {
			var activationKey = <?php echo "\"$queryString\"" ?>;
			var frequency;
			var radioButtons = document.getElementsByName("frequency");
			
			for (var x = 0; x < radioButtons.length; x ++) {
				if (radioButtons[x].checked) {
					frequency = radioButtons[x].value;
				}
			}
			
			var dataToPost = {
				activationkey: activationKey,
				frequency: frequency,
			};
			
			$('div.loading').fadeIn();
			$('div.error').hide();
			$.ajax({
				type: "POST",
				url: "manage.php",
				data: dataToPost, 
				success: function(data){
					if (data.indexOf("Error") == 0) {
						$('div.error').fadeIn();
						$('div.error').html("<font color=\"red\">" + data + "</font><br/>")
						$('div.loading').hide();
					} else {
						$('div.wrap').hide();
						$('div.success').fadeIn();
						$('div.loading').hide();
						$('div.success').html("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" + data);
					}
				}
			});
		return false;
		});
		
		$("form#unsubscribeform").submit(function() {
			var activationKey = <?php echo "\"$queryString\"" ?>;
			var frequency;
			var checkBox = document.getElementById("unsubscribe").checked;
			if (checkBox == 1) {
				$('div.error1').hide();
				$('div.wrap').hide();
				$('div.unsubscriber').fadeIn();
			} else {
				$('div.error1').fadeIn();
				$('div.error1').html("<font color=\"red\">You must agree to unsubscribe by ticking the checkbox.</font><br/>")
			}
		return false;
		});
		
		$("form#feedbackform").submit(function() {
			var activationKey = <?php echo "\"$queryString\"" ?>;
			var feedback     = $('#feedback').attr('value');
			
			var dataToPost = {
				activationkey: activationKey,
				feedback: feedback,
				unsubscribe: 1
			};
			
			$('div.loading').fadeIn();
			$('div.feedbackError').hide();
			$.ajax({
				type: "POST",
				url: "manage.php",
				data: dataToPost, 
				success: function(data){
					if (data.indexOf("Error") == 0) {
						$('div.feedbackError').fadeIn();
						$('div.feedbackError').html("<font color=\"red\">" + data + "</font><br/>")
						$('div.loading').hide();
					} else {
						$('div.unsubscriber').hide();
						$('div.success').fadeIn();
						$('div.loading').hide();
						$('div.success').html("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" + data);
					}
				}
			});
		return false;
		});
	});
</script>


</body>
</html>
