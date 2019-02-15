<?php include('private/entetes.inc.php'); ?>
			<?php $datefichier = 'date.php';
			$tableaufichier ='tableau.php';
			$titre = array('Nom du fichier','Date de modification','Taille');
			$tab = array(array($datefichier,date ("d-m-Y H:i:s.", filemtime($datefichier)),filesize($datefichier)),array($tableaufichier,date ("d-m-Y H:i:s.", filemtime($tableaufichier)),filesize($tableaufichier)));?>
			<!--<pre><?php //print_r($titre);
			//print_r($tab);
			//var_dump($titre);
			//var_dump($tab);?></pre> -->
			<?php function genereTableau($title,$body){
				$ligne = sizeof($body);
				echo "<table>";
				echo "<thead>";
				foreach ($title as $value)
					echo "<th>{$value}</th>";
				echo "</thead>";
				echo "<caption>Il y a $ligne ligne</caption>";
				$cpt = 0;
				echo "<tr>";
				foreach ($body as $value) {
					foreach ($value as $value2){
						if ($cpt==0)
							echo "<td><a href=http://localhost/TP3\\$value2>{$value2}</a></td>";
						else
							echo "<td>{$value2}</td>";
						$cpt = $cpt+1;
						if($cpt==sizeof($title)){
							$cpt=0;
							echo "</tr>";
							echo "<tr>";
						}
					}
				}
				echo "</tr>";
				echo "</table>";
			};?>
			<?php genereTableau($titre,$tab);
			$listefichier = array();
			$fichiers = glob("*.*");
			foreach ($fichiers as $value) {
				$listefichier[$value]=array($value,date("d-m-Y H:i:s", filemtime($value)),filesize($value));
			};
			error_reporting(0);
			$lien=htmlspecialchars($_GET["tri"]);
			if($lien=="reverse") //si adresse = http://localhost/TP3/tableau.php?tri=reverse
				rsort($listefichier);
			genereTableau($titre,$listefichier);
			error_reporting(1);?>
		</body>
</html>
