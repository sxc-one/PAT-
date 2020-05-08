#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
bool hashtable[maxn];
bool isprime(int n){
	if(n<2) return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	int m,n,num;
	scanf("%d%d",&m,&n);
	while(isprime(m)==false){
		m++;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		int pos=num%m;
		if(hashtable[pos]==false){
			hashtable[pos]=true;
			if(i==0) printf("%d",pos);
			else printf(" %d",pos);
		}else{
			int step;
			for(step=1;step<m;step++){
				pos=(num+step*step)%m;
				if(hashtable[pos]==false){
					hashtable[pos]=true;
					if(i==0) printf("%d",pos);
					else printf(" %d",pos);
					break;
				}
			}
			if(step>=m){
				if(i>0) printf(" ");
				printf("-");
			}
		}
	}
	return 0;
}
