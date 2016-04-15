
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;

public class C {

	static ArrayList<Long> primes = new ArrayList<Long>();
	static void sieve(int N) {
	     int M=(N-1)/2;
	     int x= ((int) (Math.floor(Math.sqrt(N))-1)) / 2;
	     int i; int j;
	     boolean[] S = new boolean[M+1];
	     for (i=1;i<=x;i++)
	         if (!S[i])
	            for (j=2*i*(i+1);j<=M;j+=(2*i+1))
	                S[j] = true;
	 
	     primes.add((long) 2);
	     for (i=1;i<=M;i++)
	         if (!S[i])
	                primes.add((long) 2*i+1);
	}

	static long primeDivisor(BigInteger p) {
		int l = primes.size();
		for (int i = 0; i < l && BigInteger.valueOf(primes.get(i) * primes.get(i)).compareTo(p) == -1; i++) {
			if (p.remainder(BigInteger.valueOf(primes.get(i))).equals(BigInteger.valueOf(0))) {
				return primes.get(i);
			}
		}
		return 0;
	}

	static char[] binaryString(int k, int N) {
		char[] str = new char[N + 1];
		str[0] = '1';
		str[N - 1] = '1';
		for (int i = 1; i < (N - 1); i++)
			str[i] = '0';
		int j = 2;
		while (k > 0) {
			if(k % 2 == 1) {
				str[N - j] = '1';
			}
			j++;
			k /= 2;
		}
		str[N] = '\0';
		return str;
	}

	public static void main(String[] args) throws IOException {
		sieve(1000000);
		int T, N, J;
		T = 1;
		for (int a = 0; a < T; a++) {
			N = 32; J = 500;
			System.out.println("Case #" + (a + 1) + ":");
			int count = 0;
			BigInteger[] numberInBaseN = new BigInteger[11];
			Long[] result = new Long[11];
			for (int k = 0; ; k++) {
				for (int i = 2; i < 11; i++) {
					numberInBaseN[i] = BigInteger.valueOf(i).pow(N - 1).add(BigInteger.valueOf(1));
				}
				int l = k;
				int p = 1;
				while(l > 0) {
					if(l % 2 == 1) {
						for (int i = 2; i < 11; i++) {
							numberInBaseN[i] = numberInBaseN[i].add(BigInteger.valueOf(i).pow(p));
						}
					}
					l /= 2;
					p++;
				}
				int i;
				for (i = 2; i < 11; i++) {
					long divisor = primeDivisor(numberInBaseN[i]);
					if (divisor == 0) break;
					else result[i] = divisor;
				}
				if (i == 11) {
					System.out.print(binaryString(k, N));
					for (i = 2; i < 11; i++) {
						System.out.print(" " + result[i]);
					}
					System.out.print("\n");
					count++;
				}
				if(count == J) break;
			}
		}
	}

}

