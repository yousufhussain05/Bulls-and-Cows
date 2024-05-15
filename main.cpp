#include <iostream>
using namespace std;

// Makes sure each digit is within range and all digits are unique
bool CheckCode(int guessCode1, int guessCode2, int guessCode3, int guessCode4) {
    if ((guessCode1 >= 0 && guessCode1 <= 9) && 
        (guessCode2 >= 0 && guessCode2 <= 9) && 
        (guessCode3 >= 0 && guessCode3 <= 9) && 
        (guessCode4 >= 0 && guessCode4 <= 9) &&
        (guessCode1 != guessCode2) && (guessCode1 != guessCode3) && (guessCode1 != guessCode4) &&
        (guessCode2 != guessCode3) && (guessCode2 != guessCode4) &&
        (guessCode3 != guessCode4)) {
        return true;
    }
    else {
        return false;
    }

}

// BullOrCow calculates and displays the number of bulls (correct digit and position) and cows (correct digit, wrong position).
void BullOrCow(int userCode1, int userCode2, int userCode3, int userCode4, int guessCode1, int guessCode2, int guessCode3, int guessCode4) {
    // Convert codes to strings to easily compare digits and positions
       string userCode = to_string(userCode1) + to_string(userCode2) + to_string(userCode3) + to_string(userCode4);
       string guessCode = to_string(guessCode1) + to_string(guessCode2) + to_string(guessCode3) + to_string(guessCode4);

        int bulls = 0;
        int cows = 0;

    // Iterate over each digit to count bulls and cows
        for (int i = 0; i < userCode.length(); i++) {
            if (userCode[i] == guessCode[i]) {
                bulls++;
            }
            if ((guessCode.find(userCode[i]) != string::npos) && (userCode[i] != guessCode[i])){
                cows++;
            }
        }
        
        // Check for a winning condition
        if (userCode == guessCode) {
            cout << "Congratulations! You win!" << endl;
            return;
        }
        cout << "There are " << bulls << " bulls and " << cows << " cows." << endl;
        
    
}

int main() {
    
    int guessCode1, guessCode2, guessCode3, guessCode4;

    // Loop until a valid code is entered
    while (true) {
        cout << "Enter the solution to use: ";

        cin >> guessCode1 >> guessCode2 >> guessCode3 >> guessCode4;

        if (CheckCode(guessCode1, guessCode2, guessCode3, guessCode4) == false) {
            cout << "Invalid code. Try again." << endl;
            continue;
        }
        else {
            break;
        }
    }

    int userCode1, userCode2, userCode3, userCode4;

    // Allow up to 10 tries
    for (int turn = 1; turn <= 10; turn++) {
        while (true) {
            cout << "Turn " << turn << ". Enter a guess: ";
            cin >> userCode1 >> userCode2 >> userCode3 >> userCode4;
            if (CheckCode(userCode1, userCode2, userCode3, userCode4) == false) {
                cout << "Invalid code. Try again." << endl;
                continue;  
            }
            else {
                break;
            }
        }
        string userCode = to_string(userCode1) + to_string(userCode2) + to_string(userCode3) + to_string(userCode4);
        string guessCode = to_string(guessCode1) + to_string(guessCode2) + to_string(guessCode3) + to_string(guessCode4);

        BullOrCow(userCode1, userCode2, userCode3, userCode4, guessCode1, guessCode2, guessCode3, guessCode4);
        if (userCode == guessCode) {
            return 0;
        }

    }
    string guessCode = to_string(guessCode1) + to_string(guessCode2) + to_string(guessCode3) + to_string(guessCode4);
        
    // Reveal the correct answer after all tries are used
    cout << "You lose. The correct answer is: " << guessCode;
}

