#include <iostream>
#include <ctime>
#include <string>
#include <limits>
#include <fstream>
#include <iomanip>
#include "functions.h"

using namespace std;


int main() {
    greet();
    int choice;
    cout << setw(120) << "Choose a difficulty:" << endl;
    cout << endl;
    cout << setw(150) << "1. Easy - You have to get 5 or more points to win." << endl;
    cout << setw(152) << "2. Normal - You have to get 7 or more points to win." << endl;
    cout << setw(146) << "3. Hard - You have to get 10 out of 10 to win." << endl;
    cout << setw(119) << "Enter your choice: ";
    cin >> choice;
    system("cls");

    srand(time(NULL));
    int score = 0;
    time_t startTime = time(NULL);
    time_t currentTime = time(NULL); // gets the current time



    for (int i = 0; i < 10; i++) {
        greet();
        CheckeredFlag(choice);
        cout << "Your score is: " << score << endl;
        UpperRoad();
        car(score);
        DownRoad();
        string question = generateQuestion();
        cout << endl << "Question " << (i + 1) << ": " << question << endl;

        int a = 0, b = 0, op = 0;
        if (question.length() == 10)
        {
            if (question.substr(2, 2) == "<<")
            {
                op = 3;
            }
            else
            {
                op = 4;
            }
            if (isdigit(question[0])) {
                a = stoi(question.substr(0, 1));
            }
            if (isdigit(question[5])) {
                b = stoi(question.substr(5, 1));
            }
        }
        else
        {
            if (question[2] == '&')
            {
                op = 0;
            }
            else if (question[2] == '|')
            {
                op = 1;
            }
            else if (question[2] == '^')
            {
                op = 2;
            }

            if (isdigit(question[0])) {
                a = stoi(question.substr(0, 1));
            }
            if (isdigit(question[4])) {
                b = stoi(question.substr(4, 1));
            }
        }


        int answer;
        cout << "Enter your answer: ";
        if (cin >> answer) {
            if (checkAnswer(a, b, op, answer)) {
                score++;
                cout << "Correct!" << endl;
            }
            else {
                cout << "Incorrect!" << endl;
            }
        }
        else {
            // Clear the failbit flag and ignore the input buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer value." << endl;
            i--;
        }
        system("cls");
    }

    currentTime = time(NULL);
    EndGame(difftime(currentTime, startTime), score, choice);

    return 0;
}