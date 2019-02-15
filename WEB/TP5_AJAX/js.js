function ask(str) { //reçoit la chaîne tapée par l'utilisateur
    xmlhttp=new XMLHttpRequest(); //objet permettant de retrouver des données à partir d'un URL avant même que la page soit chargée
    xmlhttp.onreadystatechange=function() {
       if (xmlhttp.readyState==4 && xmlhttp.status==200) { //réponse reçue + absence d'erreurs
         document.getElementById("rep").innerHTML=xmlhttp.responseText; //retourne le texte reçu par un serveur
         obj = JSON.parse(xmlhttp.responseText);
         //console.log(obj);
       }
    }
    xmlhttp.open("GET","php.php?q="+str,true); //on crée un requête ou on récupère qqch de php.php en utilisant des events listeners (true)
    xmlhttp.send(); //on envoie la requête

    if(obj){
      var style = document.createElement("style");
      var txt_1 = document.createTextNode("table,th,td{border:1px solid black;} .data-red{color:red;}");
      style.appendChild(txt_1);
      document.head.appendChild(style);
      var table = document.createElement("table");
      for(i=0;i<obj.length;i++){
         var td = document.createElement("td");
         var txt = document.createTextNode(obj[i]);
         var tr = document.createElement("tr");
         console.log(obj[i].isDirectory);
         if(obj[i].isDirectory!=false){
            td.setAttribute("class", "data-red");
            obj[i].onclick=function(){console.log("ok")};
         }
         td.appendChild(txt);
         tr.appendChild(td);
         table.appendChild(tr);
      } 
      document.body.appendChild(table);
    }

 }
 