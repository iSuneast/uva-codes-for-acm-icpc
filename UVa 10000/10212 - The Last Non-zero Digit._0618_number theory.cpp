/*
10212 - The Last Non-zero Digit.

number theory...
��������...
*/

#include<iostream>
#define MAXN 10
#define MOD 4
using namespace std;

int hash[MAXN][MOD],cnt[MAXN];

void init()
{
	hash[2][0]=6;
	hash[2][1]=2;
	hash[2][2]=4;
	hash[2][3]=8;

	hash[3][0]=1;
	hash[3][1]=3;
	hash[3][2]=9;
	hash[3][3]=7;

	hash[7][0]=1;
	hash[7][1]=7;
	hash[7][2]=9;
	hash[7][3]=3;

	hash[9][0]=1;
	hash[9][1]=9;
	hash[9][2]=1;
	hash[9][3]=9;
}

//��n!��������x���ֵĴ���
int count(int n,int x)
{
	int key=0;
	while(n)
	{
		key+=n/x;
		n/=x;
	}
	return key;
}

int g(int n,int x)
{
	int key=0;
	while(n)
	{
		key+=n/10;
		if(n%10>=x)
			++key;
		n/=5;
	}
	return key;
}

//��n!����xΪ������λ�����ָ���
int f(int n,int x)
{
	if(!n)
		return 0;
	return f(n/2,x)+g(n,x);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		cnt[2]=count(n,2)-count(n-m,2);
		cnt[5]=count(n,5)-count(n-m,5);

		cnt[3]=f(n,3)-f(n-m,3);
		cnt[7]=f(n,7)-f(n-m,7);
		cnt[9]=f(n,9)-f(n-m,9);

		int key=1;
		if(cnt[2]<cnt[5])
			key=5;
		else
		{
			if(cnt[2]>cnt[5])
				key*=hash[2][ (cnt[2]-cnt[5])%MOD ];
			key*=hash[3][ cnt[3]%MOD ];
			key*=hash[7][ cnt[7]%MOD ];
			key*=hash[9][ cnt[9]%MOD ];
			key%=MAXN;
		}

		printf("%d\n",key);
	}

	return 0;
}


