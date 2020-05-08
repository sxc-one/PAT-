#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1010;
int cbt[maxn],num[maxn],n,index=0;
void inorder(int root){
	if(root>n) return;
	inorder(root*2);
	cbt[root]=num[index++];
	inorder(root*2+1);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	inorder(1);
	for(int i=1;i<=n;i++){
		printf("%d",cbt[i]);
		if(i!=n) printf(" ");
	}
	return 0;
}
