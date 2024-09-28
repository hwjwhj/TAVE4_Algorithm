#include <stdio.h>
#include <algorithm>

using namespace std;

// 3�� ���� ���� ���� �ּڰ��� ���ϱ� 
int minimum(const int x, const int y, const int z) {
	int temp = x;
	
	if(temp > y) {
		temp = y;
	}
	
	if(temp > z) {
		temp = z;
	}
	
	return temp;
}
	
int dp(int test) {
	
	// ����� ���� ������ �迭 
	int memo[3] = {0, };

	// ���� �� ������ ������ �迭
	int RGB[3] = {0, };
		
	// ���� RGB ����� ����� �迭 
	int pastRGB[3] = {0, };
	
	// ���� �� ��� �Է�
	scanf("%d %d %d", &RGB[0], &RGB[1], &RGB[2]);
	memo[0] = RGB[0];	memo[1] = RGB[1];	memo[2] = RGB[2];
	 
	for(int i = 1; i < test; i++) {
		// i - 1������ �ּ� ��� ����
		pastRGB[0] = memo[0];
		pastRGB[1] = memo[1];
		pastRGB[2] = memo[2];
		
		// ���� �� ��� �Է�
		scanf("%d %d %d", &RGB[0], &RGB[1], &RGB[2]);

		// i - 1��° ���� i���� ���� ����� ����� ���� memo�� ����  
		memo[0] = RGB[0] + min(pastRGB[1], pastRGB[2]);
		memo[1] = RGB[1] + min(pastRGB[0], pastRGB[2]);
		memo[2] = RGB[2] + min(pastRGB[0], pastRGB[1]);		
	}
	
	// �ּڰ� return	
	return minimum(memo[0], memo[1], memo[2]);
}

int main() {
	// �ʱ� ���� ���� �� �ʱ�ȭ 
	int test = 0;

	// test ���� �Է�
	scanf("%d", &test);
	
	// �ּڰ� ��� 
	printf("%d", dp(test));
}
