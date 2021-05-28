class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        /*
        x is equals to o or one more than o.
        if one player wins, game stop.
        */
        int x = 0, o = 0, xwin = 0, owin = 0;
        
        for(int r = 0;r < 3;r++)
            for(int c = 0;c < 3;c++){
                if(board[r][c] == 'X')
                    x++;
                else if(board[r][c] == 'O')
                    o++;
            }
        // cout<<x<<" "<<o<<endl;
        if(!(x == o || x - o == 1))
            return false;
        
        for(int r = 0;r < 3;r++){
            bool isWin = true;
            for(int c = 1;c < 3 && isWin;c++)
                if(board[r][c] != board[r][c - 1])
                    isWin = false;
            if(isWin){
                if(board[r][0] == 'X')
                    xwin++;
                else if(board[r][0] == 'O')
                    owin++;
                for(int c = 0;c < 3;c++)
                    board[r][c] = ' ';
            }
        }
        for(int c = 0;c < 3;c++){
            bool isWin = true;
            for(int r = 1;r < 3 && isWin;r++)
                if(board[r][c] != board[r - 1][c])
                    isWin = false;
            if(isWin){
                if(board[0][c] == 'X')
                    xwin++;
                else if(board[0][c] == 'O')
                    owin++;
                for(int r = 0;r < 3;r++)
                    board[r][c] = ' ';
            }
        }
        
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
            if(board[0][0] == 'X')
                xwin++;
            else if(board[0][0] == 'O')
                owin++;
        }
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
            if(board[1][1] == 'X')
                xwin++;
            else if(board[1][1] == 'O')
                owin++;
        }
        
        if((xwin > 0 && owin > 0) || (xwin > 2 || owin > 2))
            return false;
        if(xwin > 0 && x == o)
            return false;
        if(owin > 0 && x - o == 1)
            return false;
        
        return true;
    }
};
// https://tinyurl.com/3z4vudnj