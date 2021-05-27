import 'colors';
console.log('----------------<ts>---------------'.bgMagenta.black.bold);

type objectType = new (...arg: any[]) => any; //new Fruit("apple")
//(...args: any[]) => any <-constructor function.

//!1. Class Decorators
// function Dec<T extends { new(...args: any[]): {} }>(constructor: T) {
function isStudent<TClass extends objectType>(target: TClass) {
   console.log(target);
   return class Student extends target {
      student = true; //adding new property to the target class.
   };
}

// ! Apply decorators
@isStudent
class Person1 {
   constructor(public name: string) {}
}
console.log(new Person1('Abul'));
// [class Person]
// Student { name: 'Abul', student: true }

//!2. Decorator with parameter
// To pass parameters to a Decorator, a 'Decorator Factory'
//is used which simply returns a function that will be called
//by the decorator at runtime.

function makeStudent(isStudent: boolean = true) {
   return function DF<TClass extends objectType>(target: TClass) {
      console.log(target);
      return class Student extends target {
         student = isStudent; //adding new property to the target class.
      };
   };
}

@makeStudent(false)
class Person2 {
   constructor(public name: string) {}
}
console.log(new Person2('Abul'));
//[class Person]
// Student { name: 'Abul', student: false }

//!3. Property Decorators:

function UpperCase(obj: any, PropertyKey: string) {
   let val = obj[PropertyKey];
   //    console.log(val);
   //    Object.defineProperty(student, 'changeName', {
   //       set: function (value) { //value=>'Sarah'

   //       }
   //    });
   //    // changing the property value
   //    student.changeName = 'Sarah';

   const descriptor = {
      get: () => {
         return val;
      },
      set: (newVal: string) => {
         //setter will get the value from getter
         val = newVal.toUpperCase();
         //  console.log(val);
      }
   };
   Object.defineProperty(obj, PropertyKey, descriptor);
}

@makeStudent(false)
class Human {
   @UpperCase
   name: string;
   constructor(name: string) {
      this.name = name;
   }
}

let student = new Human('abc');
student.name = 'Sarah';
console.log(student.name); //SARAH
