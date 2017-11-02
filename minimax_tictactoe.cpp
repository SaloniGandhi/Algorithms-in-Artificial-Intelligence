#include<stdio.h>
#include<algorithm>
#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>	
using namespace std;
struct node{
 	int x;
 	int y;
 };
//global declarations
node*optimum_move=new node;
char player = 'x', opp = 'o';
 
//function declarations
void print_board(char board[3][3]);
bool is_boardfull(char board[3][3]);
int ret_score(char b[3][3]);
int minimax(char board[3][3], int depth,bool maximiser_turn);
node*find_opt_move(char board[3][3]);


void print_board(char board[3][3]){
	cout << "-------------------";
	for(int i = 0; i < 3; i++) {
		cout << '\n' << "|";
		for(int j = 0; j < 3; j++) {
			cout << setw(3) << board[i][j] << setw(3) << " |";
		}
	}
	cout << '\n' << "-------------------" << '\n';
}
bool is_boardfull(char board[3][3])
{
    for (int m = 0; m<3; m++)
        for (int n = 0; n<3; n++)
            if (board[m][n]!='-')
                return true;
    return false;
}
int ret_score(char b[3][3]){
//we have m rows and n columns.
//check winning condition row wise.
	for(int m=0;m<3;m++){
		
			if (b[m][0]==b[m][1]&&b[m][1]==b[m][2]){
				if(b[m][0]=='x')
					return 10;
				else if (b[m][0]=='o')
					return -10;
				}	
			}
//check winning condition column wise.
	for(int n=0;n<3;n++){
			if(b[0][n]==b[1][n]&&b[1][n]==b[2][n]){
				if (b[0][n]=='x')
					return 10;
				else if(b[0][n]=='o')	
					return -10;
			}
		}
//check winning condition for main diagonal plus the other diagonal.
	if (b[0][0]==b[1][1] && b[1][1]==b[2][2]){
        	if (b[0][0]=='x')
            		return 10;
        	else if (b[0][0]=='o')
            		return -10;
   		 }
    
    
    	if (b[0][2]==b[1][1] && b[1][1]==b[2][0]){
        	if (b[0][2]=='x')
            		return 10;
        	else if (b[0][2]=='o')
            		return -10;
    	}
 }

 int minimax(char board[3][3], int depth,bool maximiser_turn){
 	int score=ret_score(board);
 	//case1 - the maximiser wins the game
 	if (score==10)
 		return score;
 	//case2 - minimiser wins the game
 	if(score==-10)
 		return score;
 	if(is_boardfull(board)==true)
 		return 0;
 	if(maximiser_turn){
 		int val=-1000;
 		//traverse the board 
 		for(int m=0;m<3;m++){
 		for(int n=0;n<3;n++){
 			if(board[m][n]=='-'){
 				//if board space empty then make the move
 				board[m][n]=player;
 				cout<<"in minimax";
 				print_board(board);
 				val=max(val,minimax(board,depth+1,!maximiser_turn));
 				//remove the first move to explore other possible paths.
 				board[m][n]=='-';
 		
 					}
 				}	
 			}
 		return val;	
 		}
	//now its the minimisers move
	else{
		int val=1000;
		for(int m=0;m<3;m++){
 		for(int n=0;n<3;n++){
 			if(board[m][n]=='-'){ 	
 				board[m][n]=opp;
 				cout<<"in minimax";
 				print_board(board);
 				val=min(val,minimax(board,depth+1,maximiser_turn));
 		board[m][n]='-';
 		}
 	}
 	}
 return val;
 }
}
 		
 		
 		
 		
 
 node*find_opt_move(char board[3][3]){
 	int bestvalue=-100;
 	optimum_move->x=-1;
 	optimum_move->y=-1;
 	//check for an available space on the board .when found the maximiser plays first and we call the minimax function to evaluate the state score.
 	for(int m=0;m<3;m++){
 		for(int n=0;n<3;n++){
 			if(board[m][n]=='-'){
 				board[m][n]=player;
 				//we give false because maximiser already played on line 124.			
 				print_board(board);
 				int state_score=minimax(board,0,false);
 				
 				board[m][n]='-';
 				//the best score (10) would get inserted in the node towards the end.
 				if(state_score>bestvalue){
 					optimum_move->x=m;
 					optimum_move->y=n;
 					
 					bestvalue=state_score;
 				}
 			}
 		}
	} 
cout<<"The value of the ideal move is :"<<bestvalue<<endl;
return optimum_move;	
} 	
 	
 	
 	
 int main(){
 	char board[3][3]={ {'x','o','x'},
 			   {'o','o','x'},
 			   {'-','-','-'},
 			  };
	//(declared globally)node*optimum_move=new node;
 	optimum_move=find_opt_move(board);
 	
 	cout<<"The optimum move is as follows:"<<endl;
 	cout<<"X:"<<optimum_move->x;
 	cout<<endl;
 	cout<<"Y:"<<optimum_move->y;
 	cout<<endl;
 	board[optimum_move->x][optimum_move->y]=player;
 	print_board(board);
 return 0;
 }
 
    
    
				
