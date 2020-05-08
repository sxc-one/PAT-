#include<bits/stdc++.h>
using namespace std;
const int maxn=50010;
struct node{
	int value,cnt;    //不能反过来 
	bool operator < (const node &a) const{
		return (cnt!=a.cnt)?cnt>a.cnt:value<a.value;
	}
};
int book[maxn];
int main(){
	int n,k;
	cin>>n>>k;
	set<node>s;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		if(i!=0){
			printf("%d:",data);
			int num=0;
			for(auto it=s.begin();it!=s.end()&&num<k;it++){
				printf(" %d",it->value);
				num++;
			}
			printf("\n");
		}
		auto it=s.find(node{data,book[data]});  //本行写成如右所示亦可   auto it = st.find({data,book[data]});
		if(it!=s.end()) s.erase(it);
		book[data]++;
		s.insert(node{data,book[data]});  //按顺序分别赋值给value、cnt，如果结构体中先定义cnt再value则这里会先赋值给cnt再value，则会出错 
	}									// 上一行行写成如右所示亦可    st.insert({data,book[data]});
	return 0;
} 

