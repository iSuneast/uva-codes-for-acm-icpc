/*
486 - English-Number Translator

终于明白说学好英语有多么重要了..
*/

#include<iostream>
#include<sstream>
#include<map>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	map<string,long> m;

	m["zero"]=0;
	m["one"]=1;
	m["two"]=2;
	m["three"]=3;
	m["four"]=4;
	m["five"]=5;
	m["six"]=6;
	m["seven"]=7;
	m["eight"]=8;
	m["nine"]=9;
	m["ten"]=10;
	m["negative"]=-1;

	m["eleven"]=11;
	m["twelve"]=12;
	m["thirteen"]=13;
	m["fourteen"]=14;
	m["fifteen"]=15;
	m["sixteen"]=16;
	m["seventeen"]=17;
	m["eighteen"]=18;
	m["nineteen"]=19;

	m["twenty"]=20;
	m["thirty"]=30;
	m["forty"]=40;
	m["fifty"]=50;
	m["sixty"]=60;
	m["seventy"]=70;
	m["eighty"]=80;
	m["ninety"]=90;

	m["hundred"]=100;
	m["thousand"]=1000;
	m["million"]=1000000;

	string buf;
	while(getline(cin,buf))
	{
		long ans=0,t,flag=1;
		istringstream stream(buf);
		string num;
		while(stream>>num)
		{
			t=m[num];
			if(t<0)
			{
				flag=-1;
				continue;
			}
			else
			{
				while(stream>>num)
				{
					if(m[num]>=100)		//这里很关键
						t*=m[num];
					else
						t+=m[num];
					if(m[num]>=1000)	//这里是ans的存档点
						break;
				}
				ans+=t;
			}
		}
		cout<<ans*flag<<endl;
	}

return 0;
}
