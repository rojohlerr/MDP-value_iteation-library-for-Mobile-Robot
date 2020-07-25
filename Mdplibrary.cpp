
#include "Mdplibrary.h"

typedef std::map<std::string,std::string> BasePairMap_S;
typedef std::map<std::string,float> BasePairMap_N;
using namespace std;
BasePairMap_S mstring[12];
BasePairMap_N mnumber[12];
//typedef std::map<string, string> BasePairMap;
Mdplibrary::Mdplibrary()
{ 
	
	discount_factor=0.9;
	epsilon=0.0001;
	cell_intializer();

	
    
}
void Mdplibrary::cell_intializer(){
	int idx_no;
   	value_matrix[3][4]={0.0};
    //policy_matrix[3][4]={{"","","",""},{"","","",""},{"","","",""}};
     float temp[] [4] {{1.0,1.0,1.0,1.0},{1.0,1.0,1.0,1.0},{1.0,1.0,1.0,1.0}};

     std::copy(&temp[0][0], &temp[0][0]+3*4,&temp_value[0][0]); 
	for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
		{

		idx_no=coordiantToIndex(i,j);
	    mstring[idx_no]["Is_terminal"]="NO";
	    mstring[idx_no]["Policy"]="";
	    mstring[idx_no]["Is_block"]="NO";

	    mnumber[idx_no]["Reward"]=-0.04;
	    mnumber[idx_no]["Value"]=0.0;
	    mnumber[idx_no]["Column"]=j;
	    mnumber[idx_no]["Row"]=i;

    }

    mnumber[9]["Reward"]=1.0;
    mnumber[10]["Reward"]=-1.0;
    mnumber[9]["Value"]=1.0;
    mnumber[10]["Value"]=-1.0;
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
}
bool Mdplibrary::is_terminal_block(int row, int col) // check if it is termina or block state

{   int idx_no;
	bool rtn=false;
	idx_no=coordiantToIndex(row,col);
	if(mstring[idx_no]["Is_terminal"]=="YES" || mstring[idx_no]["Is_block"]=="YES")
		rtn=true;

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
         	value_matrix[i][j]=mnumber[idx_no]["Value"];
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
         	policy_matrix[i][j]=mstring[idx_no]["Policy"]; 
         }
}
void Mdplibrary::policy_update(int row, int col, string policy) // update the policy under iteration
{
  int idx_no;
 idx_no=coordiantToIndex(row,col);
 policy_matrix[row][col]=policy;
}
void Mdplibrary::value_update(int row, int col, float value) // update the policy under iteration
{
  int idx_no;
 idx_no=coordiantToIndex(row,col);
 value_matrix[row][col]=value;
}
float Mdplibrary::direction_extracter(int row,int col, string direction)// this is retrung the the next value based on the directions
{
	   int idx_no,roww,coll;
	   float ret_value;
       roww=row;
       coll=col;
     
		if(direction=="north")
		{
			if(row-1>=0)
               roww=row-1;
		 idx_no=coordiantToIndex(roww,col);
        if(mstring[idx_no]["Is_block"]=="NO")
           ret_value=mnumber[idx_no]["Value"];
          else
           {
           	idx_no=coordiantToIndex(row,col);
            ret_value=mnumber[idx_no]["Value"];
        }
		}

		 
		else if(direction=="south")
		{
            if(row+1<=2)
               roww=row+1;
           
		 idx_no=coordiantToIndex(roww,col);
        if(mstring[idx_no]["Is_block"]=="NO")
           ret_value=mnumber[idx_no]["Value"];
          else
           {
           	idx_no=coordiantToIndex(row,col);
            ret_value=mnumber[idx_no]["Value"];
        }

		}
		 
		 else if(direction=="right")
		 {
             if(col+1<=3)
               coll=col+1;
         
		 idx_no=coordiantToIndex(row,coll);
        if(mstring[idx_no]["Is_block"]=="NO")
           ret_value=mnumber[idx_no]["Value"];
          else
           {
           	idx_no=coordiantToIndex(row,col);
            ret_value=mnumber[idx_no]["Value"];
        }

		 }
		 
		 else if(direction=="left")
		 {
          if(col-1>=0)
               coll=col-1;
           
		 idx_no=coordiantToIndex(row,coll);
        if(mstring[idx_no]["Is_block"]=="NO")
           ret_value=mnumber[idx_no]["Value"];
          else
           {
           	idx_no=coordiantToIndex(row,col);
            ret_value=mnumber[idx_no]["Value"];
        }
		 }
   return ret_value;
}

