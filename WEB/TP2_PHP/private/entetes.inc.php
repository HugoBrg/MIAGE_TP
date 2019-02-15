<?php session_name("preferences"); 
session_start();?>
<?xml version="1.0" encoding="utf-8" ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
	    <title>TP3</title>
	    <!-- ligne pour l'encodage de la page -->
	    <meta http-equiv="Content-Type" content="text/html;charset=utf-8" />

	    <?php if (isset($_SESSION['css'])){
	    	echo "session : ";
	    	echo $_SESSION['css'];
	    	echo "<link rel='stylesheet' href='".$_SESSION['css']."'/>";
	    }
	    include('bandeau.inc.php');
	    $bandeau = new Bandeau();
		$headers = $bandeau->genereBarNav();
		echo $headers;
		$page = explode("/",$_SERVER['PHP_SELF']);
		$publicAccess = Bandeau::$publicAccess;
		foreach ($publicAccess as $key => $value) {
        	if ($key == 2) {
        		if (!(isset($_SESSION['nom'])&isset($_SESSION['prenom']))&$page[2]==$value){
					header('Location: index.php'); 
        		}
        	}
        	if ($key > 2) {
        		if (isset($_SESSION['nom'])&isset($_SESSION['prenom'])&$page[2]==$value){
					header('Location: index.php'); 
        		}
        	}
    	}


		?>
	</head>
	<body>