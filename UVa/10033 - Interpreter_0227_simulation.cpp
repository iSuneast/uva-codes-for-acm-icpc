/*
10033 - Interpreter

ģ����.
������Ŀ����˼���Ϳ�����.
��ȡ���ݵ�ʱ��Ҫ�ر�ע��.
Ӧ�ð�mem����Ϊint[]������char[][].
���������Ե�ӷ���Ӵ�,�׳���
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset,ip[11],mem[1010];
	bool first=true;
	char buf[10];
	cin>>dataset;getchar();getchar();
	while(dataset--)
	{
		if(first)
			first=false;
		else
			cout<<endl;
		int p=0;
		memset(mem,0,sizeof(mem));
		while(gets(buf) && buf[0])
			sscanf(buf,"%d",&mem[p++]);
		bool flag=true;
		int b,c,cnt=1;
		memset(ip,0,sizeof(ip));
		for(int i=0;flag;++cnt)		//���ﲻ���޶�i�ķ�Χ.���ܻ��п�Ⱥܴ���ڴ����
		{
			b=mem[i]/10%10;
			c=mem[i]%10;
			switch(mem[i++]/100)
			{
			case 1:	cout<<cnt<<endl;	flag=false;	break;
			case 2:	ip[b]=c;	break;
			case 3:	ip[b]=(ip[b]+c)%1000;	break;
			case 4:	ip[b]=(ip[b]*c)%1000;	break;
			case 5:	ip[b]=ip[c];	break;
			case 6:	ip[b]=(ip[b]+ip[c])%1000;	break;
			case 7:	ip[b]=(ip[b]*ip[c])%1000;	break;
			case 8:	ip[b]=mem[ip[c]];	break;
			case 9:	mem[ip[c]]=ip[b];	break;
			case 0:	if(ip[c])	i=ip[b];	break;
			}
		}
		if(flag)		//�Է�û��ͣ��ʱ,��������.
			cout<<cnt<<endl;
	}

return 0;
}
