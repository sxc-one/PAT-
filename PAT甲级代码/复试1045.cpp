#include<bits/stdc++.h>
using namespace std;
int mp[210],num[10010],d[10010];
int main(){
	int n,m,k,data;
	scanf("%d%d",&n,&m);
	memset(mp,-1,sizeof(mp));
	for(int i=1;i<=m;i++){
		scanf("%d",&data);
		mp[data]=i;
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&num[i]);
	}
	int ans=-1;
	for(int i=1;i<=k;i++){
		d[i]=1;
		for(int j=1;j<i;j++){
			if((mp[num[i]]>0&&mp[num[j]]>0)&&mp[num[i]]>=mp[num[j]]&&(d[j]+1>d[i])){
				d[i]=d[j]+1;
			}
		}
		ans=max(ans,d[i]);
	}
	printf("%d",ans);
	return 0;
}
