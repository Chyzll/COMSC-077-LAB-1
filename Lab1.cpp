// GROUP 9: Duy Luu, Kristine Nguyen, Nitya Prasad
// 2025SP-COMSC-077
// Lab 1

// This program aims to take an inputted string value in binary or decimal 
// and convert the value into binary, octal, hexadecimal, or decimal

#include <iostream>
#include <string>
#include <cctype>
using namespace std; // removes need to type std:: all the time

int main() {
    string valueInput;
    string typeInput;
    string decimalValidityString = "0123456789.";
    string binaryValidityString = "01.";

    bool validInput = false;
    do { // run until user gives valid input
        // [Input Number] Binary is 0 or 1, Decimal is 0 to 9
        cout << "Input a number in binary [0 - 1] or decimal [0 - 9]!: \n";
        getline(cin, valueInput);
        // [Specify Type]
        cout << "What type of number is this? [B]inary / [D]ecimal: \n";
        getline(cin, typeInput);

        // Valid Input Check
        bool fail = false;
        
        /* this section of code doesn't work as intended

        if (typeInput == "B" || typeInput == "D") { // check if the typeInput is "B" or "D"
            if (typeInput == "B") { // Binary validity check
                for (char character : valueInput) {
                    cout << character + "\n";
                    if (!(binaryValidityString.find(character))) { // check if the single string character[0, 1, .] is NOT within the bigger preset string
                        fail = true;
                    }
                }
            } else { // Decimal validity check
                for (char character : valueInput) {
                    cout << character + "\n";
                    if (!(decimalValidityString.find(character))) { // check if the single string number[0, 1, 2, 3, ...] is NOT within the bigger preset string
                        fail = true;
                    }
                }
            }
        } else { // failed the typeInput check
            fail = true;
        } 

        */

        // if input valid, end loop or restart loop
        if (fail == false) {
            validInput = true;
        } else {
            cout << "Invalid input please reenter your inputs! \n";
        }
    } while (validInput == false);

    // Do something after?
    cout << "Reached the end of the program for now! \n";
}
