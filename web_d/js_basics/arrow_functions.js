//  Normal function can use declarational as well as expressional syntax
//  but arrpw function can only use expressional syntax

function foo() {
    // console.log('normal function');
}

var foo = () => {
    // console.log('arrow function');
}

//  Arrow functions can be anonymous

() => {
    //anonymous function
    // console.log('anonymous func');
}

// function student(name, obtainedMarks){
//     this.fName = name; //this points to the variable which calls the function using new keyword
//     // console.log(this);
//     this.lName = "lName1";
//     this.college = "chitkara";
//     this.obtainedMarks = obtainedMarks;
//     this.checkResults = function(){
//         return (obtainedMarks/maxMarks >= 0.4) ? "pass" : "fail";
//     };
//     this.checkPercentage = function(){
//         return ((obtainedMarks/maxMarks) * 100);
//     }
// }

// var student1 = new student("Divyayush", 69); //this points to student 1

//  In arrow functions, this points to the parent, eg in a global function, this points to window

/*
var foo = () => {
  console.log(this);
}
undefined
foo()
-=> Window about:newtab
debugger eval code:2:11
undefined 
*/

function student(name, obtainedMarks){
    this.fName = name; //this points to the variable which calls the function using new keyword
    // console.log(this);
    this.lName = "lName1";
    this.college = "chitkara";
    this.obtainedMarks = obtainedMarks;
    this.checkResultsNormal = function (){
        console.log(this);
        function innerFunction(){
            console.log("normal inner function: ", this);
        }
        innerFunction();
    };
    this.checkResultsArrow = () => {
        console.log(this);
        innerFunction = () => {
            console.log("arrow inner function: ", this);
        }
        innerFunction();
    };    
}

var student1 = new student("abc", 48);

console.log(student1.checkResultsNormal());
console.log(student1.checkResultsArrow());