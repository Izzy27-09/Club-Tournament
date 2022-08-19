#include <iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include <iomanip> 
#include"Club.h"
void Rankings(vector<Club>& h);//Does the rankings after each round
void SIMULATLEgAME(int, vector<Club>&);//simulates each game for each round
using namespace std;
int leagueRounds[20][20] =
{ 0,1,21,3,23,5,25,7,27,9,29,11,31,13,33,15,35,17,37,19,
20,0,3,23,5,25,7,27,9,29,11,31,13,33,15,35,17,37,19,21,
2,22,0,5,25,7,27,9,29,11,31,13,33,15,35,17,37,19,20,4,
22,4,24,0,7,27,9,29,11,31,13,33,15,35,17,37,19,20,2,25,
4,24,6,26,0,9,29,11,31,13,33,15,35,17,37,19,20,2,22,8,
24,6,26,8,28,0,11,31,13,33,15,35,17,37,19,20,2,22,4,29,
6,26,8,28,10,30,0,13,33,15,35,17,37,19,20,2,22,4,24,12,
26,8,28,10,30,12,32,0,15,35,17,37,19,20,2,22,4,24,6,33,
8,28,10,30,12,32,14,34,0,17,37,19,20,2,22,4,24,6,26,16,
28,10,30,12,32,14,34,16,36,0,19,20,2,22,4,24,6,26,8,37,
10,30,12,32,14,34,16,36,18,38,0,2,22,4,24,6,26,8,28,1,
30,12,32,14,34,16,36,18,38,1,21,0,4,24,6,26,8,28,10,22,
12,32,14,34,16,36,18,38,1,21,3,23,0,6,26,8,28,10,30,5,
32,14,34,16,36,18,38,1,21,3,23,5,25,0,8,28,10,30,12,26,
14,34,16,36,18,38,1,21,3,23,5,25,7,27,0,10,30,12,32,9,
34,16,36,18,38,1,21,3,23,5,25,7,27,9,29,0,12,32,14,30,
16,36,18,38,1,21,3,23,5,25,7,27,9,29,11,31,0,14,34,13,
36,18,38,1,21,3,23,5,25,7,27,9,29,11,31,13,33,0,16,34,
18,38,1,21,3,23,5,25,7,27,9,29,11,31,13,33,15,35,0,17,
38,2,23,6,27,10,31,14,35,18,20,3,24,7,28,11,32,15,36,0 };

string teams[20] = { "ARS","AST","BHA","BOU","BUR","CHE","EVE","LEI","LIV","MNC",
					  "MNU","NEW","NOR","PAL","SHU","SOT","TOT","WAT","WHU","WOL" };
int main()
{
	bool y = true;
	int round, option, team1=0, team2=0, gameround = 0, position = 0,sround=0,eround=0;
	
	string names[20] = { "Arsenal","Aston Villa","Brighton","Bournemouth","Burnley","Chelsea",
	"Everton","Leicester City","Liverpool","Manchester City","Manchester United","Newcastle United","Norwich City"
	,"Crystal Palace","Sheffield United","Southampton","Tottenham Hotspur","Watford","West Ham United",
	"Wolverhampton Wanderers" };
	string code;

	vector <Club> clubs(20);
	vector<Club>::iterator it;
	vector<Club>::reverse_iterator its;
	//Populates the onjects with the club names and shorthand version of them along with their strenths
	srand(time(0));
	for (int i = 0; i < 20; i++) {
		clubs[i].setName(names[i]);
		clubs[i].setCode(teams[i]);
		clubs[i].setStrength();
	}
	while (y) {
		cout << "\nLEAGUE MENU\n";
		cout << "1.CLUBS\n2.FIXTURES\n3.SIMULATE NEXT ROUND\n4.RESULTS-SINGLE CLUB\n5.CURRENT STANDING\n6.EXIT ";
		cin >> option;
		switch (option) {
		case 1:
			cout << "\nCODE   \t\tNAME\t\tStrength" << endl;
			for (it = clubs.begin(); it != clubs.end(); it++) {
				cout << it->getCode() << " " << setw(19) << it->getName() << setw(10) << it->getStrength() << endl;
			}
			break;
		case 2:
			cout << "\nEnter the round number (1 - 38): ";
			cin >> round;
			cout << "\nPremier League Fixtures" << endl;
			cout << "Round " << round << ":\n";
			for (int row = 0; row < 20; row++) {
				for (int col = 0; col < 20; col++) {
					if (leagueRounds[row][col] == round) {
						cout << " " << teams[row] << "  -  " << teams[col] << endl;
					}
				}
			}
			break;
		case 3:
			gameround++;   //used to increment the amount of rounds each team has played so far
			cout << "\nRESULTS OF ROUND " << gameround<<endl;
			SIMULATLEgAME(gameround, clubs);
			//RANKS ALL TEAMS FROM FIRST TO LAST
			Rankings(clubs);
			break;
		case 4:
			//GETS RESULTS OF THE TEAM ENTERED FOR THE GAMES THEY PLAYED SO FAR
			cout << "\nEnter Team code ";
			cin >> code;
			for ( round = 0; round < 20; round++) {
				if (clubs[round].getCode() == code)
					break;
			}
			cout << "\nEnter the start round ";
			cin >> sround;
			cout << "\nEnter the end round ";
			cin >> eround;
			if (eround <= clubs[round].verses.size()) {
				position = sround;
				for (int i = sround - 1; i < eround; i++) {
					cout << "ROUND: " << position << " " << clubs[round].verses[i] << endl;
					position++;
				}
			}
			break;
		case 5:
			//PRINTS THE SCORE BOARD TO THE SCREEN
			position = 1;
			cout << "\nRANK " << setw(5) << "TEAM " << setw(5) << "ROUND " << setw(5) << "WINS " <<setw(5)<<"DRAWS "<<
				setw(5)<<"LOSSES    "<<setw(5)<<"GOALS    "<<setw(5)<<"DIFF     "<<setw(5)<<"POINTS" << endl;
			//REVERSE ITERATOR USED AS VECTOR IS ALWAYS IN REVERSE ORDER
			for (its = clubs.rbegin(); its != clubs.rend(); its++) {
				if (position >= 10) {
					cout << position << " " << setw(5) << its->getCode() << setw(5) << its->getRound() << setw(5) << its->getWins() <<
						setw(5) << its->getDraws() << setw(6) << its->getLosses() << setw(10) << its->getGoals() << ":" << its->getGoalsConceded() <<
						setw(8) << its->Diff() << setw(9) << its->getPoint() << endl;
				}
				else {
					cout << position << " " << setw(6) << its->getCode() << setw(5) << its->getRound() << setw(5) << its->getWins() <<
						setw(5) << its->getDraws() << setw(6) << its->getLosses() << setw(10) << its->getGoals() << ":" << its->getGoalsConceded() <<
						setw(8) << its->Diff()<< setw(9) << its->getPoint() << endl;
				}
				position++;
			}
			break;
		case 6:
			y = false;
			cout << "\nSEE YOU FOR THE NEXT LEAGUE ";
			break;
		default:
			y = false;
			cout << "\nInvaild INPUT";
			break;
		}//end of switch
		system("pause");
		system("CLS");
	}//end of while	
}//end of main

