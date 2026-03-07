// one parameter, amd single return statement
sum = (x) => x + 1;

// multiple parameters, and single return statement
multiply = (x, y) => x * y;

// multiple parameters, and multiple statements
divide = (x, y) => {
    if (y === 0) {
        return "Error: Division by zero";
    }
    return x / y;
};

// Mutiple statements in function parameters
greet = (name) => {
    const greeting = `Hello, ${name}!`;
    console.log(greeting);
    return greeting;
};

// Returning an object 
createPerson = (name, age) => ({
    name: name,
    age: age
});

//calling functions

//one parameter, amd single return statement
console.log(sum(5)); // Output: 6
console.log(sum(10)); // Output: 11

//multiple parameters, and single return statement
console.log(multiply(4, 5)); // Output: 20
console.log(multiply(7, 3)); // Output: 21

//multiple parameters, and multiple statements
console.log(divide(10, 2)); // Output: 5
console.log(divide(10, 0)); // Output: Error: Division by zero

//Mutiple statements in function parameters
console.log(greet("Alice")); // Output: Hello, Alice!
console.log(greet("Bob")); // Output: Hello, Bob!

//Returning an object
console.log(createPerson("Charlie", 30)); // Output: { name: 'Charlie', age: 30 }
console.log(createPerson("Diana", 25)); // Output: { name: 'Diana', age: 25 }

