// Made by Mathewos Owens

#include <iostream>
#include "League.hpp"
using namespace std;

#define DEFAULTFILE "premierLeague.txt";
void printOptions()
{
    cout << "How would you like to see the results of the League?:" << endl;
    cout << "(0): Alphabetically." << endl;
    cout << "(1): Standard Output (Points)." << endl;
    cout << "(2): Goal Difference." << endl;
    cout << "(3): Number of goals scored." << endl;
    cout << "(4): Number of goals against." << endl;
    cout << "(5): Number of expected goals." << endl;
    cout << "(6): Number of expected goals against." << endl;
    cout << "(7): Exit" << endl;
}

int main(int argc, char *argv[])
{
    string fileName;
    if (argc > 1)
    {
        fileName = argv[1];
    }

    else
    {
        fileName = DEFAULTFILE;
    }
    League l1 = League(fileName);

    cout << endl
         << "Welcome to this League program." << endl;
    printOptions();

    string input;
    getline(cin, input);

    while (input == "0" || input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "7")
    {

        if (input == "0")
            l1.printSorted(0);
        else if (input == "1")
            l1.printSorted(1);
        else if (input == "2")
            l1.printSorted(2);
        else if (input == "3")
            l1.printSorted(3);
        else if (input == "4")
            l1.printSorted(4);
        else if (input == "5")
            l1.printSorted(5);
        else if (input == "6")
            l1.printSorted(6);
        else if (input == "7")
        {
            cout << "Thanks for using the program!" << endl;
            break;
        }

        printOptions();
        getline(cin, input);
    }
    if (!(input == "0" || input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "7"))
        cout << "Invalid input. Please try again!" << endl;

    return 0;
}
