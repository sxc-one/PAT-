#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int queen[maxn];
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		bool flag=true;
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			scanf("%d",&queen[i]);
		}
		for(int i=1;i<k;i++){
			for(int j=i+1;j<=k;j++){
				if((abs(queen[i]-queen[j])==abs(i-j))||queen[i]==queen[j]){ 
					flag=false;
					break;
				}
			}
			if(flag==false) break;
		}
		printf("%s",flag==true?"YES\n":"NO\n");
	}
	return 0;
}
