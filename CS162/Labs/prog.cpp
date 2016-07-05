#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "./mult_div.h"

using namespace std;

int main(int argc,char *argv[]){
   command_line_check(argc);
   int rows = value_check(argv[1]);
   int cols = value_check(argv[2]);
   mult_div_val **matrix = create_array(rows,cols);
   fill(matrix,rows,cols);
   print(matrix,rows,cols);

return 0;
}
