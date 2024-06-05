#include<iostream>
#include<vector>
using namespace std;

void printboard(vector<vector<char>>& board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            cout<<board[i][j]<<" ";
        }
        cout << endl; 
    }
}

bool isSafe(vector<vector<char>>& board,int row,int col){
    for(int i=row-1;i>=0;i--){
        if(board[i][col] == 'Q'){
            return false;
        }
    }

    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){ 
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    for(int i=row-1,j=col+1;i>=0 && j<board.size();i--,j++){ 
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

bool nqueens(vector<vector<char>>& board,int row){
    if(row == board.size()){
        return true;
    }

    for(int i=0;i<board.size();i++){
        if(isSafe(board,row,i)){
            board[row][i]='Q';
            if(nqueens(board,row+1)){ 
                return true;
            }
            board[row][i]='_'; 
        }
    }
    return false; 
}

int main(){
    int n=4;
    vector<vector<char>> board(n, vector<char>(n, '_')); 

    if(nqueens(board,0)){
        printboard(board);
    } else {
        cout << "No solution found" << endl;
    }
    return 0;
}