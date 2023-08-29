import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    // Create a board
    char[][] board = new char[3][3];
    for (int i = 0; i < board.length; i++) {
      for (int j = 0; j < board[i].length; j++) {
        board[i][j] = ' ';
      }
    }
    // Create player X
    char player = 'X';
    boolean gameover = false;
    Scanner inp = new Scanner(System.in);

    // Now I'll go with the loop
    while (!gameover) {
      printboard(board);
      System.out.println("Player " + player + " enter coordinates (row and column): ");
      // Create variables for coordinates
      int row = inp.nextInt();
      int col = inp.nextInt();

      // Now check if the coordinates are empty or not
      if (board[row][col] == ' ') {
        board[row][col] = player;
        gameover = havewon(board, player);
        if (gameover) {
          System.out.println("Player " + player + " has won");
        } else {
          // Switch players
          if (player == 'X') {
            player = 'O';
          } else {
            player = 'X';
          }
        }
      } else {
        System.out.println("Invalid Move by Player " + player);
      }
    }
    printboard(board);
  }

  public static boolean havewon(char[][] board, char player) {
    // Check for rows
    for (int row = 0; row < board.length; row++) {
      if (board[row][0] == player && board[row][1] == player && board[row][2] == player) {
        return true;
      }
    }

    // Check for cols
    for (int col = 0; col < board[0].length; col++) {
      if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
        return true;
      }
    }

    // Diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
      return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
      return true;
    }
    return false;
  }

  public static void printboard(char[][] board) {
    for (int i = 0; i < board.length; i++) {
      for (int j = 0; j < board[i].length; j++) {
        System.out.print(board[i][j] + " | ");
      }
      System.out.println();
    }
  }
}
