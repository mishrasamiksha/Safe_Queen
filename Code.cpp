#include <iostream>
using namespace std;

bool isSafe(int board[][10],int i,int j,int n)
{
    //Check for column
    for(int row=0;row<i;row++)
    {
        if(board[row][j]==1)
        {
            return false;
        }
    }
    //Check for the left diagonal
    int x = i;
    int y = j;
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }
    //Check for the right diagonal
    x = i;
    y = j;
    while(x>=0 && y<n)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y++;
    }
    //The position for the queen is now safe
    return true;
}

bool solveNQueen(int board[][10],int i,int n)
{
    //Base case
    if(i==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1)
                {
                    cout<<"Q ";
                }
                else
                {
                    cout<<"_ ";
                }
            }
            cout<<"\n";
        }
        return true;
    }
    //Recursive case
    for(int j=0;j<n;j++)
    {
        if(isSafe(board,i,j,n))
        {
            board[i][j] = 1;
            bool nextQueenRakhPaye = solveNQueen(board,i+1,n);
            if(nextQueenRakhPaye)
            {
                return true;
            }
            //Backtracking
            board[i][j] = 0;
        }
    }
    //We have tried for all positions in the current row, but could not place the queen
    return false;
}

int main() {
    int n;
    cin>>n;
    int board[10][10] = {0};
    solveNQueen(board,0,n);
    return(0);
}
