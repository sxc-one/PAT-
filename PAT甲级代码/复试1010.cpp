#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char n1[15],n2[15],temp[15];
int m[256],Max=-1;
void init(){
	for(char c='0';c<='9';c++){
		m[c]=c-'0';
	}
	for(char c='a';c<='z';c++){
		m[c]=c-'a'+10;
	}
}
long long change(char x[],int p){
	int len=strlen(x);
	long long ans=0;
	for(int i=0;i<len;i++){
		ans=ans*p+m[x[i]];
		Max=max(Max,m[x[i]]);
	}
	return ans;
}
int main(){
	init();
	int tag,radix;
	scanf("%s%s%d%d",n1,n2,&tag,&radix);
	if(tag==2) swap(n1,n2);
	long long x1=change(n1,radix);
	for(int i=2;i<=36;i++){
		Max=-1;
		long long x2=change(n2,i);
		if(Max>=i) continue;
		if(x1==x2){
			printf("%d",i);
			return 0;
		}
	}
	printf("Impossible");
	return 0;
}

