 /* 
Assignment 4 - Football Scoreboard
Student: Stewart Sheppard Date: 4-15-20
Dr. Tyson McMillian COCS 1437-58000
Program that keeps track of various objects and variables in a Football Scoreboard.
*/

#include <iostream>
#include <unistd.h> //for sleep command
#include <string>
#include <iomanip>
#include "colormod.h"
using namespace std;

Color::Modifier red(Color::FG_RED);
Color::Modifier blue(Color::FG_BLUE);
Color::Modifier green(Color::FG_GREEN);
Color::Modifier yellow(Color::FG_YELLOW);
Color::Modifier def(Color::FG_DEFAULT);
Color::Modifier redbg(Color::BG_RED);
Color::Modifier greenbg(Color::BG_GREEN);
Color::Modifier bluebg(Color::BG_BLUE);
Color::Modifier defbg(Color::BG_DEFAULT);


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

class Scoreboard
{
  private:
    bool poss; //true = home, false = visitor 
    int quarter; // which quarter
    int down; //down
    int yards; // yards to go for first down
    double time; //Time place holder
    Team team1; //double dot notation to get its data
    Team team2; //double dot notation to get its data

  public:
    Scoreboard() // default constructor
    {
      poss = true; // home team has the ball initially
      quarter = 1; // initial quater
      down = 1; //initial down
      yards = 10; // initial yards
      time = 0.0; 
    }
    void setPoss(bool po){poss = po;}
    void setQuarter(int q){quarter = q;}
    void setDown(int d){down = d;}
    void setYards(int y){yards = y;}
    void setTime(double t){time = t;}
    void setTeam1(Team t1) { team1 = t1; } //remember when the object changes
    void setTeam2(Team t2) {team2 = t2; } //remember when the object changes

    bool getPoss()const{return poss;}
    int getQuarter()const{return quarter;} 
    int getDown()const{return down;}
    int getYards()const{return yards;}
    double getTime()const{return time;}
    Team getTeam1() const { return team1; }
    Team getTeam2()  const { return team2; }

    void showScoreboard()
    {
        system("clear"); //clear the screen 
        
        //Show Scoreboard
        cout << green << setw(54) << "********************" << endl;
        cout << setw(55) << "Football Scoreboard \n";
        cout << setw(54) << "********************" << def << endl;
        cout << setw(40) << red << "TIME: 00:0" << setprecision(6)<< getTime() << def << "\n";
        cout << "\n\n"<< endl;
        cout <<  team1.getHome_city() <<" "<< team1.getName() << setw(5) << red << team1.getScore() << def << setw(50) << team2.getHome_city() << " "<< team2.getName() << setw(5) << red << team2.getScore() << def << endl;
        //cout << "Team 1 Name: " << team1.getName() << endl;
       // cout << "Team 1 City: " << team1.getHome_city() << "\n" << endl;
        cout << "Coach: "  << team1.getCoach_name() << setw(55) <<  " Coach: "  << team2.getCoach_name() << endl;
       
        cout << "Timeouts: " << team1.getTimeout_count() << setw(70) << "Timeouts: " << team2.getTimeout_count() << "\n";;
        cout << setw(54) << "--------------------" << endl;
        cout << setw(48) << "Quarter: " << red << quarter << def << endl; 
        cout << setw(54) << "--------------------" << endl;
        //cout << "Team 2 Name: " << team2.getName() << endl;
        //cout << "Team 2 City: " << team2.getHome_city() << "\n" << endl;
        //cout << "Team 2 Coach: "  << team2.getCoach_name() << endl;
        
        //cout << "Team 2 Score:" << team2.getScore() << "\n" << endl;
        //cout << "Team 2 Timeouts: " << team2.getTimeout_count() << "\n";

        cout << setw(30) << "Down: "<< down << "Yards To Go: " << yards << endl;
        cout << setw(54) << "--------------------" << endl;
        
        cout << "Possession: "; 
        if(poss == true)// Ball possession status.
              cout << "\n Home has the ball. " << endl;
        else
              cout << "\n Visitor has the ball." << endl;
        cout << "**************" << endl;
        if (team1.getHome_status() == true)
              {
                cout << team1.getName() << " Status: HOME  " << endl;
                cout << team2.getName() << " Status: VISITOR "<< endl;
              }
        else
              {
                cout << team1.getName() << " Status: VISITOR " << endl;
                cout << team1.getName() << " Status: HOME " << endl;
              }
        cout << "**************" << endl;
        
        

        

    }
};

