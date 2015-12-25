/*
 * 11821 - High-Precision Number
 *
 * BigDecimal...
 * just use java BigDecimal to solve this problem....
 * seems quite easy now...
 * : P
 */

import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        int dataset=in.nextInt();
        BigDecimal a,t;
        String key;
        for(int cas=1;cas<=dataset;++cas)
        {
            a=BigDecimal.ZERO;
            while(in.hasNext())
            {
                t=in.nextBigDecimal();
                if(t.equals(BigDecimal.ZERO))
                    break;
                a=a.add(t);
            }

            key=a.toPlainString();
            int l=key.length();
            while(l>0 && key.charAt(l-1)=='0')
                --l;
            if(l>0 && key.charAt(l-1)=='.')
                --l;

            System.out.println(key.substring(0,l));
        }
    }

}

