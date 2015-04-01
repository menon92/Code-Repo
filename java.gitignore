import java.util.*;
import java.math.*;

class Main {
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args) {
		int N, i;
		BigInteger AA;
		while(input.hasNext()) { 
			N = input.nextInt();
			AA = input.nextBigInteger();
			
			BigInteger sum = new BigInteger("0");
			BigInteger ii = new BigInteger("1");
			BigInteger increment = new BigInteger("1");
			
			int p = 1;
			for(i = 0; i < N; i++) {
				sum = sum.add(ii.multiply(AA.pow(p++)));
				ii = ii.add(increment);
			}
			System.out.println(sum);
		}
	}

}
