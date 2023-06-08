#include <iostream>
#include "vector"
#include "Boolean.h"

using namespace std;






class Tabulation {
    int variable_size;
    string Expression;

public:
    const string &getExpression() const {
        return Expression;
    }

    int getVariableSize() const {
        return variable_size;
    }

    void setExpression(const string &expression) {
        Expression = expression;
    }

    void setVariableSize(int variableSize) {
        variable_size = variableSize;
    }

    Tabulation(string Expression){
        this->Expression=Expression;
        int variable_size;
    }


};
int main() {
    int variable_size;
    string expression = "ABC+!AA+AB+!(AB)+!(A+B)+!A!B+!A+A!A+A+D(E+F)+E(F+G) ";
    //string expression = "A + !A ";
    cout<< "Starting expression:" << expression << endl;
    vector<string> Normal_Terms;
    vector<string> Bracketed_Terms;
    vector<string> Negated_Bracketed_Terms;

    Boolean A;

    Negated_Bracketed_Terms = A.extract_Negated_Bracketed_Terms(expression);

    for(int i=0;i<Negated_Bracketed_Terms.size();i++)
        cout<< "Extracted negated terms:" << Negated_Bracketed_Terms[i] << endl;

    expression = A.remove_negated_terms(expression);

    expression = A.removePlus(expression);

    cout << "Expression after removing negated terms:" << expression << endl;

    Bracketed_Terms = A.extract_Bracketed_Terms(expression);

    for(int i=0;i<Bracketed_Terms.size();i++)
        cout<< "Extracted bracketed terms:" << Bracketed_Terms[i] << endl;

    expression = A.remove_bracketed_terms(expression);

    cout << "Expression after removing bracketed terms:"<< expression << endl;

    Normal_Terms = A.term_Separation(expression);

    for (int i=0; i<Normal_Terms.size();i++)
        cout<< "Separated normal terms:" << Normal_Terms[i] << endl;

    Negated_Bracketed_Terms = A.apply_DeMorgan_Laws(Negated_Bracketed_Terms);

    for(int i=0;i<Negated_Bracketed_Terms.size();i++)
        cout<< "Negated terms after applying De Morgan's:" << Negated_Bracketed_Terms[i] << endl;

    Negated_Bracketed_Terms = A.removeMult(Negated_Bracketed_Terms);

    for(int i=0;i<Negated_Bracketed_Terms.size();i++)
        cout<< "Negated terms after applying De Morgan's:" << Negated_Bracketed_Terms[i] << endl;

    for(int i=0;i<Bracketed_Terms.size();i++)
        cout<< "bracketed terms:" << Bracketed_Terms[i] << endl;

    Bracketed_Terms = A.apply_Distributive_Law_Or(Bracketed_Terms);

    for(int i=0;i<Bracketed_Terms.size();i++)
        cout<< "After applying distributive law:" << Bracketed_Terms[i] << endl;

    Bracketed_Terms = A.apply_Distributive_Law_Or(Bracketed_Terms);

    for(int i=0;i<Bracketed_Terms.size();i++)
        cout<< "After applying distributive law:" << Bracketed_Terms[i] << endl;


    expression = A.mixVectors(Normal_Terms,Bracketed_Terms,Negated_Bracketed_Terms);

    cout<< expression << endl;

    Normal_Terms.clear();
    Normal_Terms=A.term_Separation(expression);
    cout<< "            Separated normal terms:";
    for (int i=0; i<Normal_Terms.size();i++)
        cout<< Normal_Terms[i] << " + ";
    cout<<endl;


    Normal_Terms=A.apply_Inverse_Law_And(Normal_Terms);
    cout<< "After applying Inverse law And:"<<endl;
    for (int i=0; i<Normal_Terms.size();i++)
        cout<< Normal_Terms[i] << " + ";
    cout<<endl;

    Normal_Terms=A.apply_Identity_Law_Or(Normal_Terms);

    cout<< "After applying identity law And:"<<endl;
    for (int i=0; i<Normal_Terms.size();i++)
        cout<< Normal_Terms[i] << " + ";
    cout<<endl;

    Normal_Terms=A.apply_Identity_Law_Or(Normal_Terms);

    cout<< "After applying identity law Or:"<<endl;
    for (int i=0; i<Normal_Terms.size();i++)
        cout<< Normal_Terms[i] << " + ";
    cout<<endl;

    Normal_Terms=A.apply_Null_Law_Or(Normal_Terms);
    Normal_Terms=A.apply_Null_Law_And(Normal_Terms);
    Normal_Terms=A.remove_parentheses(Normal_Terms);
    Normal_Terms=A.apply_Absorption_Law_Or(Normal_Terms);

    cout<< "After applying absorption law Or and both Null laws:"<<endl;
    for (int i=0; i<Normal_Terms.size();i++)
        cout<< Normal_Terms[i] << " + ";
    cout<<endl;

    Normal_Terms=A.apply_Idempotent_Law_And(Normal_Terms);


    cout<< "After applying idempotent law And:"<<endl;
    for (int i=0; i<Normal_Terms.size();i++)
        cout<< Normal_Terms[i] << " + ";
    cout<<endl;

    Normal_Terms=A.apply_Idempotent_Law_Or(Normal_Terms);


    cout<< "After applying idempotent law Or:"<<endl;
    for (int i=0; i<Normal_Terms.size();i++)
        cout<< Normal_Terms[i] << " + ";
    cout<<endl;



    Normal_Terms=A.apply_Identity_Law_And(Normal_Terms);
    Normal_Terms=A.apply_Inverse_Law_Or(Normal_Terms);
    cout<< "After applying Identity law And and Inverse Law Or:"<<endl;
    for (int i=0; i<Normal_Terms.size();i++)
        cout<< Normal_Terms[i] << " + ";
    cout<<endl;


    return 0;
}
