
+++
authors = ["grid47"]
title = "Leetcode 1774: Closest Dessert Cost"
date = "2024-05-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1774: Closest Dessert Cost in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Iom0aF6DOwU"
youtube_upload_date="2021-02-28"
youtube_thumbnail="https://i.ytimg.com/vi/Iom0aF6DOwU/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int target;
    vector<int> top;
    
    int closestCost(vector<int>& base, vector<int>& top, int target) {
        this->target = target;
        this->top = top;
        int ans = 0;
        for(int i = 0; i < base.size(); i++)
            ans = close(ans, dfs(0, base[i]));
        return ans;
    }
    
    
    int dfs(int idx, int sum) {
        if(idx >= top.size()) return sum;
        
        int a = dfs(idx + 1, sum + top[idx]);
        int b = dfs(idx + 1, sum + 2 * top[idx]);
        int c = dfs(idx + 1, sum);
        
        return close(a, close(b, c));
    }
    
    int close(int a, int b) {
        if(a == 0) return b;
        if(b == 0) return a;
        
        if(abs(target - a) == abs(target - b))
            return a < b? a: b;
        
        return abs(target - a) < abs(target - b) ? a: b;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to find the closest cost to a specified target value based on a set of base costs and optional topping costs. The user has a list of base costs and can choose to add any combination of topping costs to any of the base costs. Each topping can be added in increments of one or two, or not at all. The goal is to find the closest cost to the target by adding these optional toppings, while prioritizing lower costs when two costs are equally close to the target.

### Approach

The solution employs a depth-first search (DFS) strategy to explore all possible combinations of costs that can be formed using the base costs and toppings. The approach can be summarized in the following steps:

1. **Initialization**: The solution starts by initializing variables to store the target cost and the topping costs.

2. **Iterate Over Base Costs**: For each base cost, a recursive DFS function is called to explore all combinations of toppings that can be added to that base.

3. **Recursive DFS Function**: This function explores the three possibilities for each topping:
   - Add the topping once.
   - Add the topping twice.
   - Skip the topping.
   It calculates the total cost for each combination.

4. **Comparing Costs**: After calculating potential costs from the DFS, the closest cost to the target is updated using a helper function that compares the current best cost against the newly calculated costs.

5. **Return the Closest Cost**: Finally, the function returns the closest cost to the target.

### Code Breakdown (Step by Step)

Here’s a breakdown of the provided C++ code:

```cpp
class Solution {
public:
    int target;
    vector<int> top;
```
- The `Solution` class is defined with two public member variables: `target`, an integer that stores the target cost, and `top`, a vector that holds the topping costs.

```cpp
    int closestCost(vector<int>& base, vector<int>& top, int target) {
        this->target = target;
        this->top = top;
        int ans = 0;
        for(int i = 0; i < base.size(); i++)
            ans = close(ans, dfs(0, base[i]));
        return ans;
    }
```
- The `closestCost` function takes three parameters: `base`, a vector of base costs; `top`, a vector of topping costs; and `target`, the desired cost.
- It initializes the `target` and `top` member variables, and sets `ans` to zero.
- A loop iterates through each base cost, calling the `dfs` function to explore topping combinations and update `ans` with the closest cost found.

```cpp
    int dfs(int idx, int sum) {
        if(idx >= top.size()) return sum;
        
        int a = dfs(idx + 1, sum + top[idx]);
        int b = dfs(idx + 1, sum + 2 * top[idx]);
        int c = dfs(idx + 1, sum);
        
        return close(a, close(b, c));
    }
```
- The `dfs` function is defined to explore topping combinations recursively.
- The base case checks if all topping options have been considered (`idx >= top.size()`), in which case it returns the accumulated `sum`.
- The function makes three recursive calls to calculate potential costs:
  - `a` represents the cost when adding the topping once.
  - `b` represents the cost when adding the topping twice.
  - `c` represents the cost when skipping the topping.
- It then returns the closest cost to the target from the three calculated values using the `close` function.

```cpp
    int close(int a, int b) {
        if(a == 0) return b;
        if(b == 0) return a;
        
        if(abs(target - a) == abs(target - b))
            return a < b? a: b;
        
        return abs(target - a) < abs(target - b) ? a: b;
    }
};
```
- The `close` function is defined to compare two costs, `a` and `b`, to determine which is closer to the target.
- If one cost is zero, it returns the other cost.
- If both costs are non-zero, it checks their distances from the target and returns the cost that is closer. If both distances are equal, it prefers the smaller cost.

### Complexity

- **Time Complexity**: The time complexity of this solution is exponential, specifically \(O(3^m)\), where \(m\) is the number of toppings. This is because each topping has three possibilities (add once, add twice, skip) leading to a branching factor of three.

- **Space Complexity**: The space complexity is \(O(m)\) due to the recursive stack space used during the DFS. Additionally, the memory used to store the topping costs is also considered, but it does not scale with the input size as `top` is a fixed size.

### Conclusion

The provided code efficiently solves the problem of finding the closest cost to a target by exploring all possible combinations of base and topping costs using a recursive DFS approach. This technique allows for comprehensive exploration of combinations while leveraging a helper function to maintain optimal costs during comparisons.

By implementing this solution, developers can easily adapt it for similar problems involving combinations and optimizations, particularly in scenarios where there are constraints on the values being combined. The code exemplifies a structured approach to problem-solving, balancing clarity with the complexities inherent in recursive algorithms.

In practice, understanding the nuances of such algorithms is crucial for tackling a wide range of computational problems, making this implementation a valuable reference for both educational and practical applications in algorithm design and software development.

[`Link to LeetCode Lab`](https://leetcode.com/problems/closest-dessert-cost/description/)

---
{{< youtube Iom0aF6DOwU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
