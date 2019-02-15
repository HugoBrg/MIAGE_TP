<?php include('private/entetes.inc.php'); ?>
		<?php if (isset($_SESSION['nom'])&isset($_SESSION['prenom'])){
     		echo  "<form method=\"post\" action=\"index.php\">
     			<input type=\"submit\" value=\"Déconnecté\" name=\"deco\"/>
     		</form>";
     		if (isset($_POST['deco'])){
     			session_destroy();
     			header("Refresh:0");
     			unset($_SESSION['deco']);
     		} 
		}else{
			
			echo "<form action=\"index.php\" method=\"post\">
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
			while($tab=fgetcsv($fichier,20,';')){
				$champs = count($tab);
				for($i=0;$i<$champs;$i++){
					if($tab[$i]==$_POST['nom'] and $tab[$i+1]==$_POST['prenom'] and $tab[$i+2]==$_POST['mdp']){
						$_SESSION['nom']=$_POST['nom'];
						$_SESSION['prenom']=$_POST['prenom'];
						//header("Refresh:0");
					}
				}
			}
		}?> 
	</body>
</html>