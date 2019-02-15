/*================================v4================================*/
function changeColor(){
    var h1 = document.getElementsByTagName("h1");
    for(var i=0;i<h1.length;i++){
        if("#"+h1[i].getAttribute("id")==this.getAttribute("href")){
            h1[i].setAttribute("class", "data-red");
            this.setAttribute("class", "data-red");
        }
    }
    var h2 = document.getElementsByTagName("h2");
    for(var x=0;x<h2.length;x++){
        if("#"+h2[x].getAttribute("id")==this.getAttribute("href")){
            h2[x].setAttribute("class", "data-green");
            this.setAttribute("class", "data-green");
        }
    }
}

function resetColor(){
    var h1 = document.getElementsByTagName("h1");
    for(var i=0;i<h1.length;i++){
        if("#"+h1[i].getAttribute("id")==this.getAttribute("href")){
            h1[i].setAttribute("class", "data-none");
            this.setAttribute("class", "data-none");
        }
    }
    var h2 = document.getElementsByTagName("h2");
    for(var x=0;x<h2.length;x++){
        if("#"+h2[x].getAttribute("id")==this.getAttribute("href")){
            h2[x].setAttribute("class", "data-none");
            this.setAttribute("class", "data-none");
        }
    }
}

window.onload = function () {
    var style = document.createElement("style");
    var txt_1 = document.createTextNode(".data-none{color:none;background-color:none;} .data-red{color:red;background-color: coral;} .data-green{color:green;background-color: lightgrey;} table,th,td{border:1px solid black;");
    style.appendChild(txt_1);
    document.head.appendChild(style);

    var h1 = document.getElementsByTagName("h1");
    var h2 = document.getElementsByTagName("h2");
    var table = document.createElement("table");

    for(var i=0;i<h1.length;i++){ 
        var a_1 = document.createElement("a");   
        var td_1 = document.createElement("td");
        var tr_1 = document.createElement("tr");

        if(h1[i].id==""){
            h1[i].id="h1_"+i;
            a_1.setAttribute("href", "#h1_"+i);
        }
        else {
            a_1.setAttribute("href", "#"+h1[i].id);
        }

        var txt_2 = document.createTextNode(h1[i].innerText);
        a_1.appendChild(txt_2);
        td_1.appendChild(a_1);
        tr_1.appendChild(td_1);

        for(var x=0;x<h2.length;x++){
            if(h2[0].previousElementSibling.innerHTML==h1[i].innerHTML){
                var a_2 = document.createElement("a");
                var td_2 = document.createElement("td");

                if(h2[x].id==""){
                    h2[x].id="h2_"+x;
                    a_2.setAttribute("href", "#h2_"+x);
                }
                else {
                    a_2.setAttribute("href", "#"+h2[x].id);
                }

                var txt_2 = document.createTextNode(h2[x].innerText);
                a_2.appendChild(txt_2);
                td_2.appendChild(a_2);
                tr_1.appendChild(td_2);

                a_2.addEventListener("mouseover", changeColor);
                a_2.addEventListener("mouseleave", resetColor);
            }
        }



        table.appendChild(tr_1);

        a_1.addEventListener("mouseover", changeColor);
        a_1.addEventListener("mouseleave", resetColor);
    }
    var body = document.querySelector("h1");
    document.body.insertBefore(table,body); 
    //console.log(h1);
    console.log(h2);
}

/*================================v3================================*/
/*function changeColor(){
    this.setAttribute("class", "data-red");
}

function resetColor(){
    this.setAttribute("class", "data-none");
}


window.onload = function () {
    var style = document.createElement("style");
    var txt_1 = document.createTextNode(".data-none{color:none;background-color:none;} .data-red{color:red;background-color: coral;}");
    style.appendChild(txt_1);
    document.body.appendChild(style);
    var items = document.getElementsByTagName("h1");
    console.log(items);
    var table = document.createElement("table");
    for(var i=0;i<items.length;i++){
        var tr = document.createElement("tr");
        var td = document.createElement("td");
        var a = document.createElement("a");
        if(items[i].id==""){
            items[i].id="h1_"+i;
            a.setAttribute("href", "#h1_"+i);
        }
        else {
            a.setAttribute("href", "#"+items[i].id);
        }

        var txt_2 = document.createTextNode(items[i].innerText);
        a.appendChild(txt_2);
        td.appendChild(a);
        tr.appendChild(td);
        table.appendChild(tr);

        a.addEventListener("mouseover", changeColor);
        a.addEventListener("mouseleave", resetColor);
    }
    //var body = document.getElementsByTagName("body");
    //document.insertBefore(table,body); 
    document.body.appendChild(table);
    console.log(items);
}*/

/*================================v2================================*/
/*window.onload = function () {
    var items = document.getElementsByTagName("h1");
    console.log(items);
    var table = document.createElement("table");
    for(var i=0;i<items.length;i++){

        var tr = document.createElement("tr");
        var td = document.createElement("td");
        var a = document.createElement("a");
        if(items[i].id==""){
            items[i].id="h1_"+i;
            a.setAttribute("href", "#h1_"+i);
        }
        else {
            a.setAttribute("href", "#"+items[i].id);
        }

        var txt = document.createTextNode(items[i].innerText);
        a.appendChild(txt);
        td.appendChild(a);
        tr.appendChild(td);
        table.appendChild(tr);
    }
    //document.insertBefore(table,items); 
    document.body.appendChild(table);
    console.log(items);
}*/

/*================================v1================================*/
/*window.onload = function () {
    var items = document.getElementsByTagName("h1");
    //console.log(items);
    var table = document.createElement("table");
    for(var i=0;i<items.length;i++){
        var tr = document.createElement("tr");
        var td = document.createElement("td");
        var txt = document.createTextNode(items[i].innerText);
        td.appendChild(txt);
        tr.appendChild(td);
        table.appendChild(tr);
    }
    //document.insertBefore(table,items); 
    document.body.appendChild(table);
}*/
