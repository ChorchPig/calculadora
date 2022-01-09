var ecuation=[];
var i=0;
function obtenerNum(valor){
    ecuation[i]=valor;
    i++;
    console.log(ecuation);
}
function calcularEcuation(){
    console.time();
    let ecString=ecuation.toString();
    for(let j=0; j<ecString.length; j++){
        ecString = ecString.replace(",", "");
    }
    console.log(ecString);
    console.timeEnd();
}// retorno NaN
function allClear(){
    ecuation=[];
} //No reinicia el tamaño de ecuation