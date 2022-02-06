import java.util.Scanner;

public class tellMeTheFrequencies {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNextLine()) {
            int[] arr = new int[300];
            String s = scanner.nextLine();
            for (int i = 0; i < s.length(); i++) {
                arr[s.charAt(i)]++;
            }

            for (int i = 1; i <=s.length() ; i++) {
                for (int j = arr.length-1; j >=0; j--) {
                    if (arr[j] == i) {
                        System.out.println(j+" "+i);
                    }
                }
            }
            System.out.println("\n");
        }
    }
}
