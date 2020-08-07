设计一个算法，判断玩家是否赢了井字游戏。输入是一个 N x N 的数组棋盘，由字符" "，"X"和"O"组成，其中字符" "代表一个空位。

以下是井字游戏的规则：

玩家轮流将字符放入空位（" "）中。
第一个玩家总是放字符"O"，且第二个玩家总是放字符"X"。
"X"和"O"只允许放置在空位中，不允许对已放有字符的位置进行填充。
当有N个相同（且非空）的字符填充任何行、列或对角线时，游戏结束，对应该字符的玩家获胜。
当所有位置非空时，也算为游戏结束。
如果游戏结束，玩家不允许再放置字符。
如果游戏存在获胜者，就返回该游戏的获胜者使用的字符（"X"或"O"）；如果游戏以平局结束，则返回 "Draw"；如果仍会有行动（游戏未结束），则返回 "Pending"。

来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/tic-tac-toe-lcci著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
// 判断胜利者是不是player(X或O)
int test(char player,char** board ,int boardSize){
    int flag=0;

    // 行
    for(int i=0;i<boardSize;i++){
        if(board[i][0]==player){
            for(int j=0;j<boardSize;j++){
                if(board[i][j]!=player){
                    flag=0;
                    break;
                }else
                    flag=1;
            }
        }
        if(flag==1){
            return 1;
        }
    }

    // 列
    for(int j=0;j<boardSize;j++){
        if(board[0][j]==player){
            for(int i=0;i<boardSize;i++){
                if(board[i][j]!=player){
                    flag=0;
                    break;
                }else
                    flag=1;
            }
        }
        if(flag==1){
            return 1;
        }
    }


    // 主对角线
    for(int i=0;i<boardSize;i++){
        if(board[i][i]!=player){
            flag=0;
            break;
        }
        flag=1;
    }
    if(flag==1)
        return 1;

    // 斜对角线
    for(int i=boardSize-1;i>=0;i--){
        if(board[i][boardSize-1-i]!=player){
            flag=0;
            break;
        }
        flag=1;
    }
    if(flag==1)
        return 1;
    else
        return 0;
}

// 判断是否有空格
int have_empty(char ** board, int boardSize){
    int flag=0;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(board[i][j]==' '){
                flag=1;
                return flag;
            }
        }
    }
    return flag;
}

char* tictactoe(char** board, int boardSize){
    // X胜利
    if(test('X',board,boardSize)){
        return "X";
    // O胜利
    }else if(test('O',board,boardSize)){
        return "O";
    // X和O都没有匹配胜利，但是还有空格没有下棋
    }else if((!test('X',board,boardSize))&&(!test('O',board,boardSize))&&have_empty(board,boardSize)){
        return "Pending";
    // X和O都没胜利并且棋子已经下满
    }else{
        return "Draw";
    }
}
