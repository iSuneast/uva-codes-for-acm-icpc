/*
 * 10925 - Krakovia
 * Bign
 * 大整数加法,除法...
 * 直接用java...
 */

//package Main;
import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int cas=1;
        while(in.hasNext())
        {
            int n=in.nextInt();
            int f=in.nextInt();
            if(n==0 && f==0)
                break;
            BigInteger s=BigInteger.ZERO,t;
            for(int i=0;i<n;++i)
                s=s.add(in.nextBigInteger());
            System.out.println("Bill #"+cas+" costs "+s+": each friend should pay "+s.divide(BigInteger.valueOf(f)));
            System.out.println();
            cas++;
        }
    }
}
