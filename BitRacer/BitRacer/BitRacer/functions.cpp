#include <iostream>
#include <ctime>
#include <string>
#include <limits>
#include <fstream>
#include <iomanip>
#include "functions.h"

using namespace std;


void greet()
{
    cout << setw(105) << "     ____  _ __  ____" << endl;
    cout << setw(128) << "    / __ )(_) /_/ __ \\____ _________   _____" << endl;
    cout << setw(128) << "   / __  / / __/ /_/ / __ `/ ___ / _ \\/ ___/" << endl;
    cout << setw(124) << "  / /_/ / / /_/ _, _/ /_/ / /__ / __ / /" << endl;
    cout << setw(123) << " /_____/_/\\__/_/ |_|\\__,_/\\___ /\\___/_/" << endl;
    cout << endl;
    cout << setw(99) << "You have to answer " << 10 << " questions as fast as you can." << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << endl;
    }
}


void menu()
{
    cout << setw(116) << "Choose a difficulty:" << endl;
    cout << endl;

    cout << setw(121) << "============================" << endl;
    cout << setw(121) << "|           Easy           |" << endl;
    cout << setw(121) << "============================" << endl;
    cout << setw(121) << "============================" << endl;
    cout << setw(121) << "|          Normal          |" << endl;
    cout << setw(121) << "============================" << endl;
    cout << setw(121) << "============================" << endl;
    cout << setw(121) << "|           Hard           |" << endl;
    cout << setw(121) << "============================" << endl;
    cout << setw(121) << "============================" << endl;
    cout << setw(121) << "|           Quit           |" << endl;
    cout << setw(121) << "============================" << endl;
    cout << endl;
    cout << setw(131) << "1. Easy - You have to get 5 or more points to win." << endl;
    cout << setw(133) << "2. Normal - You have to get 7 or more points to win." << endl;
    cout << setw(127) << "3. Hard - You have to get 10 out of 10 to win." << endl;
    cout << setw(88) << "4. Quit" << endl;
    cout << endl;
    cout << setw(100) << "Enter your choice: ";
}


// Function to generate random bitwise operator question
string generateQuestion() {
    int a = rand() % 10;
    int b = rand() % 10;
    int op = rand() % 5;

    while (b == 0)
    {
        b = rand() % 10;
    }

    string question;
    if (op == 0) {
        question = to_string(a) + " & " + to_string(b) + " = ?";
    }
    else if (op == 1) {
        question = to_string(a) + " | " + to_string(b) + " = ?";
    }
    else if (op == 2) {
        question = to_string(a) + " ^ " + to_string(b) + " = ?";
    }
    else if (op == 3) {
        question = to_string(a) + " << " + to_string(b) + " = ?";
    }
    else if (op == 4) {
        question = to_string(a) + " >> " + to_string(b) + " = ?";
    }
    return question;
}

// Function to check if the player's answer is correct
bool checkAnswer(int a, int b, int op, int answer) {
    if (op == 0) {
        return (a & b) == answer;
    }
    else if (op == 1) {
        return (a | b) == answer;
    }
    else if (op == 2) {
        return (a ^ b) == answer;
    }
    else if (op == 3)
    {
        return (a << b) == answer;
    }
    else if (op == 4)
    {
        return (a >> b) == answer;
    }
    else
    {
        return false;
    }
}

void car(int sc) //print and moves the car by getting the score
{
    fstream newfile;

    newfile.open("..\\textfile\\car.txt", ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) //checking whether the file is open
    {
        string tp;
        while (getline(newfile, tp)) //read data from file object and put it into string.
        {
            cout << setw((sc * 17) + tp.length()) << tp << endl; //print the data of the string
        }
        newfile.close(); //close the file object.
    }
}

void upperRoad() //prints the upper part of the road
{
    cout << "___________________________________________________________________________________________________________________________________________________________________________________________________________________";
    cout << endl;
}

void downRoad() //prints the lower part of the road
{
    cout << endl;
    cout << "-----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -";
    for (int i = 0; i < 7; i++)
    {
        cout << endl;
    }
    cout << "___________________________________________________________________________________________________________________________________________________________________________________________________________________" << endl;
}

void checkeredFlag(int choice) // prints and locates a finish flag
{
    int distance = 0;
    switch (choice)
    {
    case 1: distance = 104; break;
    case 2: distance = 136; break;
    case 3: distance = 208; break;
    }
    cout << setw(distance) << "|>>>>>" << endl;
    cout << setw(distance) << "|>>>>>" << endl;
    cout << setw(distance) << "|>>>>>" << endl;
    cout << setw(distance - 5) << "|" << endl;
    cout << setw(distance - 5) << "|" << endl;
    cout << setw(distance - 5) << "|" << endl;
    cout << setw(distance - 5) << "|" << endl;
}


void endGame(time_t timeTaken, int score, int choice) // Shows your stats and tells you if you won or not
{
    int pointsNeeded = 0;
    switch (choice)
    {
    case 1: pointsNeeded = 5; break;
    case 2: pointsNeeded = 7; break;
    case 3: pointsNeeded = 10; break;
    }
    if (score < pointsNeeded)
    {
        cout << setw(102) << "__   __          _" << endl;
        cout << setw(114) << "\\ \\ / /__ _  _  | |___ ___ ___" << endl;
        cout << setw(115) << " \\ V / _ \\ || | | / _ (_-</ -_)" << endl;
        cout << setw(115) << "  |_|\\___/\\_,_| |_\\___/__/\\___|" << endl;
    }
    else
    {
        cout << setw(109) << "__   __                 _" << endl;
        cout << setw(113) << "\\ \\ / /__ _  _  __ __ _(_)_ _" << endl;
        cout << setw(115) << "\\ V / _ \\ || | \\ V  V / | ' \\ " << endl;
        cout << setw(115) << "|_|\\___/\\_,_|  \\_/\\_/|_|_||_|" << endl;
    }
    cout << setw(106) << endl << "Quiz complete!" << endl;
    cout << endl;
    if (timeTaken > 59)
    {
        cout << setw(90) << "You scored " << score << " out of " << 10 << " questions in " << timeTaken / 60 << " minute/s and " << timeTaken % 60 << " second/s." << endl;;
    }
    else
    {
        cout << setw(90) << "You scored " << score << " out of " << 10 << " questions in " << timeTaken << " seconds." << endl;
    }
}
