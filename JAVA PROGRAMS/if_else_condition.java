import java.util.*;

public class if_else_condition 
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int button = sc.nextInt();
        
        if (button == 1)
        {
            System.out.println("HELLO");
        }
        if (button == 2)
        {
            System.out.println("NAMASTE");
        }
        if (button == 3)
        {
            System.out.println("BONJOUR");
        }
        else
        {
            System.out.println("INVALID BUTTON");
        }
        
        sc.close();
    }
    
}
