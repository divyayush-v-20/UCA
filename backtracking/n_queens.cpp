#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int n, vector<string>& board){
    int tmprow = row;
    int tmpcol = col;

    //left diagonal
    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    row = tmprow;
    col = tmpcol;

    //vertically upward
    while(row >= 0){
        if(board[row][col] == 'Q') return false;
        row--;
    }
    
    row = tmprow;

    //right diagonal
    while(row >= 0 && col < n){
        if(board[row][col] == 'Q') return false;
        row--;
        col++;
    }
    return true;
}

void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans){
    if(row == n){
        ans.push_back(board);
        return;
    }
    for(int col = 0; col < n; col++){
        if(isSafe(row, col, n, board)){
            board[row][col] = 'Q';
            solve(row + 1, n, board, ans);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solve(0, n, board, ans);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<string>> nQueens_sol = solveNQueens(n);

    for(vector<string> board : nQueens_sol){
        for(string str : board){
            for(char c : str){
                cout<<c<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<"--------------------------------"<<endl;
    }
    return 0;
}