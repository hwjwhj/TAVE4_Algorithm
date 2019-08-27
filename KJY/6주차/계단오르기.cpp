#include <iostream>
using namespace std;

int arr[300+1];
int visit[300+1];
int main() {
	int N;
	int sum=0;
	cin >> N;
	for(int i=0;i<N;i++) {
		cin >> arr[i];
	}
	sum+=arr[N-1];
	visit[N-1]=1;
	if (N==3) {
		if(arr[0] < arr[1]) 
			sum+=arr[1];
		else
			sum+=arr[0];
	}
	if (N==2) 
		sum+=arr[0];
	if(N>3) {
	for(int i=N-2;i>1;i--) {
		if((arr[i] >= arr[i-1]) && (visit[i]==0)){
			if(visit[i+1]==1 && visit[i+2]==1)
			{
				//cout << "wow" << arr[i-1]<<'\n';
				sum+=arr[i-1];
				visit[i-1]=1;
				continue;
			}
			//cout << "wow" << arr[i]<<'\n';
			sum+=arr[i];
			visit[i]=1;
		}
		else if((arr[i] < arr[i-1]) && (visit[i-1]==0))
		{
			if(visit[i]==1 && visit[i+1]==1)
			{
				//cout << "wow" << arr[i]<<'\n';
				sum+=arr[i];
				visit[i]=1;
				continue;
			}
			//cout << "wow" << arr[i-1]<<'\n';
			sum+=arr[i-1];
			visit[i-1]=1;
		}

	
	
	}

	sum+=arr[0];
	//cout << visit[0];
	if(visit[1]==1 && visit[2]==1 && visit[0]==1){
		sum-=arr[0];
	}

	}
	
	cout << sum;
}