#include "iostream"

using namespace std;

// �Է� : ����� ���� N, <�θ�, LN, RN> 
// ��� : ���� ��ȸ(V-L-R), ���� ��ȸ(L-V-R), ���� ��ȸ(L-R-V) ������ ��� 
/*
	<������ �� ��> 
	1. ��ȸ ���� ���� ��带 ��(empty) ���� �ΰ� ������ . �Է�
	2. ���߹迭�� ���� ��带 ǥ�� => ��� �̸�[�θ� ���][�ڽ� ���]
	3. ���ĺ��� �ƽ�Ű �ڵ带 �����ؼ� �����غ��� 
*/ 

void preorder(int x); 
void inorder(int x); 
void postorder(int x); 

// ���� Ʈ�� �迭 ���� 
int node[50][2];

int main() {
	int count;
	char x, y, z;
	
	// �� ��� ���� �Է�
	cin >> count;
	
	// �θ� >> ���� �ڽ� >> ������ �ڽ� �Է� 
	for(int i = 0; i < count; i++) {

		cin >> x >> y >> z;
		x = x - 'A';

		// ���� �ڽ� ��� �����Ͱ� ������ -1 ����
		if(y == '.') {
			node[x][0] = -1;
		}
		// ���� �ڽ� ��� �����ͷ� ���� ����� ����
		else {
			node[x][0] = y - 'A';
		}

		// ������ �ڽ� ��� �����Ͱ� �������� -1 ���� 
		if(z == '.') {
			node[x][1] = -1;
		}
		// ������ �ڽ� ��� �����ͷ� ���� ����� ���� 
		else {
			node[x][1] = z - 'A';
		}
	}
	preorder(0);
	cout << endl;

	inorder(0);
	cout << endl;

	postorder(0);
	cout << endl;
	return 0;
}


// ���� ��ȸ : V - L - R 
void preorder(int x) {
	// ���� �ش� ����� �����Ͱ� �������� �ʴ´ٸ� ��� ���� ��ȯ 
	if(x == -1) {
		return;
	}
	
	// ���� ��ȸ�ϴ� ��� ���
	cout << (char)(x + 'A');

	// ���� -> ������ ��� ������ ��� ȣ��
	preorder(node[x][0]);
	preorder(node[x][1]);
}


// ���� ��ȸ : L - V - R 
void inorder(int x) {
	if(x == -1) {
		return;
	}
	
	inorder(node[x][0]);
	cout << (char)(x + 'A');
	inorder(node[x][1]);
}


// ���� ��ȸ : L - R - V 
void postorder(int x) {
	if(x == -1) {
		return;
	}
	
	postorder(node[x][0]);
	postorder(node[x][1]);
	cout << (char)(x + 'A');
}


