/*
 * 10007 - Count the Trees
 * 
 * Catalan....
 * 经典的catalan数...
 * 无标号的二叉树型态总数为catalan(n)*n!
 * ans=c(2n,n)/(n+1)*n!
 *    =(2n)!/(n+1)!
 */
//package Main;
import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        while(in.hasNext())
        {
            int n=in.nextInt();
            if(n==0)
                break;
            BigInteger ans=BigInteger.ONE;
            for(int i=2*n;i>n+1;--i)
                ans=ans.multiply(BigInteger.valueOf(i));
            System.out.println(ans);
        }
    }

}
