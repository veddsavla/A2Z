#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int counter = 0;

        for(int i =0; i<s.length(); i++){
            if(s[i]=='('){
                if(counter>0){
                    result+=s[i];
                }
                counter++;
            } else if(s[i]==')'){
                counter--;
                if(counter>0){
                    result+=s[i];
                }
            }
        }
        return result;
    }
};