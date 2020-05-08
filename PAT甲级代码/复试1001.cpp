#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char num[10][6]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	char str[105];
	int ans[5];
	scanf("%s",str);
	int sum=0;
	int len=strlen(str);
	for(int i=0;i<len;i++) {
		sum+=str[i]-'0';
	}
	int index=0;
	if(sum==0){
		printf("zero");
	}else{
		while(sum!=0){
		ans[index++]=sum%10;
		sum/=10;
	}
	for(int i=index-1;i>=0;i--){
		printf("%s",num[ans[i]]);
		if(i!=0) printf(" ");
	}
	}
	
	return 0;
}
