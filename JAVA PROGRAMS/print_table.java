import java.util.Scanner;
public class print_table {
    public static void main(String args[])
    {
        int n, a=0;
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number to print table for :");
        n=sc.nextInt();

        for(int i=1;i<=10;i++)
        {
            a+=n;
            System.out.println(n+" X "+ i +" = "+a);
        }
    }
    
}
