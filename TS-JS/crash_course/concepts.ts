
function scopeDemo() {
    if(true) {
        var x = 10; // Accessible outside this block
        let y = 20; // Block-scoped, inaccessible outside
        const z = 30; // Block-scoped and constant
    }
    console.log(x); // 10
    console.log(y); // Error: 'y' is not defined
    console.log(z); // Error: 'z' is not defined
}
scopeDemo();
