#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Fra{
	ll up,down;
};
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
Fra reduction(Fra result){
	if(result.down<0){
		result.up=-result.up;
		result.down=-result.down;
	}
	if(result.up==0){
		result.down=1;
	}else{
		int d=gcd(abs(result.up),result.down);
		result.up/=d;
		result.down/=d;
	}
	return result;
}
void showresult(Fra result){
	result=reduction(result);
	if(result.up<0) printf("(");
	if(result.down==1){
		printf("%lld",result.up);
	}else if(abs(result.up)>result.down){
		printf("%lld %lld/%lld",result.up/result.down,abs(result.up)%result.down,result.down);
	}else printf("%lld/%lld",result.up,result.down);
	if(result.up<0)	printf(")");
	}
Fra add(Fra a,Fra b){
	Fra result;
	result.up=a.up*b.down+b.up*a.down;
	result.down=a.down*b.down;
	return reduction(result);
}
Fra differ(Fra a,Fra b){
	Fra result;
	result.up=a.up*b.down-b.up*a.down;
	result.down=a.down*b.down;
	return reduction(result);
}
Fra time(Fra a,Fra b){
	Fra result;
	result.up=a.up*b.up;
	result.down=a.down*b.down;
	return reduction(result);
}
Fra divide(Fra a,Fra b){
	Fra result;
	if(b.up==0) printf("Inf");
	else{
		result.up=a.up*b.down;
		result.down=a.down*b.up;
		showresult(result);
	}
}
int main(){
	Fra f1,f2;
	scanf("%lld/%lld %lld/%lld",&f1.up,&f1.down,&f2.up,&f2.down);
	showresult(f1);
	printf(" + ");
	showresult(f2);
	printf(" = ");
	showresult(add(f1,f2));
	printf("\n");
	showresult(f1);
	printf(" - ");
	showresult(f2);
	printf(" = ");
	showresult(differ(f1,f2));
	printf("\n");
	showresult(f1);
	printf(" * ");
	showresult(f2);
	printf(" = ");
	showresult(time(f1,f2));
	printf("\n");
	showresult(f1);
	printf(" / ");
	showresult(f2);
	printf(" = ");
	divide(f1,f2);
	printf("\n");
	return 0;
}
