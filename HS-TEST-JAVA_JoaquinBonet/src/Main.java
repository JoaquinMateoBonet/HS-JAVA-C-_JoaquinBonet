import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Solution {

     static int[] climbingLeaderboard(int[] scores, int[] alice){
         // Ordeno el array de forma descendiente
         Integer[] aliceObj = Arrays.stream(alice).boxed().toArray(Integer[]::new);
         Arrays.sort(aliceObj, Comparator.reverseOrder());
         int position;

         //Creo un bulce for para buscar cada elemento dentro del puntaje
         for (int i = 0; i < aliceObj.length; i++) {
              position = Arrays.binarySearch(scores, aliceObj[i]); //Realizo una busqueda binaria para encontrar la posicion de los elementos de alice dentro del score
             if (position >= 0) { //Si el binarySearch me devuelve 0 o mayor significa que elementos de alice se encuentran dentro del score
                 System.out.println(aliceObj[i] + " numero de índice " + position);//Muestro en que parte del score se encuentran los elementos de alice
             }
         }
         return alice;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int scoresCount = scanner.nextInt();

        scanner.skip("(\r\n|[1,2,3,4,5])");

        int[] scores = new int[scoresCount];

        String[] scoresItems = scanner.nextLine().split("");

        scanner.skip("(\r\n|[2,3,4])?");

        for (int i = 0; i < scoresCount; i++) {
            int scoresItem = Integer.parseInt(scoresItems[i]);
            scores[i] = scoresItem;
        }

        int aliceCount = scanner.nextInt();

        scanner.skip("(\r\n|[10,23,40,40])?");

        int[] alice = new int[aliceCount];

        String[] aliceItems = scanner.nextLine().split("");

        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < aliceCount; i++) {
            int aliceItem = Integer.parseInt(aliceItems[i]);
            alice[i] = aliceItem;
        }

        int[] result = Solution.climbingLeaderboard(scores, alice);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(String.valueOf(result[i]));
            if (i != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }
        bufferedWriter.newLine();
        bufferedWriter.close();
        scanner.close();
    }

    private static final Scanner scanner = new Scanner(System.in);
}