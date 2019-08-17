#include <iostream>
using namespace std;
typedef struct node *treePointer;

typedef struct node {
	char data;
	treePointer leftChild, rightChild;
}node;

void preorder(treePointer ptr) {
	if(ptr) {
		cout << ptr->data;
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

void inorder(treePointer ptr) {
	if(ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data;
		inorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr) {
	if(ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data;
	}
}

int main(void){
	int num;
	char data,left,right;
	node nodes[26];
	cin >> num;
	for(int i=0;i<num;i++) {
		nodes[i].data=char(int('A')+i);
		nodes[i].leftChild=NULL;
		nodes[i].rightChild=NULL;
	}
	for(int i=0;i<num;i++) {
		cin >>  data >> left >> right;
		if(data!='.')
			nodes[(int)(data-'A')].data=data;
		if(left!='.')
			nodes[(int)(data-'A')].leftChild=&nodes[(int)(left-'A')];
		if(right!='.')
			nodes[(int)(data-'A')].rightChild=&nodes[(int)(right-'A')];
		
	}
	preorder(&nodes[0]);
	cout <<endl;
	inorder(&nodes[0]);
	cout <<endl;
	postorder(&nodes[0]);
	cout <<endl;
}