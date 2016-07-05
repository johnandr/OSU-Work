 /*
  * Program.cpp
  * 
  *  OS: Fedora 13
  *  Language: Native C++
  *  Compiler: GNU g++
  *  Created on: Sep 11, 2010
  *      Author: julian
  */
 
 #include <iostream>
 #include <stdlib.h>
 #include <time.h>
 #include "FibR.h"
 #include "FibNR.h"

 using namespace std;
 void Usage(){
 	cout<<"Correct Usage:"<<endl;
  	cout<<"./Fibonacci [n]"<<endl;
 }
 int main(int argc, char** args) {
 	try{
		clock_t t;
		clock_t r;
 		const char* input; //Note: char by default initializes to '\0'
 		if(args[1]!=0)
 		{	
  			cout<<"1st passed arguement: '"<<args[1]<<"'"<<endl;
 			input= args[1]; 
 		}
		t = clock();
  		int n= atoi(input);
 		cout<<"Finding '"<<n<<"'th "<<"fibonacci number...."<<endl;
  		cout<<"Calling Recursive Fibonacci implementation"<<endl;
  		FibonacciR fr(n);
  		fr.PrintFibonacci();
		t = clock() - t;
		cout << "it took " << t << " clicks" << endl;
		r = clock();
  		cout<<"Calling Non-Recursive Fibonacci implementation"<<endl;
  		FibonacciNR fnr(n);
   		fnr.PrintFibonacci();
		r = clock() - r;
		cout << "it took " << r << " clicks" << endl;	
  		cout << "Done!!!!" << endl; 
  		return 0;
  	}
  	catch(...)
  	{
  		cout<<"Oops an error occured! Please check usage"<<endl;
  		Usage();
  		return 1;
  	}

}
