#include<bits/stdc++.h>
using namespace std;
const int maxn=50010;
struct node{
	int value,cnt;    //���ܷ����� 
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
		auto it=s.find(node{data,book[data]});  //����д��������ʾ���   auto it = st.find({data,book[data]});
		if(it!=s.end()) s.erase(it);
		book[data]++;
		s.insert(node{data,book[data]});  //��˳��ֱ�ֵ��value��cnt������ṹ�����ȶ���cnt��value��������ȸ�ֵ��cnt��value�������� 
	}									// ��һ����д��������ʾ���    st.insert({data,book[data]});
	return 0;
} 

