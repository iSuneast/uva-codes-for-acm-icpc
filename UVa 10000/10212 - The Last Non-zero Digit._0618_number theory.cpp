/*
10212 - The Last Non-zero Digit.

number theory...
数论神题...
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

//求n!中质因子x出现的次数
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

//求n!中以x为最后非零位的数字个数
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



这个题怎么来做呢？先别急，我们先来讨论一下下面几个子问题：
1.如何求出n阶乘中质因数x(比如说5）出现的次数？
比如说15的阶乘 ：1*2*3*4*5*6*7*8*9*10*11*12*13*14*15
由于5这个质因数只在5的倍数里面才出现，所以我从5，10，15中各抽出一个5，这相当于有15/5个质因数5,之后5，10，15就变成了1，2，3；
由于非5的倍数显然不在考虑范围之内，所以我们只需继续讨论它的子问题3！即可。
这样，我们可以用递归来解决这个问题。有了这个方法，我们是不是能够轻易地解决n!末尾有多少个0呢？想想看...n!后 0的个数是不是就和某个质因数的个数有关呢？^_^
比如说，我们要求5出现的次数，可以这样写：
int get5(int n)//计算n!中质因子5的出现次数
{
if(n==0)
return 0;
return n/5+get5(n/5);
}


2.如何求出n!阶乘最后非0位？
比如说我们要找10!最后非0位，由于质因数2和5组合之后会使得末尾产生0.那么我们不妨把 10！中2，5质因数全部去掉，（但是请注意2的数目其实比5的要多，所以我们要在最后考虑多余的2对末位的影响）
如 1*2*3*4*5*6*7*8*9*10 去掉2 ，5 因子后 就是1*1*3*1*1*3*7*1*9*1，由于2，5因子已经被去除，那么剩下的数字末尾一定是3，7，9，1中四者之一。然后我们再求出这么一串数相乘以后末尾的数是几.最后再补上2对末位的影响即可！

总结一下，求10!最后一个非0位的步骤如下：
step1：首先将10! 中所有2，5因子去掉；
step2：然后求出剩下的一串数字相乘后末尾的那个数。
step3：由于去掉的2比5多，最后还要考虑多余的那部分2对结果的影响。
step4：output your answer!
正如上面文章里所说的“To compute the number of 3,7,9 among (f(1) mod 10), (f(2) mod 10), ..., (f(N) mod 10) is not so easy”，这里面步骤2是个难点。如何求出剩下的这串数字相乘后最后一位是几呢？这可以转化成求出这些数里面末尾是3，7，9的数字出现的次数（为啥？因为这些数的n次方是有规律的，周期为4，不信你可以推一下）
好，现在问题就是如何求出这串数字中末尾3，7，9各自出现的次数了；

一个数列实际上可以分成偶数列和奇数列，以1*2*3*4*5*6*7*8*9*10为例

分成1 3 5 7 9,   2 4 6 8 10

这样我们尝试分别进行统计，可以发现，实际上2，4，6，8，10中的个数也就是1 2 3 4 5中的个数，也就是说我们又把这个问题划分成了一个原来问题的子问题。

f(n) = f(n/2) + g(n),g(n)表示奇数列中的数目，所以我们需要解决g(n)

再次观察g(n)

实际上又分成了两部分1 3 7 9 11 13 17 19 21。。。以及5的奇倍数5，15，25。。。说明又出现了子问题,如果要统计这个数列中末尾为x（1，3，7，9）的个数可以这样写：g(n,x) = n/10+(n%10 >= x)+g(n/5,x) 

这样利用了两个递归方程，我们就可以在lgn的时间内计算出末尾为1,3,7,9的数的个数了
好了，现在我们得到了这串数字中末尾是3，7，9的数字的个数，我们利用循环节的性质可以快速地算出这串数字相乘后mod 10的结果，在考虑下当时多除的2(其实也可以用循环节来处理），便可求出答案！




解决了上面两个子问题，我想求 P(n,m)最后一个非0位就变得十分容易了。
P(n,m)实际上等于 n! / (n-m)!
我们可以求出n! 和(n-m)!中质因数2，5，3，7，9分别出现的次数，然后再各自相减。
然后再用循环节处理，即可！
BTW，这里还要注意一个 trick,就是2的出现次数如果小于5，（这对于排列数来说是可能的）我们可以直接输出5，如果2的数目等于5，那么2的循环节不需要考虑。至于 3，7，9的循环节，由于这些数的4次方末位刚好是1，所以就不需要特殊考虑了。

*/