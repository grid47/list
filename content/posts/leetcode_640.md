
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 640: Solve the Equation"
date = "2023-01-29"
description = "Solution to Leetcode 640"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/solve-the-equation/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string solveEquation(string eqn) {
        int i = 0;
        int para = 0, xpara = 0;
        int flag = 1;
        while(i < eqn.size()) {
            int sgn = 1;
            int tmp = 0;
            if(eqn[i] == '=') {
                flag = -1;
                i++;
            } 
            if(eqn[i] == '-') {
                sgn = -1;
                i++;
            }
            if(eqn[i] == '+') {
                sgn = 1;
                i++;
            }
            if(isdigit(eqn[i])) {
                while(i < eqn.size() && isdigit(eqn[i])) {
                    tmp = tmp * 10 + eqn[i] - '0';
                    i++;
                }
                if(i < eqn.size() && eqn[i] == 'x') {
                    xpara += flag * sgn * tmp;
                    i++;
                }
                else para += flag * sgn * tmp;
            } else {
                xpara += flag * sgn;
                i++;
            }
        }

        string res;
        cout << para << '-'<< xpara;
        if(para == 0 && xpara == 0)
            res = "Infinite solutions";
        else if (xpara == 0)
            res = "No solution";
        else res = "x=" + to_string(para/xpara*-1);

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/640.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
