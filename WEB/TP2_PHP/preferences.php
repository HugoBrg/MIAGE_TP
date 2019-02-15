<?php include('private/entetes.inc.php'); ?>
		<?php $listefichier = array();
			$fichiers = glob("private/*.css");
			foreach ($fichiers as $value) {
				$listefichier[$value]=$value;
			};?>
		<form action="preferences.php" method="post" border="1px"> 
			<select name="css" size="1">
			<?php foreach($listefichier as $value)
				echo "<option>{$value}";?>
			</select>
			<input type="submit" value="valider"/>		
		</form>
		<?php if (isset(($_POST['css']))){
			$_SESSION['css']=($_POST['css']);
			echo "page : ";
			echo $_SESSION['css'];
			header("Refresh:0");
			//echo "<link rel='stylesheet' href='private/$css'/>";
		}?>
	</body>
</html>