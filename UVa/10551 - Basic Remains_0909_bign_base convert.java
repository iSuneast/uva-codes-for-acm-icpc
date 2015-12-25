/*
 * 10551 - Basic Remains
 * 
 * bign...
 * base convert
 * just use biginteger to solve it
 */

//package Main;
import java.util.*;
import java.math.*;

public class Main {

    public static BigInteger transform(String str,int base)
    {
        BigInteger key=BigInteger.ZERO;
        int l=str.length();
        for(int i=0;i<l;++i)
        {
            key=key.multiply(BigInteger.valueOf(base)).add( BigInteger.valueOf(str.charAt(i)-'0') );
        }
        return key;
    }

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int b;
        while(in.hasNext())
        {
            b=in.nextInt();
            if(b==0)
                break;
            BigInteger p=transform(in.next(),b);
            BigInteger m=transform(in.next(),b);
            p=p.mod(m);

            BigInteger key=BigInteger.ZERO,more=BigInteger.ONE,t;
            while(!p.equals(BigInteger.ZERO))
            {
                t=more.multiply(BigInteger.valueOf(p.mod(BigInteger.valueOf(b)).intValue()));
                key=key.add(t);
                more=more.multiply(BigInteger.valueOf(10));
                p=p.divide(BigInteger.valueOf(b));
            }

            System.out.println(key);
        }
    }

}
