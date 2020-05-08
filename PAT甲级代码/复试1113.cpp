#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int num[maxn],n,sum=0,sum1=0;
int main(){
	scanf("%d",&n);
	int min=n/2;
	int max=n-min;
	printf("%d ",max-min);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		sum+=num[i];
	}
	sort(num,num+n);
	for(int i=0;i<min;i++){
		sum1+=num[i];
	}
	printf("%d",sum-2*sum1);
	return 0;
}

