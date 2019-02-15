<?php include('private/entetes.inc.php');?>
		<p>Nous sommes le :
		<?php echo date('d-m-Y');
		$ajd = date('U');
		$futur = strtotime("01 November 2018");?>
		il reste	
		<?php $notrounded = ($futur-$ajd)/86400;
		$rounded = round($notrounded);
		$seconds = abs(($notrounded-$rounded)*24*60*60);
		echo $rounded;?>
		jours et	
		<?php echo $seconds;?>
		secondes avant le
		<?php $futurS = date_create("01-11-2018");
		echo date_format($futurS,'d-m-Y'); ?>
		<br><br>
		Sélectionner une date :</p>
		<form action="date.php" method="post"> 
			<input type="date" max="2018-12-30" min="<?php date('Y-m-d');?>" name="date">
			<input type="submit" value="valider" />
		</form>
		<br>
		<p>Il reste
		<?php error_reporting(0);
		$futur2 = strtotime($_POST['date']);
		$notrounded2 = ($futur2-$ajd)/86400;
		$rounded2 = round($notrounded2);
		$seconds2 = abs(($notrounded2-$rounded2)*24*60*60);
		echo $rounded2;?>
		jours et
		<?php echo $seconds2;?>
		secondes avant le
		<?php $str = ($_POST['date']);
		$date = new DateTime($str);
		$date =  date_format($date, 'd-m-Y');
		$str = $date;
		$valeurs_remplacées = array('-01-','-02-','-03-','-04-','-05-','-06-','-07-','-08-','-09-','-10-','-11-','-12-');
		$valeurs_qui_remplacent = array(' Janvier ',' Février ',' Mars ',' Avril ',' Mai ',' Juin ',' Juillet ',' Aout ',' Septembre ',' Octobre ',' Novembre ',' Decembre ');
		$str = str_replace($valeurs_remplacées, $valeurs_qui_remplacent, $str);
		echo $str;?></p>
	</body>
</html>
