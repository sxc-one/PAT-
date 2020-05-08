#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
char str[maxn];
int d[maxn][maxn];
int main(){
	fgets(str,maxn,stdin);
	int len=strlen(str);
	int ans=1;
	for(int i=0;i<len;i++){
		d[i][i]=1;
		if(i<len-1){
			if(str[i]==str[i+1]){
				d[i][i+1]=1;
				ans=2;
			}
		}
	}
	for(int i=3;i<=len;i++){
		for(int j=0;j+i-1<len;j++){
			int k=j+i-1;
			if(str[j]==str[k]&&d[j+1][k-1]==1){
				d[j][k]=1;
				ans=i;
			}
		}
	}
	return 0;
} 
