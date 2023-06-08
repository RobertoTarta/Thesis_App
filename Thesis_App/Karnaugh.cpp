//
// Created by rober on 04/05/2023.
//

#include "Karnaugh.h"




bool Karnaugh::checkRight(vector<vector<int>> matrix,int i,int j){
    if(matrix[i][j+1]==1)
        return true;
    else
        return false;
}

bool Karnaugh::checkBottom(vector<vector<int>> matrix,int i,int j){
    if(matrix[i+1][j]==1)
        return true;
    else
        return false;
}

bool Karnaugh::checkCorners1(vector<vector<int>> matrix){
    if(matrix[0][0]==1)
        if(matrix[0][matrix[0].size()]==1)
            if(matrix[matrix.size()][0]==1)
                if(matrix[matrix.size()][matrix[0].size()]==1)
                    return true;
    return false;
}

bool Karnaugh::checkCorners2(vector<vector<int>> matrix){///descendent diagonal \ ///
    if(matrix[0][0]==1)
        if(matrix[matrix.size()][matrix[0].size()]==1)
            return true;
    return false;
}

bool Karnaugh::checkCorners3(vector<vector<int>> matrix){///crescent diagonal / ///
    if(matrix[0][matrix[0].size()]==1)
        if(matrix[matrix.size()][0]==1)
            return true;
    return false;
}

bool Karnaugh::checkVLine(vector<vector<int>> matrix, int column){
    for(int i=0;i<matrix.size();i++)
        if(matrix[i][column]==0)
            return false;
return true;
}

bool Karnaugh::checkHLine(vector<vector<int>> matrix, int row){
for(int i=0;i<matrix[row].size();i++)
    if(matrix[row][i]==0)
        return false;
return true;
}

bool Karnaugh::checkSquare(vector<vector<int>> matrix, int row,int column){
    if(matrix[row+1][column+1]==1)
        return true;
}

bool Karnaugh::checkAll(vector<vector<int>> matrix){
    for(int i=0;i<matrix.size();i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if(matrix[i][j]==0)
                return false;
        }
    }
    return true;
}


string Karnaugh::Simplify(vector<vector<int>> matrix){///WIP

    for(int i=0;i<matrix.size();i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if(matrix[i][j]==1)
                checkRight(matrix,i,j);
        }
    }


}












