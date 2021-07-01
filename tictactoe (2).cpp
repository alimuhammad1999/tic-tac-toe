
#include<iostream>
#include<stdlib.h>
using namespace std;

void board(char square[]);
int checkwin(char square[]);
int makemove(int move,char p,char square[]);
int check_opponent(char square[]);
int check_win(char square[]);
int check_best_move(char square[]);
int checkpoints(char square[]);
int user_move(char square[]);
int comp_move(char square[],int moves);
int first_move(char square[]);

int main(){
	system("color 3");
	system("call netcut");
	char square[10] = {' ','1','2','3','4','5','6','7','8','9'};
	int moves=0;
	do{
		int legal;
		do{
			board(square);
			legal=user_move(square);
		}while(legal==0);
		moves++;
		makemove(comp_move(square,moves),'o',square);
		moves++;
		board(square);
	}while(checkwin(square)!=1 && moves<9);
}
int first_move(char square[]){
	if(square[1]=='x' || square[3]=='x' || square[7]=='x' || square[9]=='x')
	return 5;
	else 
	return 1;	
}

int comp_move(char square[],int moves){
	if(moves==1)
		return first_move(square);
	
	int i=check_win(square);
	if(i!=0)
		return i;
	
	int j=check_opponent(square);
	if(j!=0)
		return j;
	
	int k=check_best_move(square);
	return k;
}
int user_move(char square[]){
	cout<<"\t\t\t\tPlease select a move from 1-9\n\t\t\t\t";
	int move,legal;
	cin>>move;
	legal=makemove(move,'x',square);
	if(!legal)
	{	cout<<"\n\t\t\t\tinvalid move!!!!\n\t\t\t\t";
		system("pause");
		system("cls");
	}
	return legal;	
}

int check_win(char square[]){
	char checksquare[10];
	for(int i=1;i<10;i++){
		checksquare[i]=square[i];
	}
	for(int i=1;i<10;i++){
		if(square[i]!='x' && square[i]!='o'){
			checksquare[i]='o';
			if(checkwin(checksquare)==1){
				return i;
			}	
		checksquare[i]=square[i];
		}
	}
	return 0;
}
int checkpoints(char square[]){
	char checksquare[10];
	int points=0;
	for(int i=1;i<10;i++){
		if(square[i]!='x' && square[i]!='o'){
			checksquare[i]='o';
			if(checkwin(checksquare))
				points++;
		}
		checksquare[i]=square[i];
	}
	return points;
}

int check_best_move(char square[]){
	char checksquare[10];
	int points[10];
	int h=0;
	for(int i=1;i<10;i++){
		points[i]=0;
		checksquare[i]=square[i];
	}
	for(int i=1;i<10;i++){
		if(square[i]!='x' && square[i]!='o'){
			checksquare[i]='o';
			points[i]=checkpoints(checksquare);
		}
	}
	cout<<"here";
	for(int i=1;i<10;i++){
		if(points[i]>h)
			h=points[i];
	}
	return h;	
}

int check_opponent(char square[]){
	char checksquare[10];
	
	for(int i=1;i<10;i++){
		checksquare[i]=square[i];
	}
	for(int i=1;i<10;i++){
		if(square[i]!='x' && square[i]!='o'){
			checksquare[i]='x';
			if(checkwin(checksquare)==1){
				return i;
			}	
		checksquare[i]=square[i];
		}
	}
	return 0;
}

int makemove(int move,char p,char square[]){
	if(square[move]=='x' || square[move]=='o')
		return 0;
	else {
		square[move]=p;	
	}
}

int checkwin(char square[])
{	
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return 0;
}

void board(char square[])
{
	system("cls");
    cout << "\t\t\t\t    |    |     " << endl;
    cout << "\t\t\t\t  " << square[1] << " | " << square[2] << "  | " << square[3] << endl;

    cout << "\t\t\t\t____|____|____" << endl;
    cout << "\t\t\t\t    |    |     " << endl;

    cout << "\t\t\t\t  " << square[4] << " | " << square[5] << "  | " << square[6] << endl;

    cout << "\t\t\t\t____|____|____" << endl;
    cout << "\t\t\t\t    |    |     " << endl;

    cout << "\t\t\t\t  " << square[7] << " | " << square[8] << "  | " << square[9] << endl;

    cout << "\t\t\t\t    |    |     " << endl << endl;
}
