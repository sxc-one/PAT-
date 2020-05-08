#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=110;
struct Fra{
	int up,down;
}fra[N];
int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
} 
Fra reduction(Fra result){
	if(result.up==0){
		result.down=1;
	}else{
		int d=gcd(abs(result.up),result.down);
		result.up/=d;
		result.down/=d;
	}
	return result;
}
Fra add(Fra f1,Fra f2){
	Fra result;
	result.up=f1.up*f2.down+f2.up*f1.down;
	result.down=f1.down*f2.down;
	return reduction(result);
}
void showresult(Fra result){
	 if(result.down==1){
	 	printf("%d\n",result.up);
	 }else if(abs(result.up)>result.down){
	 	printf("%d %d/%d\n",result.up/result.down,abs(result.up)%result.down,result.down);
	 }else printf("%d/%d",result.up,result.down);
}
int main(){
	int n;
	Fra ans;
	ans.up=0;ans.down=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d/%d",&fra[i].up,&fra[i].down);
		ans=add(ans,fra[i]);
	}
	showresult(ans);
	return 0;
}
	
