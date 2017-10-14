import java.math.*;
import java.util.Scanner;

public class test {
    public static void main(String args[]){
        System.out.println(bignum(7775656099));
    }
    public static BigDecimal bignum(long n){
        BigDecimal res = BigDecimal.ONE;
        for(long i = 1;i<=n;i++){
            res = res.multiply(new BigDecimal(i));
        }
        return res;
    }
}


