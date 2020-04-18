/* 
Assignment 4 - Football Scoreboard
Student: Stewart Sheppard Date: 4-15-20
Dr. Tyson McMillian COCS 1437-58000
Program that keeps track of various objects and variables in a Football Scoreboard.
*/

#include <iostream>
#include <unistd.h> //for sleep command
#include <string>
using namespace std;

class Team
{
  private:
    string name;
    string coach_name;
    string home_city;
    bool home_status;
    int score;
    int timeout_count;
    
  public:
  Team() // default constructor
  {
    name = "DefaultTeamName";
    coach_name = "DefaultCoachName";
    home_city = "DefaultCity";
    home_status = true;
    score = 0;
    timeout_count = 3;
  }

  void setName(string n){name = n;}
  void setCoach_name(string c){coach_name = c;}
  void setHome_city(string h){home_city = h;}
  void setHome_status(bool hs){home_status = hs;}
  void setScore(int s){score = s;}
  void settimeout_count(int tc){timeout_count = tc;}
  string getName() const {return name;} 
  string getCoach_name() const {return coach_name;} 
  string getHome_city() const {return home_city;}
  bool getHome_status() const{return home_status;}
  int getScore() const {return score;}
  int getTimeout_count(){return timeout_count;}
    
};




int main() 
{
  std::cout << "Hello Scoreboard!\n";
}