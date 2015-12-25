/*
 * 10497 - Sweet Child Makes Trouble
 * 
 * math...
 * 错排数...
 */

import java.math.*;
import java.util.*;

public class Main {
	public static void main(String args[])
	{
		Scanner in=new Scanner(System.in);
		final int MAXN=801;
		BigInteger m[]=new BigInteger [MAXN];
		m[0]=BigInteger.ZERO;
		m[1]=BigInteger.ZERO;
		m[2]=BigInteger.ONE;
		for(int i=3;i<MAXN;++i)
		{
			m[i]=BigInteger.valueOf(i-1).multiply(m[i-1].add(m[i-2]));
		}
		
		int n;
		while(in.hasNext())
		{
			n=in.nextInt();
			if(n==-1)
				break;
			System.out.println(m[n]);
		}
	}
}

