#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isValidInteger(const std::string& str) {
    for (char c : str) {
        if (c < '0' || c > '9') {
            return false; // If any character is not a digit, return false
        }
    }
    return true; // All characters are digits
}

int validateInput(const std::string& prompt) {
    std::string input;
    int x;

    while (true) {
        cout << prompt;
        getline(cin, input);

        if (input.empty()) {
            cout << "Error: Input is empty." << endl;
            continue;
        }

        if (!isValidInteger(input)) {
            cout << "Error: Input is not a valid integer." << endl;
            continue;
        }

        stringstream ss(input);
        ss >> x;

        if (x <= 0) {
            cout << "Error: Input is not a positive integer." << endl;
            continue;
        }

        break;
    }

    return x;
}

int main()
{
    cout << "Welcome to the affine cipher program.\n";

    int a, b, c;
    while (true){
    // Validation for a
    a = validateInput("Enter the positive integer A such that (A * C) % 26 = 1: ");

    // Validation for b
    b = validateInput("Enter the positive integer B: ");

    // Validation for c
    c = validateInput("Enter the positive integer C: ");
    if((a*c)%26==1){
        break;}
        cout<<"please make sure that (A * C) % 26 = 1\n";
    }




        // Define the alphabet
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    // Variables to store the messages to cipher and decipher
    string message_to_cipher, message_to_decipher;

    // Cipher a message
    cout << "Enter the message you want to cipher: ";
    getline(cin, message_to_cipher);

string ciphered_message = "";

    for (char ch : message_to_cipher) {
        if (isalpha(ch)) {
            char ciphered_char = tolower(ch);
            bool is_uppercase = isupper(ch);

            for (int j = 0; j < 26; j++) {
                if (ciphered_char == alphabet[j]) {
                    // Apply the affine cipher formula to cipher the character
                    int index_of_the_corresponding_character = (a * j + b) % 26;
                    char ciphered_result = alphabet[index_of_the_corresponding_character];
                    if (is_uppercase) {
                        ciphered_result = toupper(ciphered_result);
                    }
                    ciphered_message += ciphered_result;
                    break;
                }
            }
        } else {
            ciphered_message += ch;
        }
    }

    cout << "Ciphered message: " << ciphered_message << endl;

   // Decipher a message
    cout << "Enter the message you want to decipher: ";
    getline(cin, message_to_decipher);
    for (int i = 0; i < message_to_decipher.length(); i++) {
        char ciphered_char = message_to_decipher[i];
        if (isalpha(ciphered_char)) {
            for (int j = 0; j < 26; j++) {
                if (tolower(ciphered_char) == alphabet[j]) {
                    // Apply the affine cipher formula to decipher the character
                    int index_of_the_corresponding_character = (c * (j - b));
                    // Handle negative modulo
                    while (index_of_the_corresponding_character < 0) {
                        index_of_the_corresponding_character += 26;
                    }
                    index_of_the_corresponding_character %= 26;
                    message_to_decipher[i] = isupper(ciphered_char) ? toupper(alphabet[index_of_the_corresponding_character]) : alphabet[index_of_the_corresponding_character];
                    break;
                }
            }
        }
    }
    cout << "Deciphered message: " << message_to_decipher << endl;

    return 0;
}

