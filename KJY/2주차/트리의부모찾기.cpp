#include <iostream>
#include <vector>

using namespace std;

bool visit[100001];
vector<int> tree[100001];
int result[100001];

void dfs(int start) {
	visit[start]=true;
	for(int i=0;i<tree[start].size();i++) {
		int target=tree[start][i];
		if(visit[target]==false){
			result[target]=start;
			dfs(target);
		}
	}
}

int main(void){
	int num;
	int first, second;
	cin >> num;

	for(int i=0;i<num-1;i++) {
		cin >> first >> second;
		tree[first].push_back(second);
		tree[second].push_back(first);
	}

	dfs(1);
	for(int i=2;i<=num;i++)
		cout << result[i] <<'\n';
	return 0;
}