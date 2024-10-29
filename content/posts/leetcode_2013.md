
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2013: Detect Squares"
date = "2019-04-27"
description = "Solution to Leetcode 2013"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/detect-squares/description/)

---

**Code:**

{{< highlight cpp >}}
class DetectSquares {
    int cnt[1001][1001] = {};
    vector<pair<int, int>> pts;
public:
    DetectSquares() {
       // cnt.resize(10001, vector<int>(10001));
    }
    
    void add(vector<int> point) {
        cnt[point[0]][point[1]]++;
        pts.emplace_back(point[0], point[1]);
    }
    
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        int ans = 0;
        for(auto [x3, y3] : pts) {
            if(abs(x3 - x1) == 0 || abs(x1 - x3) != abs(y1 - y3))
                continue;
            ans += cnt[x1][y3] * cnt[x3][y1];
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

