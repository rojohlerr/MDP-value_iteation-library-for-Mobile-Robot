
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
	float value_matrix[3][4];
	string policy_matrix[3][4];
public:
	Mdplibrary();
	//~Mdplibrary();

	void String_mapper(string index ,string strvalue,int rowV,int colV);
	void number_mapper(string index ,float numvalue,int rowV,int colV);
	void Create_world();
	int coordiantToIndex(int row, int col);
	void cell_intializer();
	void value_iteration(int row,int col);
	bool is_terminal_block(int row, int col);
	bool endOf_iteration();
	void policy_toMatrix() ;
	void value_toMatrix();
	void caller();

	
};

#endif// Mdp_libray_policy