
+++
authors = ["grid47"]
title = "Leetcode 1237: Find Positive Integer Solution for a Given Equation"
date = "2024-07-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1237: Find Positive Integer Solution for a Given Equation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Two Pointers","Binary Search","Interactive"]
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
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& cf, int z) {
        int xl = 1, xr = 1000;

        vector<vector<int>> res;
        
        for(int x = 1; x <= 1000; x++) {
            if(cf.f(x, 0) > z) break;
            
            int ans = -1;
            int yl = 1, yr = 1000;            
            while(yl <= yr) {
                int ymid = yl + (yr - yl + 1) / 2;
                int sol = cf.f(x, ymid);
                if(sol == z) {
                    ans = ymid;
                    break;
                }
                if(sol < z) yl = ymid + 1;
                else        yr = ymid - 1;
            }
            if(ans != -1) res.push_back({x, ans});
        }
        return res;
    }
};
{{< /highlight >}}
---



### Problem Statement
The problem involves finding all pairs of positive integers \( (x, y) \) such that a given function \( f(x, y) \) equals a target value \( z \). The function \( f \) is strictly increasing in both \( x \) and \( y \). This means that for any fixed \( x \), if you increase \( y \), the output of \( f(x, y) \) also increases, and similarly, for any fixed \( y \), increasing \( x \) will also result in a higher output. Given this property, the objective is to efficiently identify all such pairs \( (x, y) \) within the range \( 1 \) to \( 1000 \).

### Approach
To solve this problem, we utilize a nested search strategy involving two loops:
1. **Outer Loop**: Iterate through all possible values of \( x \) from \( 1 \) to \( 1000 \).
2. **Inner Loop**: For each \( x \), perform a binary search on \( y \) to find values such that \( f(x, y) = z \).
   - If \( f(x, 0) \) exceeds \( z \), we can break early from the outer loop since all subsequent values of \( x \) will also result in outputs greater than \( z \).

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& cf, int z) {
        int xl = 1, xr = 1000;
        vector<vector<int>> res;
```
- **Lines 1-4**: We define the `Solution` class and declare the public method `findSolution`, which takes a `CustomFunction` reference and an integer `z` as inputs. We also initialize the bounds for \( x \) and an empty result vector `res` to store the valid pairs.

```cpp
        for(int x = 1; x <= 1000; x++) {
            if(cf.f(x, 0) > z) break;
```
- **Lines 5-7**: We begin an outer loop that iterates \( x \) from \( 1 \) to \( 1000 \). Inside this loop, we check if \( f(x, 0) \) is greater than \( z \). If it is, we break out of the loop, as all further values of \( x \) will also yield results greater than \( z \).

```cpp
            int ans = -1;
            int yl = 1, yr = 1000;            
```
- **Lines 8-10**: We initialize `ans` to store the valid \( y \) value when found and set the binary search bounds for \( y \) from \( 1 \) to \( 1000 \).

```cpp
            while(yl <= yr) {
                int ymid = yl + (yr - yl + 1) / 2;
                int sol = cf.f(x, ymid);
```
- **Lines 11-13**: We start a while loop for binary search, continuing as long as the lower bound \( yl \) is less than or equal to the upper bound \( yr \). We calculate the midpoint \( ymid \) and call the function \( f \) to evaluate \( sol \).

```cpp
                if(sol == z) {
                    ans = ymid;
                    break;
                }
```
- **Lines 14-16**: If \( sol \) equals \( z \), we have found a valid \( y \) for the current \( x \). We store this \( y \) in `ans` and break out of the binary search.

```cpp
                if(sol < z) yl = ymid + 1;
                else        yr = ymid - 1;
            }
```
- **Lines 17-20**: If \( sol \) is less than \( z \), we adjust the lower bound \( yl \) to \( ymid + 1 \) to search for higher \( y \) values. Conversely, if \( sol \) is greater than \( z \), we adjust the upper bound \( yr \) to \( ymid - 1 \).

```cpp
            if(ans != -1) res.push_back({x, ans});
        }
```
- **Lines 21-23**: After the binary search completes, if `ans` has been updated (i.e., it is not -1), we push the pair \( (x, ans) \) into the result vector `res`.

```cpp
        return res;
    }
};
```
- **Lines 24-26**: Finally, we return the result vector containing all pairs \( (x, y) \) that satisfy the equation \( f(x, y) = z \).

### Complexity
1. **Time Complexity**: The overall time complexity of this solution is \( O(1000 \log(1000)) \). The outer loop iterates \( 1000 \) times (for each possible \( x \)), and for each \( x \), we perform a binary search over \( y \), which also runs in logarithmic time relative to the upper limit of \( 1000 \).

2. **Space Complexity**: The space complexity is \( O(1) \) for auxiliary space used, aside from the output space, since we are only using a few additional integer variables.

### Conclusion
The `findSolution` function provides an efficient solution for finding pairs of integers \( (x, y) \) such that \( f(x, y) = z \) using a structured approach that leverages the increasing properties of the function. The combination of an outer loop to iterate over \( x \) values and an inner binary search for \( y \) values ensures that we minimize the number of function calls while systematically exploring the possible pairs. This algorithm effectively addresses the problem within the defined constraints, making it a suitable choice for applications requiring similar pair-finding logic.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
