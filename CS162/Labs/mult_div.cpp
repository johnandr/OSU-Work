#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "./mult_div.h"

using namespace std;

/*******************
 ** Function Name: command_line_check
 ** Description: Checks for correct number of command line inputs
 ** Input: int argc
 ** Output: Exit program or nothing
 *******************/
void command_line_check(int argc){
   if(argc!=3){
      cout <<"You did not enter correct number of inputs\nEnter 2 inputs" << endl;
      exit(1);
   }
}

/*******************
 ** Function Name: value_check
 ** Description: Checks for correct inputs
 ** Input: char argv
 ** Output: row or column int value
 *******************/
int value_check(char *argv){
   string val(argv);
   while(!isdigit(val[0])){
      cout<<"Bad value for input"<< endl;
      cout<<"Enter new value for input: ";
      cin >> val;
   }
   return atoi(val.c_str());
}


/*******************
 ** Function Name: create_array
 ** Description: Creates an array for the structs
 ** Input: int value for rows and columns
 ** Output: table for values
 *******************/
mult_div_val** create_array(int rows,int cols){
   mult_div_val **matrix = new mult_div_val*[rows];
   for(int i=0;i<rows;i++){
      matrix[i] = new mult_div_val[cols];
   }
   return matrix;
}

/*******************
 ** Function Name: fill
 ** Description: Fills the mult part of each array spot
 ** Input: int value for rows and columns and array
 ** Output: Nothing
 *******************/
void fill(mult_div_val **matrix,int rows,int cols){
   for(int i=0;i<rows;i++){
      for(int j=0;j<cols;j++){
	 matrix[i][j].mult = (i+1)*(j+1);
      }
   }
   for(int i=0;i<rows;i++){
      for(int j=0;j<cols;j++){
	 matrix[i][j].div = (float)(i+1)/(float)(j+1);
      }
   }
}

/*******************
 ** Function Name: print
 ** Description: Prints out array
 ** Input: int value for rows and columns and array
 ** Output: Array values in each spot
 *******************/
void print(mult_div_val **matrix,int rows,int cols){
   cout <<"Multiplication Table\n";
   for(int i=0;i<rows;i++){
      for(int j=0;j<cols;j++){
	 cout << matrix[i][j].mult <<" ";
      }
      cout << endl;
   }
   cout <<"\nDivision Table\n";
   for(int i=0;i<rows;i++){
      for(int j=0;j<cols;j++){
	 cout << setprecision(2) << matrix[i][j].div <<" ";
      }
      cout << endl;
   }
}
