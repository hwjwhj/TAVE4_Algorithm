#include <iostream>
#include <utility>		// pair �ڷ��� 
#include <algorithm>

using namespace std;


typedef struct Student {
	string name;
	int a;		// ���� 
	int b;		// ���� 
	int c;		// ���� 
}Student;


bool compare(Student s1, Student s2) {
	if(s1.a != s2.a) {
		// �������� ���� 
		return s1.a > s2.a;
	}
	// ���� ������ ������ 
	else {
		if(s1.b != s2.b) {
			// �������� ���� 
			return s1.b < s2.b;
		}
		// ���� ������ ������ 
		else {
			if(s1.c != s2.c) {
				// �������� ���� 
				return s1.c > s2.c;
			}
			else {
				// ���� ��
				return s1.name < s2.name;
			}
		}
	}
}


int main() {
	int n;

	cin >> n;

	Student student[n];
	for(int i = 0; i < n; i++) {
		cin >> student[i].name >> student[i].a >> student[i].b >> student[i].c;
	}
	
	sort(student, student + n, compare);
	
	for(int i =0; i < n; i++) {
		cout << student[i].name << '\n';
	}
	return 0;
}
