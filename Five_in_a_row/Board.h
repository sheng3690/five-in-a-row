#include<iostream>
#include<string>

static const char ch[9][4] = { "┌","┬","┐","├","┼","┤","└","┴","┘" };
std::string B[16][16];
class Board {
public:
	void PrintBoard();//打印当前棋盘
	void initBoard();//画第一次的棋盘
	
};
void Board::PrintBoard() {
	for (int i = 0; i <= 15; ++i) {
		for (int j = 0; j <= 15; ++j) {
			std::cout << B[i][j];
		}
		std::cout << std::endl;
	}
}
void Board::initBoard() {//draw chess board
				  //标数字
	B[0][0] = "  ";
	B[0][1] = "1 ";
	B[0][2] = "2 ";
	B[0][3] = "3 ";
	B[0][4] = "4 ";
	B[0][5] = "5 ";
	B[0][6] = "6 ";
	B[0][7] = "7 ";
	B[0][8] = "8 ";
	B[0][9] = "9 ";
	B[0][10] = "10";
	B[0][11] = "11";
	B[0][12] = "12";
	B[0][13] = "13";
	B[0][14] = "14";
	B[0][15] = "15";
	B[1][0] = "1 ";
	B[2][0] = "2 ";
	B[3][0] = "3 ";
	B[4][0] = "4 ";
	B[5][0] = "5 ";
	B[6][0] = "6 ";
	B[7][0] = "7 ";
	B[8][0] = "8 ";
	B[9][0] = "9 ";
	B[10][0] = "10";
	B[11][0] = "11";
	B[12][0] = "12";
	B[13][0] = "13";
	B[14][0] = "14";
	B[15][0] = "15";


	for (int i = 2; i < 15; ++i) {
		B[1][i] = ch[1];
		B[i][1] = ch[3];
		B[15][i] = ch[7];
		B[i][15] = ch[5];
	}
	B[1][1] = ch[0];
	B[1][15] = ch[2];
	B[15][1] = ch[6];
	B[15][15] = ch[8];
	for (int i = 2; i < 15; ++i) {
		for (int j = 2; j < 15; ++j) {
			B[i][j] = ch[4];
		}
	}
	PrintBoard();
}


