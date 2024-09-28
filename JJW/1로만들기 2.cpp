#include<iostream>
using namespace std;
int dp[1000001];
int one(int num) {	
	int k; //���� Ƚ ��  TOP-DOWN ��� 
	if (num == 1){ 
		return 0;
	}
	dp[num] = one(num - 1) + 1; //num - 1�� �⺻������ ��� ���� ���� ������ѳ��� ����
	if (num % 3 == 0){
		k = one(num/3) + 1;
		if (dp[num] > k) //�ּڰ��� ���ϱ� ���ؼ� ���� ���ϰ� �ٽ� ���� 
		{
			dp[num] = k;
		}
	}
	if (num % 2 == 0)
	{
		k = one(num/2) + 1;
		if (dp[num] > k){
			dp[num] = k;
		}
	}
	return dp[num];
}

int main(){
	ios_base::sync_with_stdio(0);
	int num;
	cin >> num;
	cout << one(num) <<"\n";
	
	return 0;
}


