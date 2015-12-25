/*
 * 11115 - Uncle Jack
 * 
 * bign...
 * math...
 * 强大的java啊...
 * 题目其实就是要求n^d而已...
 */

package Main;
import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        while(in.hasNext())
        {
            int n=in.nextInt();
            int d=in.nextInt();
            if(n==0 && d==0)
                break;
            BigInteger ans=BigInteger.ONE;
            while(d--!=0)
                ans=ans.multiply(BigInteger.valueOf(n));
            System.out.println(ans);
        }
    }

}
