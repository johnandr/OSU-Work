#include <iostream>
#include <cstring>

using namespace std;

struct words{
   char key[101];
   char sentence[100];
};

/*****************************
 ** Function Name: enter_word
 ** Description: Takes in key word and sentence from user
 ** Input: words matrix for storage, user input char strings for key and sentence
 ** Output: 
 *****************************/
void enter_word(words* matrix){
   for(int i=1;i<2;i++){
      cout <<"Enter the key word\n";
      cin.getline(matrix->key,100);
      cout<< strlen(matrix->key) << endl;
      if(strlen(matrix->key) > 101){
         cout <<"Key is too long, try again"<< endl;
	 i = i-1;
      }
   }
   for(int i=1;i<2;i++){
      cout <<"Enter the sentence word\n";
      cin.getline(matrix->sentence,100);
      cout << strlen(matrix->sentence) << endl;
      if(strlen(matrix->sentence) >101){
         cout <<"Sentence is too long, try again"<< endl;
	 i=i-1;
      }
   }
}

/*****************************
 ** Function Name: encript
 ** Description: uses XOR to encript sentence
 ** Input: words matrix
 ** Output: Changes matrix.sentence
 *****************************/
void encript(words* matrix){
   for(int i=1;i<strlen(matrix->sentence);i++){
      matrix->sentence[i] = matrix->sentence[i]^(matrix->key[i % strlen(matrix->key)]);
   }
}


int main(){
   words matrix;
   enter_word(&matrix);
   cout <<"Entered key: " << matrix.key << endl;
   cout <<"Entered sentence: " << matrix.sentence << endl;
   encript(&matrix);
   cout <<"Encripted Sentence: " << matrix.sentence << endl;
   encript(&matrix);
   cout <<"Decripted Sentence: " << matrix.sentence << endl;
return 0;
}
