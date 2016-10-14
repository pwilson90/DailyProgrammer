import java.util.*;

public class Fibonacci {

  private static Map<Integer, Integer> results = new HashMap<>();

  public static int fasterFib(int n) {
    if (n == 0) {
      results.put(n,0);
      return 0;
    } else if (n <= 2) {
      results.put(n,1);
      return 1;
    }
    if (results.get(n) != null) {
      return results.get(n);
    } else {
      int value = fasterFib(n - 1) + fasterFib(n - 2);
      results.put(n, value);
      return value;
    }
  }

  //fib(n) = (Phi^n-(-phi)^n)\sqrt(5) = (1\sqrt(5))()(((1+sqrt(5))\2)^n)-((1-sqrt(5)\2)^n))
  private static double Phi = (Math.sqrt(5)+1)/2;
  //double phi = Phi - 1;

  public static int nearestFibNum(int num){
    int nearestFibIndex = (int)((Math.log10(num)+(Math.log10(5)/2))/Math.log10(Phi));

    //checking that it isn't slightly off because the original formula
    //was slightly modified. Original formula is
    //nearestFibIndex = (Phi^n - (-phi)^n)\Math.sqrt(5)
    if(fasterFib(nearestFibIndex+1) <= num){
      return nearestFibIndex+1;
    }
    return nearestFibIndex;
  }
}
