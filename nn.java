import java.util.Scanner;

public class nn {

        public static boolean issafe(char board[][], int r1, int col) {
            for (int i = r1; i >= 0; i--) {
                if (board[i][col] == 'Q') {
                    return false;
                }
            }
            for (int i = r1, j = col; i >= 0 && j >= 0; i--, j--) {
                if (board[i][j] == 'Q') {
                    return false;
                }
            }
    
            for (int i = r1, j = col; i >= 0 && j < board.length; i--, j++) {
                if (board[i][j] == 'Q') {
                    return false;
                }
            }
    
            return true;
        }
    
        public static void queen(char board[][], int row) {
            if (row == board.length) {
                printarr(board);
                return ;
            }
            for (int j = 0; j < board.length; j++) {
                if (issafe(board, row, j) == true) {
                    board[row][j] = 'Q';
                    queen(board, row + 1);
                    board[row][j] = 'X';
                }
            }
        }
        public static void printarr(char board[][]) {
            System.out.println("----------------*-------------------");
            for (int i = 0; i < board.length; i++) {
                for (int j = 0; j < board.length; j++) {
                    System.out.print(board[i][j] + "  ");
                }
                System.out.println(" ");
            }
        }
    
        public static void main(String args[]) {
            Scanner myObj = new Scanner(System.in);
            int n=myObj.nextInt();
            char board[][] = new char[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    board[i][j] = 'X';
                }
            }
            queen(board, 0);
    
        }
    
        
}
