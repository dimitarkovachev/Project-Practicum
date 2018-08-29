#pragma once

#include <iostream>
#include <fstream>
#include "Vector.h"
#include "String.h"



using namespace std;

enum surface { asphalt = 0, gravel = 1, snow = 2 };
enum corner { slight = 0, sharp = 1 }; 
enum stretch { shortStretch = 0, mediumStretch = 1, longStretch = 2 };


class Rally
{
public:
	String name;
	surface trackSurface;
	corner corners;
	stretch stretches;
	Rally() {}
	~Rally() {}
	Rally(String _name, surface _trackSurface, corner _corners, stretch _stretches) {
		name = _name;
		trackSurface = _trackSurface;
		corners = _corners;
		stretches = _stretches;
	}
	Rally(const Rally& src) {
		name = src.name;
		trackSurface = src.trackSurface;
		corners = src.corners;
		stretches = src.stretches;
	}
	Rally& operator=(const Rally& src) {
		if (this != &src) {
			name = src.name;
			trackSurface = src.trackSurface;
			corners = src.corners;
			stretches = src.stretches;
		}
		return *this;
	}

	void print() {
		cout <<"Rally "<< name << endl;
		cout << "Track Surface: " << trackSurface << endl;
		cout << "Corners: " << corners << endl;
		cout << "Stretches: " << stretches << endl;
	}
};

class Pilot
{
public:
	String name;
	surface dominatingSurface;
	corner dominatingCorner;
	stretch dominatingStretch;
	double psychics; //променлива, която определя силата на психиката на пилота.(0,8-1,2) Може да укаже влияние на резулата до 20%
	double experience; // (1-1,2) може да повлия положително на резултата с до 20%
	size_t score;
	double tempScore;
	String team;
	Pilot() {
		score = 0;
		tempScore = 0;
	}
	~Pilot() {}
	Pilot(String _name, surface _dominatingSurface, corner _dominatingCorner, stretch _dominatingStretch, double _psychics, double _experience) {
		name = _name;
		dominatingSurface = _dominatingSurface;
		dominatingCorner = _dominatingCorner;
		dominatingStretch = _dominatingStretch;
		score = 0;
		tempScore = 0;
		psychics = _psychics;
		experience = _experience;
	}
	Pilot(const Pilot& src) {
		name = src.name;
		dominatingSurface = src.dominatingSurface;
		dominatingCorner = src.dominatingCorner;
		dominatingStretch = src.dominatingStretch;
		score = src.score;
		tempScore = src.tempScore;
		team = src.team;
		psychics = src.psychics;
		experience = src.experience;
	}
	Pilot& operator=(const Pilot& src) {
		if (this != &src) {
			name = src.name;
			dominatingSurface = src.dominatingSurface;
			dominatingCorner = src.dominatingCorner;
			dominatingStretch = src.dominatingStretch;
			score = src.score;
			tempScore = src.tempScore;
			psychics = src.psychics;
			experience = src.experience;
			if(src.team != NULL) team = src.team;
		}
		return *this;
	}
	void print() {
		cout << name << "      " << tempScore<<endl;
	}
	void serializeName(ofstream& fo) {
		fo << name << endl;
	}
	void serialize() {
		ofstream fo;
		String helper = "Pilot_";
		helper += name;
		helper += ".txt";
		fo.open(helper.c_str());
		if (fo.is_open()) {
			fo << name << endl << dominatingSurface << dominatingCorner << dominatingStretch << endl;
		}
		fo.close();
	}
};

class Car {
public:
	String model;
	corner cornerTraction;
	stretch power;
	surface surfaceBehavior;

	Car() {}
	~Car() {}
	Car(String _model, corner _cornerTraction, stretch _power, surface _surfaceBehavior)
	{
		model = _model;
		cornerTraction = _cornerTraction;
		power = _power;
		surfaceBehavior = _surfaceBehavior;
	}
	Car(const Car& src)
	{
		model = src.model;
		cornerTraction = src.cornerTraction;
		power = src.power;
		surfaceBehavior = src.surfaceBehavior;
	}
	Car& operator=(const Car& src) {

		if (this != &src)
		{
			model = src.model;
			cornerTraction = src.cornerTraction;
			power = src.power;
			surfaceBehavior = src.surfaceBehavior;
		}
		return *this;
	}
	void print() {
		cout << model << endl;
		cout << "Cornering: " << cornerTraction << endl;
		cout << "Power Coef. " << power << endl;
		cout << "Best on " << surfaceBehavior << " surface." << endl;
	}
};

