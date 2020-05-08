#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,len,max=0,x;
	scanf("%d",&n);
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		len=0;
		if(n%i==0){
			int temp=1;
			int j=i;
			while(1){
				temp*=j;
				if(n%temp==0){
					len++;
					j++;
				}else break;
			}
		}
		if(len>max) {
			max=len;
			x=i;
		}
	}
	if(max==0) {
		printf("1\n");
		printf("%d",n);
	}else{
		printf("%d\n",max);
		for(int i=0;i<max;i++){
			printf("%d",x+i);
			if(i<max-1) printf("*");
		}
	}
	return 0;
}
