#include <iostream>

// This is a simple card counting program for blackjack.
// It will keep track of the count based on the cards dealt and provide a running count.
// The program will use a simple counting system where high cards (10, J, Q, K, A) are counted as -1,
// low cards (2, 3, 4, 5, 6) are counted as +1, and neutral cards (7, 8, 9) are counted as 0.
// The program will also provide a true count based on the number of decks remaining in the shoe.
// The true count is calculated by dividing the running count by the number of decks remaining.
// The program will allow the user to input the cards dealt and will update the count accordingly.
// The program will also allow the user to reset the count and exit the program.

// Betting Strategy:
// The program will allow the user to specify a minimum and maximum bet.

// The program will calculate the bet based on the true count and the minimum bet.
// The bet will be adjusted based on the true count, with a maximum bet cap.
// The program will display the current count and the bet to the user.
// The program will also allow the user to reset the count and exit the program.

int main() {

    std::cout << "Welcome to the Card Counting Program!" << std::endl;
    std::cout << "This program will help you keep track of the count in blackjack." << std::endl;

    // Initialize variables
    int minBet = 0;
    int maxBet = 0;
    int bet = 0; // This will be the current bet based on the true count
    int trueCount = 0; // This will be the true count based on the running count and the number of decks remaining
    int runningCount = 0; // This will be the running count based on the cards dealt
    int decksRemaining = 0; // This will be the number of decks remaining in the shoe

    int betUnit = 0; // This will be the unit of the bet based on the minimum bet
    int betMultiplier = 0; // This will be the multiplier based on the true count

    int betAdjustment = 0; // This will be the adjustment based on the true count
    

    // Let the user specify the minimum and maximum bet
    std::cout << "Enter the minimum bet: ";
    std::cin >> minBet;

    std::cout << "Enter the maximum bet: ";
    std::cin >> maxBet;

    if (minBet <= 0 || maxBet <= 0 || minBet > maxBet) {
        std::cout << "Invalid bet values. Using default values of 1 and 100." << std::endl;
        minBet = 1; // Default minimum bet
        maxBet = 100; // Default maximum bet
    }

    // Let the user specify the number of decks remaining in the shoe
    std::cout << "Enter the number of decks remaining in the shoe (default is 6): ";
    std::cin >> decksRemaining;
    if (decksRemaining <= 0) {
        std::cout << "Invalid number of decks. Using default value of 6." << std::endl;
        decksRemaining = 6; // Default to 6 decks if invalid input
    }
    
    // Calculate the bet unit based on the minimum bet
    betUnit = minBet; // The bet unit is the minimum bet

    betMultiplier = 0; // Initialize the bet multiplier

    betAdjustment = 0; // Initialize the bet adjustment

    // Main loop to keep the program running until the user decides to exit
    while (true) {
        std::cout << "Enter the card dealt (2-10, J, Q, K, A) or 'exit' to quit: ";
        std::string card;
        std::cin >> card;

        // Check if the user wants to exit the program
        if (card == "exit") {
            break;
        }

        // Update the running count based on the card dealt
        if (card == "2" || card == "3" || card == "4" || card == "5" || card == "6") {
            runningCount += 1; // Low cards are counted as +1
        } else if (card == "7" || card == "8" || card == "9") {
            runningCount += 0; // Neutral cards are counted as 0
        } else if (card == "10" || card == "J" || card == "Q" || card == "K" || card == "A") {
            runningCount -= 1; // High cards are counted as -1
        } else {
            std::cout << "Invalid card. Please enter a valid card." << std::endl;
            continue; // Skip to the next iteration of the loop
        }

        // Calculate the true count based on the running count and the number of decks remaining
        trueCount = runningCount / decksRemaining;

        // Calculate the bet adjustment based on the true count
        if (trueCount <= 0) {
            betAdjustment = 0; // Bet minimum
        } else if (trueCount >= 6) {
            betAdjustment = maxBet; // Bet maximum
        } else {
            // Adjust the bet based on the true count and the minimum bet
            // The bet is adjusted by the true count multiplied by the bet unit
            betAdjustment = minBet + (trueCount * betUnit); // Bet based on true count
            if (betAdjustment > maxBet) {
                betAdjustment = maxBet; // Cap the bet at the maximum bet
            }
        }

        // Update the current bet based on the bet adjustment
        bet = betAdjustment;

        // Display the current count and bet to the user
        std::cout << "Running Count: " << runningCount << std::endl;
        std::cout << "True Count: " << trueCount << std::endl;
        std::cout << "Current Bet: $" << bet << std::endl;
    }

    std::cout << "Thank you for using the Card Counting Program!" << std::endl;
    std::cout << "Good luck at the tables!" << std::endl;

    std::cout << "Exiting the program..." << std::endl;

    // Clean up and exit the program
    // (In this case, there is nothing to clean up since we are not using dynamic memory allocation)

    // Return 0 to indicate successful completion of the program
    std::cout << "Program completed successfully." << std::endl;
    std::cout << "Exiting the program..." << std::endl;

    return 0;
}