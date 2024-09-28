/*
1, 2�� ° �ð��ʰ� : endl ��� "\n" ����ؾ��Ѵ�.
					 �ð������� 1�ʷ� �ſ� ª�� ����.
					 + ��� ���� ������ 100,000�� �ſ� ũ�� ������, 2�� �迭�� �Ұ����ϴ�.
3�� ° Ʋ�Ƚ��ϴ� : bfs�� ���� �Ĳ��� ����ߵǴµ� �߸ŷ� 1�� �迭�� ��ġ������..
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
vector<int> v[100001];
queue<int> tempBfs;
bool visited[100001];
int parent[100001];

void bfs(int start);

// bfs�� ���� ���� ���̿� �ִ� ������ �����ϱ� ���� ��� ������ queue�� �־ ���Լ����ϵ��� �Ѵ�.
void bfs2() {
	while (!tempBfs.empty()) {
		int temp = tempBfs.front();
		tempBfs.pop();
		bfs(temp);
	}
}

void bfs(int start) {
	visited[start] = 1;
	while (!v[start].empty()) {
		int next = v[start].back();
		v[start].pop_back();
		if (!visited[next]) {
			parent[next] = start;
			tempBfs.push(next);
		}
	}
	bfs2();
}

int main() {
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	bfs(1);
	for (int i = 2; i <= N; i++)
		cout << parent[i] << "\n";
}

/*
���μ��� ������
// vector �迭�� ���� ����� ��带 ��� �Է�
1 6 -> v[1] = {6}, v[6] = {1}
6 3 -> v[1] = {6}, v[6] = {1, 3}, v[3] = {6}
3 5	-> v[1] = {6}, v[6] = {1, 3}, v[3] = {5, 6}, v[5] = {3}
...
// 1�� ������ �����̹Ƿ� 1�� ������ ����� ��� ��带 bfs�� Ž��
v[1] = {4, 6}
v[2] = {4}
v[3] = {5, 6}
v[4] = {1, 2, 7}
v[5] = {3}
v[6] = {1, 3}
v[7] = {4}

// Ž���� ��, bfs ������ ���� visited�� true�� �ٲٰ�, 
// ����� ��� �߿� visited[next]�� false�� ��� parent[next] = start�� �������ش�.
1���� �� Ȯ�� (visited[1] = 1)
1
4		6
-> 4�� 6�� bfs�� Ȯ�� (visited[4], visited[6] = 1)
					  (parent[4] = 1, parent[6] = 1)
4		6
2, 7	3
-> 2, 7, 3�� bfs�� Ȯ�� (visited[2], visited[3], visited[7] = 1)
						(parent[2] = 4, parent[3] = 6, parent[7] = 4)
2		7		3
.		.		5
-> 5�� bfs�� Ȯ�� (visited[5] = 1)
					(parent[5] = 3)
*/