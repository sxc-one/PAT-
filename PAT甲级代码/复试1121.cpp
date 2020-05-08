#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
bool flag[maxn];
int cou[maxn],temp[maxn];
set<int>st;
int main(){
	int n,m;
	scanf("%d",&n);
	while(n--){
		int a,b;
		scanf("%d%d",&a,&b);
		cou[a]=b;
		cou[b]=a;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&temp[i]);
		flag[cou[temp[i]]]=true;
	}
	for(int i=0;i<m;i++){
		if(flag[temp[i]]==false) st.insert(temp[i]);
	}
	printf("%d\n",st.size());
	for(auto it=st.begin();it!=st.end();it++){
		if(it!=st.begin()) printf(" ");
		printf("%05d",*it);
	}
	return 0;
}
