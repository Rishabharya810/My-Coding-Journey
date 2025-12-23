import java.util.Scanner;
public class sum_of_first_n_numnber {
    public static void main (String args[])
    {
        int n,a=1;
        Scanner sc = new Scanner(System.in);
        
        
        System.out.println("Enter the number: ");
        n=sc.nextInt();

        
        for(int i=n;i>0;i--)
        {
            a*=i;
        }

        System.out.println("Sum is "+ a);
        sc.close();
    }
}