#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int maxn=100010;
int str[maxn];
int main(){
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%d",&str[i]);
	}
	sort(str,str+n);
	int m=str[n-1];
	for(int i=0;i<n;i++){
		if(m<=p*str[i]){
			printf("%d",n-i);
			break;
		}
	}
	return 0;
}
