public class Main {
    public static void main(String[] args){
        int[][] matrix = new int[6][6];
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                matrix[i][j] = i + j;
            }
        }

        matrix[0][0] = 2;
        matrix[0][5] = 0;
        matrix[3][4] = 0;

        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println();
        System.out.println();

        ArraysAndStrings.solution8b(matrix);

        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                System.out.print(matrix[i][j] +" ");
            }
            System.out.println();
        }
    }
}
