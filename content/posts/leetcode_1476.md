
+++
authors = ["Yasir"]
title = "Leetcode 1476: Subrectangle Queries"
date = "2020-10-14"
description = "Solution to Leetcode 1476"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/subrectangle-queries/description/)

---

**Code:**

{{< highlight html >}}
class SubrectangleQueries {
public:
    vector<vector<int>> rec;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rec = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i = row1; i <= row2; i++)
        for(int j = col1; j <= col2; j++)
            rec[i][j] = newValue;
    }
    
    int getValue(int row, int col) {
        return rec[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

