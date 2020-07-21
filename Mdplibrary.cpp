
#include "Mdplibrary.h"

typedef std::map<std::string,std::string> BasePairMap_S;
typedef std::map<std::string,float> BasePairMap_N;
using namespace std;
BasePairMap_S mstring[12];
BasePairMap_N mnumber[12];
//typedef std::map<string, string> BasePairMap;
Mdplibrary::Mdplibrary()
{
	cell_intializer();
    cout<<"print me"<<endl;
	
    
}
void Mdplibrary::cell_intializer(){
	int idx_no;
    value_matrix[3][4]={0.0};
    policy_matrix[3][4]={""};
	for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
		{

		idx_no=coordiantToIndex(i,j);
	    mstring[idx_no]["Is_terminal"]="NO";
	    mstring[idx_no]["Policy"]="";
	    mstring[idx_no]["Is_block"]="NO";

	    mnumber[idx_no]["Reward"]=0.4;
	    mnumber[idx_no]["value"]=0.0;
	    mnumber[idx_no]["Column"]=j;
	    mnumber[idx_no]["Row"]=i;

    }
    mnumber[9]["Reward"]=1.0;
    mnumber[10]["Reward"]=-1.0;
    mstring[9]["Is_terminal"]="YES";
    mstring[10]["Is_terminal"]="YES";
    mstring[4]["Is_block"]="YES";
		
}
void Mdplibrary::String_mapper(string index,string value,int row, int col)
{
  int idx_no;
  index=coordiantToIndex(row,col);
  mstring[idx_no][index] = value;
  
}
void Mdplibrary::number_mapper(string index,float value,int row, int col)
{     
	int idx_no;
	idx_no=coordiantToIndex(row,col);
    mnumber[idx_no][index]=value;
    //	cout<<"print me"<<endl;
}

int  Mdplibrary::coordiantToIndex(int row,int col) // change to the matrix(row, col ) to index
{  int index=0;
	if(col%2==0)
		index=abs((col%4)*3)+abs(row-2);
	else
		index=row+ abs((col%4)*3);
return index;
}

void Mdplibrary::Create_world() // create the gridworld in form of multi dimentional array
{
	float arr[3][4]={0.0};
	
	for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
		cout<<arr[i][j];
number_mapper("Reward",.5,2,3);
}
bool Mdplibrary::is_terminal_block(int row, int col) // check if it is termina or block state

{   int idx_no;
	bool rtn=false;
	idx_no=coordiantToIndex(row,col);
	if(mstring[idx_no]["Is_terminal"]=="YES" || mstring[idx_no]["Is_block"]=="YES")
		rtn=true;

		//cout<<"^^^^^^^^^^^^^^^this is ^^^^^^^^^^^^^^^"<<endl;
	return rtn;
	 
}
bool Mdplibrary::endOf_iteration() //check in the iteraion is meet the epsilon
{

}
void Mdplibrary::value_toMatrix() // calculated value to new matrix value 
{
    int idx_no;
    
	for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
         {
         	idx_no=coordiantToIndex(i,j);
         	value_matrix[i][j]=mnumber[idx_no]["value"];
         }
  // mnumber
}
void Mdplibrary::policy_toMatrix() // calculated policy to new matrix value 
{

int idx_no;
    
	for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
         {
         	idx_no=coordiantToIndex(i,j);
         	policy_matrix[i][j]=mstring[idx_no]["policy"]; //mnumber
         }
}
void Mdplibrary::value_iteration(int row,int col)
{
 
}
void Mdplibrary::caller(){

//number_mapper("Reward",.5,2,3);
is_terminal_block(1,2);
cout<<"******** :"<<mnumber[11]["Reward"]<<endl;
}