void scoreboardControls()
{
  Scoreboard s; // instantiate the scoreboard object s
  Team tOneMain; 
  Team tTwoMain;
  char decision= '\0';
  int newScore = 0;
  string newName = "";
  int updateQuarter = 0;
  bool updatePossession;
  int timeOuts;
  int downs;
  int yards;
  bool homeStatus;
  double setTime = 15.00;

  s.setTeam1(tOneMain);
  s.setTeam2(tTwoMain);

  cout << "\n Get Quarter" << s.getQuarter() << endl;
  cout << "\n Team 1 initial nam: " << s.getTeam1().getName() << endl;

  // scoreboard menu
    do
    {
      s.showScoreboard();

      //Menu options
      cout << green << "\n\n=========================\n";
        cout << "Menu: " << endl; 
        cout << "A. Update Team 1 Score" << endl; 
        cout << "B. Update Team 1 Name" << endl; 
        cout << "C. Update Team 2 Score" << endl;
        cout << "D. Update Team 2 Name" << endl;
        cout << "E. Update Quarter" << endl;
        cout << "F. Update Team 1 Coach's Name" << endl;
        cout << "G. Update Team 2 Coach's Name" << endl;
        cout << "H. Update Team 1 Home City Name" << endl;
        cout << "I. Update Team 2 Home City Name" << endl;
        cout << "J. Change Ball Possession" << endl;
        cout << "K. Update Team 1 Timeouts" << endl;
        cout << "L. Update Team 2 Timeouts" << endl;
        cout << "M. Update Down" << endl;
        cout << "N. Update Yards" << endl;
        cout << "O. Select \"Home\" status" << endl;
        cout << "T. Enter Time " << endl;
       

        cout << "X. To Exit" << def << endl; 
        cin >> decision; 

        if(decision == 'a' || decision == 'A')
        {
          cout << "Team 1 score update.\n";
          cout << "What is the new score? > ";
          cin >> newScore;
          tOneMain.setScore(newScore); // update scoreboard for Team 1
          cout << "\nUpdating new score for Team 1 to ..." << tOneMain.getScore() << endl;
          sleep(3); // 3 second pause
        }
        else if (decision == 'b' || decision == 'B')
        {
          cout << "Team 1 NAME update. \n";
          cout << "What is the new Name? > ";
          cin >> newName;
          tOneMain.setName(newName);
          cout << "\nUpdating new name for Team1 to..." << tOneMain.getName() << endl;
          sleep(3); // 3 second pause
        }

        else if (decision == 'c' || decision == 'C')
        {
          cout << "Team 2 score update. \n";
          cout << "What is the new score? > ";
          cin >> newScore;
          tTwoMain.setScore(newScore);
          cout << "\nUpdating new score for Team1 to ..." << tTwoMain.getScore() << endl;
          sleep(3); // 3 second pause()
        }

        else if (decision == 'd'|| decision == 'D')
        {
          cout << "Team 2 NAME update. \n";
          cout << "What is the new Name? > ";
          cin >> newName;
          tTwoMain.setName(newName);
          cout << "\nUpdating new name for Team2 to..." << tTwoMain.getName() << endl;
          sleep(3); // 3 second pause
        }
        
        else if (decision == 'e'|| decision == 'E')
        {
          cout << "Update the Quarter. \n";
          cout << "What Quarter is it? > ";
          cin >> updateQuarter;
          s.setQuarter(updateQuarter);
          cout << "\nUpdating Quarter..." << s.getQuarter() << endl;
          sleep(3); // 3 second pause
        }
        
        else if (decision == 'f' || decision == 'F')
        {
          cout << "Team 1 update Coach Name. \n";
          cout << "What is the Coach's Name? > ";
          cin >> newName;
          tOneMain.setCoach_name(newName);
          cout << "\nUpdating Coach's name for Team1 to..." << tOneMain.getCoach_name() << endl;
          sleep(3); // 3 second pause
        }

        else if (decision == 'g' || decision == 'G')
        {
          cout << "Team 2 update Coach Name. \n";
          cout << "What is the Coach's Name? > ";
          cin >> newName;
          tTwoMain.setCoach_name(newName);
          cout << "\nUpdating Coach's name for Team1 to..." << tTwoMain.getCoach_name() << endl;
          sleep(3); // 3 second pause
        }

        else if (decision == 'h' || decision == 'H')
        {
          cout << "Team 1 update Home City Name. \n";
          cout << "What is the City's Name? > ";
          cin >> newName;
          tOneMain.setHome_city(newName);
          cout << "\nUpdating City's Name for Team1 to..." << tOneMain.getHome_city() << endl;
          sleep(3); // 3 second pauseSn
        }

        else if (decision == 'i' || decision == 'H')
        {
          cout << "Team 2 update Home City Name. \n";
          cout << "What is the City's Name? > ";
          cin >> newName;
          tTwoMain.setHome_city(newName);
          cout << "\nUpdating City's Name for Team2 to..." << tTwoMain.getHome_city() << endl;
          sleep(3); // 3 second pause
        }
        
        else if (decision == 'j' || decision == 'J')
        {
          cout <<"Change Possession \n";
          cout << "Who has possesion? (0 = home, 1 - visitor).\n";
          cin >> updatePossession;
              if(updatePossession == 0)
              {
              s.setPoss(true);
              cout << "\n Home has the ball. " << endl;
              }
              else
              {
                s.setPoss(false);
                cout << "\n Visitor has the ball." << endl;
              }
          sleep(3); // 3 second pause
        }

        else if (decision == 'k' || decision == 'K')
        {
          cout << "Team 1 update number of Timeouts. \n";
          cout << "How many timeouts are left? > ";
          cin >> timeOuts;
          tOneMain.settimeout_count(timeOuts);
          cout << "\nUpdating number of Timeouts for Team1 to..." << tOneMain.getTimeout_count() << endl;
          sleep(3); // 3 second pauseSn
        }

        else if (decision == 'l' || decision == 'L')
        {
          cout << "Team 2 update number of Timeouts. \n";
          cout << "How many timeouts are left? > ";
          cin >> timeOuts;
          tTwoMain.settimeout_count(timeOuts);
          cout << "\nUpdating number of Timeouts for Team2 to..." << tTwoMain.getTimeout_count() << endl;
          sleep(3); // 3 second pause
        }

        
        else if (decision == 'n'|| decision == 'N')
        {
          cout << "Update the Yards \"To Go\". \n";
          cout << "Enter number of Yards\"To Go\"  > ";
          cin >> yards;
          s.setYards(yards);
          cout << "\nUpdating Quarter..." << s.getYards() << endl;
          sleep(3); // 3 second pause
        }
        
        else if (decision == 'o' || decision == 'O')
        {
          cout <<"Home Team Status \n";
          cout << "Select the \"HOME\" team.  (Enter \"0\" for" << tOneMain.getName() << " or  \"1\" for " << tTwoMain.getName() << ").\n";
          cin >> homeStatus;
              if(homeStatus == 0)
              {
              tOneMain.setHome_status(true);
              tTwoMain.setHome_status(false);
              }           
              else
              tOneMain.setHome_status(false);
              tTwoMain.setHome_status(true);
                           
          sleep(3); // 3 second pause
        }

        else if (decision == 't'|| decision == 'T')
        {
          cout << "Set Time. \n";
          cout << "Enter Time >\n ";
          cin >> setTime;
          s.setTime(setTime);
          cout << "\nUpdating Time..." << s.getTime() << endl;
          sleep(3); // 3 second pause
        }

             
        
        else if(decision == 'x' || decision == 'X')
          {
            cout << "\nEXIT.  GO TWU PIONEERS!  STILL UNDEFEATED!!" << endl;
          }
            
          s.setTeam1(tOneMain); // set Team 1 to latest data
          s.setTeam2(tTwoMain); // set Team 2 to latest data
        


    }while(decision!= 'x' && decision != 'X');

}




int main() 
{
  //std::cout << "Hello Scoreboard!\n";
  scoreboardControls(); //run
}