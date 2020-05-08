#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int maxn=100010;
int str[maxn];
int main(){
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%d",&str[i]);
	}
	sort(str,str+n);
	int ans=1;
	for(int i=0;i<n;i++){
		int j=upper_bound(str+1+i,str+n,(long long)str[i]*p)-str;
		ans=max(ans,j-i);
	}
	cout<<ans;
	return 0;
}
