import java.util.Scanner;
import java.util.ArrayList;


public class Demo 
{
   public static void main(String args[])
   {
   
System.out.print("What would you like to do? \n 
                 1. New [S]tack \n 
                 2. New [C]ard \n 
                 3. [A]dd Card to Stack /n 
                 4. [D]elete Card /n"+
                 5. [R]emove Stack /n");
       
       Scanner k = new Scanner(System.in);
       
       String input = k.nextLine();
      
       switch(input){
       
       case "S":
       System.out.print("Name of Stack?");
       input = k.nextLine();
       StackArray.createStack(input);
       break;
       
       case "C":
       System.out.print("What is the card's study term?");
       input = k.nextLine();
       Notecard.setTerm(input);
       System.out.print("Definition of term?");
       input = k.nextLine();
       break;
       
       case "A":
       System.out.print("Which: "+Stack.toArray()+"\n to which stack?: "+StackArray.toArray());
       break;
       
       }
   }
}
      
      
      
