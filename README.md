# MDp_libray_ESP32
This is an MDP library written in  c++ for mobile robot using esp32 mc

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// sample code to run the program
#include<iostream>
#include"Mdplibrary.h"
#include"Mdplibrary.cpp"
using namespace std;

int main()
{   
    Mdplibrary lib;
    lib.Create_world();
   
    lib.caller();
    return 0;
 }
 //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
