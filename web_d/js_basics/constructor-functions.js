// function student(name, obtainedMarks){
//     let fname = name;
//     return{
//         fName : fname,
//         lName : "lName1",
//         college : "chitkara",
//         obtainedMarks : obtainedMarks,
//         checkResults : function(){
//             return (obtainedMarks/maxMarks >= 0.4) ? "pass" : "fail";
//         },
//         checkPercentage : function(){
//             return ((obtainedMarks/maxMarks) * 100);
//         }
//     };
// }

var maxMarks = 500;

// var student = {
//     fName : "fName1", 
//     lName : "lName1",
//     college : "chitkara",
//     obtainedMarks : 200,
//     checkResults : function(){
//         return (this.obtainedMarks/maxMarks >= 0.4) ? "pass" : "fail";
//     }
// };


//---constructor function---
function student(name, obtainedMarks){
        this.fName = name;
        this.lName = "lName1";
        this.college = "chitkara";
        this.obtainedMarks = obtainedMarks;
        this.checkResults = function(){
            return (obtainedMarks/maxMarks >= 0.4) ? "pass" : "fail";
        };
        this.checkPercentage = function(){
            return ((obtainedMarks/maxMarks) * 100);
    }
}


// var student1 = student("Divyayush", 469);

// console.log(student1.checkResults());
// console.log(student1.checkPercentage());

var student1 = new student("Divyayush", 469);

console.log(student1.checkResults());
console.log(student1.checkPercentage());