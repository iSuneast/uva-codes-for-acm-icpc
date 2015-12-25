/*
719 - Glass Beads

string...
最小表示法 by 周源

------------------------------------------------------------------
@ double the string -> str[] = "String""String"
@ i=0 j=1 k=0 len=str.length()
  while(i<len && j<len)
    # if(str[i+k] == str[j+k]) { k++; if(k==len) break; }
    # if(str[i+k] > str[j+k])  { i=i+k+1;  if(i<=j) i=j+1; k=0; }
    # if(str[i+k] < str[j+k])  { j=j+k+1; if(j<=i) j=i+1; k=0; }

  return Min(i,j)
------------------------------------------------------------------
A simple code using O(N)time above will solve the problem  :wink: 

*/

#include<iostream>
#define MAXN 20003
using namespace std;

char str[MAXN];
int len;

int MinP()
{
	int i=0,j=1,k=0;
	while(i<len && j<len)
	{
		if(str[i+k]==str[j+k])
		{
			++k;
			if(k==len)
				break;
		}
		else if(str[i+k]>str[j+k])
		{
			i=i+k+1;
			if(i<=j)
				i=j+1;
			k=0;
		}
		else
		{
			j=j+k+1;
			if(j<=i)
				j=i+1;
			k=0;
		}
	}

	return min(i,j);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%s",str);
		len=strlen(str);
		memcpy(str+len,str,sizeof(char)*len);

		printf("%d\n",MinP()+1);
	}

	return 0;
}
