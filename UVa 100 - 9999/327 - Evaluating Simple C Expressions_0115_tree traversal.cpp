/*
327 - Evaluating Simple C Expressions
*/

#include<iostream>
#include<cstring>
#include<ctype.h>

using namespace std;

int var[30],flag[30],res[30],i,l,j;
char eva[120];

void init()
{
	memset(flag,0,sizeof(flag));
	memset(res,0,sizeof(res));
	memset(var,0,sizeof(var));
	for(i=0;i<26;i++)
		var[i]=i+1;
}

void format()
{
	for(j=i=0;i<l;i++)
		if(isalpha(eva[i]))
			flag[eva[i]-'a']=1,eva[j++]=eva[i];
		else if(eva[i]=='+'||eva[i]=='-')
			eva[j++]=eva[i];
	eva[j]='\0';
	l=j;
}

void calc()
{
	for(i=0;i<l-1;i++)
		if(eva[i]==eva[i+1])
		{
			if((i-1>=0)&&isalpha(eva[i-1]))
			{
				if(eva[i]=='+')
					res[eva[i-1]-'a']++;
				else if(eva[i]=='-')
					res[eva[i-1]-'a']--;
			}
			else if((i+2<l)&&isalpha(eva[i+2]))
			{
				if(eva[i]=='+')
					var[eva[i+2]-'a']++;
				else if(eva[i]=='-')
					var[eva[i+2]-'a']--;
			}
			eva[i]=eva[i+1]=' ';
		}
}

void result()
{
	int ans=0;
	i=0;
	if(isalpha(eva[0]))
		ans=var[eva[0]-'a'],i+=2;
	else
		i++;
	for(;i<l;i+=2)
		if(eva[i-1]=='+')
			ans+=var[eva[i]-'a'];
		else
			ans+=-var[eva[i]-'a'];
	printf("    value = %d\n",ans);
}

void print()
{
	for(i=0;i<26;i++)
		if(flag[i])
			printf("    %c = %d\n",'a'+i,var[i]+res[i]);
}

int main()
{
	char c;
	int t;
	while(gets(eva))
	{
		t=0;
		init();
		printf("Expression: %s\n",eva);
		l=strlen(eva);
		format();
		calc();
		format();
		result();
		print();
	}

return 0;
}