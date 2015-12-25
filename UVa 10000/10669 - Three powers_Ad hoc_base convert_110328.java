/*
 * 10669 - Three powers
 * 
 * Ad hoc...
 * { }             000
 * { 1 }           001
 * { 3 }           010
 * { 1, 3 }        011
 * { 9 }           100
 * { 1, 9 }        101
 * ...........
 * nothing special, just a base 3 number system
 * so using BigInteger to solve it
 * 
 * happy coding~
 */

import java.math.*;
import java.util.*;

public class Main {
   
    public static void main(String args[])
    {
        Scanner in=new Scanner(System.in);
        
        final int MAXN = 65;
        BigInteger base3[] = new BigInteger[MAXN];
        
        base3[0]=BigInteger.ONE;
        for(int i=1; i<MAXN; ++i) {
        	base3[i] = base3[i-1].multiply( BigInteger.valueOf(3) );
        }
        
        while(in.hasNext()) {
        	BigInteger n = in.nextBigInteger().subtract( BigInteger.ONE );
        	if(n.compareTo( BigInteger.ZERO )<0)
        		break;
        	boolean first = true;
        	
			System.out.print("{");
        	for(int p=0; n.compareTo(BigInteger.ZERO)>0; ++p, n=n.divide( BigInteger.valueOf(2) )) {
        		if( n.mod( BigInteger.valueOf(2) ).compareTo( BigInteger.ONE )==0 ) {
        			if(!first)
        				System.out.print(",");
        			first=false;
        			System.out.print(" " + base3[p]);
        		}
        	}
        	
        	System.out.println(" }");
        }

    }
}

