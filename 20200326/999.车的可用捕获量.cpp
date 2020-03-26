/*
 * File: 999.车的可用捕获量.cpp
 * Project: 20200326
 * File Created: Thursday, 26th March 2020 10:49:53 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Thursday, 26th March 2020 10:50:01 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */
/*
999. 车的可用捕获量
在一个 8 x 8 的棋盘上，有一个白色车（rook）。
也可能有空方块，白色的象（bishop）和黑色的卒（pawn）。它们分别以字符 “R”，“.”，“B” 和 “p” 给出。大写字符表示白棋，小写字符表示黑棋。
车按国际象棋中的规则移动：它选择四个基本方向中的一个（北，东，西和南），然后朝那个方向移动，
直到它选择停止、到达棋盘的边缘或移动到同一方格来捕获该方格上颜色相反的卒。另外，车不能与其他友方（白色）象进入同一个方格。
返回车能够在一次移动中捕获到的卒的数量。
*/
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        vector<int> site;
        for (int i =0;i<board.size();i++)
        {
            for (int j=0;j<board.size();j++)
            {
                if (board[i][j]=='R')
                {
                    site.push_back(i);
                    site.push_back(j);
                    break;
                }
            }
            if (!site.empty())
            {
                break;
            }
        }
        int i = site[0];
        int j = site[1];
        int res=0;
        while(i >0)
        {
            i--;
            if (board[i][j]=='B')
            {
                break;
            }
            if (board[i][j]=='p')
            {
                res++;
                break;
            }
        }
        i = site[0];
        j = site[1];
        while(i <board.size()-1)
        {
            i++;
            if (board[i][j]=='B')
            {
                break;
            }
            if (board[i][j]=='p')
            {
                res++;
                break;
            }
        }
        i = site[0];
        j = site[1];
        while(j >0)
        {
            j--;
            if (board[i][j]=='B')
            {
                break;
            }
            if (board[i][j]=='p')
            {
                res++;
                break;
            }
        }
        i = site[0];
        j = site[1];
        while(j <board.size()-1)
        {
            j++;
            if (board[i][j]=='B')
            {
                break;
            }
            if (board[i][j]=='p')
            {
                res++;
                break;
            }
        }
        return res;
    }
};

class Solution_ {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        // 定义上下左右四个方向
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
       
        for (int i = 0; i < 8; i++) 
        {
            for (int j = 0; j < 8; j++) 
            {
                // 找到白车所在的位置
                if (board[i][j] == 'R') 
                {
                    // 分别判断白车的上、下、左、右四个方向
                    int res = 0;
                    for (int k = 0; k < 4; k++) {
                        int x = i, y = j;
                        while (true) 
                        {
                            x += dx[k];
                            y += dy[k];
                            if (x < 0 || x >= 8 || y < 0 || y >= 8 || board[x][y] == 'B') 
                            {
                                break;
                            }
                            if (board[x][y] == 'p') 
                            {
                                res++;
                                break;
                            }
                        }
                    }
                    return res;
                }
            }
        }
        return 0;
    }
}