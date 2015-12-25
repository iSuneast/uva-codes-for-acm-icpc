/*
 * 739 - Soundex Indexing
 *
 * Ad hoc...
 * simulation...
 *
 * just do as problem description...
 * no tricks...
 */

#include<cstdio>
#include<cstring>

char s[30],key[4];
char h[128];

void init()
{
    h['A']=h['E']=h['I']=h['O']=h['U']=h['Y']=h['W']=h['H']='0';
    h['B']=h['P']=h['F']=h['V']='1';
    h['C']=h['S']=h['K']=h['G']=h['J']=h['Q']=h['X']=h['Z']='2';
    h['D']=h['T']='3';
    h['L']='4';
    h['M']=h['N']='5';
    h['R']='6';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    init();
    puts("         NAME                     SOUNDEX CODE");

    while(scanf("%s",s)!=EOF)
    {
        int p=0;
        strcpy(key,"000");

        for(int i=1;s[i] && p<3;++i)
        {
            if(h[ s[i] ]!='0' && h[ s[i-1] ]!=h[ s[i] ] )
                key[p++]=h[ s[i] ];
        }
        printf("         %s",s);
        int t=25-strlen(s);
        while(t--)
            putchar(' ');
        printf("%c%s\n",s[0],key);
    }
    
    puts("                   END OF OUTPUT");

    return 0;
}

