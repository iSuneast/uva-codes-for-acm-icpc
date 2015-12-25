/*
 * 602 - What Day Is It?
 *
 * Ad hoc...
 * no trick...but U have to read the problem carefully...
 *
 * @ if (year<=1752 && year%4==0) then year is a LEAP YEAR...
 *   else if( year%4==7 && year%100 || year%400==0 ) then year is a LEAP YEAR...
 *
 * @ indeed the days between 9/2/1752 ~ 9/14/1752 is  invalid...
 *
 * @ if the date is later than 9/2/1752 we should "minus 11"
 * because "when the day following September 2 was declared to be September 14."
 * we have jump 11 days...
 * 
 * 
 */

#include<cstdio>
using namespace std;

const char DAY[][10]={ "",
    "Monday",   "Tuesday",  "Wednesday",
    "Thursday",  "Friday",   "Saturday",    "Sunday"};

const char MONTH[][20]={ "",
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"  };

const int days[]={0,31,28,31, 30,31,30, 31,31,30, 31,30,31};

int m,d,y,add;

bool leap(int n)
{
    if(n<=1700)
        return n%4==0;
    return (n%4==0 && n%100) || (n%400==0);
}

bool chk()
{
    if(y<0 || m<1 || 12<m || d<1 || 31<d)
        return false;
    add=leap(y);
    if(m==2)
        return d<=28+add;
    if(y==1752 && m==9)
        return !(2<d && d<14);
    return d<=days[m];
}

int day()
{
    int key=d+y*365+2;
    for(int i=1;i<m;++i)
        key+=days[i];
    if(m>2)
        key+=add;
    for(int i=0;i<y;i+=4)
        key+=leap(i);

    if(y>1752)
        key-=11;
    else if(y==1752 && m>9)
        key-=11;
    else if(y==1752 && m==9 && d>2)
        key-=11;
    
    return key;
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
#endif

    while(scanf("%d%d%d",&m,&d,&y)!=EOF && (m||d||y))
    {
        if(!chk())
            printf("%d/%d/%d is an invalid date.\n",m,d,y);
        else
            printf("%s %d, %d is a %s\n",MONTH[m],d,y,DAY[day()%7+1] );
    }

    return 0;
}

