

//find program to add numbers in java ?

import java.util.Scanner;
class Student{
    int StId, StYear;
    String StName, StBranch;
    int Buffer;
    void getData(int pId,String pName, int pYear,String pBranch)
    {
        pId=StId;
        pYear=StYear;
        StName=pName;
        pBranch=StBranch;
    }
    void Avg(int pSub1, int pSub2,int pSub3,int pSub4,int pSub5,int pSub6)
    {
        Buffer=(pSub1+pSub2+pSub3+pSub4+pSub5+pSub6)/6;
        System.out.println("Average Marks: "+ Buffer);
    }
    void Percentage(int Present, int TotalDays)
    {
        System.out.println(Present);
        System.out.println(TotalDays);
        float res=((Present*100)/TotalDays);
        System.out.println("Attendance Percentage: " + res);
    }
}
public class file {
public static void main(String[] args) {
    int id,year;
    String name, branch;
    Student st=new Student();
    Scanner scan=new Scanner(System.in);
    System.out.print("Enter Your Id: ");
    id=scan.nextInt();
    System.out.print("Enter Your Name: ");
    name=scan.next();
    System.out.print("Enter Your Year: ");
    year=scan.nextInt();
    System.out.print("Enter Your Branch: ");
    branch=scan.next();
    st.getData(id, name, year, branch);
    System.out.println("Enter Marks of 6 Subjects: ");
    st.Avg(scan.nextInt(), scan.nextInt(), scan.nextInt(), scan.nextInt(), scan.nextInt(), scan.nextInt());
    System.out.print("Enter the present and total working days: "); 
    st.Percentage(scan.nextInt(), scan.nextInt());
}
}
