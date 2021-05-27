// import 'colors';
// console.log('----------------<ts>---------------'.bgMagenta.black.bold);
let msg = '100100';
let key = '1101';

let key_len = key.length;
//append 0

function appendZero(s: string, n: number): string {
   for (let i = 0; i < n; i++) {
      s += '0';
   }
   return s;
}
let s = msg;
console.log(s);
s = appendZero(s, key_len - 1);
console.log(s);

function xor(a: string, b: string) {
   let result: string = '';
   let n = b.length;
   for (let i = 1; i < n; i++) {
      if (a[i] == b[i]) result += '0';
      else result += '1';
   }
   return result;
}

function mod2div(dividend: string, divisor: string): string {
   let pick = divisor.length;
   let temp = dividend.substr(0, pick);
   let n = dividend.length;
   while (pick < n) {
      if (temp[0] == '1') temp = xor(divisor, temp) + dividend[pick];
      else temp = xor(appendZero('', pick), temp) + dividend[pick];
      pick++;
   }
   console.log(temp);
   if (temp[0] == '1') temp = xor(divisor, temp);
   else temp = xor(appendZero('', pick), temp);
   console.log(temp);

   // temp = temp + dividend[pick];
   return temp;
}

let remainder = mod2div(s, key);
let encoded = msg + remainder;
console.log(encoded);
