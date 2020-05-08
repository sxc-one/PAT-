#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
int a[maxn][maxn];
int num[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&num[i]);
	}
	sort(num,num+N,cmp);
	int m = (int)ceil(sqrt(1.0 * N));    //这个找mn的方法比自己好多了 
    while(N % m != 0) {
        m++;    
    }
    int n=N/m;
	int up=0,down=m-1,left=0,right=n-1,numnode=0;
	while(left<=right&&up<=down){  //此处用numnode<N控制循环也是可以的 
		for(int i=left;i<=right&&numnode<N;i++){
			a[up][i]=num[numnode++];
		}
		up++;
		for(int i=up;i<=down&&numnode<N;i++){
			a[i][right]=num[numnode++];
		}
		right--;
		for(int i=right;i>=left&&numnode<N;i--){
			a[down][i]=num[numnode++];
		}
		down--;
		for(int i=down;i>=up&&numnode<N;i--){
			a[i][left]=num[numnode++];
		}
		left++;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d",a[i][j]);
			if(j<n-1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
