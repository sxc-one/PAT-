#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
struct Con{
	bool flag;
	int rank;
}con[maxn];
bool isprime(int n){
	if(n<2) return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	int n,k,id;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&id);
		con[id].rank=i;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&id);
		if(con[id].rank==0) printf("%d: Are you kidding?\n",id);
		else{
			if(con[id].flag==false){
				if(con[id].rank==1) printf("%04d: Mystery Award\n",id);
				else if(isprime(con[id].rank)) printf("%04d: Minion\n",id);
				else printf("%04d: Chocolate\n",id);
				con[id].flag=true;
			}else{
				printf("%04d: Checked\n",id);
			}
		}
	}
	return 0;
} 
