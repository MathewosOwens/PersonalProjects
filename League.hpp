 // Made by Mathewos Owens
#include "Team.hpp"
#include <vector>
using namespace std;

class League
{
private:
    // The vector holding all the team information
    vector<Team*> league;

    // Sorts the league vector by a given sorting criteria
    void sortBy(int i);

public:
    // Constructor for League
    League() {}
    League(string fileName);

    // prints the Teams sorted by certain data based on the user
    void printSorted(int i = 0);

    ~League();
};