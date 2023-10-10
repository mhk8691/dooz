#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
string name1,name2;
char table[9]= {'1','2','3','4','5','6','7','8','9'};
int nobat=0;
int nobatname=0;


int round1,round2;

void nameplayer() {

	cout<<"Enter name player1 : ";
	PlaySound(TEXT("player1.wav"), NULL, SND_ASYNC);
	getline(cin,name1);

	cout<<"\n";

	cout<<"Enter name player2 : ";
	PlaySound(TEXT("player2.wav"), NULL, SND_ASYNC);
	getline(cin,name2);


}

void tabledooz() {

	cout<<endl<<endl<<endl<<endl<<endl;
	cout<<"                          "<<"player1: "<<name1<<"            player2: "<<name2<<endl;
	cout<<"                          *****************************************"<<endl;
	cout<<"                          *                                       *"<<endl;
	cout<<"                          *                                       *"<<endl;
	cout<<"                          *            "<<table[0]<<"   |   "<<table[1]<<"   |   "<<table[2]<<"          *"<<endl;
	cout<<"                          *         -------|-------|-------       *"<<endl;
	cout<<"                          *            "<<table[3]<<"   |   "<<table[4]<<"   |   "<<table[5]<<"          *"<<endl;
	cout<<"                          *         -------|-------|-------       *"<<endl;
	cout<<"                          *            "<<table[6]<<"   |   "<<table[7]<<"   |   "<<table[8]<<"          *"<<endl;
	cout<<"                          *         -------|-------|-------       *"<<endl;
	cout<<"                          *                                       *"<<endl;
	cout<<"                          *                                       *"<<endl;
	cout<<"                          *                                       *"<<endl;
	cout<<"                          *****************************************"<<endl;


}

char charnobat() {
	if(nobat % 2 == 0) {
		return 'X';
	} else {
		return 'O';
	}
}
string getname() {
	if(nobatname % 2 == 0) {
		return name1;
	} else {
		return name2;
	}
}

void getUserInput() {
	cout<<"                           Enter 1-9 player : ("<<getname()<<" ------> "<<charnobat()<<") : ";
	string input;
	cin>>input;
	int number;

	
		
		if(input.size()>1 || input[0]<=48 || input[0]>=58){
				cout<<"\n";
		cout<<"Error!";
		sleep(3);
		}
		number=	input[0];
		
	if(number>48 &&number <58) {
		number=number-48;
	}


	
	if(table[number-1] != 'X' && table[number-1] != 'O' ) {
		table[number-1] = charnobat();
		}
		
				else {
				cout<<"\n";
		cout<<"Error!";
		sleep(3);
	
		}
	nobat++;
	nobatname++;
	}





void score(char score1) {
	if('X'==score1) {
		round1++;
	} else if('O'==score1) {
		round2++;
	}
}

bool iswin() {
	if(table[0] == table[1] && table[1]==table[2]) {

		score(table[0]);
		return true;

	} else if(table[3]==table[4] && table[4]==table[5]) {
		score(table[3]);
		return true;
	} else if(table[6]==table[7] && table[7]==table[8]) {
		score(table[6]);
		return true;
	} else if(table[0]==table[3] && table[3]==table[6]) {
		score(table[0]);
		return true;
	} else if(table[1]==table[4] && table[4]==table[7]) {
		score(table[1]);
		return true;
	} else if(table[2]==table[5] && table[5]==table[8]) {
		score(table[2]);
		return true;
	} else if(table[0]==table[4] && table[4]==table[8]) {
		score(table[0]);
		return true;
	} else if(table[2]==table[4] && table[4]==table[6]) {
		score(table[2]);

		return true;
	} else {
		return false;
	}
}

bool isFull() {
	int count=0;
	for(int i=0; i<9; i++) {
		if(table[i]=='X' || table[i]== 'O') {
			count++;

		}
	}
	if(count==9 )   {

		return true;

	} else {
		return false;
	}
}

bool isend() {
	if(iswin()==true || isFull()==true) {
		return false;
	} else {
		return true;
	}
}
string getnobat() {
	if(charnobat () == 'X' ) {

		return name2;
	} else {

		return name1;
	}
}

string howiswiner() {
	if(isFull()) {

		return "                          " + name1 + " and " + name2 + " is won! ";
	} else {

		return "                          " + getnobat()+ " is won! " ;

	}

}



void updatetable() {
	table[0]='1';
	table[1]='2';
	table[2]='3';
	table[3]='4';
	table[4]='5';
	table[5]='6';
	table[6]='7';
	table[7]='8';
	table[8]='9';
}

void howiswinerround() {


	cout<<endl<<endl;


	cout<<"                                        ";
	cout<<"Max round:5";
	cout<<endl<<endl;

	cout<<"                                        ";

	cout<<name1<<":"<<round1<<"          "<<name2<<":"<<round2;

	tabledooz();
	if(round1==5 && round1>round2) {


		cout<<"                           "<<name1<<" is won! ";


	} else if(round2==5&& round2>round1) {

		cout<<"                           "<<name2<<" is won! ";
	}
}

int main() {
	system("color F1");


	nameplayer();
	system("cls");

	PlaySound(TEXT("game music.wav"), NULL, SND_ASYNC | SND_LOOP );
	while(round1<5 && round2<5) {
		while(isend()) {
			cout<<endl<<endl;

			cout<<"                                        ";
			cout<<"Max round:5";
			cout<<endl<<endl;

			cout<<"                                  ";

			cout<<name1<<":"<<round1<<"          "<<name2<<":"<<round2;

			tabledooz();
			getUserInput();

			system("cls");

		}
	
		tabledooz();
		cout<<howiswiner();

		sleep(1);


		system("cls");
		updatetable();

	}
		PlaySound(TEXT("win game.wav"), NULL, SND_ASYNC);
		howiswinerround();
		sleep(3);
}








