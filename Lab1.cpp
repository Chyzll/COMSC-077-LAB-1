// GROUP 9: Duy Luu, Kristine Nguyen, Nitya Prasad
// 2025SP-COMSC-077
// Lab 1

// This program aims to take an inputted string value in binary or decimal 
// and convert the value into binary, octal, hexadecimal, or decimal

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std; // removes need to type std:: all the time

//Nitya
// Function to validate a decimal number
bool isValidDecimal(string num) {
    for (int i = 0; i < num.length(); i++) {
        if (num[i] == '.') { // if it is a . period skip it and go to next iteration
            continue;
        }
        if (num[i] < '0' || num[i] > '9') { // this is checking if any of the digits are less than 0 or greater than 9
            return false;
        }
    }
    return true;
}

// Function to validate a binary number
bool isValidBinary(string num) {
    for (int i = 0; i < num.length(); i++) {
        if (num[i] == '.') { // if it is a . period skip it and go to next iteration
            continue;
        }
        if (num[i] != '0' && num[i] != '1') return false;
    }
    return true;
}

//Kristine
//Function to convert decimal to binary
string decimalToBinary(int decimalWhole, float decimalPeriod) {
    string binary = "";
    string binaryPeriod = "";
    while (decimalWhole > 0) {
        binary = (char)(decimalWhole % 2 + '0') + binary; //produces the remainder of decimal number when it's divided by 2
        decimalWhole /= 2; 
    } //the process of division continues until it hits 0

    if (decimalPeriod != 0 && decimalPeriod < 1) {
        while (decimalPeriod != 1) {
            decimalPeriod *= 2; // multiply by 2
            if (decimalPeriod == 1) {
                break;
            } else {
                if (decimalPeriod > 1) {
                    decimalPeriod = decimalPeriod - floor(decimalPeriod);
                    binaryPeriod = binaryPeriod + "1";
                } else {
                    binaryPeriod = binaryPeriod + "0";
                }
            }
        } //the process of division continues until it hits 1 exactly
    }

    if (binaryPeriod.empty()) {
        return binary.empty() ? "0" : (binary); // If empty, return "0" 
    } else {
        return binary.empty() ? "0" : (binary + "." + binaryPeriod); // If empty, return "0"
    }
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
    // add zeros to make sure the length is a multiple of 4
    if (n % 4 != 0) {
        int length = 4 - (n % 4);
        binary = string(length, '0') + binary;
    }

    string hex = ""; 
    // A loop that goes through length in chunks of 4 bits
    for (int i = 0; i < binary.length(); i += 4) {
        string nibble = binary.substr(i, 4); //extract 4 
        hex += binaryToHexNum(nibble); //convert 4 bits to hexadigit
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
        float decimalValue = stof(valueInput); //return float values 
        float decimalWholeValue = floor(decimalValue); // whole value before the decimal number ex 1
        float decimalPeriodValue = (decimalValue - decimalWholeValue); // decimal value after the whole number ex 0.41
        string binaryValue = decimalToBinary(decimalWholeValue, decimalPeriodValue); //calling decimalToBinary function
        string octalValue = decimalToOctal(decimalValue);//calling decimalToOctal function
        string hexaValue = decimalToHex(decimalValue);//calling decimalToHex function
       cout << "The binary number is: " << binaryValue << endl; //displays value
        cout << "The octal number is: " << octalValue <<endl;
        cout << "The hexadecimal number is: " <<hexaValue <<endl;
    }
 
    if (typeInput == "B" || typeInput == "b") {
        int decimalValue = binaryToDecimal(valueInput); //return binary string as decimal values
      string hex = binaryToHex(valueInput); //calling binaryToHex function
         string octal = binaryToOctal(valueInput); //calling binaryToOctal function
        cout << "The decimal value is: " << decimalValue << endl;
        cout << "the hexadecimal value: " << hex << endl;
        cout << "The octal value is: " << octal << endl;
        
    }
     // End
    cout << "Reached the end of the program! \n";

    }



  
    

