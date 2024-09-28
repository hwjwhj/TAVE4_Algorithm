#include "iostream"
#include "queue"

using namespace std;

// �Է� : �� �ο�(N), ���� ��ġ ���� K�� ° ���(K)
// ��� : �����ǽ� ������ ���� ��� 
/*
	<������ �� ��> 
	1. ť�� � ������� ��ȯ�� ����
*/

void permutation(int n, int k);

int main() {
	int n, k;
	
	// �� �ο� n �Է� 
	cin >> n;

	// ��� k �Է� 
	cin >> k;
	
	permutation(n, k);
	
	return 0;
}

void permutation(int n, int k) {
	queue<int> q;
	
	int i, j;
	
	for(i = 1; i <= n; i++) {
		q.push(i);
	}
		
	
	cout << '<';
	
	for(j = 0; j < k - 1; j++) {
		q.push(q.front());
		q.pop();
	}
	
	cout << q.front();
	q.pop();
	
	for(i = 1; i < n; i++) {
		for(j = 0; j < k - 1; j++) {
			q.push(q.front());
			q.pop();
		}
		cout << ", ";
		cout << q.front();

		q.pop();
	}
	cout << '>' << endl;
}



