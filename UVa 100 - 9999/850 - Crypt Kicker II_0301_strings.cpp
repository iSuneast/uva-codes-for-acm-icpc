/*
850 - Crypt Kicker II

对UVa无语了...
"There are at most 100 input lines. "
我正好弄了100,却一直WA...
后来一想也对...
如果真的有100组数据的话...
我开的数组太小时会溢出的...
可是竟然不是RE而是WA....
可能越界不是越得很厉害吧....
*/

#include<iostream>
#include<cstring>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("850.txt","w",stdout);

	char key[]="the quick brown fox jumps over the lazy dog";
	int dataset,keyl=43,keybk[100]={3,5,5,3,5,4,3,4,3};
	char buf[110][100],asc2[128];		//仅仅是改变了一下buf数组的大小就AC了.
	bool first=true;
	cin>>dataset;getchar();getchar();
	while(dataset--)
	{
		if(first)
			first=false;
		else
			cout<<endl;
		int cnt=0,i,j;
		bool found=false;
		while(gets(buf[cnt]) && buf[cnt][0])
			cnt++;
		for(i=0;i<cnt && !found;i++)
			if(strlen(buf[i]) == keyl)
			{
				char tmp[100];
				strcpy(tmp,buf[i]);
				char *token=strtok(tmp," ");
				int p=0;
				while(token!=NULL)
				{
					if(strlen(token)!=keybk[p++])
						break;
					token=strtok(NULL," ");
				}
				if(p==9)
				{
					memset(asc2,0,sizeof(asc2));
					found=true;
					for(j=0;j<keyl;j++)
						if(!asc2[buf[i][j]])
							asc2[buf[i][j]]=key[j];
						else if(asc2[buf[i][j]]!=key[j])
						{
							found=false;
							break;
						}
				}
			}
		if(!found)
		{
			cout<<"No solution."<<endl;
			continue;
		}
		for(i=j=0;i<cnt;i++,j=0)
		{
			while(buf[i][j])
				cout<<asc2[buf[i][j++]];
			cout<<endl;
		}
	}

return 0;
}
