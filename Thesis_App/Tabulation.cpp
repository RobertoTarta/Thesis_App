//
// Created by rober on 04/05/2023.
//

#include "Tabulation.h"

bool Tabulation::differenceCheck( string term1,  string term2) {
    int differences = 0;
    for (int i = 0; i < term1.length(); i++) {
        if (term1[i] != term2[i])
            differences++;
        if (differences > 1)
            return false;
    }
    return (differences == 1);
}

string Tabulation::decimalToBinary(int minterm) {
    if (minterm == 0)
        return "0";

    string binaryString;
    int numBits = log2(minterm) + 1;

    for (int i = numBits - 1; i >= 0; i--) {
        int bit = (minterm >> i) & 1;
        binaryString += to_string(bit);
    }

    return binaryString;
}

Tabulation::Term Tabulation::combineTerms(const Term& term1, const Term& term2) {
    string combinedValue;
    vector<int> combinedMinterms;

    for (int i = 0; i < term1.value.length(); i++) {
        if (term1.value[i] == term2.value[i]) {
            combinedValue += term1.value[i];
        } else {
            combinedValue += "-";
        }
    }

    combinedMinterms.insert(combinedMinterms.end(), term1.minterms.begin(), term1.minterms.end());
    combinedMinterms.insert(combinedMinterms.end(), term2.minterms.begin(), term2.minterms.end());

    return Term(combinedValue, combinedMinterms);
}
