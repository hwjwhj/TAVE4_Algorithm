#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

stack<int> st1;
stack<int> st2;

int cnt = 0;
bool flag = true;

// 
void func(int size) {
	if(size > st1.top()) {
		st1.push(size);
	}
	else if (size < st1.top()) {
		st2.push(size);
	}
	else {
		flag = false;
	}
}

// ���� �ʱ�ȭ 
void clean() {
	while(!st1.empty()) {
		st1.pop();
	}
	while(!st2.empty()) {
		st2.pop();
	}
}

int main() {
	int size;
	
	// �׽�Ʈ ���̽� �Է� 
	int testcase;
	cin >> testcase;
	
	for(int i = 0; i < testcase; i++) {
		// å�� �� �Է�
		int n;
		cin >> n;
		
		cin >> size;
		st1.push(size);
		
		for(int j = 1; j < n; j++) {
			cin >> size;
			func(size);
		}
		
		if(flag == true) {
			cnt = st2.size() + 1;
			cout << cnt << endl;			
		}
		else {
			cnt = 0;
			cout << cnt << endl;
		}
		
		cnt = 0;
		flag = true;
		clean();
	}
	return 0;
}
