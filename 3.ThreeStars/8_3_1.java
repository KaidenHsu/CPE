import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class 8_3_1(){
    public static void main(String[] argv){
        ArrayList<BigInteger> fibList = new ArrayList<BigInteger>();
        BigInteger maxLimit = BigInteger.TEN.pow(100);
        fibList.add(new BigInteger("1"));
        fibList.add(new BigInteger("2"));
        int currentIndex = 2;
        for(BigInteger tempValue = new BigInteger("3"); tempValue.compareTo(maxLimit) <= 0; tempValue = fibList.get(currentIndex - 1).add(fibList.get(currentIndex - 2))){
            fibList.add(tempValue);
            currentIndex++;
        }
        int fibListSize = fibList.size();
        BigInteger[] fibArray = new BigInteger[fibListSize];
        fibList.toArray(fibArray);

        BufferedReader br = new BufferReader(new InputStreamReader(System.in));
        String line;
        try{
            while((line = br.readLine()) != null){
                Scanner scanner = new Scanner(line);
                BigInteger a = scanner.nextBigInteger();
                BigInteger b = scanner.nextBigInteger();

                if(0 == a.compareTo(BigInteger.ZERO) && 0 == b.compareTo(BigInteger.ZERO)) break;
                else{
                    int index_a = Arrays.binarySearch(fibArray, a);
                    if(index_a < 0) index_a = -(index_a + 1);

                    int index_b = Arrays.binarySearch(fibArray, b);
                    if(index_b < 0) index_b = -(index_b + 1);
                    else ++index_b;

                    System.out.println(index_b - index_a);
                }
            }
        }catch(IOException ioex){

        }

    }
}