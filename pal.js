let num = 121;
let temp = num;
let rev = 0;

while (temp > 0) {
    let digit = temp % 10;
    rev = rev * 10 + digit;
    temp = Math.floor(temp / 10);
}

if (rev === num) {
    console.log("Palindrome");
} else {
    console.log("Not Palindrome");
}
