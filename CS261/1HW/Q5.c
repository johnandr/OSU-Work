/* CS261- Assignment 1 - Q.5*/
/* Name: Andrew Johnson
 * Date: 4/7/15
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void studly(char* word){
     /*Convert to studly caps*/
     int check;
     int i = 0;
     while(word[i] != NULL)
     {
        check = i % 2;
        if(check == 0 && word[i] > 90)
        {
            word[i] =toUpperCase(word[i]);
        }else if(check == 1 && word[i] > 65 && word[i] < 90)
        {
            word[i] = toLowerCase(word[i]);
        }
        i++;
    }
}

int main(){
    /*Read word from the keyboard using scanf*/
    char str[100];
    scanf("%s", str);
    
    /*Call studly*/
    studly(&str);
    /*Print the new word*/
    printf("%s\n", str);
    
    return 0;
}
