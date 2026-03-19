let counterEl = document.getElementById("counter-el");
let saveEl = document.getElementById("save-el");
let messageEl = document.getElementById("message-el"); // optional message display

let temp = '';
let count = 0;

function incrementCounter() {
    count++;
    updateCounterDisplay();
    clearMessage(); // clear any warning
}

function decrementCounter() {
    if (count > 0) {
        count--;
        updateCounterDisplay();
        clearMessage();
    } else {
        showMessage("Passenger count cannot be less than 0");
    }
}

function updateCounterDisplay() {
    counterEl.textContent = count;
}

function saveCount() {
    temp += count + " - ";
    saveEl.textContent = temp;
    clearMessage();
}

function resetCount() {
    count = 0;
    updateCounterDisplay();
    clearMessage();
}

function resetSave() {
    temp = '';  // Clear the saved values as well
    saveEl.textContent = "";
    clearMessage();
}

// Optional helpers for messaging
function showMessage(msg) {
    if (messageEl) {
        messageEl.textContent = msg;
    }
}

function clearMessage() {
    if (messageEl) {
        messageEl.textContent = "";
    }
}
