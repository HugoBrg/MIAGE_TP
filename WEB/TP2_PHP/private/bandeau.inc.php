<link rel='stylesheet' href='private/nav.css'/>
<?php class Bandeau {

public static $map = array( array("tableau.php", "Plan du site"),
              array("preferences.php", "Choix du style"),
              array("date.php", "Manipulation de dates"),
              array("index.php","Connexion","Deconnection"),
              array("creation.php","Inscription"));

/*
0,1 = public (tjr accessible)
2 = accessible si connecté
3,4 = accessible si deconnecté
*/

public static $publicAccess = array ( 0 => "tableau.php",
                                      1 => "index.php",
                                      2 => "preferences.php",
                                      3 => "date.php" ,
                                      4 => "creation.php");

   public function genererLien($href, $name) {
    $site = explode("/",$_SERVER['PHP_SELF']);
    $publicAccess = Bandeau::$publicAccess;
    if (isset($_SESSION['nom'])&isset($_SESSION['prenom'])){
      foreach ($publicAccess as $key => $value) {
        if ($key >= 0 & $key < 3 & $href==$value) {
          if(!($name=='Connection')){
            if($site[2]==$href){
              $ret = "<div class='lien'><a id='here' href=\"http://localhost/TP3/$href\">$name</a></div>";
            }
            else{
              $ret = "<div class='lien'><a href=\"http://localhost/TP3/$href\">$name</a></div>";
            }   
            return $ret;
        }
      }
    }
  }
    else {
      foreach ($publicAccess as $key => $value) {
        if (($key < 2 || $key > 2) & $href==$value) {
          if(!($name=='Deconnection')){
            if($site[2]==$href){
              $ret = "<div class='lien'><a id='here' href=\"http://localhost/TP3/$href\">$name</a></div>";
            }
            else{
              $ret = "<div class='lien'><a href=\"http://localhost/TP3/$href\">$name</a></div>";
            }   
            return $ret;
          }
        }
      }
    }
   }

   public function genereBarNav() {
    $map = Bandeau::$map;
    $ret = "<div class=\"barrenavigation\">";
    $ajd = date('d-m-Y H:i:s');
    if (isset($_SESSION['nom'])&isset($_SESSION['prenom'])){
      $nom = ($_SESSION['nom']);
      $prenom = ($_SESSION['prenom']);
      $ret .= "<div id='visiteur'>Bienvenue $nom $prenom , nous sommes le , $ajd</div>";
    }
    else {
      $ret .= "<div id='visiteur'>Bienvenue cher visiteur, nous sommes le , $ajd</div>";
    }  
    foreach ($map as $value) {
      foreach ($value as $key => $value2){
        if($key){
          $ret .= $this->genererLien($href,$value2);
        }
        else{
          $href=$value2;
        }
      }
    }
    $ret .= "</div>";
    return $ret;
   }
}?>