#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
int sum[maxn];
int n,m,near=100000010;
int main(){
	scanf("%d%d",&n,&m);
	sum[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	}
	int i=0,j=0;
	while(i<=n&&j<=n){
		while(j<=n&&(sum[j]-sum[i])<m){
			j++;
		}
		int temp=sum[j]-sum[i];
		if(temp>=m){
			near=min(near,temp);
		}
		i++; 
	}
    i=0,j=0;
	while(i<=n&&j<=n){
		while(j<=n&&(sum[j]-sum[i])<m){
			j++;
		}
		if(sum[j]-sum[i]==near){
			printf("%d-%d\n",i+1,j);
		}
		i++;	
	}
	return 0;
} 
