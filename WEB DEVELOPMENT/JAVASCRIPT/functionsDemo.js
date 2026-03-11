// ==========================================
//    JAVASCRIPT FUNCTION PARAMETER DEMO
// ==========================================

// 1. NO PARAMETERS
// A simple utility function that just prints a header line.
function printDivider() {
    console.log("------------------------------------------");
}

// 2. SINGLE PARAMETER
// Takes one input (the user's name) and logs a welcome message.
function welcomeUser(username) {
    printDivider();
    console.log("Welcome to the store, " + username + "!");
    console.log("Status: Active Member");
    printDivider();
}

// 3. MULTIPLE PARAMETERS
// Takes price, quantity, and tax rate to calculate the final cost.
function calculateTotal(price, quantity, taxRate) {
    let subtotal = price * quantity;
    let taxAmount = subtotal * (taxRate / 100);
    let total = subtotal + taxAmount;
    return total;
}

// 4. MULTIPLE PARAMETERS (With formatting)
// Takes the item name, the calculated cost, and a currency symbol.
function printReceipt(itemName, finalCost, currencySymbol) {
    console.log("Receipt Details:");
    console.log("Item: " + itemName);
    // .toFixed(2) rounds the number to 2 decimal places
    console.log("Total to Pay: " + currencySymbol + finalCost.toFixed(2));
    console.log("Date: " + new Date().toLocaleDateString());
    console.log("Time: " + new Date().toLocaleTimeString());
    console.log("Thank you for shopping with us!");
    printDivider();
}

// ==========================================
//        RUNNING THE PROGRAM
// ==========================================

// Step 1: Greet the user (Single Parameter)
welcomeUser("Rishab");

// Step 2: Define our product details
let product = "Gaming Laptop";
let unitPrice = 78000;
let qty = 2;
let tax = 18; // 18% tax

// Step 3: Calculate the math (Multiple Parameters)
// We pass 3 distinct arguments into the function
let finalBill = calculateTotal(unitPrice, qty, tax);

// Step 4: Show the result (Multiple Parameters)
printReceipt(product, finalBill, "₹");

// Step 5: Reuse the function for a different item
let mouseBill = calculateTotal(500, 5, 10); // 500 price, 5 items, 10% tax
printReceipt("Wireless Mouse", mouseBill, "₹");