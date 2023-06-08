//
// Created by rober on 04/05/2023.
//

#ifndef THESIS_APP_TABULATION_H
#define THESIS_APP_TABULATION_H

#include <iostream>
#include "vector"
#include <list>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

class Tabulation {
private:
    struct Term {
        string value;
        vector<int> minterms;

        Term(string val, vector<int> mints) : value(val), minterms(mints) {}
    };

    vector<Term> primeImplicants;

    bool differenceCheck( string term1,  string term2);
    string decimalToBinary(int minterm);
    Term combineTerms(const Term& term1, const Term& term2);


public:



};


#endif //THESIS_APP_TABULATION_H


/*vector<vector<int>> Binary_Table//4 variables
        {
             ///{A, B, C, D, F} F being the solution/implicants
                {0, 0, 0, 0, 0},//0
                {0, 0, 0, 0, 0},//1
                {0, 0, 0, 0, 0},//2
                {0, 0, 0, 0, 0},//3
                {0, 0, 0, 0, 0},//4
                {0, 0, 0, 0, 0},//5
                {0, 0, 0, 0, 0},//6
                {0, 0, 0, 0, 0},//7
                {0, 0, 0, 0, 0},//8
                {0, 0, 0, 0, 0},//9
                {0, 0, 0, 0, 0},//10
                {0, 0, 0, 0, 0},//11
                {0, 0, 0, 0, 0},//12
                {0, 0, 0, 0, 0},//13
                {0, 0, 0, 0, 0},//14
                {0, 0, 0, 0, 0} //15
        };*/