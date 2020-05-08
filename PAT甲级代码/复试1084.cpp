#include<cstdio>
#include<cstring>
const int maxn=1010;
int hasht[128]={0};
int main(){
	char str1[maxn],str2[maxn];
	int count=0;
	scanf("%s %s",str1,str2);
	int len1=strlen(str1);
	int len2=strlen(str2);
	for(int i=0;i<len1;i++){
		hasht[str1[i]]++;
	}
	for(int i=0;i<len2;i++){
		if(hasht[str2[i]]!=0) hasht[str2[i]]--;
		else count++;
	}
	if(count==0) printf("Yes %d",len1-len2);
	else printf("No %d",count);
	return 0;
}
