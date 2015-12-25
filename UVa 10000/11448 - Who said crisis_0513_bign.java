/*
 * 11448 - Who said crisis?
 * bign
 * 爱死java的高精度了...
 */

//package Main;
import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        BigInteger a,b;
        int dataset=in.nextInt();
        while(dataset-->0)
        {
            a=in.nextBigInteger();
            b=in.nextBigInteger();
            System.out.println(a.subtract(b));
        }
    }
}