class Team {
public:
	String name;
	String constructor;
	size_t constructorScore;
	Pilot pilots[2];
	Car car; // 2мата пилоти управляват един и същ тип кола
	Team() {
		constructorScore = 0;
	}
	Team(String _name, String _constructor, Pilot _pilots[2], Car _car) {
		name = _name;
		constructor = _constructor;
		pilots[0] = _pilots[0];
		pilots[1] = _pilots[1];
		car = _car;
		constructorScore = 0;
		pilots[0].team = name;
		pilots[1].team = name;
	}
	Team(const Team& src) {
		name = src.name;
		constructor = src.constructor;
		pilots[0] = src.pilots[0];
		pilots[1] = src.pilots[1];
		car = src.car;
		constructorScore = src.constructorScore;
	}
	Team& operator=(const Team& src) {
		if (this != &src) {
			name = src.name;
			constructor = src.constructor;
			pilots[0] = src.pilots[0];
			pilots[1] = src.pilots[1];
			car = src.car;
			constructorScore = src.constructorScore;
		}
		return *this;
	}
	~Team(){}
	void print() {
		cout << name << endl;
		cout << "constructor: " << constructor << endl;
		cout << "Pilots: " << endl;
		pilots[0].print();
		pilots[1].print();
		cout << "Car: " << endl;
		car.print();
	}
	void setTeam(String _name, String _constructor, Pilot _pilots[2], Car _car) {
		name = _name;
		constructor = _constructor;
		pilots[0] = _pilots[0];
		pilots[1] = _pilots[1];
		car = _car;
	}
};

class WRC {
public:
	Vector<Rally> rallies;
	Vector<Team> teams;

