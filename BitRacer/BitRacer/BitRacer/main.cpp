#include <iostream>
#include <ctime>
#include <string>
#include <limits>
#include <fstream>
#include <iomanip>
#include "functions.h"

using namespace std;


int main() {
    char playAgain;
    do {
        system("cls");
        greet();
        int choice;
        menu();
        cin >> choice;
        if (choice == 4)
        {
            system("cls");
            exit(0);
        }
        system("cls");

        srand(time(NULL));
        int score = 0;
        time_t startTime = time(NULL);
        time_t currentTime = time(NULL); // gets the current time


        for (int i = 0; i < 10; i++) {
            greet();
            checkeredFlag(choice);
            cout << "Your score is: " << score << endl;
            upperRoad();
            car(score);
            downRoad();
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
        endGame(difftime(currentTime, startTime), score, choice);
        cout << endl;
        cout << setw(108) << "Play again? (Y/N)";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
}
