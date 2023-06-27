package wk1_recursion;

public class ValidTicTacToeState {
    public boolean validTicTacToe(String[] board) {
        int[] counts = getCharCount(board);
        int xCount = counts[0], oCount = counts[1];
        if (xCount > 5 || oCount > 5) return false;
        if (xCount - oCount > 1 || xCount - oCount < 0) return false;

        int validCountOfX = getValidCount(board, 'X');
        int validCountOfO = getValidCount(board, 'O');

        // cannot be both-win scenario
        if (validCountOfX >= 1 && validCountOfO >= 1) return false;
        // 'X' placed first - if 'X' wins, 'O' cannot be placed
        if (validCountOfX >= 1 && xCount == oCount) return false;
        // if 'O' wins, 'X' and 'O' should have the same count
        if (validCountOfO >= 1 && xCount > oCount) return false;
        return true;
    }

    private int[] getCharCount(String[] board) {
        int xCount = 0, oCount = 0;
        for (String row: board) {
            for (int i = 0; i < 3; i++) {
                if (row.charAt(i) == 'X') xCount++;
                else if (row.charAt(i) == 'O') oCount++;
            }
        }
        return new int[]{xCount, oCount};
    }

    private int getValidCount(String[] board, char ch) {
        int validCount = 0;
        for (int i = 0; i < 3; i++) {
            int rowCount = 0, colCount = 0;
            for (int j = 0; j < 3; j++) {
                if (board[i].charAt(j) == ' ') {
                    rowCount = -4;
                }
                if (board[j].charAt(i) == ' ') {
                    colCount = -4;
                }
                if (board[i].charAt(j) == ch) rowCount++;
                if (board[j].charAt(i) == ch) colCount++;
            }
            if (rowCount == 3) validCount++;
            if (colCount == 3) validCount++;
        }
        if (board[0].charAt(0) == ch)
            if (board[0].charAt(0) == board[1].charAt(1) && board[1].charAt(1) == board[2].charAt(2))
                validCount++;
        if (board[0].charAt(2) == ch)
            if (board[0].charAt(2) == board[1].charAt(1) && board[1].charAt(1) == board[2].charAt(0))
                validCount++;
        return validCount;
    }
}
