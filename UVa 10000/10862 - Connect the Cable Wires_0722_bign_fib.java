/*
 * 10862 - Connect the Cable Wires
 * 
 * Bgin...
 * fib...
 * 第2*n项斐波那契序列
 */

package main;
import java.math.*;
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int maxn=4003;
        BigInteger fib[]=new BigInteger[maxn];
        fib[1]=fib[2]=BigInteger.ONE;
        for(int i=3;i<maxn;++i)
            fib[i]=fib[i-1].add(fib[i-2]);
        
        while(in.hasNext())
        {
            int n=in.nextInt();
            if(n==0)
                break;
            System.out.println(fib[n*2]);
        }
    }
    
}
