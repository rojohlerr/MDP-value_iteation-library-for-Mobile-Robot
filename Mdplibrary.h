
#ifndef Mdp_libray_policy
#define Mdp_libray_policy

#include <iostream>
#include <map>
#include <string.h>
using namespace std;
class Mdplibrary
{

private:
	string map_index;
	string map_Strvalue;
	float map_Numvalue;
	int row,col;
public:
	Mdplibrary();
	//~Mdplibrary();

	void String_mapper(string index ,string strvalue,int rowV,int colV);
	void number_mapper(string index ,float numvalue,int rowV,int colV);
	void Create_world();
	int coordiantToIndex(int row, int col);
	void cell_intializer();
	void value_iteration(int row,int col);
	void caller();
	
};

#endif// Mdp_libray_policy