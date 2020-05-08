#include<bits/stdc++.h>
using namespace std;
struct bign{
	int d[100];
	int len;
	bign(){
		memset(d,0,sizeof(d));
		len=0;
	}
};
bign change(char str[]){
	bign a;
	a.len=strlen(str);
	for(int i=0;i<a.len;i++){
		a.d[i]=str[a.len-1-i]-'0';
	} 
	return a;
}
bool isprime(bign a){
	for(int i=0;i<=a.len;i++){
		if(a.d[i]!=a.d[a.len-1-i]){
			return false;
		}
	}
	return true;
}
bign add(bign a,bign b){
	bign c;
	int carry=0;
	for(int i=0;i<a.len||i<b.len;i++){
		carry+=a.d[i]+b.d[i];
		c.d[c.len++]=carry%10;
		carry/=10; 
	}
	if(carry!=0){
		c.d[c.len++]=carry;
	}
	return c;
}
void print(bign a){
	for(int i=a.len-1;i>=0;i--){
		printf("%d",a.d[i]);
	}
	printf("\n"); 
}
int main(){
	char str[100];
	int k,count=0;
	scanf("%s %d",str,&k);
	bign a=change(str);
	while(count<k&&isprime(a)==false){
		bign b=a;
		reverse(b.d,b.d+b.len);
		a=add(a,b);
		count++;
	}
	print(a);
	printf("%d",count);
	return 0;
}
