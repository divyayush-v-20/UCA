let x = new Map();
x.set({"a" : 1, "b" : 2, "c" : 3});

for(let [key, val] of x){
    console.log(key, val);   
}