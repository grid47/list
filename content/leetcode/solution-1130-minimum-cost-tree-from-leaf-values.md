
+++
authors = ["grid47"]
title = "Leetcode 1130: Minimum Cost Tree From Leaf Values"
date = "2024-07-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1130: Minimum Cost Tree From Leaf Values in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Stack","Greedy","Monotonic Stack"]
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
    int mctFromLeafValues(vector<int>& arr) {
        
        int res = 0;
        
        vector<int> stk = { INT_MAX };
        for(int a : arr) {
            while(stk.back() <= a) {
                int mid = stk.back();
                stk.pop_back();
                res += mid * min(stk.back(), a);
            }
            stk.push_back(a);
        }
        
        for(int i = 2; i < stk.size(); i++) {
            res += stk[i] * stk[i - 1];
        }
        
        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
The problem of constructing a Minimum Cost Tree from Leaf Values involves building a binary tree from an array of integers such that each internal node in the tree represents the product of the two leaf values beneath it. The goal is to minimize the total cost of the tree, which is the sum of all products calculated for each internal node. Given an array of leaf values, the challenge is to determine the minimum possible cost of such a binary tree.

### Approach
To tackle the MCT problem, a greedy algorithm utilizing a stack is employed. The idea is to maintain a monotonic stack of leaf values, ensuring that we can efficiently compute the cost of merging leaf values into internal nodes while keeping track of the minimum cost at each step. 

The algorithm can be summarized in the following steps:
1. **Initialization**: Start by initializing the result (`res`) to 0 and create a stack with a single value of `INT_MAX` to handle edge cases effectively.
2. **Iterate through the array**: For each value in the array:
   - While the top of the stack is less than or equal to the current value, pop the stack and compute the cost using the popped value and the minimum of the current value and the next top of the stack.
   - Push the current value onto the stack.
3. **Final pass**: After processing all values in the array, there may still be elements in the stack. Perform a final pass to compute the remaining products of the leaf values to finalize the cost.
4. **Return the result**: The final computed value is returned as the minimum cost.

### Code Breakdown (Step by Step)
```cpp
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0; // Initialize the result to 0
        
        vector<int> stk = { INT_MAX }; // Create a stack initialized with INT_MAX
        for(int a : arr) { // Iterate over each leaf value in the input array
            while(stk.back() <= a) { // While the top of the stack is less than or equal to the current value
                int mid = stk.back(); // Store the top value
                stk.pop_back(); // Pop the top value off the stack
                // Calculate the cost using the product of mid and the minimum of the new top of the stack and current value
                res += mid * min(stk.back(), a);
            }
            stk.push_back(a); // Push the current value onto the stack
        }
        
        // Final pass to calculate the remaining products for values left in the stack
        for(int i = 2; i < stk.size(); i++) {
            res += stk[i] * stk[i - 1];
        }
        
        return res; // Return the total minimum cost
    }
};
```

- **Line 2-3**: Define the function `mctFromLeafValues` that takes a vector of integers as input. Initialize the result variable to zero and create a stack initialized with `INT_MAX`.
- **Line 4-14**: The main logic that processes each element in the array:
  - If the current value is greater than the top of the stack, pop the stack and calculate the cost, updating `res`.
  - Push the current value onto the stack for further processing.
- **Line 16-18**: After processing all values, handle any remaining values in the stack by computing their products and adding them to the result.
- **Line 20**: Return the final minimum cost.

### Complexity
The time complexity of this algorithm is \(O(n)\), where \(n\) is the number of elements in the input array. Each element is pushed and popped from the stack at most once, leading to a linear traversal of the array. The space complexity is \(O(n)\) in the worst case due to the stack storing the elements.

### Conclusion
This implementation of the MCT problem provides an efficient way to calculate the minimum cost of merging leaf values into a binary tree. By utilizing a greedy approach with a monotonic stack, the algorithm ensures that the cost is minimized at every step of merging. The method is both optimal and straightforward, making it a robust solution for similar problems involving tree constructions and cost minimization in computational scenarios.


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
