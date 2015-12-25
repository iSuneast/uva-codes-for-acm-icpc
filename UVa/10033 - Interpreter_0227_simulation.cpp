/*
10033 - Interpreter

模拟题.
按照题目的意思做就可以了.
读取数据的时候要特别注意.
应该把mem保存为int[]而不是char[][].
否则代码会显得臃肿庞大,易出错
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
		for(int i=0;flag;++cnt)		//这里不能限定i的范围.可能会有跨度很大的内存访问
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
		if(flag)		//以防没有停机时,空语句输出.
			cout<<cnt<<endl;
	}

return 0;
}
