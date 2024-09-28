#include<iostream>
#include<queue>
using namespace std;
int n, m, h;
int map[101][101];
int check[101][101];
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; // up , down, left, right check
void BFS(int,int); 

int main(){
	cin>> n >> m;//input, �� ǥ �� 
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j++){
			cout <<map[i][j];
			}
		}	
	BFS(0,0);
	cout << check[n-1][m-1] << endl;
	return 0;
}
void BFS(int x, int y){
	queue<pair<int,int> >q;
	q.push(pair<int, int>(x,y)); //2���� ������ ���� �� �� �ִ� ���� 
    check[x][y] = 1; //bfs�� �������鼭 ���° ���� ������ �����ߴ��� 
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
    for(int i = 0; i<4; i++){//�����¿� �׹��� Ž��
    		int nx = x + d[i][0];
            int ny = y + d[i][1];
            if(0<=nx && nx<n && 0<= ny && ny<m){
                if(check[nx][ny]==0&&map[nx][ny]==1){
                    q.push(make_pair(nx,ny));// ������ �湮�� �� push 
                    check[nx][ny] = check[x][y] + 1;// ���� �湮�� +1 = �����湮
                }
                else if(check[nx][ny]==0)
                    check[nx][ny] = -1;
            }
	}	
}
}



