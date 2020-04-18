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

class Scoreboard
{
  private:
    bool poss; //true = home, false = visitor 
    int quarter; // which quarter
    int down; //down
    int yards; // yards to go for first down
    Team team1; //double dot notation to get its data
    Team team2; //double dot notation to get its data

  public:
    Scoreboard() // default constructor
    {
      poss = true; // home team has the ball initially
      quarter = 1; // initial quater
      down = 1; //initial down
      yards = 10; // initial yards
    }
    void setPoss(bool po){poss = po;}
    void setQuarter(int q){quarter = q;}
    void setDown(int d){down = d;}
    void setYards(int y){yards = y;}
    void setTeam1(Team t1) { team1 = t1; } //remember when the object changes
    void setTeam2(Team t2) {team2 = t2; } //remember when the object changes

    bool getPoss()const{return poss;}
    int getQuarter()const{return quarter;} 
    int getDown()const{return down;}
    int getYards()const{return yards;}
    Team getTeam1() const { return team1; }
    Team getTeam2()  const { return team2; }

    void showScoreboard()
    {
        system("clear"); //clear the screen 
        
        //Show Scoreboard
        cout << "********************" << endl;
        cout << "Scoreboard Internal\n";
        cout << "********************" << "\n" << endl;
        cout << "Team 1 Name: " << team1.getName() << endl;
        cout << "Team 1 Score: " << team1.getScore() << "\n" << endl;
        cout << "--------------------" << endl;
        cout << "Quarter: " << quarter << endl; 
        cout << "--------------------" << endl;
        cout << "Team 2 Name: " << team2.getName() << endl;
        cout << "Team 2 Score:" << team2.getScore() << "\n" << endl;

        //dealing with Boolean data
        if(1 == true)
        {
           cout << "--------------------" << endl;
          cout << "Home team has the ball" << endl; 
           cout << "--------------------" << endl;
        }
        else
        {
           cout << "--------------------" << endl;
          cout << "Visiting team has the ball" << endl; 
           cout << "--------------------" << endl;
        }

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

  s.setTeam1(tOneMain);
  s.setTeam2(tTwoMain);

  cout << "\n Get Quarter" << s.getQuarter() << endl;
  cout << "\n Team 1 initial nam: " << s.getTeam1().getName() << endl;

  // scoreboard menu
    do
    {
      s.showScoreboard();

      //Menu options
      cout << "\n\n===================\n";
        cout << "Menu: " << endl; 
        cout << "A. Update Team 1 Score" << endl; 
        cout << "B. Update Team 1 Name" << endl; 
        cout << "C. Update Team 2 Score" << endl;
        cout << "D. Update Team 2 Name" << endl;
        cout << "E. Update Quarter" << endl;
        cout << "X. To Exit" << endl; 
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