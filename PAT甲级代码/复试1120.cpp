#include<bits/stdc++.h>
using namespace std;
set<int>num;
int main(){
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int ans=0;
		scanf("%d",&x);
		while(x!=0){
			ans+=x%10;
			x/=10;
		}
		num.insert(ans);
	}
	printf("%d\n",num.size());
	for(auto it=num.begin();it!=num.end();it++){
		if(it!=num.begin()) printf(" ");
		printf("%d",*it);
	}
	return 0;
}
/*const int maxn=40;
int hasht[maxn];
int change(int x){
	int ans=0;
	do{
		ans+=x%10;
		x/=10;
	}while(x!=0);
	return ans;
} 
int main(){
	int n,num,temp,count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		num=change(temp);
		hasht[num]++;
	}
	for(int i=0;i<maxn;i++){
		if(hasht[i]!=0) count++;
	} 
	printf("%d\n",count);
	for(int i=0;i<maxn;i++){
		if(hasht[i]!=0){
			printf("%d",i);
			count--;
			if(count!=0) printf(" ");
		}
	}
	return 0;
} */
