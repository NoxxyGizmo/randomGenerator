// main.cpp

//Context: words.txt in the same folder as the .exe file

#include <iostream>
#include <cstdlib> // for rand and srand functions
#include <ctime>   // for time function
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// Function to get a random word from the "words.txt" file
string getRandomWord() {
    // Open the file for reading
    ifstream file("words.txt");

    // Check if the file is successfully opened
    if (!file.is_open()) {
        cerr << "Error opening file 'words.txt'." << endl;
        exit(EXIT_FAILURE); // Exit the program if the file cannot be opened
    }

    // Vector to store words read from the file
    vector<string> words;
    string word;

    // Read words from the file and store them in the vector
    while (file >> word) {
        words.push_back(word);
    }

    // Close the file after reading
    file.close();

    // Check if no words were found in the file
    if (words.empty()) {
        cerr << "No words found in file." << endl;
        exit(EXIT_FAILURE); // Exit the program if no words are found
    }


    // Generate a random index within the range of the vector size
    int randomIndex = rand() % words.size();

    // Return the randomly selected word
    return words[randomIndex];
}

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Decides if the loop keeps going
    bool loop = true;
    // Initializes the input from the user
    string inputString = "";
    //initializes the var that will store whether the user wants a pass or not
    //\0 is a null character
    char responseChar = '\0';

    //Opening Message
    cout << "Hello!! Thank you for using the PasswordGenerator" << endl;

    // Driving loop
    while (loop) {
        //Repeating question
        cout << "Would you like a password?" << endl;
        // Store response
        cin >> inputString;
        // Put the first character of inputString into responseChar
        responseChar = tolower(inputString[0]);

        //If Yes
        if (responseChar == 'y') {
            // Initialize output string
            string outputString = "";

            // Pulls a random word
            outputString += getRandomWord();
            // Generates a random number between 10 and 99
            outputString += to_string(rand() % 90 + 10);

            // Pulls a random word
            outputString += getRandomWord();
            // Generates a random number between 10 and 99
            outputString += to_string(rand() % 90 + 10);

            // Output end product
            cout << outputString << endl;
        }
        // If No
        else if (responseChar == 'n') {
            cout << "Thank you!" << endl;
            loop = false;
        }
        // Catch
        else {
            cout << "Unrecognized input. Please answer y or n." << endl;
        }

    }
    //Exit loop warning
    cout << "Exiting loop" << endl;


    return 0;
}