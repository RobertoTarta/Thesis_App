//
// Created by rober on 01/05/2023.
//

#include "Boolean.h"



vector<string> Boolean::term_Separation(string Expression){//separates terms by the "+"
    string Temp = Expression;

    stringstream ss(Temp);
    string term;
    vector<string> terms;

    while (getline(ss,term, '+')){
        terms.push_back(term);
    }

    return terms;
}

vector<string> Boolean::apply_Identity_Law_And(vector<string>terms){//erases any term multiplied by 1
    for(auto& str : terms) {
        str.erase(std::remove(str.begin(), str.end(), '1'), str.end());
    }
    return terms;
}

vector<string> Boolean::apply_Null_Law_And(vector<string>terms){
    auto removal = remove_if(terms.begin(),terms.end(),[](const string str){//erases any term of value 0
        return str.find('0') != string::npos;
    });
    terms.erase(removal,terms.end());
    return terms;
}

vector<string> Boolean::apply_Idempotent_Law_And(vector<string> terms) {
    vector<string> modifiedTerms;

    for (string str : terms) {
        unordered_set<char> uniqueLetters;
        string modifiedTerm;

        for (char ch : str) {
            if (uniqueLetters.find(ch) == uniqueLetters.end() && ch != '!') {
                uniqueLetters.insert(ch);
                modifiedTerm += ch;
            } else if (ch == '!') {
                modifiedTerm += ch;
            }
        }

        modifiedTerms.push_back(modifiedTerm);
    }

    return modifiedTerms;
}

vector<string> Boolean::apply_Idempotent_Law_Or(vector<string> terms) {//removes duplicates
    unordered_set<string> uniqueTerms; // set to store unique terms
    vector<string> modified_Terms; // vector to store modified terms

    for (const auto& term : terms) {
        if (uniqueTerms.insert(term).second) { // if the term is unique, adds it to the set and the new vector
            modified_Terms.push_back(term);
        }
    }

    return modified_Terms;
}

vector<string> Boolean::apply_Inverse_Law_And(vector<string> terms) {////has error with A!A needs fixing
    for (int i = 0; i < terms.size(); i++) {
        bool deleteTerm = false;
        string negatedVariables;
        for (int j = 0; j < terms[i].size(); j++) {
            if (terms[i][j] == '!') {
                negatedVariables.push_back(terms[i][j + 1]);
            }
        }
        for (int j = 0; j < terms[i].size() - 1; j++) {
            if (terms[i][j] != '!') {
                if (negatedVariables.find(terms[i][j]) != string::npos) {
                    if (terms[i][j + 1] != '!') {
                        deleteTerm = true;
                        break;
                    }
                }
            }
        }
        if (deleteTerm) {
            terms.erase(terms.begin() + i);
            i--;
        }
    }
    return terms;
}


vector<string> Boolean::apply_Identity_Law_Or(vector<string> terms)//removes existing "0" terms
{
    vector<string> modified_Terms =terms;

    modified_Terms.erase(remove_if(modified_Terms.begin(), modified_Terms.end(),[](const string str) { return str == "0"; }),modified_Terms.end());

    return modified_Terms;
}

vector<string> Boolean::apply_Null_Law_Or(vector<string> terms) {//if there is a term with value "1", clears vector and replaces by a single "1"
    vector<string> modified_Terms = terms;
    auto term = find(modified_Terms.begin(), modified_Terms.end(), "1");
    if (term != modified_Terms.end()) {
        modified_Terms.clear();
        modified_Terms.push_back("1");
    }
    return modified_Terms;
}

vector<string> Boolean::apply_Inverse_Law_Or(vector<string> terms)
{
    vector<string> modified_Terms = terms;
    set<string> negations;
    for ( auto term : modified_Terms) {//searches each term
        if (term.front() == '!') {//if term starts with "!" searches for non-negated version of the term
            string posTerm = term.substr(1);
            if (negations.count(posTerm) > 0) {
                modified_Terms.clear();
                modified_Terms.push_back("1");//if found, clears the whole vector and replaces with "1"
                return modified_Terms;
            } else {
                negations.insert(term);
            }
        } else {
            string negatedTerm = "!" + term;
            if (negations.count(negatedTerm) > 0) {
                modified_Terms.clear();
                modified_Terms.push_back("1");
                return modified_Terms;
            } else {
                negations.insert(term);
            }
        }
    }
    return terms;
}

