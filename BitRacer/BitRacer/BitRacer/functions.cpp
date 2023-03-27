#include <iostream>
#include <ctime>
#include <string>
#include <limits>
#include <fstream>
#include <iomanip>
#include "functions.h"

using namespace std;

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

void car(int sc) //gets the score
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