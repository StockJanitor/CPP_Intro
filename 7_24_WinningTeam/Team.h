#ifndef TEAMH
#define TEAMH

#include <string>

using namespace std;

class Team
{

private:
   string name;
   int wins, losses;
   double win_rate;

public:
   void SetName(string a);
   void SetWins(int wins);
   void SetLosses(int losses);

   string GetName() const;
   double GetWins() const;
   double GetLosses() const;
   double GetWinPercentage();

   void PrintStanding();
};

#endif