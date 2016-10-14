import java.io.*;
import java.util.*;

public class main{
  public static void main(String []args){

    BufferedReader reader = null;

    try {
      String line;

      reader = new BufferedReader(new FileReader("challengeInput.txt"));
      line = reader.readLine();
      while ((line = reader.readLine()) != null) {
        zRep(Integer.parseInt(line));
      }
    } catch (IOException x) {
      System.err.format("IOException: %s%n", x);
    } finally {
      if (reader != null) {
        try {
          reader.close();
        } catch (IOException e) {
          e.printStackTracee();
        }
      }
    }
  }

  public static void zRep(int num){
    ArrayList<Integer> sequence = new ArrayList<>();
    int remainder = num;
    while(remainder > 0){
      int f = Fibonacci.fasterFib(Fibonacci.nearestFibNum(remainder)))
      sequence.add(f);
      remainder -= f;
    }

    System.out.print(num + " = ");
    for(int k=0; k<sequence.size()-1; k++){
      System.out.print(sequence.get(k) + " + ");
    }
    System.out.println(sequence.get(k));
  }
}
