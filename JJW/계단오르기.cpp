#include <iostream>
#include <algorithm>
using namespace std;
int stair[300]; // ����� 300�� ���� 
int sum[10000]; // ���� �ִ밪 
// �ǵ� ����� �ݵ�� ��ƾ��Ѵ�.
int main(){
	ios_base::sync_with_stdio(0);
	
	int num, i, j; // ����� ���� 
	cin >> num; 
	for(j = 1; j <= num; j++){
		cin >>stair[j];
	}
	 // �� ���� ��� �� �ִ��� �� ��ܱ����� �ִ� ������ �ȴ�.
    // (1) ���� ��� ���, 1 ���� ��� ���, 2 ���� ��� ���� �ʱ�
    // (2) ���� ��� ���, 1 ���� ��� ���� �ʱ�, 2 ���� ��� ���
    
	for(i = 1; i <= num; i++){ //<=�� ����� �Ѵ� 
		if(i == 1){
			sum[1] = stair[1];
		}
		if(i == 2){
			sum[2] = max(stair[1] + stair[2], stair[2]);
		}
		if(i >= 3){
			sum[i] = max(sum[i-2] + stair[i], sum[i-3] + stair[i-1] + stair[i]);
		}
	}
	cout << sum[num] << "\n"; 
	return 0;
}
