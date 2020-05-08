#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
struct bign{
	int d[maxn],len;
};
bool is(bign a){
	for(int i=0;i<a.len;i++){
		if(a.d[i]!=a.d[a.len-1-i]) return false;
	} 
	return true;
}
void show(bign a){
	for(int i=a.len-1;i>=0;i--) printf("%d",a.d[i]);
}
void add(bign &a,bign b){
	int carry=0;
	for(int i=0;i<a.len;i++){
		carry=carry+a.d[i]+b.d[i];
		a.d[i]=carry%10;
		carry/=10;
	}
	if(carry!=0){
		a.d[a.len++]=carry;
	}
}
int main(){
	char str[maxn];
	scanf("%s",str);
	bign a;
	a.len=strlen(str);
	for(int i=0;i<a.len;i++){
		a.d[i]=str[a.len-i-1]-'0';
	}
	int num=0;
	while(!is(a)){
		show(a);
		printf(" + ");
		bign b=a;
		reverse(b.d,b.d+b.len);
		show(b);
		printf(" = ");
		add(a,b);
		show(a);
		printf("\n");
		num++;
		if(num==10){
			printf("Not found in 10 iterations.\n");
			return 0;
		}
	}
	show(a);
	printf(" is a palindromic number.");
	return 0;
}
/*#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

bool isP(string s){
	int len=s.size();
	for(int i=0;i<len;i++){
	if(s[i]!=s[len-i-1]) return false;
}
    return true;
}


void add(string&str1,string&str2){//大整数加法，从索引为0的位置开始进行逐位加法，如果有最终进位可以放在数组末尾
    int jinwei=0;//进位
    for(int i=0; i<str1.size(); ++i){
        int k=str1[i]+str2[i]-'0'-'0'+jinwei;
        jinwei=k/10;
        str1[i]=k%10+'0';
    }
    if(jinwei>0)//有最终进位放在数组末尾
        str1+=jinwei+'0';
    }


int main(){
	int n=0;
	string str1,str2;
	cin>>str1;
	while(!isP(str1)){
		str2=str1;
		reverse(str1.begin(),str1.end());
		printf("%s + %s = ",str2.c_str(),str1.c_str());
		add(str1,str2);
		reverse(str1.begin(),str1.end());
		printf("%s\n",str1.c_str());
		n++;
		if(n==10){
			printf("Not found in 10 iterations.");
			return 0;
		}
	}
	printf("%s is a palindromic number.",str1.c_str());
	return 0;
}	

*/
