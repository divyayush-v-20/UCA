let x = new Map();
x.set({a : 1});

for(let val in x.values()){
    console.log(val);   
}