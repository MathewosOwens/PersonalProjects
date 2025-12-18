// Made by Mathewos Owens
#include "League.hpp"
#include <iomanip>

Team::Team(string nam, int point, int goal, int gA2, double xG2, double xGa2)
{
    name = nam;
    points = point;
    goals = goal;
    gA = gA2;
    xG = xG2;
    xGa = xGa2;
    goalDifferencial = goals - gA;
}

string Team::getName()
{
    return name;
}

// Tie breaking criteria:
// Points (1)
// Goal difference (2)
// Goals scored (3)
// Goals conceded (4)
// Expected goals (5)
// Expected goals against (6)
// Otherwise sort alphabetically.
double Team::getSortingCriteria(int i)
{
    // Proper testing
    if (i == 1) // sort by number of goals
        return points;
    else if (i == 2)
        return goalDifferencial;
    else if (i == 3)
        return goals;
    else if (i == 4)
        return gA;
    else if (i == 5)
        return xG;
    else if (i == 6)
        return xGa;
    return -1;
}

string removeUnderscores(string s)
{
    for (int i = 0; i < int(s.length()); i++)
    {
        if (s[i] == '_')
            s[i] = ' ';
    }
    return s;
}

#define SPACING 17

string getSpaces(string s)
{
    string spaces;
    for (int i = 0; i < SPACING - int(s.length()); i++)
        spaces += " ";
    return spaces;
}

void Team::printTeam()
{
    cout << removeUnderscores(name) << getSpaces(name);
    cout << "\t" << points;
    cout << "\t" << goals;
    if (goalDifferencial >= 0)
        cout << "\t " << goalDifferencial;
    else
        cout << "\t" << goalDifferencial;
    cout << "\t" << gA;
    cout << "\t" << xG;
    cout << "\t" << xGa;
}

int Team::getPoints()
{
    return points;
}

int Team::getGoals()
{
    return goals;
}

int Team::getGoalsAgainst()
{
    return gA;
}

double Team::getExpectedGoals()
{
    return xG;
}

double Team::expectedGoalsAgainst()
{
    return xGa;
}

double Team::goalDifference()
{
    return goalDifferencial;
}

Team::~Team() {}