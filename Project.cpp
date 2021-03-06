// Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RallyChampionship.h"
#include "String.h"





int main()
{
	Car x("VW Polo WRC", sharp, mediumStretch, gravel);
	Car y("Ford Fiesta STI", slight, longStretch, asphalt);
	Car z("Citroen C3 WRC", slight, longStretch, snow);
	Car t("Hyundai i20 Coupe WRC", sharp, shortStretch, snow);


	Pilot xx("Mitko", gravel, sharp, mediumStretch, 1, 1.05);
	Pilot xxx("Gosho", asphalt, slight, longStretch, 0.91,1.01);
	Pilot yy("Pesho", snow, sharp, shortStretch, 1.1, 1);
	Pilot yyy("Tosho", gravel, slight, longStretch, 0.98, 1.1);
	Pilot zz("Pencho", asphalt, sharp, shortStretch, 0.88, 1.09);
	Pilot zzz("Petko", snow, slight, shortStretch, 1.1, 1.1);
	Pilot tt("Zdravko", snow, sharp, mediumStretch, 1, 1.01);
	Pilot ttt("Ivan", asphalt, slight, longStretch,1.15, 1.05);


	Pilot xxxx[2];
	xxxx[0]=xx;
	xxxx[1]=xxx;
	Pilot yyyy[2];
	yyyy[0] = yy;
	yyyy[1] = yyy;
	Pilot zzzz[2];
	zzzz[0] = zz;
	zzzz[1] = zzz;
	Pilot tttt[2];
	tttt[0] = tt;
	tttt[1] = ttt;

	Team X("Volkswagen", "Petio-montiorcheto", xxxx, x);
	Team Y("Ford", "Momchil-poluoskata", yyyy, y);
	Team Z("Citroen", "Vanko1", zzzz, z);
	Team T("Hyundai", "Ching Chong", tttt, t);

	Rally sweden("Sweden", snow, slight, mediumStretch);
	Rally monteCarlo("Monte Carlo", asphalt, sharp, shortStretch);
	Rally bulgaria("Bulgaria", gravel, slight, longStretch);
	Rally italia("Italia", gravel, sharp, mediumStretch);
	Rally corsica("Corsica", asphalt, sharp, longStretch);
	Vector<Team> teams;
	Vector<Rally> rallies;
	teams.push_back(X);
	teams.push_back(Y);
	teams.push_back(Z);
	teams.push_back(T);
	rallies.push_back(sweden);
	rallies.push_back(monteCarlo);
	rallies.push_back(bulgaria);
	rallies.push_back(italia);
	rallies.push_back(corsica);

	WRC wrc(rallies, teams);
	wrc.rallyChampionship();
	wrc.backUpSeasonStandings();
	wrc.backUpPilotsData();

	
	/*String x;
	x = "KUR";
	String y = "HUI";
	x += y;

	
	cout <<strlen(x.content)<< x;*/




    return 0;
}

