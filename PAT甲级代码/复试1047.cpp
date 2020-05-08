#include<bits/stdc++.h>
using namespace std;
const int maxn=40010;
char name[maxn][5];
vector<int>course[2510];
bool cmp(int a,int b){
	return strcmp(name[a],name[b])<0;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		int c,x;
		scanf("%s%d",name[i],&c);
		for(int j=0;j<c;j++){
			scanf("%d",&x);
			course[x].push_back(i);
		}
	}
	for(int i=1;i<=k;i++){
		sort(course[i].begin(),course[i].end(),cmp);
		printf("%d %d\n",i,course[i].size());
		for(int j=0;j<course[i].size();j++){
			printf("%s\n",name[course[i][j]]);
		}
	}
	return 0;
}
