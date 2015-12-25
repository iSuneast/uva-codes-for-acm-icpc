/*
 * 254 - Towers of Hanoi
 * 
 * Ad hoc...
 * bitmask...
 * classical module
 * 
 * take care of the part of "The Algorithm"
 * even though you can just simulation using the classical algorithm
 * the output is not always correct
 * 
 * for case "1 1" the answer is "0 1 0", not "0 0 1", because:
 *  @"for odd moves, take the smallest disk (number 1) from the 
 *  @ peg where it lies to the next one in the circular sequence"
 * 
 * this sentence is so important, you should pay more attention to it, 
 * or you'll keep getting WA
 * 
 * *****************************************
 * classical algorithm
 * 
 * obviously, f(n) = f(n-1)*2 + 1 
 * set g(n) = f(n)+1
 * we get g(n)=2*g(n-1)
 * so g(n) = 2^n
 * then f(n) = 2^n-1
 * 
 * for example (n=3, m=5)   
 * 			# 3 disks, index from top to bottom is $1 $2 $3
 * 			# 5 = Base_2(101) = 2^2 + 2^0
 * our target is (BGN, TAR, TMP)  
 * 			# it means we should move the disks from BGN to TAR using TMP
 * 
 * so we can move the bottom one $3 from BGN to TAR in 2^2 steps
 * and the current answer is ( 0, +1, 0)
 * and the remaining moves available is m - 2^2 = 1
 * and the same time, we got a new target :
 * (TMP, TAR, BGN) with (n=2, m=1)
 * 
 * now we can't move the bottom one $2 from BGN to TAR in 2^1 steps
 * and the current answer is ( 0, 1, +1)
 * because we only have m=1 steps
 * the same time, we got another new target:
 * (TAR, TMP, BGN) with (n=1, m=1)
 * 
 * at last, we will move $1 from BGN to TAR in 1 steps
 * the answer changes to (+1, 1, 1)
 * 
 * done~
 * 
 * if you have any problem understanding above description,
 * you'd better renew your textbook again
 * *****************************************
 * 
 * happy coding~ 
 */

import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String args[]) {
		final int MAXN = 101;
		BigInteger key[] = new BigInteger[MAXN];
		key[0] = BigInteger.valueOf(1);
		for (int i = 1; i < MAXN; ++i) {
			key[i] = key[i - 1].multiply(BigInteger.valueOf(2));
		}

		Scanner in = new Scanner(System.in);

		while (in.hasNext()) {
			int n = in.nextInt();
			BigInteger m = in.nextBigInteger();
			if (n == 0 && m.compareTo(BigInteger.ZERO) == 0)
				break;

			int var[] = new int[3], cur = 0, tar = 2;
			for (int i = n; i > 0; --i) {
				if (m.compareTo(key[i - 1]) >= 0) {
					m = m.subtract(key[i - 1]);
					var[tar]++;
					cur = 3 - cur - tar;
				} else {
					var[cur]++;
					tar = 3 - cur - tar;
				}
			}

			int a = 0, b = 1, c = 2;
			if (n % 2 == 1) {
				b = 2;
				c = 1;
			}

			System.out.println(var[a] + " " + var[b] + " " + var[c]);
		}
	}

}

