function obtenerNum(){
    let num1=document.getElementById("num1").value;
    let num2=document.getElementById("num2").value;
    console.log(num1 +","+ num2);
    let operation=document.getElementsByName("operation");
    switch(true){
        case (operation[0].checked==true) : document.getElementById("resultado").innerHTML= +num1 + +num2; break;
        case (operation[1].checked==true) : document.getElementById("resultado").innerHTML= +num1 - +num2; break;
        case (operation[2].checked==true) : document.getElementById("resultado").innerHTML= +num1 * +num2; break;
        case (operation[3].checked==true) : document.getElementById("resultado").innerHTML= +num1 / +num2; break;
    }
}