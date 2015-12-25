/*
 * 11879 - Multiple of 17
 *
 * BigInteger...
 *
 * in fact, this problem is about math Theorem
 *
 * but in order to solve the problem quick enough
 * I use Java BigInteger to check the number%17==0
 * Just for AC : )
 */

import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger a;

        while (in.hasNext())
        {
            a = in.nextBigInteger();
            if (a.equals(BigInteger.ZERO))
                break;
            if (a.mod(BigInteger.valueOf(17)).equals(BigInteger.ZERO))
                System.out.println("1");
            else
                System.out.println("0");
        }
    }
}

