#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(void) {
	int N,K;
	int result=0;
	cin>> N >> K;
	vector<int> list;

	for(int i=1;i<=N;i++){
		list.push_back(i);
	}

	cout <<"<";
	while(!list.empty()) {
		result=(result+K-1);
		while (result>=list.size())
			result-=list.size();
		// result=(result+K-1) % list.size();
		cout << list[result];
		list.erase(list.begin()+result);
		if(!list.empty())
			cout << ", ";
	}
	cout << ">" <<endl;

}
//1234567
//3..2
//12 4567
//6..4
//12 45 7
//2..1
//1  45 7
//7..3
//1  45 
//5..2
//1  4
//1..0
//4