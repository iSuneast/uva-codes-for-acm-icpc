/*
 * 288 - Arithmetic Operations With Large Integers
 *
 * BigInteger
 * calculate the expression
 * I use divide && conquer POW to avoid TLE
 *
 * happy coding~
 */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	static BigInteger MyPow(BigInteger a, BigInteger b) {
		BigInteger key = BigInteger.ONE;
		for (; b.compareTo(BigInteger.ZERO) > 0; b = b.divide(BigInteger
				.valueOf(2))) {
			if (b.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ONE) == 0) {
				key = key.multiply(a);
			}
			a = a.multiply(a);
		}
		return key;
	}

	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		String buf;
		final int MAXN = 103;
		BigInteger var[] = new BigInteger[MAXN];
		int op[] = new int[MAXN];
		int IntSZ, opSZ;

		while (in.hasNext()) {
			buf = in.next() + "$";
			opSZ = IntSZ = 0;
			for (int i = 0, len = buf.length(), st = -1, end; i < len; ++i) {
				if ('0' <= buf.charAt(i) && buf.charAt(i) <= '9') {
					if (st == -1)
						st = i;
				} else if (st != -1) {
					end = i;
					var[IntSZ++] = new BigInteger(buf.substring(st, end));
					st = -1;

					int cur = 0;
					if (buf.charAt(i) == '*') {
						if (buf.charAt(i + 1) == '*') {
							cur = 3;
							++i;
						} else {
							cur = 2;
						}
					} else if (buf.charAt(i) == '+') {
						cur = 1;
					} else if (buf.charAt(i) == '-') {
						cur = -1;
					}

					if (cur != 0)
						op[opSZ++] = cur;

					while (opSZ > 1) {
						if (Math.abs(op[opSZ - 1]) <= Math.abs(op[opSZ - 2])) {
							if (op[opSZ - 2] == 3) {
								var[IntSZ - 2] = MyPow(var[IntSZ - 2],
										var[IntSZ - 1]);
							} else if (op[opSZ - 2] == 2) {
								var[IntSZ - 2] = var[IntSZ - 2]
										.multiply(var[IntSZ - 1]);
							} else if (op[opSZ - 2] == 1) {
								var[IntSZ - 2] = var[IntSZ - 2]
										.add(var[IntSZ - 1]);
							} else {
								var[IntSZ - 2] = var[IntSZ - 2]
										.subtract(var[IntSZ - 1]);
							}
							op[opSZ - 2] = cur;
							--IntSZ;
							--opSZ;
						} else {
							break;
						}
					}
				}
			}

			while (opSZ > 0) {
				if (op[opSZ - 1] == 3) {
					var[IntSZ - 2] = MyPow(var[IntSZ - 2], var[IntSZ - 1]);
				} else if (op[opSZ - 1] == 2) {
					var[IntSZ - 2] = var[IntSZ - 2].multiply(var[IntSZ - 1]);
				} else if (op[opSZ - 1] == 1) {
					var[IntSZ - 2] = var[IntSZ - 2].add(var[IntSZ - 1]);
				} else {
					var[IntSZ - 2] = var[IntSZ - 2].subtract(var[IntSZ - 1]);
				}
				--opSZ;
				--IntSZ;
			}

			System.out.println(var[0]);
		}
	}
}
