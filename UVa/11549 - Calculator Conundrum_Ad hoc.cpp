/*
 * 11549 - Calculator Conundrum
 * 
 * Ad hoc...
 * cycle finding....
 * using STL set to memorise the varlue you have reach before...
 * and got the maximum number you can get is just enough...
 */

#include<iostream>
#include<cstdio>
#include<set>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    long long dataset;
    long long mod,k,n;
    cin>>dataset;
    while(dataset--)
    {
        cin>>n>>k;

        mod=1;
        while(n--)
            mod*=10;
        set<long long> s;
        long long key=0;
        while(s.find(k)==s.end())
        {
            key=max(key,k);
            s.insert(k);

            k*=k;
            if(k>=mod)
                while(k>=mod)
                    k/=10;
        }

        cout<<key<<endl;
    }

    return 0;
}
