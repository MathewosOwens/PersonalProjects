// Made by Mathewos Owens
#include "League.hpp"

League::League(string fileName)
{
    ifstream inputFile(fileName);
    if (!inputFile.is_open())
    {
        cout << "ERR: File is not open .\n";
        return;
    }

    string inputString;

    while (getline(inputFile, inputString))
    {

        vector<string> ss; // splitting the string via spaces

        int j = 0, i;
        for (i = 0; i < int(inputString.length()); i++)
        {
            if (inputString[i] == ' ')
            {
                ss.push_back(inputString.substr(j, i - j));
                j = i + 1;
            }
        }
        ss.push_back(inputString.substr(j, i - j));
        // inputing data into team
        // creating team
        Team *team = new Team(ss[0], stoi(ss[1]), stoi(ss[2]), stoi(ss[3]), stod(ss[4]), stod(ss[5]));
        league.push_back(team);
    }
}

bool alphabetCompare(string s1, string s2)
{
    for (int i = 0; i < int(s1.length()) && i < int(s2.length()); i++)
    {
        if (s1[i] < s2[i])
            return true;
        else if (s2[i] < s1[i])
            return false;
    }
    if (s1.length() < s2.length())
        return true;
    return false;
}


// Tie breaking criteria:
// Points (1)
// Goal difference (2)
// Goals scored (3)
// Goals conceded (4)
// Expected goals (5)
// Expected goals against (6)
// Otherwise sort alphabetically.

bool tieBreak(int i, Team *t1, Team *t2)
{
    if (i != 1 && t1->getPoints() != t2->getPoints())
    {
        return (t1->getPoints() > t2->getPoints());
    }
    else if (i != 2 && t1->goalDifference() != t2->goalDifference())
    {
        return t1->goalDifference() > t2->goalDifference();
    }
    else if (i != 3 && t1->getGoals() != t2->getGoals())
    {
        return t1->getGoals() > t2->getGoals();
    }
    else if (i != 4 && t1->getGoalsAgainst() != t2->getGoalsAgainst())
    {
        return t1->getGoalsAgainst() < t2->getGoalsAgainst();
    }
    else
        return alphabetCompare(t1->getName(), t2->getName());
}

bool getCrit(int i, Team *t1, Team *t2)
{
    if (t1->getSortingCriteria(i) == t2->getSortingCriteria(i))
        return tieBreak(i, t1, t2);
    return t1->getSortingCriteria(i) > t2->getSortingCriteria(i);
}


void League::sortBy(int i)
{

    // Sort alphabetically
    if (i == 0)
    {
        for (int j = 0; j < int(league.size()); j++)
        { // sort the teams in the league by alphabet
            Team *t = league[j];
            int key = j - 1;
            while (key >= 0 && alphabetCompare(t->getName(), league[key]->getName()))
            {
                league[key + 1] = league[key];
                key--;
            }
            league[key + 1] = t;
        }
    }

    else
    {
        for (int j = 0; j < int(league.size()); j++)
        { // sort the teams in the league by alphabet
            Team *t = league[j];
            int key = j - 1;
            while (key >= 0 && getCrit(i, t, league[key]))
            {
                league[key + 1] = league[key];
                key--;
            }
            league[key + 1] = t;
        }
    }
}

void League::printSorted(int i)
{
    sortBy(i);

    // Ordering: name, points, goals, goal diff, goals against, exp goals, exp goals against
    cout << "Name\t\t\tPoints\tGoals\t gDff\tgA\txG\txGa" << endl;
    for (int i = 0; i < int(league.size()); i++)
    {
        cout << i + 1 << ". ";
        if (i + 1 < 10)
        {
            cout << " ";
        }
        league[i]->printTeam();
        cout << endl;
    }
}

League::~League()
{
    for (int i = 0; i < int(league.size()); i++)
        delete league[i];
}
