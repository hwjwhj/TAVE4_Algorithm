#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> v;

bool comp(string a, string b) {
	// �� ������ ���̰� ������� ���������� ��ȯ
	if (a.size() == b.size())
		return a < b;
	// �� ������ ���̰� �ٸ���� ���̼����� ��ȯ
	return a.size() < b.size();
}

int main() {
	int N;
	string tempS;
	cin >> N;
	// �Էºκ�
	for (int i = 0; i < N; i++) {
		cin >> tempS;
		v.push_back(tempS);
	}

	// ���� ���̺귯�� ���
	// comp�� ���� ��Ģ �Լ�
	sort(v.begin(), v.end(), comp);

	// �ߺ� �����ϰ� ���
	for (int i = 0; i < v.size(); i++) {
		if (i > 0 && v[i - 1] == v[i])
			continue;
		cout << v[i] << endl;
	}
}