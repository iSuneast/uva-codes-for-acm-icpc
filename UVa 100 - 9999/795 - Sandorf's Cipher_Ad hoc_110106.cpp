/*
 * 795 - Sandorf's Cipher
 * 
 * Ad hoc...
 * a straight forward solution will do...
 * happy coding...
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 110
#define SZ 6
using namespace std;

struct CIPHER
{
	bool cipher[SZ][SZ];
	
	void init()
	{
		memset(cipher,0,sizeof(cipher));
		cipher[0][1]=true;
		cipher[0][3]=true;
		cipher[0][5]=true;
		
		cipher[1][4]=true;
		
		cipher[2][2]=true;
		
		cipher[3][1]=true;
		cipher[3][4]=true;
		
		cipher[4][5]=true;
		cipher[5][3]=true;
	}
	
	void rotate()
	{
		CIPHER cur=*this;
		for(int i=0;i<SZ;++i)
			for(int j=0;j<SZ;++j)
				cipher[i][j]=cur.cipher[SZ-1-j][i];
	}
}final;

char mat[SZ][SZ];
char s[MAXN];

void decode()
{			
	int l=strlen(s),p=0;
	for(int i=0;i<l;i+=36)
	{
		for(int j=i;j<i+36;++j)
		{
			int r=(j-i)/SZ, c=(j-i)%SZ;
			mat[r][c]=s[j];
		}
		
		for(int d=0;d<4;++d,final.rotate())
		{
			for(int r=0;r<SZ;++r)
			{
				for(int c=0;c<SZ;++c)
				{
					if(final.cipher[r][c])
						s[p++]=mat[r][c];
				}
			}
		}
	}
	
	for(int i=0;i*2<l;++i)
		swap(s[i],s[l-1-i]);
	for(int i=l-1;i>=0;--i)
	{
		if(s[i]=='#')
			s[i]=0;
		else
			break;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    
    final.init();
    while(gets(s))
    {
    	decode();
    	puts(s);
    }

    return 0;
}

