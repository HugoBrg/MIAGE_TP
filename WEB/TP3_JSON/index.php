<?xml version="1.0" encoding="utf-8" ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
	    <title>TP3</title>
	    <meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
	</head>
	<body>
		<form action="index.php" method="post" border="1px"> 
			Localisation
			<input type="text" name="loc">
			<input type="submit" value="valider"/>	
		</form>
		<?php function meteo($lat, $lon){
			$climat ="http://www.infoclimat.fr/public-api/gfs/json?_ll=$lat,$lon&_auth=AhhTRFQqBCZRfAcwD3kGL1Y%2BATRaLAIlC3dVNg5gUSwDZ1YyBGRcP1I%2BAH1Vegc0BShUNg43U20HZAtkWCoEeAJjUz5UPgRmUToHYQ8%2FBi1WegF8WmQCJQt3VToOYFEsA2FWMwRkXCBSPwBnVWEHLQU%2FVDQOLlN0B2ULaFg9BGcCaVMwV DIEZlE%2BB2UPIAYtVmABaVphAj4LbVVgDjVROgNpVjoEM1xsUjkAYVV7BzQFMVQzDjlTaQdjC25YNgR4An5TTlREBHtRfgcnD2oGdFZ4ATRaOwJu&_c=a4c69e2851123ac57a2cabb4a6ad2608";	
			error_reporting(0);
			if (!$json2 = file_get_contents($climat,false,$context)) {
			    $error = error_get_last();
			} else {
		      	$json2 = json_decode($json2);
		      	foreach ($json2 as $keytest => $jsonver2) {
		      		$date =  date('Y-m-d');
		      		$date .=" 13:00:00";
		      		//$date = date_format("Y-m-d H:i:s");
		      		//$date -> add(new DateInterval('PT3H'));
		      		//var_dump($date);
		      		if($keytest==$date){
		      			foreach ($jsonver2 as $key => $value) {
		      				if($key=='temperature'){
		      					foreach ($value as $key2_3 => $temp) {
									if($key2_3=='sol'){
										$temp = $temp-273;
										echo "<br><br><br><br><br><br><br><br>Aujourd'hui il fait : $temp °C";
										echo "<iframe seamless width=\"888\" height=\"336\" frameborder=\"0\" src=\"https://www.infoclimat.fr/public-api/mixed/iframeSLIDE?_ll=$lat,$lon&_inc=WyJOaWNlIiwiMjUiLCIyOTkwNDQwIiwiRlIiXQ==&_auth=BhxWQVQqBCZWe1JlDngAKQdvDzpeKAIlUS0GZQ5gBHkIbAdjDm5UNwVpUSwGKQEyU35SMAw1BzkCYVA%2FDH5TLwZnVjtUPgRmVj1SNA4%2BACsHKw9yXmACJVEtBmAOYARjCHUHZg5kVCgFa1E2BjMBK1NiUjcMMAcgAn5QNgxkUzQGZ1YyVDcEYFYxUjkOOQArBysPal4zAm9ROwZjDmsEYAhqBzEOblQxBW5ROwYwAStTYVI2DDQHOQJiUDAMZVMwBnpWLVROBBVWJFJwDnwAYQdyD3JeNAJkUWY%3D&_c=269dae0159fc1588504292ddc1373ebc\"></iframe>";
									}
		      					}
		      				}
		      			}
		      		}
		      	}
			}
		}
		$context=stream_context_create(array("http" => array( "header" => "User-Agent: Mozilla")));
		$link = "http://nominatim.openstreetmap.org/search?q=";
		if (isset($_POST['loc']))
			$link.=$_POST['loc'];
		$link.="&format=json";
		$json1 = file_get_contents($link,false,$context);
		$json1 = json_decode($json1);
		foreach ($json1 as $key1_1 => $jsonver1) {
			foreach ($jsonver1 as $key1_2 => $jsonelem1){
				if($key1_2=="boundingbox")
					echo "<iframe style=\"border: none;box-shadow: 1px 1px 3px black;float: left; margin: 0 2em 2em 0;width:600px; height:480px;\" src=\"http://www.openstreetmap.org/export/embed.html?bbox=$jsonelem1[2]%2C$jsonelem1[0]%2C$jsonelem1[3]%2C$jsonelem1[1]&amp;layer=mapnik\"></iframe>";
				if($key1_2=="lat")
					$lat=$jsonelem1;
				if($key1_2=="lon")
					$lon=$jsonelem1;
			}
			/*if((isset($lon)))
				meteo($lat,$lon);*/
		}?>
	</body>
</html>