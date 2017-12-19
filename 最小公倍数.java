import java.util.Scanner;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int x = cin.nextInt();
        int y = cin.nextInt();
        int tem;
        int ox = x;
        int oy = y;
        tem = min(x,y);
        x = max(x,y);
        y = tem;
        for (;;){
            int k = x%y;
            if (k!=0) {
                x = y;
                y = k;
            }
            if (k==0){
                System.out.println(ox*oy/y);
                break;
            }
        }

    }
}