/*
The first program

Consider the number N! factored into product of powers of prime numbers. It means N!=2i * 3j * 5k * 7l * ... Note, that for each N>1 the power i is greater than k. It means, that the last non-zero digit of N! is the same as the last digit of N! / (2k * 5k). Therefore we can compute the result using the equation:
(N! / (2k * 5k)) mod 10 = ((N! / (2i * 5k)) mod 10 * 2i-k mod 10) mod 10

Number i can be obtained easily - we will divide each a=1,2,...,N by 2 until the resulting number is not divisible by 2 and after each division we will add one to the variable i. Number k can be obtained in the same manner. Let f(i) denotes the number which we obtain by dividing i by the 2a * 5b where a and b are the highest numbers such that the i is divisible by this product. Number (N! / (2i * 5k)) mod 10 is equal to f(N!) mod 10 and can be computed as f(1) * f(2) * ... * f(N) mod 10. We will perform operation mod 10 after each multiplication in order to keep the resulting number as small as possible.

The advantege of this approach is that we do not need to implement arithmetics of large numbers. Some ideas used here are used in the second, more efficient program, as well.
The second program

The second program also computes the result as (2i-k mod 10 * f(N!) ) mod 10. Numbers i and k are computed much more efficiently. More precisely
i=N div 2 + (N div 2) div 2 + ((N div 2) div 2) div 2 + ...

(We get zero after finite number of divisions.) Number k can be computed in the same way. After that we can compute i-k and we need to find 2i-k mod 10. Observe, that
21 mod 10 = 2, 22 mod 10 = 4, 23 mod 10 = 8, 24 mod 10 = 6, 25 mod 10 = 2, 26 mod 10 = 4, ...

i.e. the period is 4 and we need only to compute (i-k) mod 4 and then to find corresponding last digit. This observation can help us to simplify computation of i and k - we do not need their exact values (that can be long) but we need only (i-k) mod 4.

We have shown how to compute 2i-k mod 10. Now let us consider f(N!) mod 10 = ((f(1) mod 10) * (f(2) mod 10) * ... * (f(N) mod 10)) mod 10. Note, that f(i) mod 10 is always 1,3,7 or 9. If we knew, how many 3,7,9 are among (f(1) mod 10), (f(2) mod 10), ..., (f(N) mod 10), we could compute 3a mod 10, 7b mod 10, 9c mod 10 in the similar way as we did for 2i-k (last digits of powers of 3,7,9 are also periodical).

To compute the number of 3,7,9 among (f(1) mod 10), (f(2) mod 10), ..., (f(N) mod 10) is not so easy. We will divide numbers 1,2,...,N into groups so, that in each group are numbers with same quotient i/f(i) and we will compute number of 3,7,9 among (f(i) mod 10) for each such group separatelly (there are O(N2) such groups). First, let us consider a group in which i/f(i)=1. This is the group of all numbers not divisible by 2 and 5. The number of 3,7,9 in this group is the same as number of 3,7,9 among 1 mod 10, 2 mod 10, ..., N mod 10. This number can be counted easily - it is N div 10 + a where a is 1 if the last digit of N is at least 3 (resp. at least 7 or at least 9). Now let us consider a group in which i/f(i)=L (where L=2a * 5b). We obtain this group by taking each L-th number from the sequence 1,2,3,... and dividing it by L. It means that number of 3,7,9 for this group will be the same as the number of 3,7,9 among 1 mod 10, 2 mod 10, ..., (N div L) mod 10.

Now we know everything we needed for construction of a program. Since numbers in the input file are long, we need to implement arithmetics for long numbers. However, by careful implementation we can achieve that only division of a long number by small integer is necessary.



�������ô�����أ��ȱ𼱣�������������һ�����漸�������⣺
1.������n�׳���������x(����˵5�����ֵĴ�����
����˵15�Ľ׳� ��1*2*3*4*5*6*7*8*9*10*11*12*13*14*15
����5���������ֻ��5�ı�������ų��֣������Ҵ�5��10��15�и����һ��5�����൱����15/5��������5,֮��5��10��15�ͱ����1��2��3��
���ڷ�5�ı�����Ȼ���ڿ��Ƿ�Χ֮�ڣ���������ֻ�������������������3�����ɡ�
���������ǿ����õݹ������������⡣������������������ǲ����ܹ����׵ؽ��n!ĩβ�ж��ٸ�0�أ����뿴...n!�� 0�ĸ����ǲ��Ǿͺ�ĳ���������ĸ����й��أ�^_^
����˵������Ҫ��5���ֵĴ�������������д��
int get5(int n)//����n!��������5�ĳ��ִ���
{
if(n==0)
return 0;
return n/5+get5(n/5);
}


2.������n!�׳�����0λ��
����˵����Ҫ��10!����0λ������������2��5���֮���ʹ��ĩβ����0.��ô���ǲ����� 10����2��5������ȫ��ȥ������������ע��2����Ŀ��ʵ��5��Ҫ�࣬��������Ҫ������Ƕ����2��ĩλ��Ӱ�죩
�� 1*2*3*4*5*6*7*8*9*10 ȥ��2 ��5 ���Ӻ� ����1*1*3*1*1*3*7*1*9*1������2��5�����Ѿ���ȥ������ôʣ�µ�����ĩβһ����3��7��9��1������֮һ��Ȼ�������������ôһ��������Ժ�ĩβ�����Ǽ�.����ٲ���2��ĩλ��Ӱ�켴�ɣ�

�ܽ�һ�£���10!���һ����0λ�Ĳ������£�
step1�����Ƚ�10! ������2��5����ȥ����
step2��Ȼ�����ʣ�µ�һ��������˺�ĩβ���Ǹ�����
step3������ȥ����2��5�࣬���Ҫ���Ƕ�����ǲ���2�Խ����Ӱ�졣
step4��output your answer!
����������������˵�ġ�To compute the number of 3,7,9 among (f(1) mod 10), (f(2) mod 10), ..., (f(N) mod 10) is not so easy���������沽��2�Ǹ��ѵ㡣������ʣ�µ��⴮������˺����һλ�Ǽ��أ������ת���������Щ������ĩβ��3��7��9�����ֳ��ֵĴ�����Ϊɶ����Ϊ��Щ����n�η����й��ɵģ�����Ϊ4�������������һ�£�
�ã�������������������⴮������ĩβ3��7��9���Գ��ֵĴ����ˣ�

һ������ʵ���Ͽ��Էֳ�ż���к������У���1*2*3*4*5*6*7*8*9*10Ϊ��

�ֳ�1 3 5 7 9,   2 4 6 8 10

�������ǳ��Էֱ����ͳ�ƣ����Է��֣�ʵ����2��4��6��8��10�еĸ���Ҳ����1 2 3 4 5�еĸ�����Ҳ����˵�����ְ�������⻮�ֳ���һ��ԭ������������⡣

f(n) = f(n/2) + g(n),g(n)��ʾ�������е���Ŀ������������Ҫ���g(n)

�ٴι۲�g(n)

ʵ�����ֳַ���������1 3 7 9 11 13 17 19 21�������Լ�5���汶��5��15��25������˵���ֳ�����������,���Ҫͳ�����������ĩβΪx��1��3��7��9���ĸ�����������д��g(n,x) = n/10+(n%10 >= x)+g(n/5,x) 

���������������ݹ鷽�̣����ǾͿ�����lgn��ʱ���ڼ����ĩβΪ1,3,7,9�����ĸ�����
���ˣ��������ǵõ����⴮������ĩβ��3��7��9�����ֵĸ�������������ѭ���ڵ����ʿ��Կ��ٵ�����⴮������˺�mod 10�Ľ�����ڿ����µ�ʱ�����2(��ʵҲ������ѭ�������������������𰸣�




������������������⣬������ P(n,m)���һ����0λ�ͱ��ʮ�������ˡ�
P(n,m)ʵ���ϵ��� n! / (n-m)!
���ǿ������n! ��(n-m)!��������2��5��3��7��9�ֱ���ֵĴ�����Ȼ���ٸ��������
Ȼ������ѭ���ڴ������ɣ�
BTW�����ﻹҪע��һ�� trick,����2�ĳ��ִ������С��5�����������������˵�ǿ��ܵģ����ǿ���ֱ�����5�����2����Ŀ����5����ô2��ѭ���ڲ���Ҫ���ǡ����� 3��7��9��ѭ���ڣ�������Щ����4�η�ĩλ�պ���1�����ԾͲ���Ҫ���⿼���ˡ�

*/