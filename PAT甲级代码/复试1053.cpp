#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
struct Node{
	int weight;
	vector<int>child;
}node[maxn];
bool cmp(int a,int b){
	return node[a].weight>node[b].weight;
}
int n,m,s;
vector<int>temp,ans;
void DFS(int index,int sum){
	temp.push_back(index);
	if(node[index].child.size()==0){
		if(sum==s){
			for(int i=0;i<temp.size();i++){
				printf("%d",node[temp[i]].weight);
				if(i!=temp.size()-1) printf(" ");
				else printf("\n");
			}
			return;
		}else return;
	}
	for(int i=0;i<node[index].child.size();i++){
		DFS(node[index].child[i],sum+node[node[index].child[i]].weight);
		temp.pop_back();
	}
	
}
int main(){
	int father,child,k;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<n;i++){
		scanf("%d",&node[i].weight);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&father,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&child);
			node[father].child.push_back(child);
		}
		sort(node[father].child.begin(),node[father].child.end(),cmp);
	}
	DFS(0,node[0].weight);
	return 0;
}
