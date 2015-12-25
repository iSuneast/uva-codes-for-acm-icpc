/*
 * 10363 - Tic Tac Toe
 *
 * Ad hoc...
 * seems quite a simple problem...
 * but with a lot of tricks...
 *
 * first, count the number of X's and O's
 *      check X==O || X==O+1 at first
 * if XWin && OWin, it's "no"
 * if XWin, also should meet X==O+1
 *          because if X==O, X is first hand and X is now the winner
 *              O is not necessary take one more move...
 * if OWin, we say X==O
 *          think like this, O is the winner now,
 *          and X is not necessary take one more move...
 *
 * Solved after a lot of WA...
 * good problem...
 */
#include<cstdio>

char tic[5][5];

bool win(char c)
{
    int cnt;
    for(int i=0;i<3;++i)
    {
        cnt=0;
        for(int j=0;j<3;++j)
            if(tic[i][j]==c)
                ++cnt;
        if(cnt==3)
            return true;

        cnt=0;
        for(int j=0;j<3;++j)
            if(tic[j][i]==c)
                ++cnt;
        if(cnt==3)
            return true;
    }

    if(tic[0][0]==c && tic[1][1]==c && tic[2][2]==c)
        return true;
    if(tic[0][2]==c && tic[1][1]==c && tic[2][0]==c)
        return true;

    return false;
}

bool chk()
{
    int o=0,x=0;
    for(int i=0;i<3;++i)
    {
        scanf("%s",&tic[i]);
        for(int j=0;j<3;++j)
        {
            if(tic[i][j]=='O')
                ++o;
            else if(tic[i][j]=='X')
                ++x;
        }
    }

    if(!(x==o || x==o+1))
        return false;
    
    bool oWin=win('O');
    bool xWin=win('X');

    if(oWin && xWin)
        return false;
    if(oWin && x==o)
        return true;
    if(xWin && x==o+1)
        return true;
    return !oWin && !xWin;
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
        puts(chk()?"yes":"no");
    }

    return 0;
}

