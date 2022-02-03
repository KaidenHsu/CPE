import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main
{
  public static void main(String[] args){
    int N, F, i, turn = 1;
    Scanner scanner = new Scanner(System.in);

    while (true) {
      N = scanner.nextInt();
      F = scanner.nextInt();

      if(N == 0 && F== 0) break;

      BigInteger price, sum = BigInteger.ZERO;

      for(i = 0; i < N; i++){
        price = scanner.nextBigInteger();
        sum = sum.add(price);
      }

      System.out.printf("Bill #%d costs %d: each friend should pay %d\n\n", turn++, sum, sum.divide(BigInteger.valueOf(F)));
    }
  }
}
