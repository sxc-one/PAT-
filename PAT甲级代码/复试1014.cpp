#include<bits/stdc++.h>
using namespace std;
const int maxn=1111;
int n,m,k,query,q;
int con(int h,int m){
	return h*60+m;
}
struct Window{
	int end,pop;
	queue<int>q;
}window[20];
int ans[maxn],need[maxn];
int main(){
	int in=0;
	scanf("%d%d%d%d",&n,&m,&k,&query);
	for(int i=0;i<k;i++){
		scanf("%d",&need[i]);
	}
	for(int i=0;i<n;i++){
		window[i].pop=window[i].end=con(8,0);
	}
	for(int i=0;i<min(n*m,k);i++){
		window[in%n].q.push(in);
		window[in%n].end+=need[in];
		if(in<n) window[in].pop=need[in];
		ans[in]=window[in%n].end;
		in++;
	}
	for(;in<k;in++){
		int idx=-1,min=1<<30;
		for(int i=0;i<n;i++){
			if(window[i].pop<min){
				idx=i;
				min=window[i].pop;
			}
		}
		window[idx].q.pop();
		window[idx].q.push(in);
		window[idx].end+=need[in];
		window[idx].pop+=need[window[idx].q.front()];
		ans[in]=window[idx].end;
	}
	for(int i=0;i<query;i++){
		scanf("%d",&q);
		if(ans[q-1]-need[q-1]>=con(17,0)){
			printf("Sorry\n");
		}else{
			printf("%02d:%02d\n",ans[q-1]/60,ans[q-1]%60);
		}
	}
	return 0;
}
