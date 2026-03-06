let fruits = ['Apple', 'Banana'];
let berries = ['Strawberry', 'Blueberry'];

// Combine them into a new variable
let allFruit = fruits.concat(berries);

console.log(allFruit); 
// Output: ['Apple', 'Banana', 'Strawberry', 'Blueberry']

console.log(fruits);   
// Output: ['Apple', 'Banana'] (Original is still safe!)
console.log(berries);   
// Output: ['Strawberry', 'Blueberry'] (Original is still safe!)
