/*
 * 10519 - !! Really Strange !!
 *
 * math
 * BigInteger...
 * 找规�?写几个出来就会发现规律了
 * 注意,0的时候答案是1
 * <0的情况答案为0 (题目没说,估计没有这种数据)
 * 其它情况答案是n*n-n+2
 */

package Main;
import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        while(in.hasNext())
        {
            BigInteger key=in.nextBigInteger();
            if(key.compareTo(BigInteger.ZERO)==-1)
                System.out.println(0);
            else if(key.compareTo(BigInteger.ZERO)==0)
                System.out.println(1);
            else
                System.out.println(key.multiply(key).subtract(key).add(BigInteger.valueOf(2)));
            //n*n-n+2
        }
    }

}
