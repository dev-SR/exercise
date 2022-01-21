# Functional Interface In Java

## TypeScript Function Types

```typescript
function isEven(num: number) {
 return num % 2 == 0;
}
function MyFilter(ar: number[]): number[] {
 let newArr: number[] = [];
 for (let i = 0; i < ar.length; i++) {
  const currentEl = ar[i];
  if (isEven(currentEl)) {
   newArr.push(currentEl);
  }
 }
 return newArr;
}

console.log(MyFilter([1, 2, 3, 4, 5]));

// Built-in
console.log( [1, 2, 3, 4, 5].filter( isEven ) );
// function is like variable
const isOdd = function (num) {
 return num % 2 != 0;
};
console.log([1, 2, 3, 4, 5].filter(isOdd));
// Arrow Function
console.log([1, 2, 3, 4, 5].filter((n) => n % 2 == 0));



// Function Type
function MyFilter(ar: number[], fn: (n: number) => boolean): number[] {
 let newArr: number[] = [];
 for (let i = 0; i < ar.length; i++) {
  const currentEl = ar[i];
  if (fn(currentEl)) {
   newArr.push(currentEl);
  }
 }
 return newArr;
}
console.log(MyFilter([1, 2, 3, 4, 5], isEven));
console.log( MyFilter( [1, 2, 3, 4, 5], isOdd ) );


// using interface
interface FunctionType {
 fn(n: number): boolean;
}
function MyFilter(ar: number[], { fn }: FunctionType): number[] {
 let newArr: number[] = [];
 for (let i = 0; i < ar.length; i++) {
  const currentEl = ar[i];
  if (fn(currentEl)) {
   newArr.push(currentEl);
  }
 }
 return newArr;
}
console.log(MyFilter([1, 2, 3, 4, 5], { fn: isEven }));
console.log(MyFilter([1, 2, 3, 4, 5], { fn: isOdd }));

// Arrow Function
// function isEven(num: number) {
//  return num % 2 == 0;
// }
// console.log( [1, 2, 3, 4, 5].filter(isEven));
console.log([1, 2, 3, 4, 5].filter(isEven));

```

### Ex: android

```typescript
// Part of Android SDK
class View {
 id: string;
 constructor(id: string) {
  this.id = id;
 }
 getId() {
  return this.id;
 }
}
function findViewById(s: string) {
 return new Button(s);
}

interface OnClickListener {
 (v: View): void;
}

class Button {
 v: View;
 callback: OnClickListener;
 constructor(view_id) {
  this.v = new View(view_id);
 }
 setOnClickListener(cb: OnClickListener) {
  this.callback = cb;
 }

 //called by the framework
 runtime() {
  console.log('App is running');
  setTimeout(() => {
   this.callback(this.v);
  }, 2000);
 }
}

// User Implementation
const b: Button = findViewById('button');
function myClickHandlerCallBack(v: View) {
 if (v.getId() == 'button') {
  console.log('Button clicked');
 }
}
b.setOnClickListener(myClickHandlerCallBack);

// While the App is running, the button will be clicked by the user,
// and the callback will be called By the Android runtime.
b.runtime();
```

## Java Implementation

```java
class ArrayTest {

    @Test
    @DisplayName("Callback using Arrow Function")
    void t1() {
        //JS/TS..................
        //console.log(MyFilter([1, 2, 3, 4, 5], (n) => n % 2 == 0));
        System.out.println(Array.filter(new int[]{1, 2, 3, 4}, (n) -> n % 2 == 0));
        System.out.println(Array.filter(new int[]{1, 2, 3, 4}, (n) -> n % 2 != 0));
    }

    @Test
    @DisplayName("Callback using Anonymous Interface implementation")
    void t2() {
        /*
         * JS/TS..................
         *
         * const isOdd = function (num) {
         *  return num % 2 != 0;
         * };
         * console.log(MyFilter([1, 2, 3, 4, 5], isOdd));
         * */

        FunctionType isEven = new FunctionType() {
            @Override
            public boolean fn(int n) {
                return n % 2 == 0;
            }
        };
        System.out.println(Array.filter(new int[]{1, 2, 3, 4}, isEven));

        //Using Lambda Function
        FunctionType isEven2 = n -> n % 2 == 0;
        System.out.println(Array.filter(new int[]{1, 2, 3, 4}, isEven2));
    }

    @Test
    @DisplayName("Callback using Class Interface implementation")
    void t3() {

        class isODD implements FunctionType {
            @Override
            public boolean fn(int n) {
                return n % 2 != 0;
            }
        }
        FunctionType isOdd = new isODD();
        System.out.println(Array.filter(new int[]{1, 2, 3, 4}, isOdd));
    }
}
```

```java
import java.util.ArrayList;

interface FunctionType {
    boolean fn(int n);
}

public class Array {
    static String filter(int arr[], FunctionType callbackFunction) {
        ArrayList<Integer> list = new ArrayList();
        for (int j : arr) {
            if (callbackFunction.fn(j)) {
                list.add(j);
            }
        }
        return list.toString();
    }
}
```
