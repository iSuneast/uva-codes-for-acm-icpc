/*
 * 741 - Burrows Wheeler Decoder
 *
 * Ad hoc...
 *
 * -----------------------------------------------------------------------------------
 FUNCTION BWT (string s)
   create a table, rows are all possible rotations of s
   sort rows alphabetically
   return (last column of the table)

 FUNCTION inverseBWT (string s)
   create empty table

   repeat length(s) times
       insert s as a column of table before first column of the table   // first insert creates first column
       sort rows of the table alphabetically
   return (row that ends with the 'EOF' character)
 * -----------------------------------------------------------------------------------
 * just do as the description above...
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXLEN 303
using namespace std;

struct ANSWER
{
    char str[MAXLEN];
    bool operator<(const ANSWER &t)const
    {
        return strcmp(str,t.str)<0;
    }
}ans[MAXLEN];

char code[MAXLEN];
int n,len;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    bool first=true;
    while(scanf("%s%d",code,&n)!=EOF && (strcmp(code,"END") && n))
    {
        if(!first)
            putchar(10);
        first=false;
        
        len=strlen(code);
        for(int i=0;i<len;++i)
        {
            for(int j=0;j<len;++j)
                ans[i].str[j]='A'-1;
            ans[i].str[len]=0;
        }
        
        for(int i=len-1;i>=0;--i)
        {
            for(int j=0;j<len;++j)
                ans[j].str[i]=code[j];
            sort(ans,ans+len);
        }

        puts(ans[n-1].str);
    }

    return 0;
}

