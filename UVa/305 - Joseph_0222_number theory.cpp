/*
305 - Joseph
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int k,key[]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
	while(cin>>k && k)
		cout<<key[k]<<endl;

return 0;
}

/*
#include<iostream>

using namespace std;

int list[30],k,key;

bool chk(int key)
{
	memset(list,0,sizeof(list));
	int t,set=k,p=-1;
	while(set--)
	{
		t=key;
		while(t)
		{
			p=(p+1)%(2*k);
			if(!list[p])
				t--;
		}
		if(p < k)
			return false;
		list[p]=1;
	}
	return true;
}

int main()
{
//	freopen("in.txt","r",stdin);

	while(cin>>k && k)
	{
		key=k;
		while(key++)
			if(chk(key))
				break;
		cout<<key<<endl;
	}

return 0;
}

*/