#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
int num[maxn],d[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	d[0]=num[0];
	for(int i=1;i<n;i++){
		d[i]=max(num[i],d[i-1]+num[i]);
	}
	int sum=-0x3fffffff,last,first;
	for(int i=0;i<n;i++){
		if(d[i]>sum){
			sum=d[i];
			last=i;
		}
	}
	if(sum<0) printf("0 %d %d",num[0],num[n-1]); //全是负数 
	else if(sum==0) printf("0 0 0");  //只有负数和0 
	else{
		int temp=sum;
		for(int i=last;i>=0;i--){
		    temp-=num[i];
		    if(temp==0){
			first=i;
			break;
		}
	}
	printf("%d %d %d",sum,num[first],num[last]);
}
	return 0;
}
