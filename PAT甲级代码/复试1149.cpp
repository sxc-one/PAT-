#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
bool flag[maxn];
map<int,vector<int> >mp; 
int goods[maxn];
int main(){
	int n,m,a,b,k;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	while(m--){
		memset(flag,false,sizeof(flag));
		scanf("%d",&k);
		int data;
		for(int i=0;i<k;i++){
			scanf("%d",&goods[i]);
			for(int j=0;j<mp[goods[i]].size();j++){
				flag[mp[goods[i]][j]]=true;
			}
		}
		bool f=true;
		for(int i=0;i<k;i++){
			if(flag[goods[i]]) {
				f=false;
			break;
			}
		}
		printf("%s\n",f?"Yes":"No");
			}
	return 0;
}
