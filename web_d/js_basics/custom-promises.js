//var p1 = new Promise(promisExec)

// function customPromiseExecutor(){
//     console.log('inside custom promise executor');
// }

// function customPromise(executorFunctionArg){
//     executorFunctionArg();
//     this.state = "pending";
//     let returnValue = undefined;


// }

// let p1 = new customPromise(customPromiseExecutor);
// console.log(p1);

function customPromiseExecutor(resolve, reject){
    setTimeout(() => {
        // resolve({response : "responseValue"}) 
        reject({response : "responseValue"})
        console.log('Inside custom promise executor');
    }, 10000);
}


function customPromise(executorFunctionArg){
    this.state = "pending";
    // this.then = (arg) => {}
        let successCallbackCustom;
        let errorCallbackCustom;

    executorFunctionArg(
        (responseArg) => {
            this.state = "fulfilled";
            console.log('inside resolve function', responseArg);
            successCallbackCustom();
        },
        (errorArg) => {
            this.state = "rejected";
            console.error('inside error function', errorArg);
            errorCallbackCustom();
        }
    );
    this.then = (arg1) => {
        successCallbackCustom = arg1;
        errorCallbackCustom = arg1;
    }
    let returnValue = undefined;
}


var promiseCustom1 = new customPromise(customPromiseExecutor);
// console.log(promiseCustom1);

promiseCustom1.then((val) => {
    responseVal = val;
});