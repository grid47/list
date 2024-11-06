
+++
authors = ["Crafted by Me"]
title = "Leetcode 2353: Design a Food Rating System"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2353: Design a Food Rating System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Design","Heap (Priority Queue)","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-a-food-rating-system/description/)

---

**Code:**

{{< highlight cpp >}}
class FoodRatings {
    unordered_map<string, set<pair<int, string>>> cus_itm;
    unordered_map<string, string> fd_cus;
    unordered_map<string, int> fd_rat;
public:
    FoodRatings(vector<string>& fd, vector<string>& cus, vector<int>& rat) {
        int n = fd.size();
        for(int i = 0; i < n; i++) {
            cus_itm[cus[i]].insert(pair(-rat[i], fd[i]));
            fd_cus[fd[i]] = cus[i];
            fd_rat[fd[i]] = rat[i];
        }
    }
    
    void changeRating(string fd, int rat) {
        string cus = fd_cus[fd];
        int r = fd_rat[fd];
        cus_itm[cus].erase({-r, fd});
        cus_itm[cus].insert({-rat, fd});
        fd_rat[fd] = rat;
 
    }
    
    string highestRated(string cus) {
        return begin(cus_itm[cus])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
{{< /highlight >}}


---
{{< youtube Ikp8SgbgbEo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2354: Number of Excellent Pairs](https://grid47.xyz/posts/leetcode_2354) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

