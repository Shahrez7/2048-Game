#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;
const int GameSize=4; //size of grid 
int score;
int high=0;
void board(int game[GameSize][GameSize]){ //function just for outputting like a board
	int max=GameSize;
	int start1;
	int start2;
	HANDLE col;
	col= GetStdHandle(STD_OUTPUT_HANDLE); //to add colours
	int col_code;
	cout<<"Up/Down/Left/Right"<<endl;
	
	for(start1=0;start1<max;start1++){
		SetConsoleTextAttribute(col,start1+1);
		
		cout<<"\t\t\t  ----------------------------------\n\t\t\t";
		for (start2=0;start2<max;start2++){
			SetConsoleTextAttribute(col,start2+1);
			col_code=2;
			SetConsoleTextAttribute(col,col_code);
			col_code=8;
			SetConsoleTextAttribute(col,col_code);
				cout<<"  |   "<<game[start1][start2]<<" ";}
		
		col_code=1;
		SetConsoleTextAttribute(col,col_code);
		cout << "   |"<<endl;
		
	}
	cout<<"\t\t\t  ----------------------------------\n";	
	col_code=3;
	SetConsoleTextAttribute(col,col_code);
	//cout<<"\t\tThankyou for Playing the 2048 Game!!";
	cout<<"\n";
	cout<<"Score: "<<score<<endl;
	cout<<"HighScore: "<<high;
}
void newnum(int game[GameSize][GameSize]){
	int newnumberrow,newnumbercol,newnumber;
	
	
	while(1){
		newnumberrow=rand()%4; //random row
		newnumbercol=rand()%4; //random column
		srand(time(0)); //random seed
		if(game[newnumberrow][newnumbercol]==0){ //if that point is empty
		
		while(1){
		
		newnumber=rand()%3+2;	 //number between 2 to 4
		 
		if (newnumber==2){
			    break;
			}
			
		else{
			newnumber=4;
			    break;
			}	
		}
					
		game[newnumberrow][newnumbercol]=newnumber; //setting new number
		break;
		
		}
	}

}
void Up(int game[GameSize][GameSize]){
	int a,b,c;
	for(b=0;b<GameSize;b++){ //through each column 
		int row=0; //setting row index to 0
		for(a=0;a<GameSize;a++){ //iterating through each element
			if (game[a][b]!=0){ //if point not empty
				game[row][b]=game[a][b]; //move it up i.e current row
				if(row!=a){
					game[a][b]=0; //setting it 0 if row index is differentm
				}
				row++;
			}
		}
			for(c=0;c<3;c++){ //for merging adjacent tiles
			
			if (game[c][b]==game[c+1][b]){ //if two adjacent tiles are same, merge them and set value
				game[c][b]=game[c][b]*2;
				game[c+1][b]=0;
				score=score+game[c][b]; //update score
			
			}
		}			
		
	}
}
void Down(int game[GameSize][GameSize]){
	int a,b,c;
	for(b=0;b<GameSize;b++){ //iterating through each column
		int row=3; //setting row to 3
		for(a=3;a>=0;a--){ //iterating through each element in reverse order
			if (game[a][b]!=0){ //if point not empty
				game[row][b]=game[a][b]; //move it down
				if(a!=row){
					game[a][b]=0; //set it 0 if row index is different
				}
				row--;
			}
		}
		for(c=3;c>0;c--){
		
			if (game[c][b]==game[c-1][b]){ //merging adjacent tiles 
				game[c][b]=game[c][b]*2; //if two are same merge them
				game[c-1][b]=0;
				score=score+game[c][b]; //update score
			}
		}
				
		
	}
}
void Right(int game[GameSize][GameSize]){
	int a,b,c;
	for(b=0;b<GameSize;b++){ //iterating each row grid
		int row=3; //setting row as 3
		for(a=3;a>=0;a--){ //iterating each element in reverse order 
			if (game[b][a]!=0){ //if point not empty 
				game[b][row]=game[b][a]; //move right 
				if(row!=a){
					game[b][a]=0; //set 0 
				}
				row--;
			}
		}
		for (c=3;c>0;c--){  //merge adjacent tiles 
		
		
			if (game[b][c]==game[b][c-1]){ //if same value
				game[b][c]=game[b][c]*2; //merge and double 
				game[b][c-1]=0;
				score=score+game[b][c]; //update score 
			}
		}
				
		
	}
}
void Left(int game[GameSize][GameSize]){
	int a,b,c;
	for(b=0;b<GameSize;b++){ //iterate each row
		int row=0;
		for(a=0;a<GameSize;a++){ //iterate each element in row 
			if (game[b][a]!=0){//if current tile not empty
				game[b][row]=game[b][a];  //move left 
				if(row!=a){
					game[b][a]=0; //set 0 
				}
				row++;
			}
		}
		for(c=0;c<3;c++) //merging values 
			if (game[b][c]==game[b][c+1]){ //if adjacent tiles same 
				game[b][c]=game[b][c]*2; //merge and double 
				game[b][c+1]=0;
				score=score+game[b][c]; //update score 
			}
				
		
	}
}
int Over(int game[GameSize][GameSize]){
	int x,y;
	for (x=0;x<GameSize;x++){
		for (y=0;y<GameSize;y++){
			if(game[x][y]==2048){ //if players makes 2048 
				cout<<"\nCongratulations You Won the 2048 Game"<<endl;
				return 1; //wins
			}
			if(game[x][y]==0){
				return 0; //if empty tile, game not over yet
			}
			if(game[x][y]==game[x][y+1]){
				if(y!=3){ //if two adjacent have same value in same row 
					return 0; //game not over 
				}
			}
			if(game[x][y]==game[x+1][y]){
				if(x!=3){ //if two adjacent have same value in the same column
					return 0; //game not over 
				}
			}
		}
	}
	cout<<"No Tiles Left"<<endl;
	return 1; //game over 
}
int main(){
	int g[GameSize][GameSize];
	for (int row=0;row<4;row++){
		for (int col=0;col<4;col++){
			g[row][col]=0;
		}
	}
	HANDLE col;
	col= GetStdHandle(STD_OUTPUT_HANDLE);
	int col_code;
	SetConsoleTextAttribute(col,1);
	
	int again;
	int option;
	cout<<"---------- WELCOME TO 2048 GAME ----------"<<endl;
	SetConsoleTextAttribute(col,2);
	cout<<"---------- SELECT FROM THE OPTIONS BELOW ----------"<<endl;
	SetConsoleTextAttribute(col,3);
	cout<<"1)START THE GAME\t 2)INSTRUCTIONS\t     \t3)QUIT\t"<<endl;
	cin>>option;
	if (option==3){
		exit(0);
	}
	if (option==2){
		cout<<"1. Slide the grid left, right, up,down to merge tiles. "<<endl;
		cout<<"2. When two same number merge, they merge into one. "<<endl;
		cout<<"3. Create 2048 tile and Win the Game. "<<endl;
		cout<<"\n\n\n\n\n";
		main();
		
	}
	if (option==1){
		
	newnum(g);
	newnum(g);
	system("cls");
	//g[0][0]=2048;
	board(g);
	
	
	int ch;
	int check;
	while(check!=1){
		check=Over(g);
    	ch=getch();
    	system("cls");
    	if (ch==72){
    		Up(g);
    		check=Over(g);
    		newnum(g);
    		
		}
		else if (ch==80){
    		Down(g);
    		check=Over(g);
    		newnum(g);
    		
		}
		else if (ch==75){
    		Left(g);
    		newnum(g);
		}
		else if (ch==77){
    		Right(g);
    		check=Over(g);
    		newnum(g);
		}
		
		board(g);
		check=Over(g);
		if (check==1){
			cout<<"GAME OVER !!!"<<endl;
			break;
		}
	
		
	}
	if (score>=high){
        high=score;
        
    }
    
	cout<<"Game Finished"<<endl;
	cout<<"Final Score: "<<score<<endl;
	cout<<"High Score: "<<high<<endl;
	
	cout<<"Do you want to play again? Enter 1 for Yes or 2 for No."<<endl;
	cin>>again;
	if (again==1){
		score=0;
		system("cls");
		main();
	}
	else{
		exit(0);
	}
	}
	else if( option!=1 && option!=2 && option!=3){
		cout<<"Invalid Input"<<endl;
		cout<<"\n\n\n";
		main();
	}
	
	return 0;
}

