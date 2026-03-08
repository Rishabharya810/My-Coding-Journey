/* <-- demonstrate unshift()> */

let fruits = ['Apple', 'Banana'];
console.log(fruits);  // Output: ['Apple', 'Banana']

// Add 'Strawberry' to the start
let newLength = fruits.unshift('Strawberry'); // returns the new length of the array

console.log(fruits);     // Output: ['Strawberry', 'Apple', 'Banana']
console.log(newLength);  // Output: 3

/* <-- Now demonstrate shift()> */

let newfruits = ['Strawberry', 'Apple', 'Banana']; // Original array
console.log(newfruits);  // Output: ['Strawberry', 'Apple', 'Banana']

// Remove the first item
let removedItem = newfruits.shift(); // returns the removed item

console.log(newfruits);       // Output: ['Apple', 'Banana']
console.log(removedItem);  // Output: 'Strawberry'
console.log(newfruits.length); // Output: 2