#include<bits/stdc++.h>
using namespace std;
map<string,bool>mp;
int main(){
	int m,n,s;
	string str;
	scanf("%d%d%d",&m,&n,&s);
	bool flag=false;
	for(int i=1;i<=m;i++){
		cin>>str;
		if((i-s)>=0&&(i-s)%n==0){
			if(mp.count(str)==0){
				mp[str]=true;
				cout<<str<<endl;
			}else {
				s=i+1;
				continue;
			}
		}
	}
	if(mp.size()==0) printf("Keep going...");
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    int M,N,S;
    scanf("%d%d%d",&M,&N,&S);
    vector<string>v(M+1);//����������ַ���
    for(int i=1;i<=M;++i)
        cin>>v[i];
    unordered_set<string>s;//�����н����ַ���
    for(int i=S;i<=M;i+=N){
        while(s.find(v[i])!=s.end())//���ַ����й���
            ++i;//����˳��ȡ��һλ
        if(i<=M){
            cout<<v[i]<<endl;//������н��ַ���
            s.insert(v[i]);//�����н��ַ�������s��
        }
    }
    if(s.empty())//���û���ַ����й�������Ҫ�����
        cout<<"Keep going..."<<endl;
    return 0;

}

 */
