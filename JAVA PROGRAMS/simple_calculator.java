/*import java.io.*;
import java.lang.*;
import java.lang.Math; */
import java.util.Scanner;

public class simple_calculator {
    public static void main(String[] args)
    {
        double num1, num2;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number");
        num1 = sc.nextDouble();
        num2 = sc.nextDouble();
        System.out.println("Enter the operator");
        num1 = sc.nextDouble();
        num2 = sc.nextDouble();
        System.out.println("Enter the operator(+,-,*,/)");
        char op = sc.next().charAt(0);
        double o = 0;
        switch(op)
        {
            case '+':   o = num1 + num2;
                        break;
            case '-':   o = num1 - num2;
                        break;
            case '*':   o = num1 * num2;
                        break;
            case '/':   o = num1 / num2;
                        break;
            default:    System.out.println("You have entered wrong input");
                        break;
           
        }
        System.out.println("The final result:");
        System.out.println();
        System.out.println(num1 + " " + op + " " + num2 + " = " + o);

    }
  
}