vector<string> Boolean::extract_Bracketed_Terms(string expression) {//extracts bracketed terms, including any letters multiplying by the brackets
    vector<string> bracketed_terms;
    int start = 0;
    int end = 0;
    while (start < expression.size()) {
        if (expression[start] == '(') {
            int count = 1;
            end = start + 1;
            while (count > 0 && end < expression.size()) {
                if (expression[end] == '(') {
                    count++;
                } else if (expression[end] == ')') {
                    count--;
                }
                end++;
            }
            if (end < expression.size() && isalpha(expression[end])) {
                bracketed_terms.push_back(expression.substr(start, end-start));
            } else {
                int i = start - 1;
                while (i >= 0 && isalpha(expression[i])) {
                    i--;
                }
                bracketed_terms.push_back(expression.substr(i+1, end-i-1));
            }
            start = end;
        } else {
            start++;
        }
    }
    return bracketed_terms;
}

vector<string> Boolean::apply_Distributive_Law_Or(vector<string> bracketed_Terms) {///has bugs, nothing major but needs fix
    vector<string> expanded_Terms;
    for (string term: bracketed_Terms) {
        term.insert(0, "(");
        term.push_back(')');
    }

    for (string term: bracketed_Terms) {
        vector<string> modified_Terms;
        modified_Terms.push_back("");
        int start = 0;
        while (start < term.size()) {
            if (term[start] == '(') {
                int count = 1;
                int end = start + 1;
                while (count > 0 && end < term.size()) {
                    if (term[end] == '(') {
                        count++;
                    } else if (term[end] == ')') {
                        count--;
                    }
                    end++;
                }
                string inner_Term = term.substr(start + 1, end - start - 2);
                vector<string> factors;
                string current_factor = "";
                for (int i = 0; i < inner_Term.size(); i++) {
                    if (inner_Term[i] == '+') {
                        factors.push_back(current_factor);
                        current_factor = "";
                    } else {
                        current_factor += inner_Term[i];
                        if (i == inner_Term.size() - 1) {
                            factors.push_back(current_factor);
                        }
                    }
                }
                vector<string> new_terms;
                for (string factor: factors) {
                    for (int i = 0; i < modified_Terms.size(); i++) {
                        string new_term = modified_Terms[i] + factor;
                        new_terms.push_back(new_term);
                    }
                }
                modified_Terms = new_terms;
                start = end;
            } else {
                vector<string> new_terms;
                for (int i = 0; i < modified_Terms.size(); i++) {
                    string new_term = modified_Terms[i] + term[start];
                    new_terms.push_back(new_term);
                }
                modified_Terms = new_terms;
                start++;
            }
        }
        for (string term: modified_Terms) {
            if (term != "") {
                expanded_Terms.push_back(term);
            }
        }
    }
    return expanded_Terms;
}

vector<string> Boolean::apply_Absorption_Law_Or(vector<string> Terms) {///still has bug... absorbing DE into E when should be opposite
    vector<string> absorbed_Terms;
    for (int i = 0; i < Terms.size(); i++) {
        for (int j = i+1; j < Terms.size(); j++) {
            if (Terms[i].size() < Terms[j].size() && Terms[j-1]!="!" && Terms[j].find(Terms[i]) != string::npos) {//checks if the string equal to term[i] exists within term[j]
                absorbed_Terms.push_back(Terms[i]);//then absorbs
                break;
            }
            else if (Terms[j].size() < Terms[i].size() && Terms[i-1]!="!" && Terms[i].find(Terms[j]) != string::npos) {//checks if the string equal to term[j] exists within term[i]
                absorbed_Terms.push_back(Terms[j]);//then absorbs
                break;
            }

            else if (Terms[i].size() < Terms[j].size() && Terms[j-1]=="!" && Terms[i-1]=="!" && Terms[j].find(Terms[i]) != string::npos) {//for cases where i and j are negations
                absorbed_Terms.push_back(Terms[i]);//then absorbs
                break;
            }

            else if (Terms[j].size() < Terms[i].size() && Terms[i-1]=="!" && Terms[j-1]=="!" && Terms[i].find(Terms[j]) != string::npos) {//for cases where i and j are negations
                absorbed_Terms.push_back(Terms[j]);//then absorbs
                break;
            }

        }
    }
    vector<string> modified_Terms;
    for (string term : Terms) {
        bool is_absorbed = false;
        for (string absorbed_Term : absorbed_Terms) {
            if (term == absorbed_Term) {//if the term already exists in absorbed_Terms breaks and goes to next one, if it doesn't, adds it to list of modified terms
                is_absorbed = true;
                break;
            }
        }
        if (!is_absorbed) {
            modified_Terms.push_back(term);
        }
    }
    return modified_Terms;
}

