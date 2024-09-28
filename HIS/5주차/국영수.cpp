#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int N;
pair < pair<string, int>, pair<int, int>> v[100000];

/*
error1 : pair �ڷ����� �ƴ� vec�� ����ϸ� �����ϴ�. pair�迭�� �ڷ������ν� �������� �˰Ե�

error2 : "\n"�� ��Ȱȭ����. endl��������. ���ǹ��� ���� �Ἥ �ð��ʰ��� �߻��� �� �˾Ҵµ�, �� ��������.

��� ��1 : comp �Լ��� 2���� ������� ������ �� �ִ�.
  �Ʒ� �ڵ忡�� comp, comp2 �� ���� ��� ��� �����̴�.
  comp�� pair�迭�� ���� �� �ϳ��� ���� ���� ���� ���� ���, ���ǿ� ���� ����
  comp2�� ���ǿ� ���� ������ ��, ���� ��쿡 ���� ���� �������� �Ѿ�� ���
  �������δ� comp�� �� ���ǹ��� ��� ���� �� �ϴ�.
  // comp �Լ��� return ���� ���� ���� �ش� ���� true�� �ǵ��� �����Ѵٰ� �����ϸ� ����.

  ��� ��2 : c++�� cin, cout�� �� �ӵ��� �����ٴ� ���� ���� �����ϴ�. 
  �ش� ������ Ǯ�鼭 �ð� �ʰ��� ���� �߻��ؼ� ������ ��� (���� "\n"����������)
  c�� printf, scanf�� ���� ������� �ʰ�, cin, cout�� �ӵ��� �����Ű�� �ڵ带 ã�Ҵ�.
  [code]
  ios_base::sync_with_stdio(0); // 168ms->92ms
  cin.tie(0);					// 168ms->168ms (�̰͸����δ� ����ȿ�� x)
  �� �� ����ϴ� ���			// 168ms->88ms
  [/code]
  ���ѽð��� 1�ʶ�� ������ 88ms�� �����ϴ°��� ū ������ �ƴϹǷ�, �ش� ���������� ū �ҿ��� ������
  �ܿ��дٸ� ���� ���������� ���δ�.
*/

/*
�ð� ���� �ڵ忡 ���� ����
ios_base::sync_with_stdio(0)	= cpp�� iostream�� c�� stdio�� ����ȭ��Ű�� ����.
								  ������ iostream, stdio�� ���۸� ��� ����ؼ� �����̰� �߻��ϴµ�,
								  0, ��, false�� �����ϸ� c++���� �������� ���۰� �����ȴ�.
cin.tie(0)						= cin�� �ڿ� cout �������� cin�� �����ϰ��ϴ� �ڵ��� �� ����.
								  ���������� �������� �𸣰ڴ�. �����͸� �ܿ�����.
*/

bool comp(pair < pair<string, int>, pair<int, int>> a, pair < pair<string, int>, pair<int, int>> b) {
	if (a.first.second != b.first.second)
		return a.first.second > b.first.second;
	else {
		if (a.second.first != b.second.first)
			return a.second.first < b.second.first;
		else {
			if (a.second.second != b.second.second)
				return a.second.second > b.second.second;
			else {
				return a.first.first < b.first.first;
			}
		}
	}
}

bool comp2(pair < pair<string, int>, pair<int, int>> a, pair < pair<string, int>, pair<int, int>> b) {
	if (a.first.second > b.first.second)
		return true;
	else if (a.first.second == b.first.second) {
		if (a.second.first < b.second.first)
			return true;
		else if (a.second.first == b.second.first) {
			if (a.second.second > b.second.second)
				return true;
			else if (a.second.second == b.second.second) {
				if (a.first.first < b.first.first)
					return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string ts;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
	sort(v, v + N, comp);
	for (int i = 0; i < N; i++)
		cout << v[i].first.first << "\n";
}

/*
1. ����� ��������
2. ����� ��������
3. ������ ��������
4. �̸��� ������, �빮�ڴ� �ҹ��ں��� �տ� �´�.
*/