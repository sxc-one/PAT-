#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
bool isprime(int n){
	if(n<2) return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0) return false;
	}
	return true;
}
int prime[maxn],pnum=0;
void findprime(){
	for(int i=2;i<maxn;i++){
		if(isprime(i)) prime[pnum++]=i;
	}
}
int main(){
	findprime();
	int n,num=0;
	scanf("%d",&n);
	printf("%d=",n);
	if(n==1) printf("1");
	for(int i=0;i<pnum;i++){
		int count=0;
		if(n%prime[i]==0){
			while(n%prime[i]==0){
				count++;
				n/=prime[i];
			}
			num++;
			if(num!=1) printf("*");
			if(count==1){
				printf("%d",prime[i]);
			}else printf("%d^%d",prime[i],count);
		}	
	}
	return 0;
}
