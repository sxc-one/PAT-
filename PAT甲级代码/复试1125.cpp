#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
int num[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	double ans=num[0];
	for(int i=1;i<n;i++){
		ans=(ans+num[i])*0.5;
	}
	printf("%d",(int)ans);
	return 0;
}
