#include "iostream"
#include "stack"

using namespace std;

// �Է� : ��ȣ 
// ��� :  �߸� �踷��� ������ ���� 
// �ִ� time cost : 1��
// �ִ� memory cost : 256MB
/*
	<������ �� ��>
	1. ���ڿ� �˻縦 �� �� ��ȣ ���°� '������'���� Ȯ�� => ���ÿ� ��ȣ�� �ִ� ���� �ƴ� �ε����� �������ν� Ȯ���ϱ�
	2. �������� �� ����⸦ �ڸ� ��, �� �߸� �踷��� ���� ������ ��� ������� 
*/
int counting(string str);

int main() {
	string input_value;
	
	cin >> input_value;
	
	cout << counting(input_value) << endl;
	
	return 0;
}

int counting(string str) {
	stack<int> s;		// �ε���(index)�� ������ �ڷ���
	int cnt = 0;		// �� �踷��� ������ ������ ����
	
	// ()(((()())(())()))(())
	for(int i = 0; i < str.length(); i++) {
		if(str.at(i) == '(') {
			s.push(i);
		}
		else {
			// �������̸� 
			if((i - 1) == s.top()) {
				s.pop();
				cnt += s.size();
			}
			// �踷����� �������̸�
			else {
				s.pop();
				cnt += 1;
			}
		}
	}
	
	return cnt;
}


