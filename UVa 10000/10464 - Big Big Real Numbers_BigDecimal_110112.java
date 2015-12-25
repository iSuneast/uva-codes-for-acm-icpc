/*
 * 10464 - Big Big Real Numbers
 * 
 * Ad hoc..
 * just use java BigDecimal to solve this problem...
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
			BigDecimal a=in.nextBigDecimal(), b=in.nextBigDecimal();
			String key= a.add(b).toPlainString();
			int l=key.length(), p, e=-1;
			for(p=l-1;p>=0;--p)
			{
				if(key.charAt(p)=='.')
				{
					for(e=l;e>0;--e)
					{
						if(key.charAt(e-1)!='0')
							break;
					}
					break;
				}
			}
			
			if(p==-1)
			{
				key=key+".0";
			}
			else
			{
				if(e==p+1)
					key=key.substring(0,e)+"0";
				else
					key=key.substring(0, e);
			}
			
			System.out.println(key);
		}
	}
}

