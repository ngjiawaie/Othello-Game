#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

char board[8][8];
bool player = true;
bool sp1 =false; 
bool sp2 =false; 
bool move; 
bool stars;
bool check1, check2;

string xy, userchoice,spsp1,spsp2;
void menu();
void map();
void help();
void command();
void status();
void flipping(int,int);
void star();

int aaa (char);
int bbb (int);
int total = 0;
int x1=0, x2=0, y1=0, y2=0;


void menu(){
	system("CLS");
	cout 
	<< "|----------------------------------------------------|\n"
	<< "|                 Super Othello Game                 |\n"
	<< "|----------------------------------------------------|\n"
	<< " 1. New Game.\n"
	<< " 2. Load Game. \n"
	<< " 3. Help.\n"
	<< " 4. Quit.\n"
	<< " 1 or 2 or 3 or 4. \n" 
	<< " Type full of the command also can.\n";

	getline(cin,userchoice);
	for(int i=0; i< userchoice.length(); i++) { 
		userchoice[i] = toupper(userchoice[i]);
	}	

	if ( userchoice == "NEW GAME" || userchoice == "1" ){
	cout << "PLEASE ENSURE THAT YOU HAVE READ THE HELP IN MENU.\n";
	system("pause");
	cout 
	<< "|----------------------------------------------------|\n"
	<< "|               The Super Othello Game               |\n"
	<< "|----------------------------------------------------|\n";

	for (int a=0; a<=7; a++)
	{
		for (int b=0; b<=7; b++)
		{
			board [b][a] = ' ';
		}
	}
	board[3][4] = 'X';
	board[4][3] = 'X';
	board[3][3] = 'O';
	board[4][4] = 'O';
	x1=0, x2=0, y1=0, y2=0;
	player=true;
	sp1 = false;
	sp2 = false;
	map();
	}
	else if (userchoice == "LOAD GAME" || userchoice == "2" ){
		ifstream loadFile;

		loadFile.open ("a.txt", ifstream::in);

		for(int z=0;z<=7;z++){
			for (int v=0;v<=7;v++){
				loadFile.get(board[v][z]);
			}
		}
			loadFile >> x1>>x2>>y1>>y2>>player;
			loadFile.close();
			map();
		}
		else if ( userchoice == "HELP" || userchoice == "3" ){
			help();
		}
		else if ( userchoice == "QUIT" || userchoice == "4" ){
			cout << " End Of Program. \n";
			system("cls");
			exit(0);
		}
}

void help(){
	system("CLS");
	cout 
	<< " __________ Othello is a good game to play __________\n\a"
	<< " 1. X is always moves first.\n\n"
	<< " 2. Once the coordinate has been taken,\n"
	<< "   	the next opponent cant put the same coordinate.\n"
	<< "    User just need to input the coordinate as like 'f 4', then it will fill in. \n\n"
	<< " 3. When it is no longer possible move for either player to move,\n"
	<< "    The game consider end. The solution to end this game is to \n"
	<< "    get as many as possible of your symbols until it is more than your opponent. \n"
	<< "    However, if user1's total is same with user2's total, it will be draw game. \n\n"
	<< " 4. Users are allow to input 'menu' or 'next player' during the game.\n\n"
	<< " 5. The 'menu' that user input during the game allow user go back to menu \n"
	<< "    While 'next player' allow user to change the current playing player. \n "
	<< " 6. However, there are 2 superpowers that user can choose when in game,\n"
	<< "	but user only can use 1 time for each super power. \n\n"
	<< "  a. User require to type 'SP1' to activate super power 1 which is  \n"
	<< "     replace a Opponent's coordinate (which it had been taken),\n"
	<< "	 then on the same row it will become all 'X' Or all 'O'. \n"
	<< "  b. User require to type 'SP2' to activate super power 1 which is\n"
	<< "     user can input 2 times consecutively \n"
	<< " However, the 1st input, user can input anywhere include opponent piece,\n "
	<< " the second input, user only allow to fill in the empty box. \n\n\a";
	system("pause");
	menu();
}


void map(){	
	star();
	system("CLS");
	int count = 8;
	for (int a=0;a<=7;a++)
	{
		cout << " |---+---+---+---+---+---+---+---|\n";
		cout << count--   << "|";
		for (int b=0;b<=7;b++){
			cout << " " << board[a][b] << " |";
		}
		cout << endl;
	}
	cout << " |---+---+---+---+---+---+---+---|\n";
	cout << "   a   b   c   d   e   f   g   h  ";
	status();
	
	if (total != 64)
	{
		command();

	} else {
		total = 0; 
		menu();
	}	
}


