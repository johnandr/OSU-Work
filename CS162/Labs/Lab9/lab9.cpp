#include <iostream>
#include <time.h>

using namespace std;
	
int rfactorial(int n){
	if(n==1){
		return 1;
	}
	else{
		return n * rfactorial(n-1);
	}
}
int factorialHelper (int n, int	result)	{	
	if(n ==	1){	
		return	result;	
	}else{	
		return	factorialHelper(n-1,n*result);	
	}
}	
int factorial(int n){
	return	factorialHelper(n,1);		
}

int main(){
	int i;

	cin >> i;
	clock_t t;	
	t = clock();
	cout << rfactorial(i) << endl;
	t = clock() - t;
	cout << t << endl;
	clock_t r;
	r = clock();
	cout << factorial(i) << endl;
	r = clock() - r;
	cout << r << endl;
	return 0;
}	
