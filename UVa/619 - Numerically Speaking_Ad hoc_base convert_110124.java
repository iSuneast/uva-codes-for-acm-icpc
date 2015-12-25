/*
 * 619 - Numerically Speaking
 *
 * Ad hoc~
 * base convert
 */

import java.util.*;
import java.math.*;

public class Main {

    static void NumberOut(String s)
    {
        int rem=s.length()%3;
        for(int i=0;i<s.length();++i)
        {
            System.out.print(s.charAt(i));
            if(i+1>=rem && (i-rem+1)%3==0 && i+1!=s.length())
                System.out.print(',');
        }
        System.out.println();
    }

    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        String s;
        while(in.hasNext())
        {
            s=in.next();
            if(s.equals("*"))
                break;
            
            if('0'<=s.charAt(0) && s.charAt(0)<='9')
            {
                String ans="";
                BigInteger n=BigInteger.ZERO;
                for(int i=0;i<s.length();++i)
                {
                    n=n.multiply( BigInteger.valueOf(10) );
                    n=n.add( BigInteger.valueOf(s.charAt(i)-'0') );
                }
                
                while(!n.equals(BigInteger.ZERO))
                {
                    long t=n.mod(BigInteger.valueOf(26)).longValue()+96;
                    char c=(char)t;
                    n=n.divide( BigInteger.valueOf(26) );
                    ans=c+ans;
                }

                System.out.print(ans);
                for(int i=ans.length();i<22;++i)
                    System.out.print(' ');
                NumberOut(s);
            }
            else
            {
                System.out.print(s);
                for(int i=s.length();i<22;++i)
                    System.out.print(' ');

                BigInteger key=BigInteger.ZERO;
                for(int i=0;i<s.length();++i)
                {
                    key=key.multiply( BigInteger.valueOf( 26 ) );
                    key=key.add( BigInteger.valueOf( s.charAt(i)-'a'+1 ) );
                }
                NumberOut(key.toString());
            }
        }
    }
}
