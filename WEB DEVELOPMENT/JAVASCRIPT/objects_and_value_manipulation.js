let obj = { name: "Rishab", age: 20, city: "New Delhi" };
console.log("Initial Object:", obj);
// Output: { name: 'Rishab', age: 20, city: 'New Delhi' }

// Accessing properties
console.log("Name:", obj.name); // Output: Rishab
console.log("Age:", obj["age"]); // Output: 20

// Modifying properties
obj.age = 23;
obj["city"] = "Greater Noida";

console.log("Updated Age:", obj.age); // Output: 23
console.log("Updated City:", obj.city); // Output: Greater Noida

// Adding new properties
obj.country = "India";
obj["profession"] = "Developer";
console.log("Country:", obj.country); // Output: India
console.log("Profession:", obj.profession); // Output: Developer

console.log("After additions:", obj);
// Output: { name: 'Rishab', age: 23, city: 'Greater Noida', country: 'India', profession: 'Developer' }

// Deleting properties
delete obj.city;
console.log("After deletion, City:", obj.city); // Output: undefined
console.log("Final Object:", obj);
// Output: { name: 'Rishab', age: 23, country: 'India', profession: 'Developer' }

// Checking property existence
console.log("Has age?", "age" in obj); // Output: true
console.log("Has city?", obj.hasOwnProperty("city")); // Output: false