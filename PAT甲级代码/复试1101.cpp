#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100010;
int num[maxn],leftmax[maxn],rightmin[maxn],ans[maxn];
int main(){
	int n,count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	leftmax[0]=0;
	for(int i=1;i<n;i++){
		leftmax[i]=max(leftmax[i-1],num[i-1]);
	}
	rightmin[n-1]=1000000007;
	for(int i=n-2;i>=0;i--){
		rightmin[i]=min(rightmin[i+1],num[i+1]);
	}
	for(int i=0;i<n;i++){
		if(num[i]>leftmax[i]&&num[i]<rightmin[i]) {
			ans[count]=num[i];
			count++; 
		}
	}  
	printf("%d\n",count);
	for(int i=0;i<count;i++){
		printf("%d",ans[i]);
		if(i<count-1) printf(" ");
	}
	printf("\n");
	return 0;
}
