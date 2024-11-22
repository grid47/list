
+++
authors = ["grid47"]
title = "Leetcode 1014: Best Sightseeing Pair"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1014: Best Sightseeing Pair in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& val) {

        int res = 0, cur = 0;

        for(int x : val) {
            res = max(res, cur + x);
            cur = max(cur, x) - 1;
        }

        return res;
    }
};
{{< /highlight >}}
---



### Problem Statement
The problem involves finding the maximum score from a pair of sightseeing locations, where each location has an associated score. The score for a pair of locations `(i, j)` is defined as:

\[ \text{score}(i, j) = \text{val}[i] + \text{val}[j] + i - j \]

Here, `val[i]` and `val[j]` represent the values of the two locations, and the term `i - j` accounts for the distance between the two locations. The goal is to maximize this score for all possible pairs of locations in the array.

For instance, given an array `val = [8, 1, 5, 2, 6]`, we want to determine the maximum score possible from all pairs of indices `(i, j)` where `i < j`.

### Approach
To solve this problem efficiently, we can adopt a linear scan approach that keeps track of the best potential score as we iterate through the array:
1. **Initialize Variables**: We will use a variable to store the maximum score (`res`) and another to keep track of the current best value adjusted for the distance penalty (`cur`).
2. **Iterate Through Values**: As we iterate through the values, for each position `j`, we calculate the score using the best previously encountered value adjusted by the index offset.
3. **Update Values**: After calculating the score for the current index, we update the `cur` value for future pairs.

This method ensures that we only need a single pass through the array, making it highly efficient.

### Code Breakdown (Step by Step)

1. **Function Declaration**:
   - The function `maxScoreSightseeingPair` is defined as a public member of the `Solution` class, taking a vector of integers (`val`) as input.

2. **Variable Initialization**:
   - We initialize `res` to 0, which will hold the maximum score found, and `cur` to 0, which tracks the best adjusted value for previously encountered scores.

3. **Iterating Through Values**:
   - A `for` loop iterates over each value `x` in the `val` array. This loop processes each location one at a time:
     - Inside the loop, we first update `res` by calculating the potential score using the current value `x` and the best previously adjusted score `cur`. This is done using the expression `res = max(res, cur + x)`.
     - We then update `cur` to account for the current value minus the distance penalty of 1. This is done with the expression `cur = max(cur, x) - 1`. The maximum function ensures we keep the best score for future comparisons.

4. **Returning the Result**:
   - After processing all values, the function returns `res`, which contains the maximum score found.

### Complexity Analysis
- **Time Complexity**: The time complexity of this function is O(n), where `n` is the number of elements in the `val` array. This efficiency arises from the single pass through the array, processing each value in constant time.
- **Space Complexity**: The space complexity is O(1) because we are only using a fixed amount of extra space for the variables `res` and `cur`, regardless of the input size.

### Conclusion
The `maxScoreSightseeingPair` function provides an efficient solution for maximizing the score from pairs of sightseeing locations. By utilizing a single linear pass through the array and maintaining a running tally of the best potential scores, this approach achieves an optimal runtime while remaining straightforward and easy to understand.

This solution exemplifies the power of dynamic programming concepts, specifically the idea of maintaining state (in this case, the `cur` value) to make informed decisions as we iterate through the input. This method can be applied to various problems where optimal substructure and overlapping subproblems are present, enhancing one's problem-solving toolkit.

Moreover, the clarity and efficiency of this implementation make it suitable for competitive programming and technical interviews, where performance and correctness are paramount. The straightforward nature of the approach allows for easy comprehension and adaptation to related problems, reinforcing its value in a programmer's repertoire.

In summary, the `maxScoreSightseeingPair` function illustrates an elegant and efficient method for tackling optimization problems within an array, showcasing the effectiveness of simple yet powerful algorithms in solving real-world challenges in a computational context.


[`Link to LeetCode Lab`](https://leetcode.com/problems/best-sightseeing-pair/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
