/*
 * 910 - TV game
 *
 * dp...
 * a simple problem...
 * almost the same as Number_Triangle..
 */

#include<cstdio>
#include<cstring>
#include<vector>
#define MAXN 33
using namespace std;

int dp[MAXN][MAXN],next[MAXN][2];
char s[3];

int in()
{
    scanf("%s",s);
    return s[0]-'A';
}

bool special()
{
    scanf("%s",s);
    return s[0]=='x';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int n,m;
    while(scanf("%d",&n)!=EOF)
    {
        vector<int> sp;
        for(int i=0;i<n;++i)
        {
            int u=in();
            next[u][0]=in();
            next[u][1]=in();
            if(special())
                sp.push_back(u);
        }

        scanf("%d",&m);
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                dp[i+1][ next[j][0] ]+=dp[i][j];
                dp[i+1][ next[j][1] ]+=dp[i][j];
            }
        }

        int key=0;
        for(int i=0;i<sp.size();++i)
            key+=dp[m][ sp[i] ];
        printf("%d\n",key);
    }

    return 0;
}

