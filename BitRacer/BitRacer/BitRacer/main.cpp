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
}