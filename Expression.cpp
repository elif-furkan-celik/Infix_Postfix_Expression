#include <string>
#include <stack>
#include <iostream>

using namespace std;

///----------------------------------------------------------------------------------
/// Given an expression in infix-notation, converts it to a string in post-fix notation
///
string Infix2Postfix(string &s) {
	// Fill this in
	string s2 = s;
	string result = "";
	stack<char> signs;


    for(int i=0; i<s2.length() ; i++){
          if(s2[i]==' '){
            s2.erase(i,1);
            i--;
          }
    }

    while(s2.length() != 0){
        if(s2[0]<58 && 47<s2[0]){
            int n;
            n = stoi(s2);
            result += to_string(n) + ' ';
            s2.erase(0, to_string(n).length());
        }else if(signs.empty()){
            signs.push(s2[0]);
            s2.erase(0,1);

        }else if(s2[0] == '('){
            signs.push(s2[0]);
            s2.erase(0,1);

        }else if(s2[0]=='*' || s2[0]=='/'){
            signs.push(s2[0]);
            s2.erase(0,1);

            if(s2[0] == '('){
                signs.push(s2[0]);
                s2.erase(0,1);

            }else{
                int temp;
                temp = stoi(s2);
                s2.erase(0, to_string(temp).length());
                result += to_string(temp) + ' ';
                result += signs.top();
                signs.pop();
            }
        }else if(s2[0]=='-' || s2[0]=='+'){
            if(signs.top()=='(' || signs.empty()){
                signs.push(s2[0]);
                s2.erase(0,1);

            }else{
                result += signs.top();
                signs.pop();
                signs.push(s2[0]);
                s2.erase(0,1);
            }
        }else if(s2[0] == ')'){
            s2.erase(0,1);
            while(!signs.empty() && signs.top()!='('){
                result += signs.top();
                signs.pop();
            }
            signs.pop();
        }else{
            cout<<"Sometihng is wrong."<<endl;
        }
    }

    while(!signs.empty()){
        result += signs.top();
        signs.pop();
    }

	return result;
} // end-Infix2Postfix

///----------------------------------------------------------------------------------
/// Given a string in post-fix notation, evaluates it and returns the result
///
int EvaluatePostfixExpression(string& s) {
	string s2 = s;
	stack<int> numbers;

    while(s2.length() != 0){
        if(s2[0]==' '){
            s2.erase(0,1);
        }else if(s2[0]<58 && 47<s2[0]){
            int n;
            n = stoi(s2);
            numbers.push(n);
            s2.erase(0, to_string(n).length());
        }else if(s2[0] == '*'){
            int n1 = numbers.top();
            numbers.pop();
            int n2 = numbers.top();
            numbers.pop();
            numbers.push(n2 * n1);
            s2.erase(0,1);

        }else if(s2[0]=='/'){
            int n1 = numbers.top();
            numbers.pop();
            int n2 = numbers.top();
            numbers.pop();
            numbers.push(n2 / n1);
            s2.erase(0,1);

        }else if(s2[0]=='+'){
            int n1 = numbers.top();
            numbers.pop();
            int n2 = numbers.top();
            numbers.pop();
            numbers.push(n2 + n1);
            s2.erase(0,1);

        }else if(s2[0]=='-'){
            int n1 = numbers.top();
            numbers.pop();
            int n2 = numbers.top();
            numbers.pop();
            numbers.push(n2 - n1);
            s2.erase(0,1);

        }else{
            cout<<"Sometihng is wrong."<<endl;
        }
    }

    if(numbers.size() != 1){
        cout<<"Something is wrong."<<endl;
        return 0;
    }
	return numbers.top();
} // end-EvaluatePostfixExpression
