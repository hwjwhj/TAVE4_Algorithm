#include <iostream>

using namespace std;


int main() {
	int T;
	cin >> T;
	int ans[11];
	for(int i=0;i<T;i++) {
		int arr[11];
		int num;
		cin >> num;
		arr[1]=1;
		arr[2]=2;
		arr[3]=4;
		for(int j=4;j<=num;j++) {
			arr[j]=arr[j-3]+arr[j-2]+arr[j-1];
		}
		ans[i]=arr[num];
	}
	for(int i=0;i<T;i++)
		cout << ans[i] << '\n';
}
