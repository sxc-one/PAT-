#include<cstdio>
#include<cstring>
const int maxn=90;
bool hashtable[128]={false};
int main(){
	char str1[maxn],str2[maxn];
	scanf("%s %s",str1,str2);
	int len1=strlen(str1);
	int len2=strlen(str2);
	for(int i=0;i<len1;i++){
		if(str1[i]<='z'&&str1[i]>='a') str1[i]-=32;
		int j;
		for(j=0;j<len2;j++){
			if(str2[j]<='z'&&str2[j]>='a') str2[j]-=32;
			if(str1[i]==str2[j]) break;
		}
		if(j==len2&&hashtable[str1[i]]==false) {
			printf("%c",str1[i]); 
			hashtable[str1[i]]=true;
		}
	}
	return 0;
}
