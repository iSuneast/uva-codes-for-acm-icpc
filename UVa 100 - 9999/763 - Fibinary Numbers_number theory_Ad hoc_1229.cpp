/*
 * 763 - Fibinary Numbers
 *
 * Ad hoc...
 * use String to handle the Input, transform it into BigInteger.
 * add these two numbers and output as the problem description...
 *
 * I get WA for so many times because of some silly mistake...
 * How poor I am~... : (
 */

import java.util.*;
import java.math.*;

public class Main {

    public static Scanner in=new Scanner(System.in);
    static final int MAXN=110;
    public static BigInteger fib[]=new BigInteger[MAXN];

    public static BigInteger general()
    {
        String s=in.next();
        int l=s.length();
        BigInteger f=BigInteger.ZERO;

        for(int i=0;i<l;++i)
        {
            if(s.charAt(i)=='1')
                f=f.add(fib[l-1-i]);
        }

        return f;
    }

    public static void output(BigInteger key)
    {
        if(key.compareTo(BigInteger.ZERO)==0)
        {
            System.out.println("0");
            return ;
        }
        
        String s="";
        for(int i=MAXN-1;i>=0;--i)
            if(key.compareTo(fib[i])>=0)
            {
                for(int j=i;j>=0;--j)
                {
                    if(key.compareTo(fib[j])>=0)
                    {
                        s+="1";
                        key=key.subtract(fib[j]);
                    }
                    else
                        s+="0";
                }
                System.out.println(s);
                return ;
            }
    }

    public static void main(String[] args)
    {
        fib[0]=BigInteger.ONE;
        fib[1]=BigInteger.valueOf(2);
        for(int i=2;i<MAXN;++i)
        {
            fib[i]=fib[i-1].add(fib[i-2]);
        }

        boolean first=true;
        while(in.hasNext())
        {
            if(!first)
                System.out.println();
            first=false;

            output(general().add(general()));
        }
    }

}

