#include<cstdio>
#include<cstring>
const int maxn=100010;
int hasht[maxn]={0};
int o[maxn];
int main(){
	int num,n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&o[i]);
		hasht[o[i]]++;
	}
	for(int i=0;i<n;i++){
		if(hasht[o[i]]==1) {
			printf("%d",o[i]);
			return 0;
		}
		
	}
	 printf("None");
	return 0;
}