void status(){
	int score_X = 0, score_O = 0, validvalid = 0;
	for (int a=0;a<=7;a++)
	{
		for (int b=0;b<=7;b++)
		{
			if (board [b][a] == 'X')
			{
				score_X++;
			}
			else if (board [b][a] == 'O')
			{
				score_O++; 
			}
			if (board [b][a] == '*'){
				validvalid++;
			}
		}
	}

	total = score_X + score_O;
	cout << "\n Score  :      O = " << score_O <<  "        X = "<< score_X << endl;
	cout << " Your Valid Move Choices Have : " << validvalid <<endl;

	if (validvalid == 0){
		if (score_X > score_O)
		{
			cout << " Player X Won \n";
		}
		else if (score_O > score_X)
		{
			cout << " Player O Won \n ";
		}
		else 
		{
			cout << " Draw Game. \n";
		}
		cout << "\a";
		system("pause");
		system("cls");
		exit(0);
	}
	else if (score_X != 0 && score_O != 0)
	{
		if (player==true)
		{
			cout << " Current Player  :\tX \n";
		}
		else if (player==false)
		{
			cout << " Current Player  :\tO \n";
		}
	}
}
	

void flipping(const int a,const int b){
	check1=false; 
	check2=false; 
	int c = b;	
	int d = a;	

	//going north
	if (player == true && board[b+1][a] == 'O'){
		check1=true;
		}
		else if (player == false && board [b+1][a]== 'X'){ 
			check1=true;
	}

	if (check1==true){	
		while(c<7){
			if(board [c+1][a] == ' '){
				break;
			}
			if (player == true){
				if (board[c+1][a] == 'X'){
					check2=true;
					break;
				}
			}
			else if (player == false){
				if (board[c+1][a] == 'O'){
					check2=true;
					break;	
				}	
			}
		c++;
		}
	}

	if(check1 == true && check2==true){
		move = true;
		if (stars == false){
			while (c>b){
			if (player == true){
				board [c][a] = 'X';
			}
			else if (player == false){
				board [c][a] = 'O';
			}
			c--;
			}
		}
	}


	check1 = false, check2 = false, c=b; 
	//going south
	if (player == true && board [b-1][a] == 'O'){
			check1 = true;
			}
			else if (player == false && board [b-1][a] == 'X'){
				check1 = true;
	}

	while(c>0){
		if(board [c-1][a] == ' '){
				break;
			}
		if (player == true){
			if (board [c-1][a] == 'X'){
				check2=true;
				break;	
			}
		}
		else if (player == false){
			 if (board [c-1][a] == 'O'){
				check2=true;
				break;		
			}
		}
		c--;
	}

	if(check1 == true && check2==true){
		move = true;
		if(stars == false){
			while (c<b){
				if (player == true){
					board [c][a] = 'X';
				}
				else if (player == false){
					board [c][a] = 'O';
				}
			c++;
			}
		}
	}

	check1 = false, check2 = false, d=a; 
	//going west

	if (player == true && board [b][a+1] == 'O'){
		check1 = true;
		}
		else if (player == false && board [b][a+1] == 'X'){
				check1 = true;
	}

	if (check1==true){	
		while(d<7){
			if(board [b][d+1] == ' '){
				break;
			}
			if (player == true){
				if (board[b][d+1] == 'X'){
					check2=true;
					break;
				}
			}
			else if (player == false){
				if (board[b][d+1] == 'O'){
					check2=true;
					break;	
				}	
			}
		d++;
		}
	}

	if(check1 == true && check2==true){
		move = true;
		if(stars==false){
			while (d>a){
				if (player == true){
					board [b][d] = 'X';
				}
				else if (player == false){
					board [b][d] = 'O';
				}
			d--;
			}
		}
	}

	check1 = false, check2 = false, d=a; 
	//going east
	if (player == true && board [b][a-1] == 'O'){
			check1 = true;
			}
			else if (player == false && board [b][a-1] == 'X'){
				check1 = true;
	}

	if (check1==true){	
		while(d>0){
			if(board [b][d-1] == ' '){
				break;
			}
			if (player == true){
				if (board[b][d-1] == 'X'){
					check2=true;
					break;
				}
			}
			else if (player == false){
				if (board[b][d-1] == 'O'){	
					check2=true;
					break;	
				}	
			}
		d--;
		}
	}

	if(check1 == true && check2==true){
		move = true;
		if(stars==false){
			while (d<a){
				if (player == true){
					board [b][d] = 'X';
				}
				else if (player == false){
					board [b][d] = 'O';
				}
			d++;
			}
		}
	}


	check1 = false, check2 = false, d=a, c=b; 
	//going northeast
	if (player == true && board [b+1][a-1] == 'O'){
			check1 = true;
			}
			else if (player == false && board [b+1][a-1] == 'X'){
				check1 = true;
	}

	if (check1==true){	
		while(d>0 && c<7){
			if(board [c+1][d-1] == ' '){
				break;
			}
			if (player == true){
				if (board[c+1][d-1] == 'X'){
					check2=true;
					break;
				}
			}
			else if (player == false){
				if (board[c+1][d-1] == 'O'){
					check2=true;
					break;	
				}	
			}
		d--,c++;
		}
	}

	if(check1 == true && check2==true){
		move = true;
		if(stars==false){
			while (d<a && c>b){
				if (player == true){
					board [c][d] = 'X';
				}
				else if (player == false){
					board [c][d] = 'O';
				}
			d++,c--;
			}
		}
	}

	check1 = false, check2 = false, d=a, c=b; 
	//going northwest

	if (player == true && board [b+1][a+1] == 'O'){
			check1 = true;
			}
			else if (player == false && board [b+1][a+1] == 'X'){
					check1 = true;
	}

	if (check1==true){	
		while(c<7 && d<7){
			if(board [c+1][d+1] == ' '){
				break;
			}
			if (player == true){
				if (board[c+1][d+1] == 'X'){
					check2=true;
					break;
				}
			}
			else if (player == false){
				if (board[c+1][d+1] == 'O'){
					check2=true;
					break;	
				}	
			}
		d++,c++;
		}
	}

	if(check1 == true && check2==true){
		move = true;
		if(stars==false){
			while (d>a && c>b){
				if (player == true){
					board [c][d] = 'X';
				}
				else if (player == false){
					board [c][d] = 'O';
				}
			d--,c--;
			}
		}
	}

	check1 = false, check2 = false, d=a, c=b;
	//going southeast
	if (player == true && board [b-1][a-1] == 'O'){
			check1 = true;
			}
			else if (player == false && board [b-1][a-1] == 'X'){
				check1 = true;
	}

	if (check1==true){	
		while(c>0 && d>0){
			if(board [c-1][d-1] == ' '){
				break;
			}
			if (player == true){
				if (board[c-1][d-1] == 'X'){
					check2=true;
					break;
				}
			}
			else if (player == false){
				if (board[c-1][d-1] == 'O'){
					check2=true;
					break;	
				}	
			}
		c--;d--;
		}
	}

	if(check1 == true && check2==true){
		move = true;
		if(stars==false){
			while (c<b && d<a){
				if (player == true){
					board [c][d] = 'X';
				}
				else if (player == false){
					board [c][d] = 'O';
				}
			c++,d++;
			}
		}
	}


	check1 = false, check2 = false, d=a, c=b;
	//going southwest
	if (player == true && board [b-1][a+1] == 'O'){
			check1 = true;
			}
			else if (player == false && board [b-1][a+1] == 'X'){
				check1 = true;
	}

	if (check1==true){	
		while(c>0 && d<7){
			if(board [c-1][d+1] == ' '){
				break;
			}
			if (player == true){
				if (board[c-1][d+1] == 'X'){
					check2=true;
					break;
				}
			}
			else if (player == false){
				if (board[c-1][d+1] == 'O'){
					check2=true;
					break;	
				}	
			}
		c--;d++;
		}
	}

	if(check1 == true && check2==true){
		move = true;
		if(stars==false){
			while (c<b && d>a){
				if (player == true){
					board [c][d] = 'X';
				}
				else if (player == false){
					board [c][d] = 'O';
				}
			c++,d--;
			}
		}
	}
}	


