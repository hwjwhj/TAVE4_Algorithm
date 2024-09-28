#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>>v;
int map[8][8];
int tempMap[8][8];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int N, M, ans = 0;

void bfs() {
	// map���� ���̷����� ������ ���� ����ϱ� ����, �ʱ� map�� ���� ����� tempMap�� �����صд�.
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++) {
			tempMap[y][x] = map[y][x];
			if (map[y][x] == 2)
				v.push_back(make_pair(y, x));
		}
	// v�� ���Ҵ� ���̷��� ��ǥ. ���̷��� ��ǥ�� ��� Ȯ���� �� ���� ���鼭, ���̷��� ��ó�� 0 ��ġ�� 2�� ������Ű��, 0 ��ǥ�� v�� push
	while (!v.empty()) {
		int y = v.back().first;
		int x = v.back().second;
		v.pop_back();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
				if (tempMap[ny][nx] == 0) {
					tempMap[ny][nx] = 2;
					v.push_back(make_pair(ny, nx));
				}
			}
		}
	}
	// ���̷����� ��ĵ� tempMap���� 0�� �ش��ϴ� �������� ���� ����
	int cnt = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			if (tempMap[y][x] == 0)
				cnt++;
	if (cnt > ans)
		ans = cnt;
}

void makeWall(int cnt) {
	// cnt = 3�� �Ǵ� ��� ����!
	if (cnt == 3) {
		bfs();
		return;
	}
	// ex) cnt = 0 ,  ��, �� �ϳ��� �� ���� ��� ��� map ���Ҹ� Ž���ϴٰ�
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			// ���� ���� 0 ��ġ ã����
			if (map[y][x] == 0) {
				map[y][x] = 1; // �ӽ÷� ���� ���� ������
				makeWall(cnt + 1); // �� 1�� ���� ��쿡 �ش��ϴ� ��͸� ������
				map[y][x] = 0; // ���� ��Ͱ� ������ ���������� ���� �ӽ÷� ������ ���� 0���� �ٲ㼭 �㹫�� �۾�
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> map[y][x];

	makeWall(0);

	cout << ans << endl;
}

/*
1. ���� �����
2. �� 3�� ���� ���, ���� ���� Ž���� ���� dfs �����ϰ�
3. dfs��� �������� ũ�⸦ ���ؼ� �ִ� ũ�� ���
*/