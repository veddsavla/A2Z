import java.util.*;

public class RevTables {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int i = 10, n;

        n = sc.nextInt();
        while (i > 0) {
            System.out.print(i * n);
            i--;
        }

        sc.close();
    }
}