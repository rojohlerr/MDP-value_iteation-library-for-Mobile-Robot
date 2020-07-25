/*************************
This is is a c++ libray writing for the Esp32:
this is is the value iteration algorithm  implementation of MDP


***************************/
#ifndef Mdp_libray_policy
#define Mdp_libray_policy

#include <iostream>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;
class Mdplibrary
{

private:
	float epsilon;
	float discount_factor;
	string map_index;
	string map_Strvalue;
	float map_Numvalue;
	int row,col;
	float value_matrix[3][4];
	string policy_matrix[3][4];
	float temp_value [3][4];
public:
	Mdplibrary();
	//~Mdplibrary();

	void String_mapper(string index ,string strvalue,int rowV,int colV);
	void number_mapper(string index ,float numvalue,int rowV,int colV);
	void Create_world();
	int coordiantToIndex(int row, int col);
	void cell_intializer();
	void value_iteration();
	bool is_terminal_block(int row, int col);
	bool endOf_iteration();
	void policy_toMatrix() ;
	void value_toMatrix();
	bool comp_diff_episilon();
	void policy_update(int row, int col, string policy);
	void value_update(int row, int col, float value);
	float direction_extracter(int row,int col,string direction);
	void caller();

	
};

#endif// Mdp_libray_policy