
+++
authors = ["grid47"]
title = "Leetcode 2232: Minimize Result by Adding Parentheses to Expression"
date = "2024-03-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2232: Minimize Result by Adding Parentheses to Expression in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "8Nt7G6bIkSI"
youtube_upload_date="2022-04-10"
youtube_thumbnail="https://i.ytimg.com/vi_webp/8Nt7G6bIkSI/maxresdefault.webp"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2232.md" >}}
---
{{< youtube 8Nt7G6bIkSI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2233: Maximum Product After K Increments](https://grid47.xyz/leetcode/solution-2233-maximum-product-after-k-increments/) |
| --- |