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
		
		cout<<"\t\t\t-----------------\n\t\t\t";
		for (start2=0;start2<max;start2++){
			SetConsoleTextAttribute(col,start2+1);
			//col_code=2;
			//SetConsoleTextAttribute(col,col_code);
			if(game[start1][start2]==1000) cout<<"|   ";
			else
			col_code=8;
			SetConsoleTextAttribute(col,col_code);
				cout<<"| "<<game[start1][start2]<<" ";
		}
		col_code=1;
		SetConsoleTextAttribute(col,col_code);
		cout << "|"<<endl;
		
	}
	cout<<"\t\t\t-----------------\n";	
	col_code=3;
	SetConsoleTextAttribute(col,col_code);
	//cout<<"\t\tThankyou for Playing the 2048 Game!!";
	cout<<"\n";
	cout<<"Score: "<<score<<endl;
	cout<<"HighScore: "<<high;
}
