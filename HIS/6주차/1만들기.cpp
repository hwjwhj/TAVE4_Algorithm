#include<iostream>
#include<algorithm>
using namespace std;
int N;
int arr[1000001];

int main() {
	cin >> N;
	arr[1] = 0;
	// i��° ���Ҹ� �����صΰ�, �� ���� ������� ���� ���� ���ϴ� ����
	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i - 1] + 1;
		// ���� �񱳸� 2�� �ϴ°� ��¦ ��Ή�µ�, �ٸ� ����� ������ �ȳ�
		if (i % 2 == 0)
			arr[i] = min(arr[i / 2] + 1, arr[i]);
		if (i % 3 == 0)
			arr[i] = min(arr[i / 3] + 1, arr[i]);
	}
	cout << arr[N] << endl;
}