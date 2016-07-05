#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct mult_div_values{
    int mult;
    float div;
};

/************************
 * Function Name: command_line_check
 * Description: Checks for correct number of command line inputs
 * Input: int argc
 * Output: Exit program or nothing
*************** *********/
void command_line_check(int argc){
    cin >> argc;
   /* if(argc!=3){
        cout << "You did not enter the correct number of inputs\nPlease enter 2 inputs" << endl;
        exit(1);
    }*/
}

int value_check(char *argv){
    string val(argv);
    cin >> val;
    if(!isdigit(val[0])){
        cout << "Bad value for input" << endl;
        cout << "Enter new value for input: ";
        cin >> val;
    }
    else{
    }
    return atoi(val.c_str());
}

int main(int argc, char* argv[]){
    //command_line_check(argc);
    int rows = value_check(argv[1]);
    int cols = value_check(argv[2]);
    

    //mult_fill(matrix,rows,cols);

return 0;
}
