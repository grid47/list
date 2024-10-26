
+++
authors = ["Yasir"]
title = "Leetcode 736: Parse Lisp Expression"
date = "2022-10-22"
description = "Solution to Leetcode 736"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/parse-lisp-expression/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int evaluate(string expression) {
        unordered_map<string,int> myMap;
        return help(expression,myMap);
    }
    
    int help(string expression,unordered_map<string,int> myMap) {

        if ((expression[0] == '-') || (expression[0] >= '0' && expression[0] <= '9'))
            return stoi(expression);
        else if (expression[0] != '(')
            return myMap[expression];

        string s = expression.substr(1,expression.size()-2);

        int start = 0;
        string word = parse(s,start);
        if (word == "let") {
            while (true) {
                string variable = parse(s,start);
                //if there is no more expression, simply evaluate the variable
                if (start > s.size())
                    return help(variable,myMap);
                string temp = parse(s,start);
                myMap[variable] = help(temp,myMap);                    
            }
        }

        else if (word == "add") 
            return help(parse(s,start),myMap) + help(parse(s,start),myMap);

        else if (word == "mult") 
            return help(parse(s,start),myMap) * help(parse(s,start),myMap);

        return 0;
    }
    
    //function to seperate each expression
    string parse(string &s,int &start) {
        int end = start+1, temp = start, count = 1;
        if (s[start] == '(') {
            while (count != 0) {
                if (s[end] == '(')
                    count++;
                else if (s[end] == ')')
                    count--;
                end++;
            }
        }
        else {
            while (end < s.size() && s[end] != ' ')
                end++;
        }
        start = end+1;
        return s.substr(temp,end-temp);
    }
};
{{< /highlight >}}

