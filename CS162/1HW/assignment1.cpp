#include <iostream>

using namespace std;

const int rows=80;
const int cols=22;
const char live = 'X';
const char dead = '.';
char board_update[rows][cols];

void check_area(char board[][cols]);
void check_life(char board[][cols]);
void change(char board[][cols]);


int main(){
    int gene;
    char board[rows][cols];
    cout << "How many generations do you want to simulate?"<< endl;
    cin >> gene;
    //cout << gene << endl;
    for(int l = 0;l<gene; l++){
        check_area(board);
	change(board);
    }
return 0;
}

/*****************
 * Function Name: check_area
 * Description: Adds up all living cells around current cell
 * Input: Surrounding cell's status
 * Output: life_count of current cell
 ****************/

void check_area(char board[][cols]){
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            int life_count;
	    if(board[r-1][c-1]==live){
	        life_count++;
	    }
	    if(board[r-1][c]==live){
	        life_count++;
	    }
	    if(board[r-1][c+1]==live){
	        life_count++;
	    }
	    if(board[r][c-1]==live){
	        life_count++;
	    }
	    if(board[r][c+1]==live){
	        life_count++;
	    }
	    if(board[r+1][c-1]==live){
	        life_count++;
	    }
	    if(board[r+1][c]==live){
	        life_count++;
	    }
	    if(board[r+1][c+1]==live){
	        life_count++;
	    }
	    check_life(board);
        }
    }
}

/*********************
 * Function Name: check_life
 * Description: Determines if cell lives or dies next generation
 * Input: life_count & current status
 * Output: New status
 ********************/

void check_life(char board[][cols],int life_count,int r, int c){
    if(board[r][c] == live && life_count < 2){
        board_update[r][c] = dead;
    }
    else if(board[r][c] == live && life_count > 3){
        board_update[r][c] = dead;
    }
    else if(board[r][c] == dead && life_count == 3){
        board_update[r][c] = live;
    }
    else if(board[r][c] == live && (life_count == 2 || life_count == 3)) {
        board_update[r][c] = live;
    }
    else{
        board_update[r][c] = dead;
    }
}

/******************************
 * Function Name: change
 * Description: Changes old board into updated board
 * Input: New Status (board_update)
 * Output: Board (Updated for next generation)
 *****************************/

void change(char board[][cols]){
    for(int r=0;r<rows;r++){
        for(int c=0;c,cols;c++){
            board[r][c] = board_update[r][c];
        }
    }
}


