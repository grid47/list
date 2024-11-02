
+++
authors = ["Crafted by Me"]
title = "Leetcode 2353: Design a Food Rating System"
date = "2017-05-24"
description = "Solution to Leetcode 2353"
tags = [
    
]
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


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

