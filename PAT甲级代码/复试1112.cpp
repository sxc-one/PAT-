#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int mp[256];
int main(){
	char str[maxn];
	int k;
	scanf("%d%s",&k,str);
	int len=strlen(str);
	int i=0,j=1;
	while(i<len&&j<len+1){
		while(j<len+1&&str[i]==str[j]) j++;
		if((j-i)%k==0) mp[str[i]]=1;
		else mp[str[i]]=0;
		i=j;
		j++;
	}
	for(i=0;i<len;i++){
		if(mp[str[i]]==1) {
			printf("%c",str[i]);
			mp[str[i]]=2;
		}
	}
	printf("\n");
	i=0;
	while(i<len){
		if(mp[str[i]]==0) {
			printf("%c",str[i]);
			i++;
		}else{
			printf("%c",str[i]);
			i+=k;
		}
	}
	return 0;
}
