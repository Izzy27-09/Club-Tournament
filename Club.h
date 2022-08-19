#include <iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<vector>
using namespace std;

class Club {
private:
	string code, name;
	int round, wins, draws, losses, goals, goalsConceded,strength,points;
public:
	vector <string> verses;

	Club() {//constructor
		round = 0;
		wins = 0;
		draws = 0;
		losses = 0;
		goals = 0;
		goalsConceded = 0;
		strength = 0;
		points = 0;
	}
	//accessors
	int getRound() {
		return round;
	}
	int getWins() {
		return wins;
	}
	int getDraws() {
		return draws;
	}
	int getLosses() {
		return losses;
	}
	int getGoals() {
		return goals;
	}
	int getGoalsConceded() {
		return goalsConceded;
	}
	int getStrength() {
		return strength;
	}
	string getCode() {
		return code;
	}
	string getName() {
		return name;
	}
	int getPoint() {
		return points;
	}
	//Mutators
	void setCode( string n) {
		code=n;

	}
	void setName(string n) {
		name = n;
	}
	void setRound() {
		round += 1;
	}
	void setWins() {
		wins += 1;
	}
	void setDraws() {
		draws += 1;
	}
	void setLosses() {
		losses += 1;
	}
	void setGoals(int n) {
		goals += n;
	}
	void setGoalsConceded(int n) {
		goalsConceded += n;
	}
	void setStrength() {
		
		strength = 1+ (rand() % 10);
	}
	int GoalsGame() {
		int goalsgot = (rand() % strength);
		return goalsgot;

	}
	void pointCalc() {
		points = (3 * wins) + draws;
	}

	int Diff() {
		return goals - goalsConceded;
	}


};
