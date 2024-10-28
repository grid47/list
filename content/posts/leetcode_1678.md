
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1678: Goal Parser Interpretation"
date = "2020-03-26"
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

{{< highlight cpp >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