	WRC() {}
	WRC(Vector<Rally> _rallies, Vector<Team> _teams) {
		rallies = _rallies;
		teams = _teams;
	}
	~WRC() {}
	void print() {
		cout << "WRC 2018" << endl;
		cout << "Stages: " << endl;
		for (int i = 0; i < rallies.size(); i++) {
			rallies[i].print();
		}
		cout << "Teams: " << endl;
		for (int i = 0; i < teams.size(); i++) {
			teams[i].print();
		}
	}
	Team& getTeam(String name) {
		for (int i = 0; i < teams.size(); i++) {
			if (teams[i].name == name) return teams[i];
		}
	}
	void rallyScoring(Vector<Pilot*> &table, Rally& rally) {
		for (int i = 0; i < teams.size(); i++) {
			if (rally.trackSurface == teams[i].pilots[0].dominatingSurface) teams[i].pilots[0].tempScore++;
			if (rally.trackSurface == teams[i].pilots[1].dominatingSurface) teams[i].pilots[1].tempScore++;
			if (rally.trackSurface == teams[i].car.surfaceBehavior) {
				teams[i].pilots[0].tempScore++;
				teams[i].pilots[1].tempScore++;
			}
			if (rally.corners == teams[i].pilots[0].dominatingCorner) teams[i].pilots[0].tempScore++;
			if (rally.corners == teams[i].pilots[1].dominatingCorner) teams[i].pilots[1].tempScore++;
			if (rally.corners == teams[i].car.cornerTraction) {
				teams[i].pilots[0].tempScore++;
				teams[i].pilots[1].tempScore++;
			}
			if (rally.stretches == teams[i].pilots[0].dominatingStretch) teams[i].pilots[0].tempScore++;
			if (rally.stretches == teams[i].pilots[1].dominatingStretch) teams[i].pilots[1].tempScore++;
			if (rally.stretches == teams[i].car.power) {
				teams[i].pilots[0].tempScore++;
				teams[i].pilots[1].tempScore++;
			}
			table.push_back(&teams[i].pilots[0]);
			table.push_back(&teams[i].pilots[1]);
		}
		for (int i = 0; i < table.size() - 1; i++) {
			table[i]->tempScore *= table[i]->psychics;
			table[i]->tempScore *= table[i]->experience;
		}

		for (int i = 0; i < table.size() - 1; i++) {
			for (int j = 0; j < table.size() - i - 1; j++) {
				if (table[j]->tempScore < table[j + 1]->tempScore) {
					Pilot* helper;
					helper = table[j];
					table[j] = table[j + 1];
					table[j + 1] = helper;
				}
			}
		}
		table[0]->score += 20;
		table[1]->score += 15;
		table[2]->score += 10;
		if (table.size() > 3) table[3]->score += 8;
		if (table.size() > 4) table[4]->score += 6;
		if (table.size() > 5) table[5]->score += 5;
		if (table.size() > 6) table[6]->score += 4;
		if (table.size() > 7) table[7]->score += 3;
		if (table.size() > 8) table[8]->score += 2;
		if (table.size() > 9) table[9]->score += 1;
	}
	void rallyPlacement(Rally& rally) {
		Vector<Pilot*> table;
		rallyScoring(table, rally);
		
		cout << "Rally "<<rally.name << endl;
		for (int i = 0; i < table.size(); i++) {
			cout << i + 1 << " ";
			table[i]->print();
		}
		for (int i = 0; i < teams.size(); i++) {
			teams[i].pilots[0].tempScore = 0;
			teams[i].pilots[1].tempScore = 0;
		}
	}
	void rallyChampionship() {
		for (int i = 0; i < rallies.size(); i++) {
			rallyPlacement(rallies[i]);
		}
		Vector<Pilot> seasonTable;
		for (int i = 0; i < teams.size(); i++) {
			seasonTable.push_back(teams[i].pilots[0]);
			seasonTable.push_back(teams[i].pilots[1]);
		}
		for (int i = 0; i < seasonTable.size()-1; i++) {
			for (int j = 0; j < seasonTable.size() - i - 1; j++) {
				if (seasonTable[j].score < seasonTable[j + 1].score) {
					Pilot helper;
					helper = seasonTable[j];
					seasonTable[j] = seasonTable[j + 1];
					seasonTable[j + 1] = helper;
				}
			}
		}
		cout << endl << "Season Table:" << endl;
		for (int i = 0; i < seasonTable.size(); i++) {
			cout << i + 1 << " ";
			seasonTable[i].print();

		}
		cout << "Champion: ";
		seasonTable[0].print();

		for (int i = 0; i < teams.size(); i++) {
			teams[i].constructorScore = teams[i].pilots[0].score + teams[i].pilots[1].score;
		}
		for (int i = 0; i < teams.size()-1; i++) {
			for (int j = 0; j < teams.size() - i - 1; j++) {
				if (teams[j].constructorScore < teams[j + 1].constructorScore) {
					Team helper;
					helper = teams[j];
					teams[j] = teams[j + 1];
					teams[j + 1] = helper;
				}
			}
		}
		cout << "Constructor Standings: " << endl;
		for (int i = 0; i < teams.size(); i++) {
			cout <<i+1<<" "<< teams[i].constructor << " " << teams[i].constructorScore<<" "<< teams[i].name << endl;
		}
		cout << "Constructor champion: ";
		cout << teams[0].constructor<<" "<<teams[0].name << endl;
	}
	void backUpRaceStanding(ofstream& fo, Rally& rally) {
		Vector<Pilot*> table;
		rallyScoring(table, rally);
		for (int i = 0; i < table.size(); i++) {
			fo << i + 1 << " ";
			table[i]->serializeName(fo);
		}
	}
	void backUpSeasonStandings() {
		ofstream fo("races.txt");
		if (fo.is_open()) {
			for (int i = 0; i < rallies.size(); i++) {
				fo <<"Rally "<< rallies[i].name << endl;
				backUpRaceStanding(fo, rallies[i]);
			}
		}
		fo.close();
	}
	void backUpPilotsData() {
		for (int i = 0; i < teams.size(); i++) {
			teams[i].pilots[0].serialize();
			teams[i].pilots[1].serialize();
		}
	}
};
