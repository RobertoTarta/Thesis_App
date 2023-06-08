//
// Created by rober on 01/05/2023.
//

#ifndef THESIS_APP_BOOLEAN_H
#define THESIS_APP_BOOLEAN_H
#include <iostream>
#include "vector"
#include <list>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;


class Boolean {
    string Expression;
    int variable_size;
public:
    vector<string> term_Separation(string Expression);
    vector<string> apply_Identity_Law_And(vector<string>terms);
    vector<string> apply_Null_Law_And(vector<string>terms);
    vector<string> apply_Idempotent_Law_Or(vector<string> terms);
    vector<string> apply_Idempotent_Law_And(vector<string> terms);
    vector<string> apply_Inverse_Law_And(vector<string> terms);
    vector<string> apply_Identity_Law_Or(vector<string> terms);
    vector<string> apply_Null_Law_Or(vector<string> terms);
    vector<string> apply_Inverse_Law_Or(vector<string> terms);
    vector<string> extract_Bracketed_Terms(string expression);
    vector<string> apply_Distributive_Law_Or(vector<string> bracketed_Terms);
    vector<string> apply_Absorption_Law_Or(vector<string> Terms);
    vector<string> apply_DeMorgan_Laws(vector<string> negatedTerms);
    vector<string> extract_Negated_Bracketed_Terms(string expression);
    vector<string> remove_parentheses(vector<string> terms);
    string remove_negated_terms(string expression);
    string remove_bracketed_terms(string expression);
    string removePlus(string expression);
    vector<string> removeMult(vector<string>& terms);
    string mixVectors(vector<string>& normal_Terms,vector<string>& bracketed_Terms,vector<string>&negated_Terms);

};




#endif //THESIS_APP_BOOLEAN_H
