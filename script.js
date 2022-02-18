var equation=[];
var i=0;
function obtenerNum(valor){
    equation[i]=valor;
    i++;
    console.log(equation);
}
function calcularEcuation(){
    console.time();
    let ecString=equation.toString();
    for(let j=0; j<ecString.length; j++){
        ecString = ecString.replace(",", "");
    }
    console.log(ecString);
    console.timeEnd();
}// retorno NaN
function allClear(){
    equation=[];
    i=0;
}
