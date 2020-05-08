#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int judge(int num){
	int count=0;
	while(num!=0){
		if(num%10==1) count++;
		num/=10;
	}
	return count;
}
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ans+=judge(i);
	}
	printf("%d",ans);
	return 0;
}
