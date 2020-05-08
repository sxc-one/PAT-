#include<cstdio>
#include<cstring>
const int maxn=10010;
bool hasht[128];
char str1[maxn],str2[maxn];
int main(){
	fgets(str1,maxn,stdin);
	fgets(str2,maxn,stdin);
	int len1=strlen(str1);
	int len2=strlen(str2);
	for(int i=0;i<len2;i++){
		hasht[str2[i]]=true;
	}
	for(int i=0;i<len1;i++){
		if(hasht[str1[i]]==false) printf("%c",str1[i]);
	}
	return 0;
}
