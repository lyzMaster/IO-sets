import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        String str = cin.next();
        int n = cin.nextInt();

        char[] chars = str.toCharArray();
        int[] ints = new int[str.length()];
        String[] strings = new String[str.length()];
        int sum = 0;

        for (int i=0;i<str.length()-1;i++){
            if ((int)str.charAt(i)>(int)str.charAt(i+1)) {
                str = str.replaceFirst(String.valueOf(str.charAt(i)), "");
                sum++;
                if (i>=2) {
                    i = i - 2;
                }
                else i--;
                if (sum == n) {
                    break;
                }
            }
        }
        if(sum<n){
            for (int i=1;i<=n-sum;i++){
                str = str.replace(String.valueOf(str.charAt(str.length()-1)),"");//常用的将string去掉的方法（要将char转化为string，因为char不能是空字符）
            }
        }

        System.out.println(str);
    }
}
