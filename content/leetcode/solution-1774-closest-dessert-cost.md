
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
comments = true
+++



---
You are planning to make a custom dessert by choosing an ice cream base and toppings. The dessert must follow these rules: You must select one ice cream base. You can add one or more types of toppings, or choose to skip toppings. You can add at most two of each topping type. You are given an array representing the base costs and topping costs. The goal is to create a dessert where the total cost is as close as possible to the target price. If there are multiple dessert combinations that meet the target price, return the lower cost.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given three inputs:
- **Example:** `baseCosts = [2, 4], toppingCosts = [3, 5], target = 12`
- **Constraints:**
	- 1 <= baseCosts.length, toppingCosts.length <= 10
	- 1 <= baseCosts[i], toppingCosts[i] <= 10^4
	- 1 <= target <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the closest possible cost of the dessert to target. If there are multiple, return the lower one.
- **Example:** `Input: baseCosts = [2, 4], toppingCosts = [3, 5], target = 12, Output: 12`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the combination of base and toppings that gives the closest cost to the target.

- 1. Iterate through all the possible combinations of base and toppings (with up to two of each topping).
- 2. Calculate the cost for each combination.
- 3. Compare the cost to the target and track the closest possible cost.
- 4. If multiple combinations are equally close to the target, return the lower cost.
{{< dots >}}
### Problem Assumptions ✅
- You can choose any combination of base and toppings.
- There is no limit on the number of toppings you can choose, but no more than two of each topping type.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: baseCosts = [2, 4], toppingCosts = [3, 5], target = 12`  \
  **Explanation:** By choosing base 1 (cost 4), topping 0 (1 x 3) and topping 1 (1 x 5), the total cost is exactly 12, which matches the target.

- **Input:** `Input: baseCosts = [1, 6], toppingCosts = [2, 4], target = 15`  \
  **Explanation:** By choosing base 1 (cost 6), topping 0 (1 x 2) and topping 1 (2 x 4), the total cost is 14, which is the closest value to 15.

{{< dots >}}
## Approach 🚀
The approach is to explore all possible combinations of base and toppings, calculating the total cost for each combination and comparing it to the target.

### Initial Thoughts 💭
- We need to consider all possible topping combinations (0, 1, or 2 of each topping).
- This will result in a large number of possible combinations, but the limits make it feasible to check all.
- We can solve this with a depth-first search (DFS) approach to try all topping combinations.
{{< dots >}}
### Edge Cases 🌐
- Ensure the inputs are non-empty arrays for baseCosts and toppingCosts.
- The solution should handle up to 10 base flavors and 10 topping types efficiently.
- Consider cases where the target is smaller than the lowest possible cost or larger than the maximum possible cost.
- Constraints should be respected, and the solution should be optimal within the given bounds.
{{< dots >}}
## Code 💻
```cpp
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
```

This code defines a solution to find the closest cost by considering base costs and adding optional top-up costs in different combinations. The helper functions 'dfs' and 'close' evaluate the best possible cost close to the target.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int target;
	```
	Declare an integer variable `target`, which will hold the target cost value for comparison.

2. **Variable Declaration**
	```cpp
	vector<int> top;
	```
	Declare a vector `top` to store additional cost options that can be added to the base cost.

3. **Function Definition**
	```cpp
	int closestCost(vector<int>& base, vector<int>& top, int target) {
	```
	Define the `closestCost` function, which takes two vectors (`base` and `top`) and an integer `target`, and returns the closest cost to the target.

4. **Assign Target**
	```cpp
	    this->target = target;
	```
	Assign the `target` value passed to the function to the class-level `target` variable.

5. **Assign Top**
	```cpp
	    this->top = top;
	```
	Assign the `top` vector passed to the function to the class-level `top` vector.

6. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initialize an integer variable `ans` to store the closest cost.

7. **Loop Through Base**
	```cpp
	    for(int i = 0; i < base.size(); i++)
	```
	Start a loop to iterate over each element in the `base` vector.

8. **Update Answer**
	```cpp
	        ans = close(ans, dfs(0, base[i]));
	```
	Update the `ans` variable by calling the `close` function with the current value of `ans` and the result from the `dfs` function.

9. **Return Statement**
	```cpp
	    return ans;
	```
	Return the value of `ans`, which contains the closest cost found.

10. **Function Definition**
	```cpp
	int dfs(int idx, int sum) {
	```
	Define the `dfs` function, which recursively computes the possible sums by considering each top-up cost.

11. **Base Case**
	```cpp
	    if(idx >= top.size()) return sum;
	```
	Base case: If the index `idx` exceeds the size of `top`, return the accumulated sum.

12. **Recursive Call a**
	```cpp
	    int a = dfs(idx + 1, sum + top[idx]);
	```
	Recursive call to `dfs` considering adding the current `top[idx]` to the sum.

13. **Recursive Call b**
	```cpp
	    int b = dfs(idx + 1, sum + 2 * top[idx]);
	```
	Recursive call to `dfs` considering adding twice the current `top[idx]` to the sum.

14. **Recursive Call c**
	```cpp
	    int c = dfs(idx + 1, sum);
	```
	Recursive call to `dfs` considering not adding the current `top[idx]` to the sum.

15. **Return Statement**
	```cpp
	    return close(a, close(b, c));
	```
	Return the result of `close`, which determines the closest cost from the recursive results.

16. **Function Definition**
	```cpp
	int close(int a, int b) {
	```
	Define the `close` function, which compares two costs and returns the one closer to the target.

17. **Handle Zero Case**
	```cpp
	    if(a == 0) return b;
	```
	If `a` is zero, return `b` as the closest cost.

18. **Handle Zero Case**
	```cpp
	    if(b == 0) return a;
	```
	If `b` is zero, return `a` as the closest cost.

19. **Compare Costs**
	```cpp
	    if(abs(target - a) == abs(target - b))
	```
	If the absolute differences from the target are the same for both `a` and `b`, compare their values directly.

20. **Return Closest**
	```cpp
	        return a < b? a: b;
	```
	Return the smaller value between `a` and `b` if both are equidistant from the target.

21. **Return Closest**
	```cpp
	    return abs(target - a) < abs(target - b) ? a: b;
	```
	Return the value (`a` or `b`) that is closer to the target.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * 3^m)
- **Average Case:** O(n * 3^m)
- **Worst Case:** O(n * 3^m)

We need to evaluate 3^m combinations of toppings for each base, leading to a time complexity of O(n * 3^m).

### Space Complexity 💾
- **Best Case:** O(n * 3^m)
- **Worst Case:** O(n * 3^m)

The space complexity is O(n * 3^m) due to the recursive calls and storing the cost combinations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/closest-dessert-cost/description/)

---
{{< youtube Iom0aF6DOwU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
