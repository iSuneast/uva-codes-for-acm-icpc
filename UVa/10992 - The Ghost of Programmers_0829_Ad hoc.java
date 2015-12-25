/*
 * 10992 - The Ghost of Programmers
 * 
 * Ad hoc...
 * a simple problem...
 * you should use big integer to hold the year...
 */

//package Main;
import java.util.*;
import java.math.*;

public class Main {

   public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        boolean first=true;
        while(in.hasNext())
        {
            BigInteger year=in.nextBigInteger();
            if(year.equals(BigInteger.ZERO))
                break;

            if(!first)
                System.out.println();
            first=false;
            System.out.println(year);

            if(year.compareTo(BigInteger.valueOf(2148))<0)
            {
                System.out.println("No ghost will come in this year");
                continue;
            }
            year=year.subtract(BigInteger.valueOf(2148));
            boolean nice=false;
            if(year.mod(BigInteger.valueOf(2)).equals(BigInteger.ZERO))
            {
                System.out.println("Ghost of Tanveer Ahsan!!!");
                nice=true;
            }
            if(year.mod(BigInteger.valueOf(5)).equals(BigInteger.ZERO))
            {
                System.out.println("Ghost of Shahriar Manzoor!!!");
                nice=true;
            }
            if(year.mod(BigInteger.valueOf(7)).equals(BigInteger.ZERO))
            {
                System.out.println("Ghost of Adrian Kugel!!!");
                nice=true;
            }
            if(year.mod(BigInteger.valueOf(11)).equals(BigInteger.ZERO))
            {
                System.out.println("Ghost of Anton Maydell!!!");
                nice=true;
            }
            if(year.mod(BigInteger.valueOf(15)).equals(BigInteger.ZERO))
            {
                System.out.println("Ghost of Derek Kisman!!!");
                nice=true;
            }
            if(year.mod(BigInteger.valueOf(20)).equals(BigInteger.ZERO))
            {
                System.out.println("Ghost of Rezaul Alam Chowdhury!!!");
                nice=true;
            }
            if(year.mod(BigInteger.valueOf(28)).equals(BigInteger.ZERO))
            {
                System.out.println("Ghost of Jimmy Mardell!!!");
                nice=true;
            }
            if(year.mod(BigInteger.valueOf(36)).equals(BigInteger.ZERO))
            {
                System.out.println("Ghost of Monirul Hasan!!!");
                nice=true;
            }

            year=year.add(BigInteger.valueOf(2148));
            if(year.mod(BigInteger.valueOf(4)).equals(BigInteger.ZERO) 
                    && !year.mod(BigInteger.valueOf(100)).equals(BigInteger.ZERO)
                    || year.mod(BigInteger.valueOf(400)).equals(BigInteger.ZERO))
            {
                System.out.println("Ghost of K. M. Iftekhar!!!");
                nice=true;
            }

            if(!nice)
                System.out.println("No ghost will come in this year");
        }

    }
}
