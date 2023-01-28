int K;
int logK = 20; //K個先を求めたい時、logK*N個の要素が必要

vector<vector<int>> doubling(logK, vector<int>(N));

for (int i = 0; i < N; i++)｛
	doubling[0][i] = par1[i]
}


    // 前処理 doubling の計算
for (int i = 0; i < logK - 1; i++) {
	for (int j = 0; j < N; j++) {
            doubling[i + 1][j] = doubling[i][doubling[i][j]];
        }
}

for (int i = 0; K > 0; i++) {
   	if (K & 1) now = doubling[i][now]
        K = (K >> 1);
}

cout << now << endl; //K個先の要素はnowです