#include<bits/stdc++.h>
using namespace std;
int n,k,p,maxsum=-1;
vector<int>fac,ans,temp;
int power(int x){
	int ans=1;
	for(int i=0;i<p;i++){
		ans*=x;
	}
	return ans;
}
void init(){
	int i=0,temp=0;
	while(temp<=n){
		fac.push_back(temp);
		temp=power(++i);
	}
}
void DFS(int index,int nowk,int sum,int facsum){
	if(nowk==k&&sum==n){
		if(facsum>maxsum){
			ans=temp;
			maxsum=facsum;
		}
	}
	if(nowk>k||sum>n||index<1) return;
	temp.push_back(index);
	DFS(index,nowk+1,sum+fac[index],facsum+index);
	temp.pop_back();
	DFS(index-1,nowk,sum,facsum);
}
int main(){
	scanf("%d%d%d",&n,&k,&p);
	init();
	DFS(fac.size()-1,0,0,0);
	if(maxsum==-1) printf("Impossible\n");
	else{
		printf("%d = %d^%d",n,ans[0],p);
		for(int i=1;i<ans.size();i++){
			printf(" + %d^%d",ans[i],p);
		}
	}
	return 0;
}
