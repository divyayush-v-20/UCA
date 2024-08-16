let arr = [1, 2, 3, 4, 4];
let set1 = new Set(arr);
// console.log(set1);

set1.add(1)
// console.log(set1);

//primary usecase - no duplicate elements

let obj1 = {1 : "a", 2 : "b"};
let obj2 = {1 : "a", 2 : "b"};

// let s1 = new Set();
// s1.add(obj1);
// s1.add(obj2);

// console.log(s1); // it treats obj1 & obj2 as different objects even though the values are the same

let s1 = new Set([1, 2, 3, 1, 2, 4, 5, 6, 7, 5]);

//iterating set
for(let val of s1.values()){
    console.log(val);    
}

for(let val of s1.entries()){
    console.log(val);    
}