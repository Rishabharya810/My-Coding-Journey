/* Example A: Removing Items */

let fruits = ['Apple', 'Banana', 'Orange', 'Mango'];

// Start at index 1, remove 2 items
let removed = fruits.splice(1, 2);

console.log(fruits);   
// Output: ['Apple', 'Mango'] (Banana and Orange are gone)

console.log(removed);  
// Output: ['Banana', 'Orange'] (The items we cut out)


/* Example B: Adding Items/Replacing Items */

let newfruits = ['Apple', 'Mango'];

// Start at index 1, remove 0 items, and insert 'Lemon'
newfruits.splice(1, 0, 'Lemon');

console.log(newfruits);
// Output: ['Apple', 'Lemon', 'Mango']