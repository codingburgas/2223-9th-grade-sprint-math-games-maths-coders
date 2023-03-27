#pragma once
using namespace std;

void greet(); // prints logo and instructions
void menu(); // prints the main menu
string generateQuestion(); // generates a random question
bool checkAnswer(int a, int b, int op, int answer); // checks if the user's answer is correct
void car(int sc); // prints a model of a car and moves it
void upperRoad(); // prints the upper part of the road
void downRoad(); // prints the lower part of the road
void checkeredFlag(int choice); // prints a finish flag
void endGame(time_t timeTaken, int score, int choice); // prints stats and "You win" or "You lose" when the game ends
