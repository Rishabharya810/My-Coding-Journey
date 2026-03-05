let emp = {
    name: "John",
    age: 30,
    city: "New York"
};

let key = Object.keys(emp);
console.log(key); // Output: [ 'name', 'age', 'city' ]

let value = Object.values(emp);
console.log(value); // Output: [ 'John', 30, 'New York' ]
let entries = Object.entries(emp);
console.log(entries); // Output: [ [ 'name', 'John' ], [ 'age', 30 ], [ 'city', 'New York' ] ]

console.log("Before freeze:", emp);
Object.freeze(emp); // Freezes the object i.e. allows no addition or deletion of properties
emp.country = "USA"; // This will be ignored
console.log(emp); // Output: { name: 'John', age: 30, city: 'New York' }


let emp2 = { id : 21 , age: 23, name : "arya" , city:"New York"}; 
console.log("Before seal:", emp2);

Object.seal(emp2); // Seals the object i.e. allows modification of existing properties but no addition or deletion
emp2.age = 31; // This will work
delete emp2.city; // This will be ignored
console.log(emp2); // Output: { id: 21, age: 31, name: 'arya', city: 'New York' }

