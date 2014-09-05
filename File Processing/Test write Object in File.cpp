//============================================================================
// Name        : TestTask3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "HugeTovar.h"
#include "Koleti.h"
#include "Letters.h"
#include "SmallPlick.h"
#include <vector>
#include <fstream>
int main() {

	fstream paks("pakage.txt" , ios::out);

	vector<Pakage*> pakage;
	Pakage info("Vasil Sakalev", "s.Qgodina", "Daniel Kisimov", "gr.Smolqn");
	HugeTovar hugeCargo(info, 2.3, 1, 12.3, 56.3);
	pakage.push_back(&hugeCargo);

	Koleti kolet(info, 2.1,5.3,2.1);
	pakage.push_back(&kolet);

	Letters lett(info,1,1.2,1,3);
	pakage.push_back(&lett);

	SmallPlick plick(info,1,4);

	pakage.push_back(&plick);

	for(unsigned int i = 0 ; i < pakage.size(); i ++){
		cout << pakage[i]->getInfo() << endl;
		paks << pakage[i]->getInfo() << endl;
	}


	return 0;
}
