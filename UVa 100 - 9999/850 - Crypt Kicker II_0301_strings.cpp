/*
850 - Crypt Kicker II

��UVa������...
"There are at most 100 input lines. "
������Ū��100,ȴһֱWA...
����һ��Ҳ��...
��������100�����ݵĻ�...
�ҿ�������̫Сʱ�������...
���Ǿ�Ȼ����RE����WA....
����Խ�粻��Խ�ú�������....
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
	char buf[110][100],asc2[128];		//�����Ǹı���һ��buf����Ĵ�С��AC��.
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
