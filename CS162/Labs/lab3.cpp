#include <iostream>
#include <string>

using namespace std;

class list{
   public: 
      string *name;
      string *unit;
      double *price;
      int *number;
      int num;
   
      void create_list();
      void add_item();
      void remove_item();
      void print_list();
};

void list::create_list(){
   cout <<"How many items are on your list?\n";
   cin >> num;
   name = new string[num];
   unit = new string[num];
   price = new double[num];
   number = new int[num];
}

void list::add_item(){
   for(int i=0;i<num;i++){
      cout <<"What is the name of item"<< i+1 <<"? \n";
      cin >> name[i];
      cout <<"What is the price per unit?\n";
      cin >> price[i];
      cout <<"What is the unit size?\n";
      cin >> unit[i];
      cout <<"How many are you buying?\n";
      cin >> number[i];
   }
}

void list::print_list(){
   for(int j=0;j<num;j++){
      cout <<"\nItem Number:"<< j+1 << endl;
      cout <<"Item Name: "<< name[j] << endl;
      cout <<"Unit Size: "<< unit[j] << endl;
      cout <<"Unit Price: "<< price[j] << endl;
      cout <<"Number to buy: "<< number[j] << endl;
   }
}

void list::remove_item(){
   int var;
   cout <<"What item number do you want to remove?\n";
   cin >> var;
   for(int i=var;i<num;i++){
      name[i-1] = name[i];
      unit[i-1] = unit[i];
      price[i-1] = price[i];
      number[i-1] = number[i];
   }
   num = num-1;
}
   

int main(){
   list example;
   example.create_list();
   example.add_item();
   example.print_list();
   example.remove_item();
   example.print_list();

return 0;
}
