#include<iostream>
using namespace std;
int N, cnt;
char map[101][101];
int visited[101][101];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void refresh() {
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			visited[y][x] = 0;
	cnt = 1;
}

void RtoG() {
	for(int y=0; y<N; y++)
		for (int x = 0; x < N; x++)
			if (map[y][x] == 'R')
				map[y][x] = 'G';
}

void dfs(int y, int x) {
	visited[y][x] = cnt;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
			if (visited[ny][nx] == 0 && map[ny][nx] == map[y][x])
				dfs(ny, nx);
		}
	}
}

int main() {
	cin >> N;
	int temp;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> map[y][x];
	refresh();
	for(int y=0; y<N; y++)
		for(int x=0; x<N; x++)
			if (visited[y][x] == 0) {
				dfs(y, x);
				cnt++;
			}
	cout << cnt - 1 << endl;
	RtoG();
	refresh();
	for(int y=0; y<N; y++)
		for(int x=0; x<N; x++)
			if (visited[y][x] == 0) {
				dfs(y, x);
				cnt++;
			}
	cout << cnt - 1 << endl;
}

/*
1. N, map �Է�
2. map, cnt �ʱ�ȭ
3. ��� map ���ҿ� ���� visited[][]�� 0�� ��� dfs ȣ���ϰ� cnt�� �߰�
4. dfs �Լ������� y, x�� ����� ��� ���Ҹ� Ž���ϸ� cnt �ο�
*/