vector<string> Boolean::apply_DeMorgan_Laws( vector<string> negatedTerms) {
    vector<string> result;

    for (const string& negatedTerm : negatedTerms) {
        string term = negatedTerm.substr(2, negatedTerm.size() - 3); // extract the inner term without the negation symbol and brackets
        string newTerm = "";

        for (int i = 0; i < term.size(); i++) {
            if (term[i] == '+') { // apply De Morgan's law for disjunction
                newTerm += "!";
            } else {
                newTerm += "!" + string(1, term[i]); // negate the current character
                if (i < term.size() - 1 && term[i + 1] != '+') { // if the next character is not a disjunction symbol, add a conjunction symbol
                    newTerm += "+";
                }
            }
        }

        result.push_back(newTerm);
    }

    return result;
}


vector<string> Boolean::extract_Negated_Bracketed_Terms(string expression) {//returns negated bracketed terms
    vector<string> negated_Terms;

    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '!' && expression[i+1] == '(') {
            int j = i+1;
            while (expression[j] != ')') {
                j++;
            }
            negated_Terms.push_back(expression.substr(i, j-i+1));
        }
    }

    return negated_Terms;
}

string Boolean::remove_negated_terms(string expression) {//removes terms with brackets and a negation before said brackets from the vector
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '!' && expression[i+1] == '(') {
            int j = i+2, count = 1;
            while (count != 0) {
                if (expression[j] == '(') {
                    count++;
                } else if (expression[j] == ')') {
                    count--;
                }
                j++;
            }
            expression.erase(i, j-i);
        }
    }
    return expression;
}

string Boolean::remove_bracketed_terms(string expression) {//removes terms with brackets
    int i = 0;
    while (i < expression.size()) {
        if (expression[i] == '(') {
            int j = i + 1;
            int bracket_count = 1;
            while (j < expression.size() && bracket_count > 0) {
                if (expression[j] == '(') {
                    bracket_count++;
                } else if (expression[j] == ')') {
                    bracket_count--;
                }
                j++;
            }
            if (bracket_count == 0) {
                expression.erase(i, j - i);
                i = 0;
            } else {
                i = j;
            }
        } else {
            i++;
        }
    }
    return expression;
}

string Boolean::removePlus(string expression) {//removes "+" from string
    for(int i = 0; i < expression.size(); i++) {
        if(expression[i] == '+' && expression[i+1] == '+') {
            expression.erase(i+1, 1);
            i--; // decrement i since the string has been modified
        }
    }
    return expression;
}

vector<string> Boolean::removeMult(vector<string>& terms) {//removes "*" from string
    for(string& expression : terms) {
        for(int i = 0; i < expression.size(); i++) {
            if(expression[i] == '!' && expression[i+1] == '!') {
                expression.erase(i+1, 1);
                i--; // decrement i since the string has been modified
            }
        }
    }
    return terms;
}

string Boolean::mixVectors(vector<string>& normal_Terms, vector<string>& bracketed_Terms, vector<string>& negated_Terms) {//mixes all 3 vectors into 1
    string expression = "";
    for (int i = 0; i < normal_Terms.size(); i++) {
        expression += normal_Terms[i] + "+";
    }
    for (int i = 0; i < bracketed_Terms.size(); i++) {
        expression += bracketed_Terms[i] + "+";
    }
    for (int i = 0; i < negated_Terms.size() - 1; i++) {
        expression += negated_Terms[i] + "+";
    }
    if (negated_Terms.size() > 0) {
        expression += negated_Terms[negated_Terms.size() - 1];
    }
    return expression;
}

vector<string> Boolean::remove_parentheses(vector<string> terms) {
    for (auto& term : terms) {
        term.erase(remove(term.begin(), term.end(), '('), term.end());
        term.erase(remove(term.begin(), term.end(), ')'), term.end());
    }
    return terms;
}

