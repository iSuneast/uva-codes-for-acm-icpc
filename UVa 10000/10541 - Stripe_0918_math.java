/*
 * 10541 - Stripe
 * 
 * BigInteger...
 * just calc combination math format
 * C( n-sum+1,k )
 */

//package Main;
import java.util.*;
import java.math.*;

public class Main {

    public static BigInteger c(int a,int b)
    {
        BigInteger key=BigInteger.ONE;
        for(int i=2;i<=a;++i)
            key=key.multiply( BigInteger.valueOf(i) );
        for(int i=2;i<=b;++i)
            key=key.divide( BigInteger.valueOf(i) );
        b=a-b;
        for(int i=2;i<=b;++i)
            key=key.divide( BigInteger.valueOf(i) );
        return key;
    }
    
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int dataset=in.nextInt();
        while(dataset-->0)
        {
            int n=in.nextInt(),k=in.nextInt(),sum=0;
            for(int i=0;i<k;++i)
            {
                sum+=in.nextInt();
            }
            if(k-1+sum>n)
            {
                System.out.println(0);
            }
            else
            {
                System.out.println(c(n-sum+1,k));
            }
        }
    }

}
