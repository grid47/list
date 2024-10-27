
+++
authors = ["Yasir"]
title = "Leetcode 722: Remove Comments"
date = "2022-11-06"
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

{{< highlight html >}}
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

