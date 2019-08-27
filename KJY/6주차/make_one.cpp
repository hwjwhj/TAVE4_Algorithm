#include <stdio.h>
#include <algorithm>

using namespace std;

int d[1000001];

int dp(int x) {
	d[1]=0;
	d[2]=1;
	d[3]=1;
	for(int i=4;i<=x;i++) {
		d[i]=d[i-1]+1;
		if(i%2==0)
		{
			d[i]=min(d[i], d[i/2]+1);
		}
		if(i%3==0){
			d[i]=min(d[i],d[i/3]+1);
		}
	}
	return d[x];
}

int main(void){
	int x;
	scanf("%d", &x);
	printf("%d\n", dp(x));
}