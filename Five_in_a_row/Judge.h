class Judge:public Board {
friend int WhoWin(int x, int y);
};
int WhoWin(int x, int y) {
	int num = 0;
	for (int l = -1; l <= 1; ++l) {
		for (int m = -1; m <= 1; ++m) {//�˸�����
			if (l != 0 || m != 0) {
				for (int n = 1; n <= 4; ++n) {//������ӵľ���
					if (x + n*l >= 1 && x + n*l <= 15 && y + n*m >= 1 && y + n*m <= 15 && (B[x + n*l][y + n*m]) == B[x][y]) {//�߽�m
						++num;
					}
					else { break; }
				}
				for (int n = -1; n >= -4; --n) {
					if (x + n*l >= 1 && x + n*l <= 15 && y + n*m >= 1 && y + n*m <= 15 && (B[x + n*l][y + n*m]) == B[x][y]) {//�߽�m
						++num;
					}
					else { break; }

				}
			}
		}
		return 0;
	}
}
