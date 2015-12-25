/*
 * 11489 - Integer Game
 * 
 * game theory...
 * It seams so easy...
 * just calc the sum of all the digits...
 * count the numbers of legal number i,so that
 * (sum-i)%3==0
 * if numbers is odd,S win...
 * oters T win...
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 1003
using namespace std;

char var[MAXN];
int cnt[13];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
        scanf("%s",var);
        memset(cnt,0,sizeof(cnt));
        int p=0,s=0;
        while(var[p])
        {
            ++cnt[ var[p]-'0' ];
            s+=var[p++]-'0';
        }
        int key=0;
        bool done=true;
        while(p && done)
        {
            done=false;
            for(int i=1;i<10 && !done;++i)
                if(cnt[i] && (s-i)%3==0)
                {
                    s-=i;
                    --p;
                    --cnt[i];
                    ++key;
                    done=true;
                    break;
                }
        }
        printf("Case %d: %c\n",cas,key%2?'S':'T');
    }

    return 0;
}
