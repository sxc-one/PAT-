#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
map<int,bool>hasht;
int main(){
	int n,data;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		hasht[data]=true;
	}
	for(int i=1;i<maxn;i++){
		if(hasht[i]==false){
			printf("%d",i);
			return 0;
		}
	}
	printf("%d",n+1);
	return 0;
}
/*#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
int s[maxn];
int main(){
	int n,ans=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	sort(s,s+n);
    for(int i=0;i<n;i++){
    	if(s[i]==ans) ans++;
    	
	}
	printf("%d",ans);
	return 0;
}*/
