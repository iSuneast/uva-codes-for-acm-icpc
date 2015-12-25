/*
 * 10814 - Simplifying Fractions
 * 
 * Bign...
 * 大整数的gcd...
 * java自带...实在强大..
 */

package main;
import java.math.*;
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int dataset=in.nextInt();
        for(int cas=1;cas<=dataset;++cas)
        {
            BigInteger a=in.nextBigInteger();
            String t=in.next();
            BigInteger b=in.nextBigInteger();

            BigInteger g=a.gcd(b);
            System.out.println(a.divide(g)+" / "+b.divide(g));
        }
    }
}
