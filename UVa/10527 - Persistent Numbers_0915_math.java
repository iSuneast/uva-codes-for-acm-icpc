/*
 * 10527 - Persistent Numbers
 * 
 * math...
 * just try to resolve the BigNumber use number [9-2]
 * and then just sort them by value
 */

package uva;
import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        BigInteger n,t;
        short ans[]=new short[100000];
        
        while(in.hasNext())
        {
            n=in.nextBigInteger();
            if(n.compareTo(BigInteger.ZERO)<0)
                break;
            
            if(n.compareTo(BigInteger.valueOf(10))<0)
            {
                System.out.println("1"+n);
                continue;
            }
            int tot=0;

            for(int i=9;i>1;--i)
            {
                t=BigInteger.valueOf(i);
                while(n.mod(t).equals(BigInteger.ZERO))
                {
                    ans[tot++]=(short)i;
                    n=n.divide(t);
                }
            }

            if(!n.equals(BigInteger.ONE))
            {
                System.out.println("There is no such number.");
                continue;
            }

            Arrays.sort(ans,0,tot);
            for(int i=0;i<tot;++i)
                System.out.print(ans[i]);
            System.out.println();
        }
    }

}
