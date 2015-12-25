/*
 * 911 - Multinomial Coefficients
 * 
 * combination math~
 * C(n, a1) * C(n-a1, a2) * ...
 * 
 * happy coding~
 */

import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	static BigInteger C(int n, int k) {
		BigInteger key = BigInteger.ONE;
		for (int i = n - k + 1; i <= n; ++i) {
			key = key.multiply(BigInteger.valueOf(i));
		}

		for (int i = 2; i <= k; ++i) {
			key = key.divide(BigInteger.valueOf(i));
		}
		return key;
	}

	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);

		while (in.hasNext()) {
			int n = in.nextInt();
			int k = in.nextInt();
			BigInteger key = BigInteger.ONE;
			for (int i = 0; i < k; ++i) {
				int t = in.nextInt();
				key = key.multiply(C(n, t));
				n -= t;
			}

			System.out.println(key);
		}
	}
}

