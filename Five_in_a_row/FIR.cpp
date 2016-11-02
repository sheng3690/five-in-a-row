#include<iostream>
#include<string>
#include<stdlib.h>
static const char ch[11][4] = { "○","●" };
//函数声明
void PrintBoard();//打印当前棋盘
void DrawBoard();//画第一次的棋盘
int  AddChess(int x, int y);//下棋
int AddChess2(int x, int y);
void Single();
void Double();
int Whowin(unsigned x,unsigned y);
//变量定义
char Board[16][31];//棋盘数组
unsigned int Number_of_player1 = 0;//玩家1棋子数量
unsigned int Number_of_player2 = 0;//玩家2棋子数量
unsigned int Number_of_all = 0;//棋盘上棋子的总数量



//函数定义
void DrawBoard() {//draw chess board

	//画"├", , "┤"
	for (int i = 2; i < 15; ++i) {
		
		Board[i][1] = (char)195;
		
		Board[i][29] = (char)180;
	}
	//画"┬""┴"
	for (int i = 2; i < 31; ++i) {
		++i;
		Board[1][i] = (char)194;
		Board[15][i] = (char)193;
	}
	//画"┌",,"┐","└",,"┘"
	Board[1][1] = (char)218;
	Board[1][29] = (char)191;
	Board[15][1] = (char)192;
	Board[15][29] = (char)217;
	//画"┼"
	for (int i = 2; i < 15; ++i) {
		for (int j = 2; j < 28; ++j) {
			++j;
			Board[i][j] = (char)197;
			
		}
	}
	for (int i = 1; i <= 15; ++i) {
		for (int j = 1; j <= 29; ++j) {
			++j;
			Board[i][j] = (char)196;
		}
	}
	//标数字
	for (int i = 1; i <= 9; ++i) {
		Board[0][2*i-1] = '0' + i;
		Board[i][0] = '0' + i;
	}
	for (int i = 0; i <= 5; ++i) {
		Board[i + 10][0] = '0' + i;
		Board[0][2*i + 19] = '0' + i;
	}
	PrintBoard();
}
void PrintBoard() {
	for (int i = 0; i <= 15; ++i) {
		for (int j = 0; j <= 29; ++j) {
			std::cout << Board[i][j];
		}
		std::cout << std::endl;
	}
}
int  AddChess(int x, int y) {
	if (!Number_of_player1|| (Number_of_player1 <= Number_of_player2)) {
		Board[x][2*y-1] = (char)1;
		system("cls");
		PrintBoard();
		int result = Whowin(x, y);
		if (result == 1) {
			std::cout << "Black win" << std::endl;
			return 1;
		}
		std::cout << "Now white" << std::endl;
		++Number_of_player1;
	}
	else {
		Board[x][2*y-1] = (char)2;
		system("cls");
		PrintBoard();
		int result = Whowin(x, y);
		if (result == 1) {
			std::cout << "White win" << std::endl;
			return 1;
		}
		std::cout << "Now black" << std::endl;
		++Number_of_player2;
	}	
}
int AddChess2(int x, int y) {
	if (!Number_of_player1 || (Number_of_player1 <= Number_of_player2)) {
		Board[x][2*y-1] = (char)1;
		system("cls");
		PrintBoard();
		int result = Whowin(x,y);
		if (result == 1) {
			std::cout << "Black win" << std::endl;
			return 1;
		}
		std::cout << "Now white" << std::endl;
		++Number_of_player1;
	}
	else {
		//加入一个评分系统
		system("cls");
		PrintBoard();
		int result = Whowin(x, y);
		if (result == 1) {
			std::cout << "White win" << std::endl;
			return 1;
		}
		std::cout << "Now black" << std::endl;
		++Number_of_player2;
	}
	++Number_of_all;
}
void Single() {
	std::cout << "Player 1 -- black  Player 2 -- white" << std::endl;
	std::cout << "Add chess like x y. Note space!" << std::endl;
	unsigned x, y;
	while (std::cin >> x >> y) {
		if (Number_of_all < 256) {
			if (x >= 1 && x <= 15 && y >= 1 && y <= 15 && Board[x][2*y-1] != (char)2 && Board[x][2*y-1] != (char)1)
				AddChess(x, y);
			else
				std::cout << "The position was wrong!!Please enter agian!" << std::endl;
		}
		else
			std::cout << "The board is full!" << std::endl;
	}
}
void Double() {
	std::cout << "You -- black  robot -- white" << std::endl;
	std::cout << "Add chess like x y. Note space!" << std::endl;
	unsigned x, y;
	while (std::cin >> x >> y) {
		if (Number_of_all < 256) {
			if (x >= 1 && x <= 15 && y >= 1 && y <= 15 && Board[x][2*y-1] != (char)2 && Board[x][2*y-1] != (char)1)
				AddChess(x, y);
			else
				std::cout << "The position was wrong!!Please enter agian!" << std::endl;
		}
		else
			std::cout << "The board is full!" << std::endl;
	}
}
int Whowin(unsigned x,unsigned y) {
	int num = 0;
	for (int l = -1; l <= 1; ++l) {
		for (int m = -1; m <= 1; ++m) {//八个方向
			if (l != 0 || m != 0) {
				for (int n = 1; n <= 4; ++n) {//走五个子的距离
					if (x + n*l >= 1 && x + n*l <= 15 && y + n*m >= 1 && y + n*m <= 15 && (Board[x + n*l][2*y-1 + n*m]) == Board[x][2*y-1]) {//边界m
						++num;
						std::cout << num << std::endl;
						
					}
					else { break; }
				}
				for (int n = -1; n >= -4; --n) {
					if (x + n*l >= 1 && x + n*l <= 15 && y + n*m >= 1 && y + n*m <= 15 && (Board[x + n*l][2*y-1 + n*m]) == Board[x][2*y-1]) {//边界m
						++num;
					}
					else { break; }
				}
				
				if (num >= 4) {
					return 1;
				}
				else {
					num = 0;
				}
			}
		}
	}
	return 0;
}
int main() {
	DrawBoard();
	std::cout << "Welcome to Five-in-a-row!"<<std::endl;
	std::cout << "Please chosse a modle" << std::endl;
	std::cout << "1.singe  2.double" << std::endl;
	int choice;
	std::cin >> choice;
	switch (choice){
	case 1:Single();
	case 2:Double();
	default:std::cout << "Please enter the number of 1 or 2" << std::endl;


	}
}