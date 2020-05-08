#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int num[maxn],n;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	sort(num+1,num+n+1,cmp);
	int i;
	for(i=1;i<=n;i++){
		if(num[i]<=i) break;
}
    printf("%d",i-1);
    return 0;
}
