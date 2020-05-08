#include<bits/stdc++.h>
using namespace std;
stack<int>st;
int que[1010];
int main(){
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	while(k--){
		while(!st.empty()){
			st.pop();
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&que[i]);
		}
		int now=1;
		bool flag=true;
		for(int i=1;i<=n;i++){
			st.push(i);
			if(st.size()>m){
				flag=false;
				break;
			}
			while(!st.empty()&&st.top()==que[now]){
				st.pop();
				now++;
			}
		}
		if(st.empty()&&flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
