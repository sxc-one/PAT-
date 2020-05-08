#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2000010;
int num[maxn];
int main(){
	int n,m,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	scanf("%d",&m);
	for(;i<n+m;i++){
		scanf("%d",&num[i]);
	}
	sort(num,num+n+m);
	printf("%d",num[(n+m-1)/2]);
	return 0;
}
