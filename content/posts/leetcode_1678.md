
+++
authors = ["Yasir"]
title = "Leetcode 1678: Goal Parser Interpretation"
date = "2020-03-25"
description = "Solution to Leetcode 1678"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/goal-parser-interpretation/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    string interpret(string command) {
        string result= "";
        for(int i=0; i<command.size(); i++)
        {
            if(command[i] == '(')
            {
                if(command[i+1] == ')')
                    result += "o";
                if(command[i+1] == 'a' && command[i+2] == 'l')
                {
                    result += "al";
                    i += 2;
                }
            }
            if(command[i] == 'G')
                result += "G";
        }
        return result;
    }
};
{{< /highlight >}}

