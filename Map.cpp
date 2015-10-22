#pragma once
#include <vector>

using namespace std;
class Map {

public:

vector < vector < vector<int> > > carte;




	Map() {
		
	}


	~Map() {

	};


	int getSize() {
		return carte.size();
	}

	void creerMap(int taille) {
		for (int i = 0; i < taille; i++)
		{
			carte.push_back(vector<vector<int> >());
			for (int j = 0; j<taille; j++)
			{
				carte[i].push_back(vector<int>());
				for (int k = 0; k<taille; k++)
				{
					carte[i][j].push_back(12);
				}
			}
		}
	
	}


};

