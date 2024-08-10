const arr = [3, 1, 4, 2, 5];
for(let i in arr){
    // console.log(arr[i]);
}
arr.forEach((item) => {
    // console.log("in forEach " + item);
});

const agent = {
    name : "Reyna",
    abilities : {
        E : "Dismiss",
        Q : "Devour",
        X : "Empress",
        C : "Leer"
    },
    category : "Duelist",
    nationality : "Mexican",
    ultPoints : 6
};

for(let i in agent){
    // console.log(agent[i]);
}

arr.map((item) => {
    if(item == 4) return; // to skip any element
    // console.log(item);
});

const arr1 = [1,2,3];
const arr2 = [3,4,5];

const arr3 = [...arr1, ...arr2]; // (...) -> spread operator to join 2 or more arrays
// console.log(arr3);

function spread(...args){ // ...->rest operator  we can provide multiple arguments
    let res = 1;
    for(let i = 0; i < args.length; i++)
        res *= args[i];
    return res;
}

console.log(spread(1,2,3,4));