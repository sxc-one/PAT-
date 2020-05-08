#include<bits/stdc++.h>
using namespace std;
bool isprime(int n){
	if(n<2) return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0) return false;
	}
	return true;
}
int num[100];
int main(){
	int n,r;
	while(1){
		scanf("%d",&n);
		if(n<0) break;
		scanf("%d",&r);
		if(isprime(n)==false){
			printf("No\n");
		}else{
			int len=0;
			do{
				num[len++]=n%r;
				n/=r;
			}while(n!=0);
			for(int i=0;i<len;i++){
				n=n*r+num[i];
			}
			if(isprime(n)){
				printf("Yes\n");
			}else printf("No\n"); 
		}
	}
	return 0;
}
