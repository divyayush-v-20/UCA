// prototypical inheritance
// achieved through prototype or prototype chains

var arr = [1, 2, 3];

callbackFunc = (val) => {
    console.log(val); 
}

// arr.forEach(callbackFunc);

Array.prototype.forEachCustom = function(callbackFunc){
    console.log(this);
    for(let i = 0; i < this.length; i++){
        callbackFunc(this[i]);
    }    
}

// arr.forEachCustom(callbackFunc);

multiplyBy2callbackFunc = (val) => {
    return val * 2;
}

const isPowerOfTwo = (val) => {
    let x = Math.log2(val);
    return Math.round(x) == x;
}

Array.prototype.mapCustom = function(callBack){
    let ans = new Array();
    // console.log(this);   
    for(let i = 0; i < this.length; i++){
        ans.push(callBack(this[i]));
    }   
    return ans; 
}

// console.log([3, 1, 6, 2, 5, 4].mapCustom(multiplyBy2callbackFunc));

// console.log([512, 255, 128, 10].mapCustom(isPowerOfTwo));

const type = (val) => {
    if(val < 0) return "negative";
    else if(val == 0) return "zero";
    else return "positive";
}

// console.log([-1, -2, 0, 2, 1].mapCustom(type));