void Rankings(vector<Club>& h) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20 - 1; j++) {
			if (h[j].getPoint() > h[j + 1].getPoint())
				swap(h[j], h[j + 1]);
			else if ((h[j].getPoint() == h[j + 1].getPoint()) && ((h[j].Diff() > h[j + 1].Diff())))
				swap(h[j], h[j + 1]);
			else if (((h[j].getPoint() == h[j + 1].getPoint()) && ((h[j].Diff() == h[j + 1].Diff())) && (h[j].Diff() > h[j + 1].Diff())))
				swap(h[j], h[j + 1]);
		}
	}
}//end of function

void SIMULATLEgAME(int gameround,vector<Club>& clubs) {
	string results = "", team1s, team2s;
	int team1, team2;
	for (int row = 0; row < 20; row++) {
		for (int col = 0; col < 20; col++) {
			if (leagueRounds[row][col] == gameround) {
				clubs[row].setRound();
				clubs[col].setRound();
				team1 = clubs[row].GoalsGame();
				team2 = clubs[col].GoalsGame();
				team1s = team1;
				team2s = team2;
				if (team1 > team2) {
					clubs[row].setWins();
					clubs[col].setLosses();
					team1s = to_string(team1);
					team2s = to_string(team2);
					results = " " + teams[row] + " " + team1s + "  -  " + team2s + " " + teams[col];
					cout << results << endl;
					clubs[col].verses.push_back(results);
					clubs[row].verses.push_back(results);
				}
				else if (team2 > team1) {
					clubs[col].setWins();
					clubs[row].setLosses();
					team1s = to_string(team1);
					team2s = to_string(team2);
					results = " " + teams[row] + " " + team1s + "  -  " + team2s + " " + teams[col];
					cout << results << endl;
					//THE REUSLTS DISPLAYED TO THE SCREEN ARE STORED FOR LATER USE
					clubs[col].verses.push_back(results);
					clubs[row].verses.push_back(results);
				}
				else {
					clubs[col].setDraws();
					clubs[row].setDraws();
					team1s = to_string(team1);
					team2s = to_string(team2);
					results = " " + teams[row] + " " + team1s + "  -  " + team2s + " " + teams[col];
					cout << results << endl;
					clubs[col].verses.push_back(results);
					clubs[row].verses.push_back(results);
				}
				clubs[row].setGoals(team1);
				clubs[col].setGoals(team2);
				clubs[col].setGoalsConceded(team1);
				clubs[row].setGoalsConceded(team2);
			}
			//CALCULATE THE TWO TEAMS POINTS AS OF THE MOMENT
			clubs[col].pointCalc();
			clubs[row].pointCalc();
		}//for loop
	}
}//end of function















	
	

