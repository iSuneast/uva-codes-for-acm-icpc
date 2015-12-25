/*
 * 10275 - Guess the Number!
 * 
 * Ad hoc...
 * 神题啊~
 * 交了我大几十次...
 * 
 * 思路很简单
 * N^N = S
 * 则 N*log10(N) = log10(S) = log10( 10^500 000 ) = 500 000
 * 即 N的最大值为100 000
 * 二分N,比较N^N与S的长度, Length( N^N ) = floor(N*log10(N))+1
 *   @ 不同, 继续二分
 *   @ 相同, 算出N^N, 与S比较 (显然这里是最关键的)
 * 
 * 一直没搞明白: 如下的条件怎么用
 * "I promise that if I'm wrong, my result and the correct result will differ in exactly one single digit"
 * 后来看了别人的blog才知道,对某>10的素数MOD
 * S % MOD = (N^N) % MOD
 * 因为至多只有一位不同, 所以, 只要MOD后能相等,原来的也相等
 * 
 * 证明如下:
 * 令 S = S' + X, 且S'与 S至多一位不同
 * S % MOD = S' % MOD + X % MOD = N^N % MOD
 * 易知, X 数值形式为 +/-10^k, 而 10^k % MOD != 0 (注意,MOD为大于10的素数)
 * 于是,可得 S' % MOD != N^N % MOD
 * 证明完毕.
 * 
 * happy coding~
 */

import java.math.*;
import java.io.*;

public class Main {

	static int len;
	static final int MOD = 13;
	static String str;
	
	static int pow_mod(int a,int b)
	{
		int ans=1, mul=a;
		for(; b>0; b>>=1)
		{
			if(b%2==1)
				ans = (ans*mul)%MOD;
			mul = (mul*mul)%MOD;
		}
		return ans;
	}
	
	static int process(int m)
	{
		int l=(int)Math.floor( m * Math.log10((double)m) )+1;
		if(l!=len)
			return l>len?1:-1;
		
		int rem=0;
		for(int i=0; i<len; ++i)
		{
			rem = ( rem*10 + str.charAt(i)-'0' )%MOD;
		}
		
		if(pow_mod(m%MOD, m)==rem)
			return 0;
		return -2;
	}
	
	public static void main(String args[]) throws IOException
	{		
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

		int dataset=Integer.parseInt(in.readLine());
		for(int cas=1; cas<=dataset; ++cas)
		{
			str = in.readLine().trim();
			len=str.length();
			
			if(len==1)
			{
				if(str.compareTo("1")==0)
					out.println(1);
				else if(str.compareTo("4")==0)
					out.println(2);
				else
					out.println(-1);
				continue;
			}
			
			int low = 3, up = 100000, ans=-1;
			while(low<=up)
			{
				int mid= (up+low)/2;
				int what = process(mid);
				if(what==1)
					up=mid-1;
				else if(what==-1)
					low=mid+1;
				else
				{
					if(what==0)
						ans=mid;
					break;
				}
			}
			
			out.println(ans);
		}
		out.flush();
	}
}
