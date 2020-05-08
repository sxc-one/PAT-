#include<bits/stdc++.h>
using namespace std;
struct bign{
	int d[21]={0};
	int len=0;
};
bign change(char str[]){
	bign a;
	a.len=strlen(str);
	for(int i=0;i<a.len;i++){
		a.d[i]=str[a.len-1-i]-'0';
	}
	return a;
}
bign multi(bign a,int b){
	bign c;
	int carry=0;
	for(int i=0;i<a.len;i++){
		carry+=a.d[i]*b;
		c.d[c.len++]=carry%10;
		carry/=10;
	}
	while(carry!=0){
		c.d[c.len++]=carry%10;
		carry/=10;
	}
	return c;
}
int main(){
	char str[21];
	scanf("%s",str);
	bign a=change(str);
	bign c=multi(a,2);
	if(a.len!=c.len) printf("No\n");
	else{
		int count[10]={0};
		for(int i=0;i<a.len;i++){
			count[a.d[i]]++;
			count[c.d[i]]--;
		}
		int i;
		for(i=0;i<10;i++){
			if(count[i]!=0) {
				printf("No\n");
				break;
			}
		}
	    if(i==10)	printf("Yes\n");
	}
	for(int i=c.len-1;i>=0;i--){
		printf("%d",c.d[i]);
	}
	return 0;
}
