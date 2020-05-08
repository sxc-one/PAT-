#include<bits/stdc++.h>
using namespace std;
const int maxn=60000007;
int hasht[maxn];
int main(){
	int m,n,num;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&num);
			hasht[num]++;
		}
	}
	int max=0,index;
	for(int i=0;i<maxn;i++){
		if(hasht[i]>max){
			max=hasht[i];
			index=i;
		}
	}
	printf("%d",index);
	return 0;
}
