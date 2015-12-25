/*
 * 10275 - Guess the Number!
 * 
 * Ad hoc...
 * ���Ⱑ~
 * �����Ҵ�ʮ��...
 * 
 * ˼·�ܼ�
 * N^N = S
 * �� N*log10(N) = log10(S) = log10( 10^500 000 ) = 500 000
 * �� N�����ֵΪ100 000
 * ����N,�Ƚ�N^N��S�ĳ���, Length( N^N ) = floor(N*log10(N))+1
 *   @ ��ͬ, ��������
 *   @ ��ͬ, ���N^N, ��S�Ƚ� (��Ȼ��������ؼ���)
 * 
 * һֱû������: ���µ�������ô��
 * "I promise that if I'm wrong, my result and the correct result will differ in exactly one single digit"
 * �������˱��˵�blog��֪��,��ĳ>10������MOD
 * S % MOD = (N^N) % MOD
 * ��Ϊ����ֻ��һλ��ͬ, ����, ֻҪMOD�������,ԭ����Ҳ���
 * 
 * ֤������:
 * �� S = S' + X, ��S'�� S����һλ��ͬ
 * S % MOD = S' % MOD + X % MOD = N^N % MOD
 * ��֪, X ��ֵ��ʽΪ +/-10^k, �� 10^k % MOD != 0 (ע��,MODΪ����10������)
 * ����,�ɵ� S' % MOD != N^N % MOD
 * ֤�����.
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
