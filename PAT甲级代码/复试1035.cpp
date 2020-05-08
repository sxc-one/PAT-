#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char sen[110][260];
int main(){
	int n,min=260,same=0;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		fgets(sen[i],260,stdin);
		int len=strlen(sen[i]);
		reverse(sen[i],sen[i]+len);
		
		if(len<min) min=len;
	}
	for(int i=0;i<min;i++){
		char c=sen[0][i];
		bool flag=true;
		for(int j=1;j<n;j++){
			if(c!=sen[j][i]){
				flag=false;
				break;
			}
		}
		if(flag) same++;
		else break;
	} 
	if(same){
		for(int i=same-1;i>=0;i--){
				printf("%c",sen[0][i]);
		}
	}else printf("nai");
	return 0;
}
