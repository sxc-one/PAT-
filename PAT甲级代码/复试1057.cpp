#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
const int maxb=(int)sqrt(1.0*maxn);
int block[maxb],table[maxn];
stack<int>st;
void Push(int x){
	st.push(x);
	block[x/maxb]++;
	table[x]++;
}
void Pop(){
	if(st.size()==0) printf("Invalid\n");
	else{
		block[st.top()/maxb]--;
		table[st.top()]--;
		printf("%d\n",st.top());
		st.pop();
	}
}
void me(int k){
	if(st.empty()){
		printf("Invalid\n");
		return;
	}
	int sum=0,id=0;
	while(sum+block[id]<k){
		sum+=block[id++];
	}
	int num=id*maxb;
	while(sum+table[num]<k){
		sum+=table[num++];
	}
	printf("%d\n",num);
}
int main(){
	int n;
	char str[20];
	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		if(strcmp(str,"Push")==0){
			int num;
			scanf("%d",&num);
			Push(num);
		}else if(strcmp(str,"Pop")==0) Pop();
		else{
			int k=(st.size()+1)/2;
			me(k);
		}
	}
	return 0;
}
