/*
 * 10460 - Find the Permuted String
 * 
 * simulation...
 * just simulation as the problem description...
 * I have got a dozen of WA because of silly misktake...
 * how poor I am~
 * 
 * happy coding...
 */

import java.math.*;
import java.util.*;

public class Main {
	public static void main(String args[])
	{
		Scanner in=new Scanner(System.in);
		
		int dataset=in.nextInt();
		for(int cas=1; cas<=dataset; ++cas)
		{
			in.nextLine();
			String s=in.nextLine(), key="";
			BigInteger per=in.nextBigInteger(), idx=BigInteger.ONE;
			int l=s.length();
			
			for(int i=2;i<=l;++i)
			{
				idx=idx.multiply(BigInteger.valueOf(i));
			}
			
			per=per.mod(idx);
			
			if(per.equals(BigInteger.ZERO))
			{
				System.out.println(s);
				continue;
			}
			
			BigInteger pre=BigInteger.ZERO;
			for(int dep=0;dep<l;++dep)
			{
				idx=idx.divide(BigInteger.valueOf(dep+1));
				BigInteger sum=pre.add(idx);
				
				for(int insert=0;insert<=dep;++insert)
				{					
					if(per.compareTo(sum)<=0)
					{
						String buf=key;
						key=buf.substring(0,insert)+ s.charAt(dep) +buf.substring(insert, dep);							

						pre=sum.subtract(idx);
						
						break;
					}
					sum=sum.add(idx);
				}
			}
			
			System.out.println(key);
		}
	}
}

