
+++
authors = ["grid47"]
title = "Leetcode 198: House Robber"
date = "2024-10-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 198: House Robber in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/198.webp"
youtube = "UVNgW5nSoiU"
youtube_upload_date="2023-06-20"
youtube_thumbnail="https://i.ytimg.com/vi/UVNgW5nSoiU/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/198.webp" 
    alt="A series of houses softly glowing, with the optimal path for robbing illuminating."
    caption="Solution to LeetCode 198: House Robber Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are a burglar planning to rob houses along a street. Each house has an amount of money, but robbing two adjacent houses will trigger an alarm. Given an integer array `nums` representing the money stashed in each house, find the maximum amount you can rob without triggering the alarm.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of integers where each integer represents the amount of money in each house.
- **Example:** `nums = [5, 3, 4, 11]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 0 <= nums[i] <= 400

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the maximum amount of money that can be robbed without triggering the alarm by robbing adjacent houses.
- **Example:** `Output = 16`
- **Constraints:**
	- The output is a single integer representing the maximum amount of money that can be robbed.

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the total amount of money robbed while ensuring no two adjacent houses are robbed.

- Step 1: Use dynamic programming to keep track of the maximum money robbed up to each house.
- Step 2: For each house, calculate the maximum amount by either skipping the house or robbing it and adding its value to the previous non-adjacent house's value.
- Step 3: Return the maximum value at the last house.
{{< dots >}}
### Problem Assumptions ✅
- The input array is non-empty.
- The values in the input array are valid integers within the given range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [5, 3, 4, 11]`  \
  **Explanation:** The maximum money that can be robbed is 16 by robbing house 1 (5) and house 4 (11). The adjacent houses can't both be robbed, so we skip house 2 and 3.

- **Input:** `Input: nums = [3, 2, 5, 10, 7]`  \
  **Explanation:** The optimal choice is to rob house 1 (3), house 3 (5), and house 5 (7), yielding a total of 15.

{{< dots >}}
## Approach 🚀
We can solve this problem using dynamic programming. The idea is to iterate through the houses and keep track of the maximum money we can rob up to each house without robbing two adjacent houses.

### Initial Thoughts 💭
- This is a typical dynamic programming problem where we need to make decisions based on previous results.
- We can define a dp array where dp[i] represents the maximum money we can rob up to the i-th house.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs, as the problem guarantees at least one house.
- The problem's constraints are small enough (up to 100 houses) that large inputs are not a concern.
- If the array contains only one house, we simply rob that house.
- The input will always have at least one house.
{{< dots >}}
## Code 💻
```cpp
int rob(vector<int>& a) {
    int n = a.size();
    if(n == 1) return a[0];
    vector<int> dp(n,0);
    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);
    for(int i = 2; i < n; i++)
        dp[i] = max(dp[i-2]+a[i], dp[i-1]);
    return dp[n-1];
}
```

This function implements the 'House Robber' problem using dynamic programming. It determines the maximum amount of money that can be robbed from a series of houses, where adjacent houses cannot be robbed on the same night.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int rob(vector<int>& a) {
	```
	Define the function 'rob' which accepts a vector of integers 'a' representing the amount of money in each house, and returns the maximum amount that can be robbed.

2. **Array Size**
	```cpp
	    int n = a.size();
	```
	Store the size of the input vector 'a' in the variable 'n', which represents the number of houses.

3. **Edge Case Check**
	```cpp
	    if(n == 1) return a[0];
	```
	Check if there is only one house. If so, return the amount in that single house as there are no other houses to consider.

4. **DP Array Initialization**
	```cpp
	    vector<int> dp(n,0);
	```
	Initialize a dynamic programming (DP) array 'dp' of size 'n' with all elements set to zero. This array will store the maximum amount that can be robbed up to each house.

5. **Base Case Initialization**
	```cpp
	    dp[0] = a[0];
	```
	Set the base case: the maximum amount that can be robbed from just the first house is the amount in the first house itself.

6. **Base Case Comparison**
	```cpp
	    dp[1] = max(a[0], a[1]);
	```
	For the second house, the maximum amount that can be robbed is the greater of the first and second house values.

7. **Loop Through Houses**
	```cpp
	    for(int i = 2; i < n; i++)
	```
	Start a loop from the third house onward to compute the maximum amount that can be robbed by either including or excluding the current house.

8. **DP Update**
	```cpp
	        dp[i] = max(dp[i-2]+a[i], dp[i-1]);
	```
	Update the DP array by choosing the maximum between robbing the current house (dp[i-2] + a[i]) or skipping the current house (dp[i-1]).

9. **Return Result**
	```cpp
	    return dp[n-1];
	```
	Return the maximum amount that can be robbed from all houses, which is stored in the last element of the DP array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the input array `nums`. We process each house once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the dynamic programming array used to store the maximum amounts for each house.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/house-robber/description/)

---
{{< youtube UVNgW5nSoiU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
