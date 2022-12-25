#include <iostream>
#include <iomanip>
#include "Team.h"
using namespace std;

void Team::SetName(string a)
{
   name = a;
}
void Team::SetWins(int wins)
{
   this->wins = wins;
}

void Team::SetLosses(int losses)
{
   this->losses = losses;
}

string Team::GetName() const
{
   return name;
}
double Team::GetWins() const
{
   return wins;
}
double Team::GetLosses() const
{
   return losses;
}

double Team::GetWinPercentage()
{
   return static_cast<double>(wins) / (static_cast<double>(wins) + static_cast<double>(losses));
}
void Team::PrintStanding()
{
   this->win_rate = static_cast<double>(wins) / (static_cast<double>(wins) + static_cast<double>(losses));
   if (win_rate >= 0.5)
   {
      cout <<fixed<<setprecision(2)<< "Win percentage: " << win_rate << endl
           << "Congratulations, Team Ravens has a winning average!" << endl;
   }
   else
   {
      cout <<fixed<<setprecision(2)<< "Win percentage: " << win_rate << endl
           << "Team Angels has a losing average." << endl;
   }
}