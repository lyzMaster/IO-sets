import java.util.Scanner;

public class hello {
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        String n = cin.nextLine();
        boolean flag = false;
        if(n.length()==11){
            if (n.charAt(3)=='-'&&n.charAt(6)=='-'){
                for (int i=0;i<=10;i++){
                    if (i==3||i==6){
                        i++;
                        continue;
                    }
                    else if ((int)n.charAt(i)>=48&&(int)n.charAt(i)<=57){
                        flag=true;
                    }
                    else flag=false;
                }
            }
        }
        if (flag){
            System.out.println("shi shebaohaoma.....$_$");
        }
        else System.out.println("bushi shebaohaoma...../_/");
    }
}

