/*
 * 10023 - Square root
 * 
 * math...
 * 对大整数开根号...
 * 有神奇的结论...
 * 
 *
Preparation:
- make groups of two digits, starting from the right: 14-89-96. (if the number of digits was odd, the leftmost group would have only one digit);
- initialise the variables remain, odd and answer with 0.

Loop for every group of two digits, from left to right:
   - odd  = 20 * answer +1;
   - remain = 100 * remain + group;
   - count = 0;
   - loop while remain >= odd:
      - count = count + 1;
      - remain = remain - odd;
      - odd = odd + 2;
   - answer = 10 * answer + count.
 */

//package Main;
import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int dataset=in.nextInt();
        while(dataset!=0)
        {
            String n=in.next();
            BigInteger odd=BigInteger.ZERO;
            BigInteger remain=BigInteger.ZERO;
            BigInteger ans=BigInteger.ZERO;
            int l=n.length(),p=0;
            if(l%2==1)
            {
                odd=BigInteger.ONE;
                remain=BigInteger.valueOf(n.charAt(p)-'0');
                p++;
                int cnt=0;
                while(remain.compareTo(odd)>=0)
                {
                    ++cnt;
                    remain=remain.subtract(odd);
                    odd=odd.add(BigInteger.valueOf(2));
                }
                ans=BigInteger.valueOf(10).multiply(ans).add(BigInteger.valueOf(cnt));
            }
            for(;p<l;p+=2)
            {
                odd=BigInteger.valueOf(20).multiply(ans).add(BigInteger.ONE);
                remain=BigInteger.valueOf(100).multiply(remain).add
                        (BigInteger.valueOf((n.charAt(p)-'0')*10+n.charAt(p+1)-'0'));
                int cnt=0;
                while(remain.compareTo(odd)>=0)
                {
                    ++cnt;
                    remain=remain.subtract(odd);
                    odd=odd.add(BigInteger.valueOf(2));
                }
                ans=BigInteger.valueOf(10).multiply(ans).add(BigInteger.valueOf(cnt));
            }
            System.out.println(ans);
            --dataset;
            if(dataset!=0)
                System.out.println();
        }
    }

}
