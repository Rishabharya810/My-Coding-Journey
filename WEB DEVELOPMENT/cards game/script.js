// Game state variables
let cards = [];
let sum = 0;
let score = 100; // Starting bonus
let health = 100;
let isGameStarted = false;

// DOM elements
const startGameBtn = document.getElementById('startGame');
const drawCardBtn = document.getElementById('drawCard');
const cardsContainer = document.getElementById('cards-container');
const sumElement = document.getElementById('sum');
const messageElement = document.getElementById('message');
const scoreElement = document.getElementById('score');
const healthElement = document.getElementById('health');

// Event listeners
startGameBtn.addEventListener('click', startGame);
drawCardBtn.addEventListener('click', drawCard);

// Functions
function getRandomCard() {
    // Generate random card value between 1 and 13
    return Math.floor(Math.random() * 13) + 1;
}   

function updateUI() {
    // Update cards display
    cardsContainer.innerHTML = '';
    cards.forEach(card => {
        const cardElement = document.createElement('div');
        cardElement.className = 'card';
        cardElement.textContent = card;
        cardsContainer.appendChild(cardElement);
    });

    // Update sum
    sumElement.textContent = sum;

    // Update score and health
    scoreElement.textContent = score;
    healthElement.textContent = health;
}

function checkGameState() {
    if (sum === 21) {
        // Win condition
        messageElement.textContent = "Congratulations! You've hit 21!";
        messageElement.className = 'message-win';
        score += 100;
        endGame(true);
    } else if (sum > 21) {
        // Lose condition
        messageElement.textContent = "Out of luck! Better luck next time!";
        messageElement.className = 'message-lose';
        health -= 20;
        endGame(false);
    }

    // Check if health is depleted
    if (health <= 0) {
        messageElement.textContent = "Game Over! You've run out of health!";
        messageElement.className = 'message-lose';
        health = 0;
        endGame(false);
        promptRestart();
    }

    updateUI();
}

function startGame() {
    // Reset game state
    cards = [];
    sum = 0;
    messageElement.textContent = '';
    messageElement.className = '';
    isGameStarted = true;

    // Draw first card
    const card = getRandomCard();
    cards.push(card);
    sum += card;

    // Enable draw button and update start button
    drawCardBtn.disabled = false;
    startGameBtn.textContent = 'Restart';
    startGameBtn.disabled = true;

    updateUI();
}

function drawCard() {
    if (!isGameStarted) return;

    const card = getRandomCard();
    cards.push(card);
    sum += card;

    checkGameState();
}

function endGame(isWin) {
    isGameStarted = false;
    drawCardBtn.disabled = true;
    startGameBtn.disabled = false;
    
    // Handle win/lose conditions for restart
    if (isWin) {
        startGameBtn.textContent = 'Start New Game';
    } else {
        startGameBtn.textContent = 'Restart';
    }
}

function promptRestart() {
    if (score >= 50) {
        const wantToRestart = confirm("Would you like to restart the game? This will cost 50 points from your score.");
        if (wantToRestart) {
            score -= 50;
            health = 100;
            startGameBtn.disabled = false;
            messageElement.textContent = "Game restarted! -50 points deducted.";
            messageElement.className = '';
            updateUI();
        }
    } else {
        alert("You don't have enough points to restart! (Need 50 points)");
        messageElement.textContent = "Game Over! Not enough points to restart!";
    }
}

// Reset the game state when the page loads
startGameBtn.textContent = 'Start Game';
updateUI();
