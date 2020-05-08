#include<cstring>
#include<cstdio>
const int maxn=100010;
char str[maxn];
int pnum[maxn]={0};
int main(){
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i<len;i++){
		if(i>0) pnum[i]=pnum[i-1];
		if(str[i]=='P') pnum[i]++;
	}
	int ans=0,count=0;
	for(int i=len-1;i>=0;i--){
		if(str[i]=='T') count++;
		else if(str[i]=='A') ans=(ans+count*pnum[i])%1000000007;
	}
	printf("%d",ans);
	return 0;
}
