#include <iostream>
using namespace std;

int main()
{
    int score = 0;
    char answer;

    cout << "===== Simple Quiz Application =====" << endl;

    // Question 1
    cout << "\n1. What is the capital of India?" << endl;
    cout << "A. Mumbai" << endl;
    cout << "B. New Delhi" << endl;
    cout << "C. Kolkata" << endl;
    cout << "D. Chennai" << endl;
    cout << "Enter your answer (A/B/C/D): ";
    cin >> answer;

    if (answer == 'B' || answer == 'b')
        score++;

    // Question 2
    cout << "\n2. Which language is used for C++ programming?" << endl;
    cout << "A. HTML" << endl;
    cout << "B. CSS" << endl;
    cout << "C. C++" << endl;
    cout << "D. SQL" << endl;
    cout << "Enter your answer (A/B/C/D): ";
    cin >> answer;

    if (answer == 'C' || answer == 'c')
        score++;

    // Question 3
    cout << "\n3. How many days are there in a week?" << endl;
    cout << "A. 5" << endl;
    cout << "B. 6" << endl;
    cout << "C. 7" << endl;
    cout << "D. 8" << endl;
    cout << "Enter your answer (A/B/C/D): ";
    cin >> answer;

    if (answer == 'C' || answer == 'c')
        score++;

    // Display Score
    cout << "\n===== Quiz Result =====" << endl;
    cout << "Your Score: " << score << " out of 3" << endl;

    if (score == 3)
        cout << "Excellent! You got all answers correct." << endl;
    else if (score == 2)
        cout << "Good Job!" << endl;
    else
        cout << "Keep Practicing!" << endl;

    return 0;
}