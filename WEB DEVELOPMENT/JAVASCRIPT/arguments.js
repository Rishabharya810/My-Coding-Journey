function SumOfAllParameters() {
    let sum = 0;
    for (let i = 0; i < arguments.length; i++) {
        sum += arguments[i];
    }
    return sum;
}

console.log(SumOfAllParameters(1, 2, 3)); // Output: 6
console.log(SumOfAllParameters(10, 20, 30, 40, 50));
// Output: 150
console.log(SumOfAllParameters()); // Output: 0
console.log(SumOfAllParameters(5)); // Output: 5