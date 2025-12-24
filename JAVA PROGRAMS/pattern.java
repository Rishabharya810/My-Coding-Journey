// Java code to demonstrate right star triangle


// Function to demonstrate printing pattern
   
class Star
{
    private class Right
    {
        public void print(int n)
        {
            int a, b;

            // outer loop to handle number of rows
            // k in this case
            for (a = 0; a < n; a++) 
            {

                // inner loop to handle number of columns
                // values changing acc. to outer loop
                for (b = 0; b <= a; b++) 
                {
                // printing stars
                System.out.print("* ");
                }

                // end-line
                System.out.println();
            }
    
            // Driver Function
        
        }
        
        
        
    }
    void starRightTriangle(int n1)
    {
        Right r1 = new Right();
        r1.print(n1);
    }
     
    
}
    

public class pattern 
{
    public static void main(String args[])
        {
            
            int k = 5;
            
            Star s1 = new Star();
            s1.starRightTriangle(k);
        }

    
}


