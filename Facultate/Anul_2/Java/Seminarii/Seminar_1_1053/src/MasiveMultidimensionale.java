public class MasiveMultidimensionale {
    public static void main(String[] args) {
        int[][][] cub = new int[][][] {
                {{1, 2}, {3, 4}, {5, 6}},
                {{7, 8}, {9, 10}, {11, 12}}
            };

        // parcugere masiv multidimensional
        for (int[][] matrice : cub) {
            for (int[] vector : matrice) {
                for (int element : vector) {
                    System.out.print(element + "\t");
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}
