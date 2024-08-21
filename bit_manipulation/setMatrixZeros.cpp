#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>>& matrix){
    int rowMask = 0, colMask = 0;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            if(!matrix[i][j]){
                rowMask = (1 << i) | rowMask;
                colMask = (1 << j) | colMask;
            }
        }
    }
    for(int i = 0; i < matrix.size(); i++){
        if((1 << i) & rowMask) {
            for(int j = 0; j < matrix[0].size(); j++){
                matrix[i][j] = 0;
            }
        }
    }
    for(int j = 0; j < matrix[0].size(); j++){
        if((1 << j) & colMask){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][j] = 0;
            }
        }
    }
}

int main(){
    int rows, cols;
    cin>>rows>>cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin>>matrix[i][j];
        }
    }
    setZeros(matrix);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}