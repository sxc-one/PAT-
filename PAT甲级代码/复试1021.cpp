#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
vector<int>adj[maxn],temp;
bool vis[maxn];
set<int>s;
int n,s1,maxd=-1;
void DFS(int index,int depth){
	vis[index]=true;
	if(depth>maxd){
		temp.clear();
		maxd=depth;
		temp.push_back(index);
	}else if(maxd==depth){
		temp.push_back(index);
	}
	for(int i=0;i<adj[index].size();i++){
		int next=adj[index][i];
		if(vis[next]==false) DFS(next,depth+1);
	}
}
int main(){
	    scanf("%d",&n);
	    int a,b,block=0;
	    for(int i=0;i<n-1;i++){
	    	scanf("%d%d",&a,&b);
	    	adj[a].push_back(b);
	    	adj[b].push_back(a);
		}
        for(int i=1;i<=n;i++){
        	if(vis[i]==false){
        		DFS(i,1);
        		if(i==1){
        			s1=temp[0];
        			for(int j=0;j<temp.size();j++){
        				s.insert(temp[j]);
					}
				}
				block++;
			}
		}
		if(block>1){
			printf("Error: %d components\n",block);
		}else{
			memset(vis,false,sizeof(vis));
			maxd=-1;
			DFS(s1,1);
			for(int i=0;i<temp.size();i++){
				s.insert(temp[i]);
			}
			for(auto it=s.begin();it!=s.end();it++){
				printf("%d\n",*it);
			}
		}
		return 0;

}
