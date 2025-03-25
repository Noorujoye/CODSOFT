#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

// create a function name playGame

void playGame(int maxNumber,int maxAttempts){
    srand(time(0));
    int number = rand() % maxNumber + 1;
    // will generate a random number
    int guess , attempts = 0;

    // Display game instruction
    cout << " I have chosen a number between 1 and " << maxNumber << "." << endl;
    cout << " You have " << maxAttempts << " attempts to guess it! " << endl;

    // This loop will will run until the user guesses the number
    while(attempts < maxAttempts){
        cout << "Attempt " << (attempts + 1) << "/" << maxAttempts << " - Enter your guess: ";
        cin >> guess; //Take user input

        if (cin.fail() || guess < 1 || guess > maxNumber){
            cin.fail();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Enter a number between 1 and " << maxNumber << ".\n";
            continue;
        }
        attempts++; // Increment the attempt counter

        // now condition will check guess is correct or not
        if ( guess == number) {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts!" << endl;
            return; // Exit the function since the game is won
        }

        // check if the guess is too high
        else if(guess > number) {
            cout << "Guess is too high! Try again." << endl;
        }

        //check if the guess is too low
        else {
            cout << "Guess is too high! Try again." << endl;
        }
    }
    //If all attempts are used, display the correct number
    cout << "Sorry, you've used all  " << maxAttempts << " attempts! THe correct number was " << number << "." << endl;
}

int main(){
    string playAgain;
    do {
        int maxNumber,maxAttempt;
    cout << " Enter the max number : ";
    cin >> maxNumber;
    cout << " Enter the max attempts : ";
    cin >> maxAttempt;
    playGame(maxNumber,maxAttempt);

    // ask user if they wanna play again
    cout << " Do you want to play again? (yes / no)";
    cin >> playAgain;
    }
    while (playAgain == "yes");
    cout << "Thanks for playing! " << endl;
    return 0;
}

