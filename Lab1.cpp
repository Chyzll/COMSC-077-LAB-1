// GROUP 9: Duy Luu, Kristine Nguyen, Nitya Prasad
// 2025SP-COMSC-077
// Lab 1

// This program aims to take an inputted string value in binary or decimal 
// and convert the value into binary, octal, hexadecimal, or decimal

#include <iostream>
#include <string>
#include <cctype>
using namespace std; // removes need to type std:: all the time

//Nitya
// Function to validate a decimal number
bool isValidDecimal(string num) {
    for (int i = 0; i < num.length(); i++) {
        if (num[i] < '0' || num[i] > '9') return false;
    }
    return true;
}

// Function to validate a binary number
bool isValidBinary(string num) {
    for (int i = 0; i < num.length(); i++) {
        if (num[i] != '0' && num[i] != '1') return false;
    }
    return true;
}
//Kristine
//Function to convert decimal to binary
string decimalToBinary(int decimal) {
    string binary = "";
    while (decimal > 0) {
        binary = (char)(decimal % 2 + '0') + binary; //produces the remainder of decimal number when it's divided by 2
        decimal /= 2; 
    } //the process of division continues until it hits 0
    return binary.empty() ? "0" : binary; // If empty, return "0"
}

//Function to convert decimal to octal
string decimalToOctal(int decimal) {
    string octal = "";
    while (decimal > 0) {
        octal = (char)(decimal % 8 + '0') + octal; //produces the remainder of decimal number when it's divded by 8
        decimal /= 8;
    }
    return octal.empty() ? "0" : octal; //If empty return "0"
}

// Function to convert decimal to hexadecimal
string decimalToHex(int decimal) {
    if (decimal == 0) return "0";
    string hex = "";
    const string hexDigits = "0123456789ABCDEF"; //Unchangeable values; A=10 B=11 C=12 D=13 E=14 F=15
    while (decimal > 0) {
        hex = hexDigits[decimal % 16] + hex; //produces the remainder of decimal number when it's divided by 16
        decimal /= 16;
    }
    return hex;
}




// Function to convert binary to decimal
int binaryToDecimal(const string& binary) {
    int decimal = 0;

    //Go over each character of the binary string
    for (int i = 0; i < binary.length(); i++) {
        // Shift decimal value one place to the left
        decimal *= 2;

        // If the current character is 1, add 1 to decimal number
        if (binary[i] == '1') {
            decimal += 1;
        }
    }

    return decimal;
}
//Function to convert binary to hexadecimal
int binaryToHexNum(string binary) {
    int decimal = 0;

    //Convert binary to decimal number
    for (int i = 0; i < 4; ++i) {
        if (binary[i] == '1') {
            decimal += (1 << (3 - i));  //adds power of 2 to decimal value
        }
    }

    // Convert decimal to hexadecimal
    if (decimal < 10) {
        return '0' + decimal;  //[0-9 Values]
    } else {
        return 'A' + (decimal - 10);  // [A-F Values]
    }
}

string binaryToHex(string binary) {
    int n = binary.length();
    // add zeros to make sure the length a multiple of 4
    if (n % 4 != 0) {
        int length = 4 - (n % 4);
        binary = string(length, '0') + binary;
    }

    string hex = "";
    // A loop that goes through length in chunks of 4
    for (int i = 0; i < binary.length(); i += 4) {
        string nibble = binary.substr(i, 4); //contains 4 characters
        hex += binaryToHexNum(nibble); //convert 4 bits to hexadigit equivalent
    }

    return hex;
}


// Function to convert binary to octal
string binaryToOctal(string binary) {

    int n = binary.length();
    if (n % 3 != 0) { //check if length is not divisible by 3
        int Length = 3 - (n % 3); // ensure that length is a multiple of 3
        binary = string(Length, '0') + binary; // add zeros at the beginning
    }

    //Convert binary to decimal
    int decimal = binaryToDecimal(binary);

    //Convert decimal to octal
    return decimalToOctal(decimal);
}



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
    
        if (typeInput == "B" || typeInput == "b") {
            if (!isValidBinary(valueInput)) {
                cout << "Invalid binary number! Please enter only 0s and 1s.\n";
                continue;
            }
            validInput = true;
        } else if (typeInput == "D" || typeInput == "d") {
            if (!isValidDecimal(valueInput)) {
                cout << "Invalid decimal number! Please enter only digits 0-9.\n";
                continue;
            }
            validInput = true;
        } else {
            cout << "Invalid type selection! Enter 'B' for binary or 'D' for decimal.\n";
        }

    } while (validInput == false);
    if (typeInput == "D" || typeInput == "d") {
        int decimalValue = stoi(valueInput); // Convert integer to string
        string binaryValue = decimalToBinary(decimalValue); //implemet conversion
        string octalValue = decimalToOctal(decimalValue);
        string hexaValue = decimalToHex(decimalValue);
       cout << "The binary number is: " << binaryValue << endl; //displays value
        cout << "The octal number is: " << octalValue <<endl;
        cout << "The hexadecimal number is: " <<hexaValue <<endl;
    }
 
    if (typeInput == "B" || typeInput == "b") {
        int decimalValue = binaryToDecimal(valueInput); 
      string hex = binaryToHex(valueInput); //Will  convert binary to hexadecimal
         string octal = binaryToOctal(valueInput); //Will convert binary to octal
        cout << "The decimal value is: " << decimalValue << endl;
        cout << "the hexadecimal value: " << hex << endl;
        cout << "The octal value is: " << octal << endl;
        
    }
     // Do something after?
    cout << "Reached the end of the program for now! \n";

    }



  
    

