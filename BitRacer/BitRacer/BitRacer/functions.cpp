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
    cout << setw(121) << "     ____  _ __  ____" << endl;
    cout << setw(144) << "    / __ )(_) /_/ __ \\____ _________   _____" << endl;
    cout << setw(144) << "   / __  / / __/ /_/ / __ `/ ___ / _ \\/ ___/" << endl;
    cout << setw(140) << "  / /_/ / / /_/ _, _/ /_/ / /__ / __ / /" << endl;
    cout << setw(139) << " /_____/_/\\__/_/ |_|\\__,_/\\___ /\\___/_/" << endl;
    cout << endl;
    cout << setw(115) << "You have to answer " << 10 << " questions as fast as you can." << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << endl;
    }
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
            cout << setw((sc * 20) + tp.length()) << tp << endl; //print the data of the string
        }
        newfile.close(); //close the file object.
    }
}

void UpperRoad() //prints the upper part of the road
{
    cout << "___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________";
    cout << endl;
}

void DownRoad() //prints the lower part of the road
{
    cout << endl;
    cout << "-----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     -----     ---     ";
    for (int i = 0; i < 7; i++)
    {
        cout << endl;
    }
    cout << "___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________" << endl;
}

void CheckeredFlag(int choice) // print and positions the finish flag
{
    int distance = 0;
    switch (choice)
    {
    case 1: distance = 117; break;
    case 2: distance = 160; break;
    case 3: distance = 235; break;
    }
    cout << setw(distance) << "|>>>>>" << endl;
    cout << setw(distance) << "|>>>>>" << endl;
    cout << setw(distance) << "|>>>>>" << endl;
    cout << setw(distance - 5) << "|" << endl;
    cout << setw(distance - 5) << "|" << endl;
    cout << setw(distance - 5) << "|" << endl;
    cout << setw(distance - 5) << "|" << endl;
}


void EndGame(time_t TimeTaken, int score, int choice) // Shows your stats and tells you if you won or not
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
        cout << setw(118) << "__   __          _" << endl;
        cout << setw(130) << "\\ \\ / /__ _  _  | |___ ___ ___" << endl;
        cout << setw(131) << " \\ V / _ \\ || | | / _ (_-</ -_)" << endl;
        cout << setw(131) << "  |_|\\___/\\_,_| |_\\___/__/\\___|" << endl;
    }
    else
    {
        cout << setw(125) << "__   __                 _" << endl;
        cout << setw(129) << "\\ \\ / /__ _  _  __ __ _(_)_ _" << endl;
        cout << setw(131) << "\\ V / _ \\ || | \\ V  V / | ' \\ " << endl;
        cout << setw(131) << "|_|\\___/\\_,_|  \\_/\\_/|_|_||_|" << endl;
    }
    cout << setw(122) << endl << "Quiz complete!" << endl;
    cout << endl;
    if (TimeTaken > 59)
    {
        cout << setw(100) << "You scored " << score << " out of " << 10 << " questions in " << TimeTaken / 60 << " minute/s and " << TimeTaken % 60 << " second/s." << endl;;
    }
    else
    {
        cout << setw(100) << "You scored " << score << " out of " << 10 << " questions in " << TimeTaken << " seconds." << endl;
    }
}