/*
253 - Cube painting
...
*/

#include<iostream>
#include<string>

using namespace std;

string str;
int cub[24][6]={
{1,2,3,4,5,6},{1,3,5,2,4,6},{1,5,4,3,2,6},{1,4,2,5,3,6},
{2,6,3,4,1,5},{2,3,1,6,4,5},{2,1,4,3,6,5},{2,4,6,1,3,5},
{6,5,3,4,2,1},{6,3,2,5,4,1},{6,2,4,3,5,1},{6,4,5,2,3,1},
{5,1,3,4,6,2},{5,3,6,1,4,2},{5,6,4,3,1,2},{5,4,1,6,3,2},
{4,2,1,6,5,3},{4,1,5,2,6,3},{4,5,6,1,2,3},{4,6,2,5,1,3},
{3,1,2,5,6,4},{3,2,6,1,5,4},{3,6,5,2,1,4},{3,5,1,6,2,4}};

int calc()
{
	int i;
	for(i=0;i<24;i++)
		if(str[cub[i][0]-1]==str[6])
		if(str[cub[i][1]-1]==str[7])
		if(str[cub[i][2]-1]==str[8])
		if(str[cub[i][3]-1]==str[9])
		if(str[cub[i][4]-1]==str[10])
		if(str[cub[i][5]-1]==str[11])
			return 1;
	return 0;
}

int main()
{
	while(getline(cin,str))
	{
		if(calc())
			cout<<"TRUE"<<endl;
		else
			cout<<"FALSE"<<endl;
	}

return 0;
}
