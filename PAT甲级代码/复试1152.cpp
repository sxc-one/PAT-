#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
char str[maxn];
bool isprime(int n){
	if(n<2) return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	int len,k;
	scanf("%d %d %s",&len,&k,str);
	for(int i=0;i<len-k+1;i++){
		int j=i,ans=0;
		while(j<i+k){
			ans=ans*10+str[j]-'0';
			j++;
		}
		if(isprime(ans)){
			printf("%0*d",k,ans);
			return 0;
		}
	}
	printf("404");
}
/*
#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;
const int max=1010;
int l,k;
bool isprime(int n){
	if(n<2) return false;
	for(int i=2;i*i<n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	scanf("%d%d",&l,&k);
	string s;
	cin>>s;
	for(int i=0;i<s.size()-k+1;i++){
		int ans=stoi(s.substr(i,k));
		if(isprime(ans)){
			printf("%0*d",k,ans);
			return 0;
		}
	}
	printf("404");
	return 0;
} */





