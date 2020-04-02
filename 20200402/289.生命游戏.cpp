/*
 * File: 289.生命游戏.cpp
 * Project: 20200402
 * File Created: Thursday, 2nd April 2020 10:04:49 am
 * Author: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Last Modified: Thursday, 2nd April 2020 11:09:54 am
 * Modified By: lingtan (<<danling@stu.xjtu.edu.cn>>)
 * Copyright 2017 - 2020 Your Company, <<xjtu>>
 */

/*
根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。

给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），
或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。
下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。

示例：
输入： 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
输出：
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/game-of-life
*/
#include<vector>
#include<iostream>
using namespace std;

class Solution {
private:
    int CountActiveCell(int x,int y,vector<vector<int>> &board)
    {
        int dx[8]={-1,0,1,-1,1,-1, 0, 1};
        int dy[8]={ 1,1,1, 0,0,-1,-1,-1};
        int xx,yy;
        int count=0;
        for (int k=0;k<8;k++)
        {
            xx=x+dx[k];
            yy=y+dy[k];
            if ((xx>=0&&xx<board.size())&&(yy>=0&&yy<board[0].size()))
            {
                count+=board[xx][yy];
            }
        }
        return count;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> board_cache=board;
        int count=0;
        for (int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                count=CountActiveCell(i,j,board_cache);
                if (board_cache[i][j]==1)
                {
                    if (count<2) board[i][j]=0;
                    if (count==2||count==3) continue;
                    if (count>3) board[i][j]=0;
                }
                else
                {
                    if (count==3) board[i][j]=1;
                }
            }
        }
    }
};

public class Solution_bit {
    private static final int[] DX = {0, 0, 1, -1, 1, 1, -1, -1};
    private static final int[] DY = {1, -1, 0, 0, 1, -1, 1, -1};

    public void gameOfLife(int[][] board) {
        if (board.length == 0) {
            return;
        }
        int n = board.length;
        int m = board[0].length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + DX[k];
                    int y = j + DY[k];
                    if (x < 0 || x >= board.length || y < 0 || y >= board[0].length) {
                        continue;
                    }
                    // 这里不能直接加board[x][y]，因为 board[x][y] 的倒数第二位是可能有值的。
                    cnt += board[x][y] & 1;
                }
                if ((board[i][j] & 1) > 0) {
                    // 这个是活细胞
                    if (cnt >= 2 && cnt <= 3) {
                        // 周围有2/3个活细胞，下一个状态还是活细胞。
                        board[i][j] = 0b11;
                    }
                    // 周围活细胞过多或过少都会死，因为原数据是0b01，所以这里不用额外赋值。
                } else if (cnt == 3) {
                    // 这个是死细胞，周围有3个活细胞，下一个状态变为活细胞。
                    board[i][j] = 0b10;
                }
            }
        }
        // 最后一位去掉，倒数第二位变为更新后的状态。
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
}

void printM(vector<vector<int>> &board)
{
    for (int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    vector<vector<int>> board={{0,1,0},
                               {0,0,1},
                               {1,1,1},
                               {0,0,0}};
    cout << "初始细胞矩阵：" << endl;
    printM(board);
    Solution Slo;
    for (int i=0;i<20;i++)
    {
        Slo.gameOfLife(board);
        cout << "第" << i+1 << "轮变化：" <<endl;
        printM(board);
    }
    int a =0;
    a|=2;
    cout << a;
    
    return 0;
}