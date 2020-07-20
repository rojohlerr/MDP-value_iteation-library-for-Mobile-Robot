
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

int  Mdplibrary::coordiantToIndex(int row,int col)
{  int index=0;
	if(col%2==0)
		index=abs((col%4)*3)+abs(row-2);
	else
		index=row+ abs((col%4)*3);
return index;
}

void Mdplibrary::Create_world()
{
	float arr[3][4]={0.0};
	
	for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
		cout<<arr[i][j];
}
void Mdplibrary::caller(){

String_mapper("this"," rojo",2,3);
cout<<"******** :"<<mnumber[11]["Reward"]<<endl;
}