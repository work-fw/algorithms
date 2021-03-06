// 20180601 memory 34372kb, time 264ms, code 1522b
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int n, m;
int board[1000][1000];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
	
			cin >> board[i][j];
		
		}
	}

	queue<pair<int, int>> buffer;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1) {
				buffer.push(pair<int, int>(i, j));
			}
		}
	}

	while (buffer.size() != 0) {
		auto it = buffer.front();
		buffer.pop();

		for (int i = 0; i < 4; i++) {
			int tmpx = it.first + dx[i];
			int tmpy = it.second + dy[i];
			if (tmpx >= 0 && tmpy >= 0 && tmpx < n&&tmpy < m) {
				if (board[tmpx][tmpy] == 0) {
					board[tmpx][tmpy] = board[it.first][it.second] + 1;
					buffer.push(pair<int, int>(tmpx, tmpy));
				}
			}
		}
	}

	
	int curr = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] > curr) curr = board[i][j];
			if (board[i][j] == 0) curr = 99999999;
		}
	}
	if (curr == 99999999) cout << "-1" << endl;
	else cout << curr-1 << endl;
}