void star(){
	stars = true;
	for(int a=0;a<=7;a++){
		for(int b=0;b<=7;b++){
			move = false;
			if (!(board[b][a]== 'X' || board[b][a]== 'O')){
				flipping(a,b);
				if(move== true){
					board[b][a] = '*';
				}else{
					board[b][a] = ' ';
				}

			}
		}
	}
	stars = false;
}

void command(){
cout 
<< " Special Command : SP1, SP2, MENU, NEXT PLAYER, SAVE, HELP.\n\n"
<< "  SP1 : allow user to input anywhere include opponent's piece,\n"
<< "  	on the same row it will become all 'X' Or all 'O' \n"
<< "  SP2 : the 1st input, user can input anywhere include opponent piece,\n "
<< " 	the second input, user only allow to fill in the empty box. \n";

if (sp1==true)
	cout << " Super Power 1 activated, you can replace one piece of your opponent piece.";
else if (sp2==true)
	cout << " Super Power 2 activated, you may insert 2 inputs consecutively.\n";
cout << "\n ==> ";

getline(cin,xy);
for(int i=0; i< xy.length(); i++) { 
	xy[i] = toupper(xy[i]); }	
	if (xy == "MENU")
	{
		for (int a=0; a<=7; a++) 
		{
			for (int b=0; b<=7; b++)
			{
				board [b][a] = ' ';
			}
		}
		sp1 = false;
		sp2 = false;
		x1=0, x2=0, y1=0, y2=0;
		menu();
	}
	else if (xy == "HELP")
		help();
	else if (xy == "NEXT PLAYER")
	{
		if (player == true)
		{
			player = false;
		}
		else 
		{
			player = true;
			cout  << xy;
		}

		map();
	}
	else if (xy == "SAVE"){
		ofstream saveFile ("a.txt");
		for(int a=0;a<=7;a++){
			for (int b=0;b<=7;b++){
				saveFile << board[b][a];
			}
		}
		saveFile <<x1<<x2<<y1<<y2<<player;
		saveFile.close();  
		cout << "  SAVE SUCCESS \n";
		system("pause");
		cout << endl;
		map();

	}
	else if (xy == "SP1"){
		if (player == true && x1 == 0)
		{
			sp1 = true;
		}
		else if (player == false && y1 == 0){
			sp1 = true;
		}
		else {
			cout << "You had used Super Power 1\n\a";
			system("pause");
		}
		map();
	}
	else if (xy == "SP2"){
		if (player == true && x2 ==0 )
		{
			sp2=true;
		}
		else if (player == false && y2 ==0 )
		{
			sp2=true;
		}
		else {
			cout << "You had used Super Power 2\n\a";
			system("pause");
		}
		map();
	}
	else 
	{	
		istringstream input(xy);
		char a;
		int b;
		input>>a>>b;
		a = aaa(a);
		b = bbb(b);
		flipping(a,b);
		
		if (sp1==true){
			
			if (player == true){
				if(x1 == 0){
					
					for (int a=0;a<=7;a++){
					board[b][a] = 'X';
					}
					player = false;
					x1++;
					sp1 = false;
					
				}
			}
			else if(player == false){
				if(y1 == 0){
					for (int a=0;a<=7;a++){
					board[b][a] = 'O';
					}
					player = true;
					y1++;
					sp1=false;
					
				}
			}

		}
		else if (sp2==true){
			if (player == true){
				if(x2==0){
					
					board[b][a] = 'X';
					x2++;
					
				}

			}
			else if (player==false){
				if(y2==0){
					
					board[b][a] = 'O';
					y2++;
					
				}
			}
			sp2=false;

		}
		else if (move == true){
				if (player == true)
				{
					board[b][a] = 'X';
					player = false;
					move = false;
					
				}
				else if (player == false)
				{
					board[b][a] = 'O';
					player = true;
					move = false;
				}
		}
		else {
			cout << " Invalid input.\n\a";
			system("pause");
		}
	map();
	}


}

int bbb(int b)
{
	switch(b)
	{
		case 1:
		return 7;
		break;
		case 2:
		return 6;
		break;
		case 3:
		return 5;
		break;
		case 4:
		return 4;
		break;
		case 5:
		return 3;
		break;
		case 6:
		return 2;
		break;
		case 7:
		return 1;
		break;
		case 8:
		return 0;
		break;
		default:
		map();
	}	
}

int aaa(char a)
{
	switch(a)
	{
		case 'A':
		return 0;
		break;
		case 'B':
		return 1;
		break;
		case 'C':
		return 2;
		break;
		case 'D':
		return 3;
		break;
		case 'E':
		return 4;
		break;
		case 'F':
		return 5;
		break;
		case 'G':
		return 6;
		break;
		case 'H':
		return 7;
		break;
		default:
		map();
	}
}

int main()
{
	menu();	
	return(0);
}