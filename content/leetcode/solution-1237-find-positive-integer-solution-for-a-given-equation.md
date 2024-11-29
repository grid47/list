
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
comments = true
+++



---
You are given a callable function f(x, y) with a hidden formula and a target value z. Your task is to find all pairs of positive integers x and y such that f(x, y) == z. The function is monotonically increasing, meaning: f(x, y) < f(x + 1, y) and f(x, y) < f(x, y + 1). Return a list of all such pairs. If no valid pairs are found, return an empty list.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a function identifier and a target value z. The function_id will be used to choose the formula that defines f(x, y).
- **Example:** `Input: function_id = 1, z = 5`
- **Constraints:**
	- 1 <= function_id <= 9
	- 1 <= z <= 100
	- 1 <= x, y <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of pairs of positive integers [x, y] such that f(x, y) == z. If no such pairs exist, return an empty list.
- **Example:** `Output: [[1, 4], [2, 3], [3, 2], [4, 1]]`
- **Constraints:**
	- The pairs should be ordered by x first, then by y.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to reverse-engineer the hidden formula and find all pairs (x, y) such that f(x, y) equals the target value z.

- 1. Iterate over possible values of x and y within the defined range.
- 2. Use binary search to find the value of y for each x such that f(x, y) == z.
- 3. Collect and return all valid pairs.
{{< dots >}}
### Problem Assumptions ✅
- The function f(x, y) is deterministic and will return the same output for the same inputs every time.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: function_id = 1, z = 5`  \
  **Explanation:** For function_id = 1, the formula is f(x, y) = x + y. The pairs [1, 4], [2, 3], [3, 2], [4, 1] all give f(x, y) = 5.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to efficiently search for all valid pairs (x, y) where f(x, y) equals z using a binary search approach.

### Initial Thoughts 💭
- The function f(x, y) is monotonically increasing in both x and y.
- This allows us to apply binary search to reduce the search space.
- We can iterate through possible values of x and use binary search for y.
{{< dots >}}
### Edge Cases 🌐
- If no valid pairs exist, the function should return an empty list.
- For larger values of z, the approach should efficiently search within the valid range of x and y.
- The approach should handle edge cases like the smallest and largest possible values of x and y.
- Ensure that the time complexity allows the solution to handle the maximum range of x and y (1 <= x, y <= 1000).
{{< dots >}}
## Code 💻
```cpp
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
```

This function finds pairs of integers (x, y) such that the result of a function `f(x, y)` is equal to a given value `z`. The function uses a binary search on `y` for each `x` in the range 1 to 1000.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> findSolution(CustomFunction& cf, int z) {
	```
	The function `findSolution` is defined, which takes a `CustomFunction` object `cf` and an integer `z` as input and returns a 2D vector containing the pairs (x, y) where `f(x, y) == z`.

2. **Variable Initialization**
	```cpp
	    int xl = 1, xr = 1000;
	```
	The variables `xl` and `xr` are initialized to 1 and 1000, respectively, representing the search range for the `x` values.

3. **Result Initialization**
	```cpp
	    vector<vector<int>> res;
	```
	A 2D vector `res` is initialized to store the pairs (x, y) that satisfy the condition `f(x, y) == z`.

4. **Outer Loop**
	```cpp
	    for(int x = 1; x <= 1000; x++) {
	```
	An outer loop starts that iterates over all possible values of `x` from 1 to 1000.

5. **Early Termination Check**
	```cpp
	        if(cf.f(x, 0) > z) break;
	```
	If the result of `f(x, 0)` is greater than `z`, the loop is broken early as no valid pairs can be found for this `x`.

6. **Binary Search Initialization**
	```cpp
	        int ans = -1;
	```
	The variable `ans` is initialized to -1, indicating that no valid `y` has been found yet for the current `x`.

7. **Binary Search Boundaries**
	```cpp
	        int yl = 1, yr = 1000;            
	```
	The binary search range for `y` is initialized with `yl = 1` and `yr = 1000`.

8. **Binary Search Loop**
	```cpp
	        while(yl <= yr) {
	```
	A while loop begins to perform binary search within the range of `y` values from `yl` to `yr`.

9. **Binary Search Midpoint**
	```cpp
	            int ymid = yl + (yr - yl + 1) / 2;
	```
	The midpoint `ymid` of the current `y` range is calculated using the formula `yl + (yr - yl + 1) / 2`.

10. **Function Evaluation**
	```cpp
	            int sol = cf.f(x, ymid);
	```
	The function `f(x, ymid)` is evaluated to get the result `sol` for the current `x` and `ymid`.

11. **Solution Found**
	```cpp
	            if(sol == z) {
	```
	If the result of `f(x, ymid)` is equal to `z`, the solution has been found for this pair (x, ymid).

12. **Store Solution**
	```cpp
	                ans = ymid;
	```
	The variable `ans` is updated with the value of `ymid`, which is the value of `y` that satisfies `f(x, y) == z`.

13. **Break from Binary Search**
	```cpp
	                break;
	```
	The loop breaks because a valid `y` has been found for the current `x`.

14. **Adjust Search Range**
	```cpp
	            if(sol < z) yl = ymid + 1;
	```
	If `sol` is less than `z`, the search range for `y` is adjusted by setting `yl` to `ymid + 1` to search in the upper half.

15. **Adjust Search Range**
	```cpp
	            else        yr = ymid - 1;
	```
	If `sol` is greater than `z`, the search range for `y` is adjusted by setting `yr` to `ymid - 1` to search in the lower half.

16. **Store Valid Pair**
	```cpp
	        if(ans != -1) res.push_back({x, ans});
	```
	If a valid `y` has been found (`ans != -1`), the pair (x, ans) is added to the result vector `res`.

17. **Return Result**
	```cpp
	    return res;
	```
	The function returns the vector `res` containing all valid pairs (x, y) where `f(x, y) == z`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n), where n is the number of possible values of y for each x.
- **Average Case:** O(n log n), where n is the number of values for y.
- **Worst Case:** O(n log n), where n is the number of values for x and y.

The time complexity is logarithmic for each binary search, and linear for iterating through x.

### Space Complexity 💾
- **Best Case:** O(1), if no valid pairs are found.
- **Worst Case:** O(n), where n is the number of valid pairs.

The space complexity is determined by the number of valid pairs returned.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
