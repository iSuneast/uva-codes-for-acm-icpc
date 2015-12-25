/*
271 - Simply Syntax

Ad hoc...
stack...
prefix expression...
ǰ׺���ʽ...
�жϱ��ʽ�Ƿ�Ϸ�����...
*/

#include<iostream>
#include<string>
using namespace std;

string s;
char hash[128];

void init()
{
	for(int i='p';i<='z';++i)
		hash[i]=1;		//�൱�ڱ���
	hash['N']=2;		//�൱�뵥Ŀ�����
	hash['C']=hash['D']=hash['E']=hash['I']=3;	//�൱��˫Ŀ�����
}

int main()
{
//	freopen("in.txt","r",stdin);

	init();
	while(cin>>s)
	{
		int l=s.length(),i,correct=0;
		bool key=true;
		for(i=l-1;i>=0 && key;--i)
			if(hash[s[i]]==1)
				++correct;
			else if(hash[s[i]]==2 && correct>=1)
				continue;
			else if(hash[s[i]]==3 && correct>=2)
				correct--;
			else
				key=false;
		cout<<((key && correct==1)?"YES":"NO")<<endl;
	}

	return 0;
}
