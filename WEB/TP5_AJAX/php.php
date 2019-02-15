<?php
header("Content-type: text/json");
$q=$_GET["q"]; //on récup la requête
$odir = opendir($q);
$dirtab;
while (false != ($rdir = readdir($odir))) {
    $dirtab[]=$rdir;
}
/*$test=implode("|",$dirtab);
var_dump($test);*/
echo json_encode($dirtab);
?>