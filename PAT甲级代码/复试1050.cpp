#include<cstdio>
#include<cstring>
int hasht[1010];
int main(){
	int n,m,num;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		hasht[num]++;
	}
	int i;
    for(i=1;i<=m/2;i++){
    	if(hasht[i]&&hasht[m-i]){
    		if(i==m-i&&hasht[i]<=1) break;
			printf("%d %d",i,m-i);
			return 0;
			}
			} 
			printf("No Solution");
	return 0;
} 
