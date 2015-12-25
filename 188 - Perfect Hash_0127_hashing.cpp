/*
188 - Perfect Hash
*/

#include<iostream>
#include<cstring>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j,cnt;
	unsigned long hash[15],c,t1,t2,b;
	char buf[500],*token;
	
	while(gets(buf))
	{
		cout<<buf<<endl;
		memset(hash,0,sizeof(hash));
		cnt=0;c=2147483648;
		token=strtok(buf," ");
		while(token!=NULL)
		{
			for(i=0;i<strlen(token);i++)
				hash[cnt]=hash[cnt]*32+token[i]-'a'+1;
			c=c<hash[cnt]?c:hash[cnt];
			cnt++;
			token=strtok(NULL," ");
		}
		while(1)
		{
			b=-1;
			for(i=0;i<cnt;i++)
				for(j=0;j<cnt;j++)
					if(i!=j&&((c/hash[i])%cnt==(c/hash[j])%cnt))
					{
						t1=(c/hash[i]+1)*hash[i];
						t2=(c/hash[j]+1)*hash[j];
						if(t1>t2)
							b=t2;
						else
							b=t1;
					}
			if(b==-1)
				break;
			c=b;
		}
		cout<<c<<endl<<endl;
	}

return 0;
}
