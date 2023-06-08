//
// Created by rober on 04/05/2023.
//

#ifndef THESIS_APP_KARNAUGH_H
#define THESIS_APP_KARNAUGH_H
#include <iostream>
#include "vector"
#include <list>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class Karnaugh {

    int variable_size;
    vector<vector <int>> Matrix;

    bool checkRight(vector<vector<int>> matrix,int i,int j);
    bool checkBottom(vector<vector<int>> matrix,int i,int j);
    bool checkCorners1(vector<vector<int>> matrix);
    bool checkCorners2(vector<vector<int>> matrix);
    bool checkCorners3(vector<vector<int>> matrix);
    bool checkHLine(vector<vector<int>> matrix, int row);
    bool checkVLine(vector<vector<int>> matrix, int column);
    bool checkSquare(vector<vector<int>> matrix, int row,int column);
    bool checkAll(vector<vector<int>> matrix);
    string Simplify(vector<vector<int>> matrix);


public:
    ///CheckRight
    ///CheckCorners1
    ///CheckCorners2
    ///CheckCorners3
    ///CheckBot
    ///CheckVLine
    ///CheckHLine
    ///CheckSquare
    int getVariableSize() const {
        return variable_size;
    }

    void setVariableSize(int variableSize) {
        variable_size = variableSize;
    }


    Karnaugh(vector<vector<int>> Matrix){
        this->Matrix=Matrix;
        size_t numRows = Matrix.size(); // Get the number of rows
        size_t totalSize = 0;
        for (const auto& row : Matrix) {
            totalSize += row.size(); // Add the number of columns in each row
        }
        variable_size = log2(totalSize);
    }




};


#endif //THESIS_APP_KARNAUGH_H

/*
vector<vector<int>> Matrix3//4 variable matrix
        {
                {0, 0, 0, 0},
                {0, 0, 0, 0}

        };

 vector<vector<int>> Matrix4//5 variable matrix
        {
                {0, 0, 0, 0},//j
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
                //i
        };

vector<vector<int>> Matrix5//5 variable matrix
        {
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0}
        };

vector<vector<int>> Matrix6//6 variable matrix
        {
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0}
        };
*/