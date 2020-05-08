#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int temp[4]={0};
bool cmp(int a,int b){
	return a>b;
}
void numtoarray(int x){
	for(int i=0;i<4;i++){
		temp[i]=x%10;
		x/=10;
	}
}
int arraytonum(int a[]){
	int ans=0; 
	for(int i=0;i<4;i++){
	    ans=ans*10+a[i];
	}
	return ans; 
}
int main(){
	int n;
	scanf("%d",&n);
	while(1){
		numtoarray(n);
	    sort(temp,temp+4,cmp);
	    int Max=arraytonum(temp);
	    sort(temp,temp+4);
	    int Min=arraytonum(temp);
	    n=Max-Min;
	    printf("%04d - %04d = %04d\n",Max,Min,n);
	    if(n==0||n==6174) break;
	}
	return 0;
}
