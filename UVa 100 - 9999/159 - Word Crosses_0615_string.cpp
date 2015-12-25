/*
159 - Word Crosses

string...
Ð´µÄºÜ±©Á¦...
*/

#include<iostream>
#define MAXN 15
using namespace std;

struct WORD
{
	char s[2][MAXN];
	int p[2],l[2];
}a,b;

bool chk(WORD &t)
{
	t.l[0]=strlen(t.s[0]);
	t.l[1]=strlen(t.s[1]);

	for(int i=0;i<t.l[0];++i)
		for(int j=0;j<t.l[1];++j)
			if(t.s[0][i]==t.s[1][j])
			{
				t.p[0]=i;
				t.p[1]=j;
				return true;
			}
	return false;
}

void empty(int n)
{
	while(n--)
		putchar(' ');
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	bool first=true;
	while(cin>>a.s[0] && a.s[0][0]!='#')
	{
		if(!first)
			putchar('\n');
		first=false;

		cin>>a.s[1]>>b.s[0]>>b.s[1];
		if(!chk(a) || !chk(b))
			puts("Unable to make two crosses");
		else
		{
			int jump=a.l[0]-a.p[0]+3+b.p[0]-1;

			int p=0;
			if(a.p[1]>b.p[1])
			{
				int d=a.p[1]-b.p[1];
				for(int i=0;i<d;++i)
				{
					empty(a.p[0]);
					putchar(a.s[1][i]);
					putchar('\n');
				}

				for(int i=d;i<a.p[1];++i)
				{
					empty(a.p[0]);
					putchar(a.s[1][i]);
					empty(jump);
					putchar(b.s[1][ i-d ]);
					putchar('\n');
				}
			}
			else
			{
				int d=b.p[1]-a.p[1];
				for(int i=0;i<d;++i)
				{
					empty(a.l[0]+3+b.p[0]);
					putchar(b.s[1][i]);
					putchar('\n');
				}

				for(int i=d;i<b.p[1];++i)
				{
					empty(a.p[0]);
					putchar(a.s[1][ i-d ]);
					empty(jump);
					putchar(b.s[1][i]);
					putchar('\n');
				}
			}

			printf("%s   %s\n",a.s[0],b.s[0]);

			int l1=a.l[1]-a.p[1]-1;
			int l2=b.l[1]-b.p[1]-1;

			if(l1>l2)
			{
				for(int i=0;i<l2;++i)
				{
					empty(a.p[0]);
					putchar(a.s[1][ i+a.p[1]+1 ]);
					empty(jump);
					putchar(b.s[1][ i+b.p[1]+1 ]);
					putchar('\n');
				}
				for(int i=l2;i<l1;++i)
				{
					empty(a.p[0]);
					putchar(a.s[1][ i+a.p[1]+1 ]);
					putchar('\n');
				}
			}
			else
			{
				for(int i=0;i<l1;++i)
				{
					empty(a.p[0]);
					putchar(a.s[1][ i+a.p[1]+1 ]);
					empty(jump);
					putchar(b.s[1][ i+b.p[1]+1 ]);
					putchar('\n');
				}
				for(int i=l1;i<l2;++i)
				{
					empty(a.l[0]+3+b.p[0]);
					putchar(b.s[1][ i+b.p[1]+1 ]);
					putchar('\n');
				}
			}
		}
	}

	return 0;
}
