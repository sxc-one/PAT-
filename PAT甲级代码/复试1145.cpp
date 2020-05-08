#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
int hasht[maxn],ct[maxn];
bool isprime(int n){
	if(n<2) return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	int msize,n,m;
	scanf("%d%d%d",&msize,&n,&m);
	while(isprime(msize)==false) msize++;
	while(n--){
		int data;
		scanf("%d",&data);
		int step;
		for(step=0;step<msize;step++){
		   int pos=(data%msize+step*step)%msize;
		   if(hasht[pos]==0) {
		   	   hasht[pos]=data;
		   	   break;
		   }
	}
	if(step>=msize) printf("%d cannot be inserted.\n",data);
	}
	double ans=0;
    for(int i=0;i<m;i++){
		int data;
		scanf("%d",&data);
		int step;
		for(step=0;step<msize;step++){
		   int pos=(data%msize+step*step)%msize;
		   if(hasht[pos]!=0){
		   	   if(hasht[pos]==data){
		   	   	ans+=1;
		   	   	break;
				}else{
					ans+=1;
					continue;
				}
		   }
		   else {
		   	   ans+=1;
		   	   break;
		   }
	}
	if(step>=msize) ans+=1;
	}
	
	printf("%.1f",ans/m); 
	return 0;
}
