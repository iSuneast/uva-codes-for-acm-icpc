/*
 * 11538 - Chess Queen
 * 
 * math...
 * a boring math problem...
 * just try to general the format and than verify it...
 * 
 * submit it ,and you'll get AC...
 */

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    unsigned long long n,m;
    while(cin>>n>>m && (n||m))
    {
        if(n<m)
            swap(n,m);
        cout<<(10*m*m*m+2*m)/3-4*m*m+((((m*5)-3)*(n-m))+((n-m)-1)*(n-m))*m<<endl;
    }
    
    return 0;
}
