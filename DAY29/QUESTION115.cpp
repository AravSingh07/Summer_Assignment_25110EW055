#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

// Function declarations
void displayMenu();
void concatenateStrings();
void reverseString();
void convertCase();
void countVowelsAndConsonants();
void searchSubstring();

int main() {
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice (1-6): ";
        
        // Handle non-integer inputs gracefully
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input! Please enter a number.\n";
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
            continue;
        }
        
        // Clear input buffer newline character before string processing
        std::cin.ignore(10000, '\n');

        switch (choice) {
            case 1:
                concatenateStrings();
                break;
            case 2:
                reverseString();
                break;
            case 3:
                convertCase();
                break;
            case 4:
                countVowelsAndConsonants();
                break;
            case 5:
                searchSubstring();
                break;
            case 6:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice! Please choose between 1 and 6.\n";
        }
        std::cout << "\n-------------------------------------------------\n";
    } while (choice != 6);

    return 0;
}

// Displays the CLI system menu options
void displayMenu() {
    std::cout << "=== String Operations System ===\n";
    std::cout << "1. Concatenate Two Strings\n";
    std::cout << "2. Reverse a String\n";
    std::cout << "3. Convert Case (Uppercase / Lowercase)\n";
    std::cout << "4. Count Vowels and Consonants\n";
    std::cout << "5. Search for a Substring\n";
    std::cout << "6. Exit\n";
}

// 1. Appends the second string directly to the first one
void concatenateStrings() {
    std::string str1, str2;
    std::cout << "Enter the first string: ";
    std::getline(std::cin, str1);
    std::cout << "Enter the second string: ";
    std::getline(std::cin, str2);

    std::string result = str1 + str2;
    std::cout << "Concatenated Result: " << result << "\n";
}

// 2. Reverses the order of characters in the string
void reverseString() {
    std::string str;
    std::cout << "Enter a string to reverse: ";
    std::getline(std::cin, str);

    std::string reversedStr = str;
    std::reverse(reversedStr.begin(), reversedStr.end());
    std::cout << "Reversed Result: " << reversedStr << "\n";
}

// 3. Converts all alphabetic text characters to upper or lower case
void convertCase() {
    std::string str;
    int subChoice;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    std::cout << "Choose case conversion:\n1. Convert to UPPERCASE\n2. Convert to lowercase\nChoice: ";
    std::cin >> subChoice;

    if (subChoice == 1) {
        std::transform(str.begin(), str.end(), str.begin(), ::toupper);
        std::cout << "Uppercase Result: " << str << "\n";
    } else if (subChoice == 2) {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        std::cout << "Lowercase Result: " << str << "\n";
    } else {
        std::cout << "Invalid sub-choice selection.\n";
    }
}

// 4. Tallies up vowels and alphabetical consonants
void countVowelsAndConsonants() {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    int vowels = 0, consonants = 0;
    for (char ch : str) {
        if (std::isalpha(ch)) {
            char lowerCh = std::tolower(ch);
            if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    std::cout << "Vowels found: " << vowels << "\n";
    std::cout << "Consonants found: " << consonants << "\n";
}

// 5. Locates if a small block of text exists inside the main string
void searchSubstring() {
    std::string mainStr, subStr;
    std::cout << "Enter the main text string: ";
    std::getline(std::cin, mainStr);
    std::cout << "Enter the substring to look for: ";
    std::getline(std::cin, subStr);

    size_t position = mainStr.find(subStr);
    if (position != std::string::npos) {
        std::cout << "Substring match found at character index position: " << position << "\n";
    } else {
        std::cout << "Substring pattern not found in main text string.\n";
    }
}
