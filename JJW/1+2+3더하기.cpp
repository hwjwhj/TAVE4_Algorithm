#include <iostream>
using namespace std;
int dp[11]; //n�� ����̸� 11���� �۴�.
int recursive(int n){
    if(n == 1){ // 1�� ����� �� 1 => 1��
        return 1;
    }
    if(n == 2){ // 2�� ����� �� 1+1, 2 => 2��
        return 2;
    }
    if(n == 3){  // 3�� ����� �� 1+1+1, 1+2, 2+1, 3 => 4��
        return 4;
    }
    if(dp[n]){
       return dp[n] = recursive(n-1) + recursive(n-2) + recursive(n-3);
    }
    //N ���� 4�� ��� ���� �Ǹ� ���������� 1,2,3 �� ������ ��� �� ���� �����ϰ� �ȴٸ� �� ����� ������ ��� ����ǰ�
}
int main(){
	ios_base::sync_with_stdio(0);
    int num, n ,result ;
    cin >> num;
    while(num >= 1){
        cin >> n;
        for(int i = 4; i <= n; i++){
        result = recursive(n-1);
    	}
        cout << result << "\n";
        num--;
    }
    return 0;
}
