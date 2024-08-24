var outerFunction = function () {
    console.log('outside inner');
    return{
        innerFunction(){
            console.log('inside inner');
        },
        anotherFunction(){
            console.log('another function');
        },
    };
};

console.log(outerFunction().innerFunction());
// console.log(outerFunction().anotherFunction());


let x = "str1";

x.concat("str2").concat("str3").concat("str4");

function infiniteConcat(initialString){
    this.initialString = initialString;
    this.result = initialString;

    return{
        concat(incomingValue){
            this.result = this.result + " " + incomingValue;
            return this;
        }
    };
}

var concat1 = new infiniteConcat("str1");

