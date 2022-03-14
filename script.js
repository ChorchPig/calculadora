var equation=[];
var i=0;
function obtenerNum(valor){
    equation[i]=valor;
    i++;
    console.log(equation);
}
function calcularEcuation(){
    let ecString=equation.toString();
    for(let j=0; j<ecString.length; j++){
        ecString = ecString.replace(",", "");
    }
    console.log(Numbre(ecString));
}// retorno NaN, sin solución aparente
function allClear(){
    equation=[];
    i=0;
}
