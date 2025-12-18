// Made by Mathewos Owens
#include <iostream>
#include <fstream>
using namespace std;

class Team
{
private:
    string name;
    int points;
    int goals;

    int gA;               // goals against
    double xG;            // expected goals
    double xGa;           // expected goals against
    int goalDifferencial; // goalDifferencial is goals-gA

public:
    // Constructor 1 for Team (just takes in values)
    Team(string nam, int point, int goal, int gA2, double xG2, double xGa2);

    // Constructor 2: takes an ifstream objects and inputs data accordingly
    Team(string fileName);

    // Returns the sorting criteria you're currently looking for
    double getSortingCriteria(int i);

    // Prints out the team for the print function in league
    void printTeam();

    int getPoints();

    int getGoals();

    int getGoalsAgainst();

    double getExpectedGoals();

    double expectedGoalsAgainst();

    double goalDifference();

    string getName();

    ~Team();
};
