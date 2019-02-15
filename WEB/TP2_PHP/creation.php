<?php include('private/entetes.inc.php'); 
		echo "<form action=\"creation.php\" method=\"post\">
			Nom : 
			<input type=\"text\" name=\"nom\">
			<br>
			Prénom : 
			<input type=\"text\" name=\"prenom\">
			<br>
			Mot de passe : 
			<input type=\"text\" name=\"mdp\">
			<br>
			<input type=\"submit\" value=\"valider\"/>
			</form>";
		$fichier = fopen("private/users.csv", "a+");
		error_reporting(0);
		$existe = FALSE;
		echo $existe;
		while($tab=fgetcsv($fichier,20,';')){
			$champs = count($tab);
			for($i=0; $i<$champs; $i ++){
				if($tab[$i]==$_POST['nom'] and $tab[$i+1]==$_POST['prenom'] and $tab[$i+2]==$_POST['mdp']){
					$existe = TRUE;
					echo "Ce compte existe déjà";
				}
			}
		}
		if($existe==FALSE){
			$array = array($_POST['nom'],$_POST['prenom'],$_POST['mdp']);
				if(fputcsv($fichier,$array,';')==FALSE){
					echo "Erreur fputcsv()";
				}
				else {
					echo "Compte crée";
				}
		}
		fclose($fichier);?>
	</body>
</html>
