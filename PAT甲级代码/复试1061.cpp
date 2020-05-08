#include<cstdio>
#include<cstring>
int main(){
	char str[10010];
	int pos=0,exp=0;
	scanf("%s",str);
	if(str[0]=='-') printf("-");
	int len=strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]=='E') pos=i;
	}
	for(int i=pos+2;i<len;i++){
		exp=exp*10+(str[i]-'0');
	}
	if(str[pos+1]=='-'){
		printf("0.");
		for(int i=0;i<exp-1;i++){
			printf("0");
		}
		printf("%c",str[1]);
		for(int i=3;i<=pos-1;i++){
			printf("%c",str[i]);
		}
	}else{
		int count=pos-3;
		if(exp>=count){
			printf("%c",str[1]);
		    for(int i=3;i<=pos-1;i++){
			printf("%c",str[i]);
		}
		for(int i=0;i<exp-count;i++){
			printf("0");
		}
		}else{
			printf("%c",str[1]);
		    for(int i=0;i<exp;i++){
			printf("%c",str[i+3]);
		}
		printf(".");
		for(int i=0;i<count-exp;i++){
			printf("%C",str[i+3+exp]);
		}
		}
	}
	return 0;
}
