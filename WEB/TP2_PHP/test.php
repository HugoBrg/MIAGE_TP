<?php session_name("preferences"); 
session_start();?>
<?xml version="1.0" encoding="utf-8" ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
	    <title>TP3</title>
	    <meta http-equiv="Content-Type" content="text/html;charset=utf-8" />

	    <!--chargement du css de la page via variable de session-->
	    <?php
	    	echo "session : ";
	    	echo $_SESSION['css'];
	    	echo "<link rel='stylesheet' href='".$_SESSION['css']."'/>";

	    /*on scan les fichiers css*/
		$listefichier = array();
		$fichiers = glob("private/*.css");
		foreach ($fichiers as $value) {
			$listefichier[$value]=$value;
		};?>

		<!--formulaire de choix du style-->
		<form action="test.php" method="post" border="1px"> 
		<select name="css" size="1">
		<?php foreach($listefichier as $value)
			echo "<option>{$value}";?>
		</select>
		<input type="submit" value="valider"/>
		</form>

		<!--actualisation du nouveau css-->
		<?php
			$_SESSION['css']=($_POST['css']);
			echo "page : ";
			echo $_SESSION['css'];
			echo "<link rel='stylesheet' href='private/'".$_SESSION['css']."'/>";
		?>
	</body>
</html>