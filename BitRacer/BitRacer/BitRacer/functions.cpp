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