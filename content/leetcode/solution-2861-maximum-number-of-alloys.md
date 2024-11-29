
+++
authors = ["grid47"]
title = "Leetcode 2861: Maximum Number of Alloys"
date = "2024-01-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2861: Maximum Number of Alloys in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "0lK_WWukTyA"
youtube_upload_date="2023-09-17"
youtube_thumbnail="https://i.ytimg.com/vi/0lK_WWukTyA/maxresdefault.jpg"
comments = true
+++



---
You are running a company that manufactures alloys using various types of metals. There are n different metal types available, and you have k machines that can be used to create alloys. Each machine requires a specific amount of each metal type to create an alloy. The i-th machine requires composition[i][j] units of metal type j. You have stock[i] units of metal type i, and purchasing one unit of metal type i costs cost[i] coins. Your task is to maximize the number of alloys you can produce while staying within a budget of budget coins. Each alloy must be made using the same machine.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of: an integer n (the number of different metals), an integer k (the number of machines), and an integer budget (the budget for buying additional metals). A 2D array composition where composition[i][j] gives the units of metal type j needed to produce an alloy using machine i. Arrays stock and cost where stock[i] is the current stock of metal type i and cost[i] is the cost of purchasing one additional unit of metal type i.
- **Example:** `n = 3, k = 2, budget = 15, composition = [[1,1,1],[1,1,10]], stock = [0,0,0], cost = [1,2,3]`
- **Constraints:**
	- 1 <= n, k <= 100
	- 0 <= budget <= 10^8
	- composition.length == k
	- composition[i].length == n
	- 1 <= composition[i][j] <= 100
	- stock.length == cost.length == n
	- 0 <= stock[i] <= 10^8
	- 1 <= cost[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of alloys that the company can create within the given budget.
- **Example:** `For input n = 3, k = 2, budget = 15, composition = [[1,1,1],[1,1,10]], stock = [0,0,0], cost = [1,2,3], the output is 2.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to maximize the number of alloys that can be created with a given budget, using any of the k machines.

- For each machine, calculate the number of alloys that can be produced while staying within the budget.
- Use binary search to determine the maximum number of alloys that can be made with the budget.
{{< dots >}}
### Problem Assumptions ✅
- It is assumed that each machine can be used to produce alloys independently, and the number of alloys produced is limited by the available budget and stock.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 3, k = 2, budget = 15, composition = [[1,1,1],[1,1,10]], stock = [0,0,0], cost = [1,2,3]`  \
  **Explanation:** The total cost for producing 2 alloys using the first machine is within the budget, while any higher number of alloys would exceed the budget.

{{< dots >}}
## Approach 🚀
A binary search approach is used to determine the maximum number of alloys that can be created under the given budget.

### Initial Thoughts 💭
- The problem is about maximizing alloys under a given budget, which suggests a binary search solution to check the maximum number of alloys that can be created.
- We can try each machine and check how many alloys can be created based on the current stock and cost of metals.
{{< dots >}}
### Edge Cases 🌐
- If n or k is 0, return 0 as no alloys can be made.
- Ensure that the solution handles the upper limits of the input constraints efficiently.
- If the stock is sufficient to create alloys without any additional purchase, the cost is 0.
- The binary search approach ensures that the solution is efficient even for large inputs.
{{< dots >}}
## Code 💻
```cpp
bool func(ll mid, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost)
{
    ll minCost = INT_MAX;
    for (int i = 0; i < composition.size(); ++i)
    {
        ll currCost = 0;
        for (int j = 0; j < composition[i].size(); ++j)
        {
            ll curr = mid * composition[i][j];
            if (stock[j] >= curr)
                continue;
            else
            {
                ll extra = (curr - stock[j]) * cost[j];
                currCost += extra;
            }
        }
        minCost = min(currCost, minCost);
    }
    return (minCost <= budget);
}
int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
    ll low = 0, high = 1e9, ans = 0;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (func(mid, budget, composition, stock, cost))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
```

This code defines a solution to determine the maximum number of alloys that can be produced given a budget and constraints on composition, stock, and cost.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool func(ll mid, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost)
	```
	This function checks whether a given number of alloys (mid) can be produced within the provided budget, taking into account the stock and cost for each material.

2. **Variable Initialization**
	```cpp
	    ll minCost = INT_MAX;
	```
	Initialize the minimum cost to the maximum possible value to keep track of the lowest cost encountered.

3. **Loop**
	```cpp
	    for (int i = 0; i < composition.size(); ++i)
	```
	Loop over all the alloy compositions to calculate the cost of producing 'mid' number of alloys.

4. **Variable Initialization**
	```cpp
	        ll currCost = 0;
	```
	Initialize the current cost for producing the alloys to zero.

5. **Inner Loop**
	```cpp
	        for (int j = 0; j < composition[i].size(); ++j)
	```
	Loop over each material in the current composition.

6. **Cost Calculation**
	```cpp
	            ll curr = mid * composition[i][j];
	```
	Calculate the amount of material needed for the current alloy composition.

7. **Condition Check**
	```cpp
	            if (stock[j] >= curr)
	```
	Check if there is enough stock of the material to produce 'mid' number of alloys.

8. **Continue**
	```cpp
	                continue;
	```
	If there is enough stock, skip to the next material.

9. **Else Block**
	```cpp
	            else
	```
	If there is not enough stock, calculate the extra cost needed.

10. **Cost Calculation**
	```cpp
	            {
	```
	Opening block for calculating the extra cost required.

11. **Cost Calculation**
	```cpp
	                ll extra = (curr - stock[j]) * cost[j];
	```
	Calculate the additional cost required to buy the missing materials.

12. **Cost Accumulation**
	```cpp
	                currCost += extra;
	```
	Add the extra cost for the material to the current total cost.

13. **Cost Comparison**
	```cpp
	        minCost = min(currCost, minCost);
	```
	Update the minimum cost with the lower value between the current cost and the previously stored minimum cost.

14. **Return**
	```cpp
	    return (minCost <= budget);
	```
	Return true if the minimum cost is within the provided budget, otherwise return false.

15. **Function Definition**
	```cpp
	int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
	```
	This function finds the maximum number of alloys that can be produced within the given budget using binary search.

16. **Variable Initialization**
	```cpp
	    ll low = 0, high = 1e9, ans = 0;
	```
	Initialize the binary search range with 'low' as 0 and 'high' as a large number (1e9).

17. **While Loop**
	```cpp
	    while (low <= high)
	```
	Binary search loop to find the maximum number of alloys.

18. **Mid Calculation**
	```cpp
	        ll mid = low + (high - low) / 2;
	```
	Calculate the midpoint of the current binary search range.

19. **Condition Check**
	```cpp
	        if (func(mid, budget, composition, stock, cost))
	```
	Check if it's possible to produce 'mid' number of alloys within the budget using the helper function.

20. **Update Result**
	```cpp
	            ans = mid;
	```
	Update the result with the current value of 'mid' which is a valid solution.

21. **Update Low**
	```cpp
	            low = mid + 1;
	```
	Move the lower bound up to 'mid + 1' to search for a larger valid solution.

22. **Else Block**
	```cpp
	        else
	```
	If 'mid' number of alloys cannot be produced, narrow the search range.

23. **Update High**
	```cpp
	            high = mid - 1;
	```
	Move the upper bound down to 'mid - 1' to search for a smaller valid solution.

24. **Return**
	```cpp
	    return ans;
	```
	Return the result which is the maximum number of alloys that can be produced within the budget.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k log(max_possible_alloys))
- **Average Case:** O(k log(max_possible_alloys))
- **Worst Case:** O(k log(max_possible_alloys))

The time complexity depends on the binary search and the number of machines k.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(k)

The space complexity is O(k) due to the array used for composition, stock, and cost.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-alloys/description/)

---
{{< youtube 0lK_WWukTyA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
