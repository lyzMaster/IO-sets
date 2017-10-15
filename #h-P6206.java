import java.math.BigDecimal;
import java.util.Scanner;

public class test {
    public static void main(String args[]) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        BigDecimal x,y,x1,y1,x2,y2,x3,y3,x01,y01,x02,y02,y03,x0,y0,r,r2;
        BigDecimal two = new BigDecimal("2");
        for (int i = 1; i <= n; i++) {
            x1 = cin.nextBigDecimal();
            y1 = cin.nextBigDecimal();
            x2 = cin.nextBigDecimal();
            y2 = cin.nextBigDecimal();
            x3 = cin.nextBigDecimal();
            y3 = cin.nextBigDecimal();
            x = cin.nextBigDecimal();
            y = cin.nextBigDecimal();


            x01 = x1.multiply(x1).multiply(y2.subtract(y3)).add(x2.multiply(x2).multiply(y3.subtract(y1))).add(x3.multiply(x3).multiply(y1.subtract(y2))).subtract(y1.subtract(y2).multiply(y2.subtract(y3)).multiply(y3.subtract(y1)));
            x02 = x1.multiply(y2.subtract(y3)).add(x2.multiply(y3.subtract(y1))).add(x3.multiply(y1.subtract(y2)));
            x0 = x01.divide(two).multiply(x02);

            y01 = y1.subtract(y1).multiply(x2.subtract(x3)).add(y2.multiply(y2).multiply(x3.subtract(x1))).add(y3.multiply(y3).multiply(x1.divide(x2)));
            y02 = x1.subtract(x2).multiply(x2.subtract(x3)).multiply(x3.subtract(x1));
            y03 = x1.multiply(y2.subtract(y3)).add(x2.multiply(y3.subtract(y1))).add(x3.multiply(y1.subtract(y2)));
            y0 = y02.subtract(y01).divide(two).multiply(y03);

            r = x1.subtract(x0).multiply(x1.subtract(x0)).add(y1.subtract(y0).multiply(y1.subtract(y0)));    //????
            r2 = x.subtract(x0).multiply(x.subtract(x0)).add(y.subtract(y0).multiply(y.subtract(y0)));
            if (r.compareTo(r2)<0){
                System.out.println("Accepted");
            }
            else System.out.println("Rejected");
        }
    }
}


