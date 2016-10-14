public class Factorial {
  public static int reverseFactorial(int input){
    int count = 2;
    int remainder = input;

    while(remainder%count == 0){
      remainder = remainder/count;
      count++;
    }

    if(remainder == 1){
      return --count;
    } else {
      return 0;
    }
  }
}
