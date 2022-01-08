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
        if(ecString[j]==","){ecString[j]=" "}
    }
    console.log(ecString);
    console.timeEnd();
}