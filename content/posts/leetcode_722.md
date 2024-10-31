
+++
authors = ["Crafted by Me"]
title = "Leetcode 722: Remove Comments"
date = "2022-11-10"
description = "Solution to Leetcode 722"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-comments/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool is_mul = false;
        string res = "";
        for(int i = 0; i < source.size(); i++) {
            string str = source[i];
            res = is_mul? res:"";
            for(int j = 0; j < str.size() ; j++) {
                if(!is_mul) {
                    if (j < str.size() - 1 && str[j] == '/' && str[j + 1] == '/') {
                        break;
                    } else if (j < str.size() - 1 && str[j] == '/' && str[j + 1] == '*') {
                        is_mul = true;
                        j++;
                    } else {
                        res += str[j];
                    }
                } else {
                    if(j < str.size() - 1 && str[j] == '*' && str[j + 1] == '/') {
                        is_mul = false;
                        j++;
                    }
                }
            }

            if(!is_mul && res != "") ans.push_back(res);
        }
        return ans;
    }
};

//
/*
*/
/* */
// */ --- //
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/722.md" >}}

---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

