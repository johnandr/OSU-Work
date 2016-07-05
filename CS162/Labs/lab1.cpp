#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct mult_div_val{
	int mult;
	float div;
};

void value_check(int x){
    if(x == 0){
        cout << "You wont be able to divide by 0" << endl;
        cout << "Please enter a number greater than 0" << endl;
        cin << x
    }
    else{
    }
    return x;
}

int main(){
    int rows;
    int cols;
    cout << "Enter how many rows for your table: ";
    cin >> rows;
    value_check(rows);
    cout << rows << endl;
return 0;
}
