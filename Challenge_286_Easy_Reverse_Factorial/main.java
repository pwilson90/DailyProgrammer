import java.util.Scanner;

public class main {
  public static void main(String []args){
    Scanner scanner = new Scanner(System.in);
    char choice = 'y';

    do{
      System.out.print("What number would you like to find the factorial for? ");
      int input = scanner.nextInt();

      int factorial = Factorial.reverseFactorial(input);

      if(factorial > 0){
        System.out.println("The factorial of " + input + " is " + factorial + "!");
      } else {
        System.out.println(input + " has no factorial.");
      }
      System.out.println();

      System.out.print("Would you like to find another?");
      choice = scanner.next().charAt(0);
    }while(choice == 'y');
  }
}
