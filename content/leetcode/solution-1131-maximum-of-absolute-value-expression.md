
+++
authors = ["grid47"]
title = "Leetcode 1131: Maximum of Absolute Value Expression"
date = "2024-07-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1131: Maximum of Absolute Value Expression in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "cNEQMhXa1uI"
youtube_upload_date="2022-07-29"
youtube_thumbnail="https://i.ytimg.com/vi/cNEQMhXa1uI/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxAbsValExpr(vector<int>& x, vector<int>& y) {
        int res = 0, n = x.size(), smallest, cur;
        for(int p: {1, -1}) {
            for(int q: {1, -1}) {
                smallest = p * x[0] + q * y[0] + 0;
                for(int i = 1; i < n; i++) {
                    cur = p * x[i] + q * y[i] + i;
                    res = max(res, cur - smallest);
                    smallest = min(smallest, cur);
                }
            }
        }
        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
The problem is to find the maximum absolute value of the expression defined as:

\[
| (x[i] - x[j]) + (y[i] - y[j]) |
\]

for all pairs of indices \(i\) and \(j\) in the given arrays \(x\) and \(y\). This expression can be rewritten in a way that simplifies the calculation and enables efficient computation. The goal is to determine this maximum value in a time-efficient manner.

### Approach
To solve this problem, we utilize the properties of absolute values and the idea of calculating the expression in a manner that avoids direct pairwise comparisons, which would be inefficient. The core concept is to reformulate the expression and analyze it under different configurations:

1. **Reformulation**: The expression can be expressed in various forms based on the signs of \(p\) and \(q\) (which represent potential configurations for \(x\) and \(y\)):
   - \( p \in \{1, -1\} \)
   - \( q \in \{1, -1\} \)

   This gives us four combinations to evaluate:
   - \( (x[i] + y[i]) \)
   - \( (x[i] - y[i]) \)
   - \( (-x[i] + y[i]) \)
   - \( (-x[i] - y[i]) \)

2. **Iterate through configurations**: For each combination of \(p\) and \(q\), the algorithm calculates a transformed value for each index and keeps track of the smallest value observed thus far.

3. **Maximize the expression**: The maximum absolute value is updated based on the current transformed value minus the smallest value seen for that configuration, allowing us to effectively compute the maximum absolute difference without needing a nested loop for all pairs.

### Code Breakdown (Step by Step)
```cpp
class Solution {
public:
    int maxAbsValExpr(vector<int>& x, vector<int>& y) {
        int res = 0; // Variable to hold the maximum absolute value found
        int n = x.size(); // Size of the input arrays
        int smallest, cur; // Variables for current calculation and smallest value
        
        for(int p: {1, -1}) { // Loop over possible values for p
            for(int q: {1, -1}) { // Loop over possible values for q
                smallest = p * x[0] + q * y[0] + 0; // Initialize smallest for this configuration
                for(int i = 1; i < n; i++) { // Loop through the elements of the arrays
                    cur = p * x[i] + q * y[i] + i; // Calculate the current expression value
                    res = max(res, cur - smallest); // Update result if current value is greater
                    smallest = min(smallest, cur); // Update smallest value found
                }
            }
        }
        return res; // Return the maximum absolute value found
    }
};
```

- **Line 2-3**: Define the function `maxAbsValExpr` which takes two vectors of integers, `x` and `y`, as input. Initialize the result variable `res` to zero and determine the size of the input arrays.
- **Line 4-5**: Two nested loops iterate through the combinations of \(p\) and \(q\) which take values of either 1 or -1. This allows us to compute all possible configurations of the expression.
- **Line 6**: The variable `smallest` is initialized with the first calculated value for the given configuration of \(p\) and \(q\).
- **Line 7-10**: For each index starting from 1:
  - Compute the current transformed value `cur`.
  - Update `res` by calculating the difference between `cur` and `smallest`.
  - Update `smallest` if the current value is less than the previously recorded smallest value.
- **Line 11**: Finally, return the maximum absolute value stored in `res`.

### Complexity
The time complexity of this algorithm is \(O(n)\), where \(n\) is the length of the input vectors \(x\) and \(y\). The outer loops run a constant number of times (four combinations of \(p\) and \(q\)), and the inner loop iterates through the elements of the input arrays only once. The space complexity is \(O(1)\) as we are using only a few additional variables.

### Conclusion
The provided C++ solution effectively computes the maximum absolute value of the specified expression derived from two input vectors by utilizing a systematic approach with nested loops for sign configurations. This method avoids the inefficiencies of a direct pairwise comparison and ensures that we only perform linear work relative to the size of the input arrays. The use of minimal additional space makes this solution both time-efficient and space-efficient, suitable for large datasets in competitive programming and algorithmic challenges.


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-of-absolute-value-expression/description/)

---
{{< youtube cNEQMhXa1uI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
