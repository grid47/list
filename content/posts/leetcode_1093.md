
+++
authors = ["Crafted by Me"]
title = "Leetcode 1093: Statistics from a Large Sample"
date = "2021-11-04"
description = "Solution to Leetcode 1093"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/statistics-from-a-large-sample/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    double getKth(vector<int> &cnt, int k) {
        int x = 0;
        for(int i = 0; i < 256; i++) {
            x += cnt[i];
            if(x >= k) return i;
        }
        return 256;
    }
    
    vector<double> sampleStats(vector<int>& cnt) {
        double mn = 257, mx = -1, sum = 0, mode, frq = 0, median;
        int x = 0;
        for(int i = 0; i < 256; i++) {
            if(cnt[i] > 0) {
                mn = min(mn, (double)i);
                mx = i;
                sum += (double)cnt[i] * i;
                if(frq < cnt[i]) {
                    frq = cnt[i];
                    mode = i;
                }
                x += cnt[i];                 
            }
        }

        if(x % 2 == 0) {
            double a = getKth(cnt, x / 2);
            double b = getKth(cnt, x / 2 + 1);
            median = (a + b) / 2;
        } else median = getKth(cnt, x/ 2 + 1);
        
        return vector<double> {mn, mx, sum / x, median, mode };
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

