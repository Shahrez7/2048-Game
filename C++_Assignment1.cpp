#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;
const int GameSize=4;
int score;
int high=0;
void board(int game[GameSize][GameSize]){
	int max=GameSize;
	int start1;
	int start2;
	HANDLE col;
	col= GetStdHandle(STD_OUTPUT_HANDLE);
	int col_code;
	cout<<"Up/Down/Left/Right"<<endl;
	
	for(start1=0;start1<max;start1++){
		SetConsoleTextAttribute(col,start1+1);
		
		cout<<"\t\t\t  ----------------------------------\n\t\t\t";
		for (start2=0;start2<max;start2++){
			SetConsoleTextAttribute(col,start2+1);
			col_code=2;
			SetConsoleTextAttribute(col,col_code);
			//if(game[start1][start2]>100) cout<<"|   ";
			//if(game[start1][start2]>1000) cout<<"|    ";
			//else{
			
			col_code=8;
			SetConsoleTextAttribute(col,col_code);
				cout<<"  |   "<<game[start1][start2]<<" ";}
		//}
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
		newnumberrow=rand()%4;
		newnumbercol=rand()%4;
		srand(time(0));
		if(game[newnumberrow][newnumbercol]==0){
		
		while(1){
		
		newnumber=rand()%3+2;	
		if (newnumber==2){
			    break;
			}
		
		else{
			newnumber=4;
			    break;
			}	
		}
					
		game[newnumberrow][newnumbercol]=newnumber;
		break;
		
		}
	}

}
void Up(int game[GameSize][GameSize]){
	int a,b,c;
	for(b=0;b<GameSize;b++){
		int row=0;
		for(a=0;a<GameSize;a++){
			if (game[a][b]!=0){
				game[row][b]=game[a][b];
				if(row!=a){
					game[a][b]=0;
				}
				row++;
			}
		}
			for(c=0;c<3;c++){
			
			if (game[c][b]==game[c+1][b]){
				game[c][b]=game[c][b]*2;
				game[c+1][b]=0;
				score=score+game[c][b];
			
			}
		}			
		
	}
}
void Down(int game[GameSize][GameSize]){
	int a,b,c;
	for(b=0;b<GameSize;b++){
		int row=3;
		for(a=3;a>=0;a--){
			if (game[a][b]!=0){
				game[row][b]=game[a][b];
				if(a!=row){
					game[a][b]=0;
				}
				row--;
			}
		}
		for(c=3;c>0;c--){
		
			if (game[c][b]==game[c-1][b]){
				game[c][b]=game[c][b]*2;
				game[c-1][b]=0;
				score=score+game[c][b];
			}
		}
				
		
	}
}
void Right(int game[GameSize][GameSize]){
	int a,b,c;
	for(b=0;b<GameSize;b++){
		int row=3;
		for(a=3;a>=0;a--){
			if (game[b][a]!=0){
				game[b][row]=game[b][a];
				if(row!=a){
					game[b][a]=0;
				}
				row--;
			}
		}
		for (c=3;c>0;c--){
		
		
			if (game[b][c]==game[b][c-1]){
				game[b][c]=game[b][c]*2;
				game[b][c-1]=0;
				score=score+game[b][c];
			}
		}
				
		
	}
}
void Left(int game[GameSize][GameSize]){
	int a,b,c;
	for(b=0;b<GameSize;b++){
		int row=0;
		for(a=0;a<GameSize;a++){
			if (game[b][a]!=0){
				game[b][row]=game[b][a];
				if(row!=a){
					game[b][a]=0;
				}
				row++;
			}
		}
		for(c=0;c<3;c++)
			if (game[b][c]==game[b][c+1]){
				game[b][c]=game[b][c]*2;
				game[b][c+1]=0;
				score=score+game[b][c];
			}
				
		
	}
}
int Over(int game[GameSize][GameSize]){
	int x,y;
	for (x=0;x<GameSize;x++){
		for (y=0;y<GameSize;y++){
			if(game[x][y]==2048){
				cout<<"Congratulations You Won the 2048 Game"<<endl;
				return 1;
			}
			if(game[x][y]==0){
				return 0;
			}
			if(game[x][y]==game[x][y+1]){
				if(y!=3){
					return 0;
				}
			}
			if(game[x][y]==game[x+1][y]){
				if(x!=3){
					return 0;
				}
			}
		}
	}
	cout<<"No Tiles Left"<<endl;
	return 1;
}
int main(){
	int g[GameSize][GameSize]={0};
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
	board(g);
	
	int ch;
	int check;
	while(check!=1){
		
    	ch=getch();
    	system("cls");
    	if (ch==72){
    		Up(g);
    		newnum(g);
    		
		}
		else if (ch==80){
    		Down(g);
    		newnum(g);
    		
		}
		else if (ch==75){
    		Left(g);
    		newnum(g);
		}
		else if (ch==77){
    		Right(g);
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
		main();
	}
	else{
		exit(0);
	}
	
		
	}
	else if( option!=1 && option!=2 && option!=3){
		cout<<"Invalid Input"<<endl;
		cout<"\n\n\n";
		main();
	}
	
	
	
	



}