void Mdplibrary::value_iteration()
{
	 float max=0.0,motion_valut [4];
	 string motion[]={"N","S","R","L"};
	 int key=0,idx_no;
  for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
		{

           idx_no=coordiantToIndex(i,j);
            if(mstring[idx_no]["Is_block"]=="YES" )
                        {  mstring[idx_no]["Policy"]="B";
                        	continue;
                        }
             else if (mstring[idx_no]["Is_terminal"]=="YES")
            
            	{
            		mstring[idx_no]["Policy"]="T";
            		continue;
            	}
            else{
             motion_valut[0]=0.8*direction_extracter(i,j,"north") + 0.1*direction_extracter(i,j,"left") + 0.1*direction_extracter(i,j,"right");
             max=motion_valut[0];
             key=0;
             motion_valut[1]=0.8*direction_extracter(i,j,"south") + 0.1*direction_extracter(i,j,"left") + 0.1*direction_extracter(i,j,"right");
             motion_valut[2]=0.8*direction_extracter(i,j,"right") + 0.1*direction_extracter(i,j,"north") + 0.1*direction_extracter(i,j,"south");
             motion_valut[3]=0.8*direction_extracter(i,j,"left") + 0.1*direction_extracter(i,j,"north") + 0.1*direction_extracter(i,j,"south");
            
           for (int k= 0; k<4; k++) 
             {if (motion_valut[k] > max) 
                { max = motion_valut[k]; 

                 key=k;

             }}
            
         mnumber[idx_no]["Value"]= max*discount_factor+ mnumber[idx_no]["Reward"];
         
         mstring[idx_no]["Policy"]=motion[key];
     }
		}

}
bool Mdplibrary::comp_diff_episilon()
{
  bool ret=false;
  float buffer[3][4];
  for (int i = 0; i < 3; i++) 
  	for (int j = 0; j < 4; j++) {
  	  buffer[i][j]=abs(value_matrix[i][j]-temp_value[i][j]);
  	 
  	}

  for (int i = 0; i < 3; i++) {
    float max = *std::max_element(buffer[i], buffer[i] + 4);
      if(max>epsilon)
      {
      	ret=true;
      	
      	break;
      }
 } 
  
   return ret;
}
void Mdplibrary::caller(){
 int iter;
 value_toMatrix();

   iter=0;
	while (true)
	{
       if(!comp_diff_episilon())
       	 {
       	 	cout<<"((((****************************teminated *****************************)))))))"<<endl;
       	 	break;

       	 }
       	 cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ iteration : "<< iter<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^%"<<endl;
	   std::copy(&value_matrix[0][0], &value_matrix[0][0]+3*4,&temp_value[0][0]);
	  
	   value_iteration();
       value_toMatrix() ;
        for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
		{  
			cout << value_matrix[i][j] << "\t\t";
            if(j == 3)
                cout << endl;                                                                                                                       

			} 
       iter++;
	}
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~ policy ~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	policy_toMatrix(); 
  for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
		{  
			cout << policy_matrix[i][j] << "\t\t";
            if(j == 3)
                cout << endl;                                                                                                                       

			} 
       
	
//direction_extracter(0,1,"north");
//number_mapper("Reward",.5,2,3);
//is_terminal_block(1,2);
//cout<<"******** :"<<mnumber[11]["Reward"]<<endl;
}