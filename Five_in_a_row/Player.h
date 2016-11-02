#include<iostream>
#include<string>
#include<vector>

#include"Board.h"
using namespace std;
static const char ch2[2][4] = { "○", "●" };
class Player :public Board {
	//friend void Single();
	//friend void Double();
public:
	int WhoWin(int x, int y);
	void Single();
	void Double();
	void ChooseMode();
	//void ChooseChess();
	void AddChess(int x, int y);
	void AddRobotChess(int x, int y);
	int CheckChess(int x,int y);
	void CheckScore();
	void InitScoreArr();

private:
	int MaxScore = 0;
	int Score = 0;
	int score[16][16] = { 0 };//建立评分矩阵，初始化为0
	//int score = 0;
	unsigned int Number_of_player1 = 0;//玩家1棋子数量
	unsigned int Number_of_player2 = 0;//玩家2棋子数量
	unsigned int Number_of_all = 0;//棋盘上棋子的总数量

};
int Player::CheckChess(int x, int y) {//检查棋子是否合法
	if (x >= 1 && x <= 15 && y >= 1 && y <= 15 && B[x][y] != ch2[0] && B[x][y] != ch2[1]) {
		return 1;
	}
	else
		return 0;
}
void Player::AddRobotChess(int x, int y) {
	/*vector<int> ScoreArr;
	
	for (int l = -1; l <= 1; ++l) {
		for (int m = -1; m <= 1; ++m) {//八个方向
			if (l != 0 || m != 0) {
				for (int n = 1; n <= 4; ++n) {//走五个子的距离
					if (x + n*l >= 1 && x + n*l <= 15 && y + n*m >= 1 && y + n*m <= 15 && (B[x + n*l][y + n*m]) == B[x][y]) {//边界m
						score += 10;
					}
					else if (x + n*l >= 1 && x + n*l <= 15 && y + n*m >= 1 && y + n*m <= 15 && (B[x + n*l][y + n*m]) == ch2[0]){
						score -= 11;
					}
					
				}
				for (int n = -1; n >= -4; --n) {
					if (x + n*l >= 1 && x + n*l <= 15 && y + n*m >= 1 && y + n*m <= 15 && (B[x + n*l][y + n*m]) == B[x][y]) {//边界m
						score += 10;
					}
					else if (x + n*l >= 1 && x + n*l <= 15 && y + n*m >= 1 && y + n*m <= 15 && (B[x + n*l][y + n*m]) == ch2[0]) {
						score -= 11;
					}

				}
				ScoreArr.push_back(score);
				

			}
		}

	}*/
	
	while (!Number_of_player1 || (Number_of_player1 <= Number_of_player2)) {
		B[x][y] = ch2[0];
		system("cls");
		PrintBoard();
		int result = WhoWin(x, y);
		if (result == 1)
			cout << "Black win!" << endl;
		else
			std::cout << "Now white" << std::endl;
		++Number_of_player1;
	}

	while(Number_of_player1>Number_of_player2){
		CheckScore();
		system("cls");
		PrintBoard();
		int result = WhoWin(x, y);
		if (result == 1)
			cout << "White win!" << endl;
		else
			std::cout << "Now black" << std::endl;
		++Number_of_player2;
	}

}
void  Player::AddChess(int x, int y) {
	if (!Number_of_player1 || (Number_of_player1 <= Number_of_player2)) {
		B[x][y] = ch2[0];
		system("cls");
		PrintBoard();
		int result= WhoWin(x, y);
		if (result==1)
			cout << "Black win!" << endl;
		else
			std::cout << "Now white" << std::endl;
		++Number_of_player1;
	}
	else {
		B[x][y] = ch2[1];
		system("cls");
		PrintBoard();
		int result = WhoWin(x, y);
		if (result == 1)
			cout << "White win!" << endl;
		else
			std::cout << "Now black" << std::endl;
		++Number_of_player2;
	}
}
void Player::Single() {
	std::cout << "you -- black  robot -- white" << std::endl;
	std::cout << "Add chess like x y. Note space!" << std::endl;
	unsigned x, y;
	while (std::cin >> x >> y) {
		if (Number_of_all < 256) {
			if (x >= 1 && x <= 15 && y >= 1 && y <= 15 && B[x][y] != ch2[0] && B[x][y] != ch2[1]) {
				AddRobotChess(x, y);

			}
			else
				std::cout << "The position was wrong!!Please enter agian!" << std::endl;
		}
		else
			std::cout << "The board is full!" << std::endl;
	};
}
void Player::Double() {
	std::cout << "Player 1 -- black  Player 2 -- white" << std::endl;
	std::cout << "Add chess like x y. Note space!" << std::endl;
	unsigned x, y;
	while (std::cin >> x >> y) {
		if (Number_of_all < 256) {
			if (x >= 1 && x <= 15 && y >= 1 && y <= 15 && B[x][y] != ch2[0] && B[x][y] != ch2[1]) {
				AddChess(x, y);

			}
			else
				std::cout << "The position was wrong!!Please enter agian!" << std::endl;
		}
		else
			std::cout << "The board is full!" << std::endl;
	}
}
void Player::ChooseMode() {
	cout << "欢迎来到五子棋！" << endl;
	cout << "  1. 单人模式   " << endl;
	cout << "  2. 双人模式   " << endl;
	cout << "   请选择模式： " << endl;
	int choice;
	cin >> choice;
	switch(choice) {
		case 1:Single();//在类中允许一个成员函数调用另外一个成员函数，不用加对象
		case 2:Double();
		default:std::cout << "Please enter the number of 1 or 2" << std::endl;

	}
}
/*
void Player::ChooseChess() {
	cout << "玩家1请选择棋子颜色：　";
	cout << "  1. 黑子   " << endl;
	cout << "  2. 白子   " << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:Single();
	case 2:Double();
	default:std::cout << "Please enter the number of 1 or 2" << std::endl;
	
	}
}
*/
int Player::WhoWin(int x, int y) {
	int num = 0;
	for (int l = -1; l <= 1; ++l) {
		for (int m = -1; m <= 1; ++m) {//八个方向
			if (l != 0 || m != 0) {
				for (int n = 1; n <= 4; ++n) {//走五个子的距离
					if (x + n*l >= 1 && x + n*l <= 15 && y + n*m >= 1 && y + n*m <= 15 && (B[x + n*l][y + n*m]) == B[x][y]) {//边界m
						++num;
					}
					else { break; }
				}
				for (int n = -1; n >= -4; --n) {
					if (x + n*l >= 1 && x + n*l <= 15 && y + n*m >= 1 && y + n*m <= 15 && (B[x + n*l][y + n*m]) == B[x][y]) {//边界m
						++num;
					}
					else { break; }

				}
				if (num == 4)
					return 1;
				else
					num = 0;

			}
		}
	}
}
void Player::InitScoreArr() {
	for (int i = 1; i <= 15; ++i) {
		for (int j = 1; j <= 15; ++j) {
			score[i][j] = 0;
		}
	}

}
void Player::CheckScore() {//评分函数
	InitScoreArr();
	int dnum1 = 0; int dnum2 = 0; int MaxScore = 0;
	for (int i = 1; i <= 15; ++i) {
		for (int j = 1; j <= 15; ++j) {//扫描棋盘上的所有点
			if (B[i][j] != ch2[0] && B[i][j] != ch2[1]) {//判断是否有子

				for (int l = -1; l <= 1; ++l) {
					for (int m = -1; m <= 1; ++m) {//八个方向,可改进为四个方向试试
						if (l != 0 || m != 0) {//排除原点

							for (int n = 1; n <= 4; ++n) {//再走4个子的距离

								if (i + n*l >= 1 && i + n*l <= 15 && j + n*m >= 1 && j + n*m <= 15 && (B[i + n*l][j + n*m]) == ch2[0]) {//在该方向上第一个子若是黑子
									dnum1 += 1;
								}
								else if (i + n*l >= 1 && i + n*l <= 15 && j + n*m >= 1 && j + n*m <= 15 && (B[i + n*l][j + n*m]) == ch2[1]) {
									dnum2 += 1;
								}
								else
									break;

							}
							for (int n = -1; n >= -4; --n) {//走五个子的距离
								if (i + n*l >= 1 && i + n*l <= 15 && j + n*m >= 1 && j + n*m <= 15 && (B[i + n*l][j + n*m]) == ch2[0]) {//边界m
									dnum1 += 1;
								}
								else if (i + n*l >= 1 && i + n*l <= 15 && j + n*m >= 1 && j + n*m <= 15 && (B[i + n*l][j + n*m]) == ch2[1]) {
									dnum2 += 1;
									
								}
								else
									break;
							}
							if (dnum1 == 1) {
								score[i][j] = 10;
							}
							if (dnum1 == 2) {
								if(dnum2==0)
									score[i][j] = 20;
								else
									score[i][j] = 19;
							}
							if (dnum1 == 3) {
								if (dnum2 == 0)
									score[i][j] = 30;
								else
									score[i][j] = 29;
							}
							if (dnum1 == 4) {
								if (dnum2 == 0)
									score[i][j] = 40;
								else
									score[i][j] = 39;
							}
							if (dnum2 == 1) {
								if(i<5||j<5||i>10||j>10)
									score[i][j] = -1;
								else
									score[i][j] = 2;
							}
							if (dnum2 == 2) {
								score[i][j] = 25;
							}
							dnum1 = 0;
							dnum2 = 0;


						}
					}
				}
			}

		}
	}
	for (int i = 1; i <= 15; ++i) {
		for (int j = 1; j <= 15; ++j) {
			if (score[i][j] > MaxScore)
				MaxScore = score[i][j];
		}
	}
	for (int i = 1; i <= 15; ++i) {
		for (int j = 1; j <= 15; ++j) {
			if (score[i][j] == MaxScore && B[i][j] != ch2[0] && B[i][j] != ch2[1]) {
				B[i][j] = ch2[1];
				return;
			}
			

		}
		
	}
}





