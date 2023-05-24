#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> leftRowCheck;
unordered_map<int, bool> upperLeftDiagonalCheck;
unordered_map<int, bool> bottomLeftDiagonalCheck;

void printSolution(vector<vector<char>> &board, int n){
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl <<endl;
}

bool isSafe(int row, int col, vector<vector<char>> &board, int n){
    //check if we can place queen at current cell
    if(leftRowCheck[row] ==true){
        return false;
    }
    
    if(upperLeftDiagonalCheck[n-1+col-row] == true){
        return false;
    }
    
    if(bottomLeftDiagonalCheck[row+col] ==true){
        return false;
    }
    
    return true;

}

void solve(vector<vector<char>> board , int col, int n){
    //base case
    if(col >= n){
        printSolution(board,n);
    }
    
    for(int row=0; row <n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col] = 'Q';
            leftRowCheck[row] = true;
            upperLeftDiagonalCheck[n-1+col-row] = true;
            bottomLeftDiagonalCheck[row+col] =true;
            //recusrion
            solve(board, col+1,n);
            //backtrack
            board[row][col] = '-';
             leftRowCheck[row] = false;
            upperLeftDiagonalCheck[n-1+col-row] = false;
            bottomLeftDiagonalCheck[row+col] =false;
        }
    }
}

int main()
{
    int n=4;
    vector<vector<char>> board(n, vector<char>(n,'-'));
    int col=0;
    //0->empty cell
    //1->Queen at the cell
    solve(board, col,n);
 
    return 0;
}
