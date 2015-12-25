/*
 * 10219 - Find the ways !
 * 
 * UVa的水题真是水到没谱了...
 * java暴力竟然直接过...
 */

//package Main;
import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int a,b;
        while(in.hasNext())
        {
            a=in.nextInt();
            b=in.nextInt();
            BigInteger key=BigInteger.ONE;
            for(int i=a;i>a-b;--i)
                key=key.multiply(BigInteger.valueOf(i));
            for(int i=2;i<=b;++i)
                key=key.divide(BigInteger.valueOf(i));

            System.out.println(key.toString().length());
        }
    }

}
