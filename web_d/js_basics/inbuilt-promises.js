// implement custom promises 

//promise
//Promise is an object created using Promise() constructor function and have 2 properties
//  .state
// .value

// state - Possible value
//  - pending
//  - fulfilled
//  -  rejected

// value - Possible value
//  - undefined
//  - return value or error

promise1.then((value)=>{})

function inbuiltPromise(resolve, reject){
    setTimeout(() => {
        resolve({response : "responseValue"})
        // reject({response : "responseValue"})
        console.log('Inside custom promise executor');
    }, 10000);
}


let responseVal;
var p1 = new Promise(inbuiltPromise);
p1.catch((val) => {
    responseVal = val;
});

