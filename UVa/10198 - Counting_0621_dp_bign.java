/*
 * 10198 - Counting
 * 
 * bign
 * dp
 * ans[n]=ans[n-1]*2+ans[n-2]+ans[n-3]
 * 注意一下n==1的时候,答案是2(1,4)
 * 其实就是相当于,有"1"出现的地方变成"1"或"4"
 * 于是*2就好了
 */

package Main;
import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int MAXN=1001;
        BigInteger key[]=new BigInteger[MAXN];
        key[0]=BigInteger.ZERO;
        key[1]=BigInteger.valueOf(2);	//这里是2,不是1
        key[2]=BigInteger.valueOf(5);
        key[3]=BigInteger.valueOf(13);

        for(int i=4;i<MAXN;++i)
            key[i]=key[i-3].add(key[i-1].multiply(BigInteger.valueOf(2))).add(key[i-2]);

        while(in.hasNext())
            System.out.println( key[in.nextInt()] );
    }

}
