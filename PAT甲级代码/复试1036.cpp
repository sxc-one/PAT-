#include<cstdio>
#include<cstring>
int main(){
	char str[85];
	int n1,n2,n3;
	gets(str);
	int n=strlen(str);
	n1=(n+2)/3,n3=n1,n2=n+2-2*n1;
	for(int i=0;i<n1-1;i++){
		printf("%c",str[i]);
		for(int j=0;j<n2-2;j++){
			printf(" ");
		}
		printf("%c\n",str[n-i-1]);
	}
	for(int i=n1-1;i<n1+n2-1;i++){
		printf("%c",str[i]);
	}
	return 0;
}
