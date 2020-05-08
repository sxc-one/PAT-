#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
int pos[maxn];
int main(){
	int n,count=0,num;
	scanf("%d",&n);
	int left=n-1;
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		pos[num]=i;
		if(num==i&&num!=0) left--;
	}
	int k=1;
	while(left>0){
		if(pos[0]==0){
			while(k<n){
				if(pos[k]!=k){
				swap(pos[k],pos[0]);
				count++;
				break;
			}
			k++;
			}
	}
		while(pos[0]!=0){
				swap(pos[0],pos[pos[0]]);
				count++;
				left--;
				break;
	}
	}
	printf("%d",count);
	return 0;
}
