/*
 * 11545 - Avoiding Jungle in the Dark
 *
 * dp...
 *
 * a little hard for me to understand the problem
 * after struggle for a long time, I finally solve it : )
 *
 * -----------------------------    input
5
S*******D
S*******.***********D
S***********.*******D
S***********D
S************D
 * -----------------------------    output
Case #1: 8
Case #2: 36
Case #3: 36
Case #4: 12
Case #5: -1
 * -----------------------------
 *
 * these test cases will help U understand this problem better...
 *
 * use dynamic-programming to handle these problem
 * dis[POSITION][HOUR] to store the time we spend when we are in POSITION at HOUR
 * when we are in position "P", try to backtrack position [P-16,P) and find a better way
 *
 * "However, he can decide to have a rest anytime he wants, even after getting up from one rest session"
 * so we have to process dis[P][HOUR+SLEEP_TIME] and dis[P][HOUR+SLEEP_TIME*2] using dis[P][HOUR]
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 1003
#define HOUR 24
#define TRAVEL 16
#define SLEEP 8
#define MORNING 6
using namespace std;
const int INF=0x3f3f3f3f;

char maps[MAXN];
int dis[MAXN][HOUR];

void ChkMin(int &cur,int t)
{
    if(t<cur)
        cur=t;
}

bool ok(int pre,int hour,int cur)
{
    for(;pre<=cur;++pre,hour=(hour+1)%HOUR)
        if(maps[pre]=='*' && !(6<hour && hour<18))
            return false;
    if(maps[cur]!='*')
        return true;
    for(int add=1;add<SLEEP;++add,hour=(hour+1)%HOUR)
        if(!(6<hour && hour<18))
            return false;
    return true;
}

int dp()
{
    memset(dis,0x3f,sizeof(dis));
    dis[0][MORNING]=MORNING;
    int l=strlen(maps);
    
    for(int s=0;s<l;++s)
    {
        for(int pre=s-1,go=1;go<=TRAVEL && pre>=0;--pre,++go)
        {
            for(int hour=0;hour<HOUR;++hour)
            {
                if(dis[pre][hour]==INF || !ok(pre,hour,s))
                    continue;
                int final=dis[pre][hour]+go+SLEEP;
                ChkMin(dis[s][final%HOUR],final);
            }
        }

        for(int hour=0;hour<HOUR;++hour)
        {
            int next=hour;
            next=(next+SLEEP)%HOUR;
            if(maps[s]!='*' || (12<next && next<18))
                ChkMin(dis[s][next],dis[s][hour]+SLEEP);
            next=(next+SLEEP)%HOUR;
            if(maps[s]!='*' || (12<next && next<18))
                ChkMin(dis[s][next],dis[s][hour]+SLEEP*2);
        }
    }

    int key=INF;
    for(int i=0;i<HOUR;++i)
        key=min(key,dis[l-1][i]);
    
    return key==INF?-1:key-MORNING-SLEEP;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d",&dataset);
    for(int cas=1;cas<=dataset;++cas)
    {
        scanf("%s",maps);
        printf("Case #%d: %d\n",cas,dp());
    }

    return 0;
}

