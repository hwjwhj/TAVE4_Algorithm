#include<iostream>
#include<queue>
using namespace std;
int N, M, V;
bool visited[1001][1001];
/*
�Է� ������ ���ĵ����� �ʱ� ������,
vector, queue ���� ����ϸ� ���� ������ �߰��� �ʿ�
�׿� ����, 2�� ����� Ư���� �ڵ� ���ĵǹǷ� ����
*/
int map[1001][1001];
/*
������ �� �������δ� bfs�� ���� ������ queue�� �����
���� ��������
*/
queue<int>q;

void setZero() {
	for (int y = 0; y <= N; y++)
		for (int x = 0; x <= N; x++)
			map[y][x] = 0;
}

void refresh() {
	for (int y = 0; y <= N; y++)
		for (int x = 0; x <= N; x++)
			visited[y][x] = false;
	cout << "\n" << V << " ";
}

/*
dfs������ �ڷᱸ���� ������� ����.
��, for���� ���� �� ������ �����

y���� start�� ���� ���� �� ���� 1�� �༮�鿡�� ��������� �湮.
�������� dfs�� ���� ������ �ȴ�.

visited[a][b]�� a�� b�� ������ Ž���ߴ��� ���θ� ���
visited[a][a]�� a��� ��尡 �̹� Ž���� �Ϸ�Ǿ����� ���θ� ���
*/

void dfs(int start) {
	cout << start << " ";
	visited[start][start] = true;
	for (int i = 1; i <= N; i++) {
		if (map[start][i] == 1 && !visited[start][i] && !visited[i][i]) {
			visited[start][i] = true;
			visited[i][start] = true;
			visited[i][i] = true;
			dfs(i);
		}
	}
}

/*
dfs�� ���������� y���� start�� ���� ���� �� ���� 1�� �༮����
��������� �湮�ϴ� ���� �ƴ϶�, ��¸� ��Ű�� queue�� �־�ξ��ٰ�
�װ͵鿡 ���� ���Լ��� ������ �װ͵��� �ڽĿ� �湮��.
*/

void bfs(int start) {
	visited[start][start] = true;
	for (int i = 1; i <= N; i++) {
		if (map[start][i] == 1 && !visited[start][i] && !visited[i][i]) {
			visited[start][i] = true;
			visited[i][start] = true;
			visited[i][i] = true;
			cout << i << " ";
			q.push(i);
		}
	}
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		bfs(n);
	}
}

int main() {
	int t1, t2;
	cin >> N >> M >> V;
	setZero();
	for (int i = 0; i < M; i++) {
		cin >> t1 >> t2;
		map[t1][t2] = 1;
		map[t2][t1] = 1;
	}
	dfs(V);
	refresh();
	bfs(V);
}