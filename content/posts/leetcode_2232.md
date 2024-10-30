
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2232: Minimize Result by Adding Parentheses to Expression"
date = "2018-09-21"
description = "Solution to Leetcode 2232"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string minimizeResult(string exp) {
        
        int pos = -1;
        int x = 0, y = 0, p = 0, q = 0;        
        for(int i = 0; i < exp.size(); i++) {
            if(exp[i] == '+') pos = i;
            if(pos == -1) {
                y = y * 10 + exp[i] - '0';
            } else if (exp[i] != '+'){
                q = q * 10 + exp[i] - '0';
            }
        }
        int tmp = q;
        // cout << y << " " << pos << " " << q << "\n";
        
        vector<int> res = {-1, -1}; int ans = INT_MAX;
        

        for(int i = 0; i < pos; i++) {
            
            x = x * 10 + (i > 0? exp[i - 1] - '0': 0);
            y = y % (int)pow(10, pos - i);
            
            for(int j = pos + 1; j < exp.size(); j++) {
                
                p = p * 10 + (exp[j] - '0');
                q= q % (int)pow(10, exp.size() - 1 - j);
                // cout << x << " " << y << " " << p << " " << q << " " << ans << "\n";                  
                if((x==0?1:x) * (y + p) * (q==0?1:q) < ans) {
                    ans = (x==0?1:x) * (y + p) * (q==0?1:q);
                    // cout << x << " " << y << " " << p << " " << q << " " << ans << "\n";                    
                    res = {i, j};
                }
            }
            p = 0;
            q = tmp;
        }
        // cout << res[0] << " " << res[1];
        
        string ret = "";
        
        int i = 0;
        while(i < res[0]) ret += exp[i++];
        ret += '(';
        while(i <= res[1]) ret += exp[i++];
        ret += ')';
        while(i < exp.size()) ret += exp[i++];
        
        return ret;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

