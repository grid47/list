
+++
authors = ["grid47"]
title = "Leetcode 2952: Minimum Number of Coins to be Added"
date = "2024-01-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2952: Minimum Number of Coins to be Added in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "txrhznINlhM"
youtube_upload_date="2023-12-03"
youtube_thumbnail="https://i.ytimg.com/vi/txrhznINlhM/maxresdefault.jpg"
comments = true
+++



---
You are given a list of coin denominations and a target value. Your task is to determine the minimum number of new coin denominations you need to add to the list, so that every integer value from 1 to the target can be formed as a sum of some subset of the coins. A coin denomination can be added if it helps form values that cannot be formed using the existing coins.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A list of integers `coins` representing the denominations of the available coins and an integer `target` representing the target value.
- **Example:** `coins = [1, 4, 10], target = 19`
- **Constraints:**
	- 1 <= target <= 100000
	- 1 <= coins.length <= 100000
	- 1 <= coins[i] <= target

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of coins needed to be added to the list so that every integer value from 1 to the target can be formed.
- **Example:** `2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the minimum number of coin denominations to add so that all integers from 1 to the target can be formed.

- Sort the existing coins.
- Start with a sum of 0 and try to form all numbers up to the target.
- If a coin can contribute to the current sum, add it to the sum.
- If the coin cannot contribute, add the next required coin (current_sum + 1).
- Repeat this until the sum reaches the target.
{{< dots >}}
### Problem Assumptions ✅
- The list of coins is initially sorted.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: coins = [1, 4, 10], target = 19`  \
  **Explanation:** We need to add coins with values 2 and 8 to make it possible to form all integers from 1 to 19.

{{< dots >}}
## Approach 🚀
The approach involves iterating over the coins and determining which coin values need to be added in order to ensure that all numbers from 1 to the target can be formed.

### Initial Thoughts 💭
- The key is to always check if the next coin in the list can extend the reachable sum.
- Start by sorting the coins and track the largest sum that can be formed. If the next coin is not reachable, add the next smallest coin that would bridge the gap.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as there will always be coins provided.
- Ensure that the solution is efficient even when there are up to 100,000 coins and the target is 100,000.
- If the coins array already covers all sums up to the target, no new coins are needed.
- The input list will have at least 1 coin.
{{< dots >}}
## Code 💻
```cpp
int minimumAddedCoins(vector<int>& coins, int target) {
    sort(coins.begin(), coins.end());

    int current_max = 0;
    int additions = 0;
    int index = 0;

    while (current_max < target) {
        if (index < coins.size() && coins[index] <= current_max + 1) {
            current_max += coins[index];
            index++;
        } else {
            current_max += current_max + 1;
            additions++;
        }
    }

    return additions;
}
```

This function calculates the minimum number of additional coins needed to reach the target value. It sorts the coins and iterates, adding coins if possible, or otherwise adding the smallest missing value.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimumAddedCoins(vector<int>& coins, int target) {
	```
	Defines the function 'minimumAddedCoins' that takes a vector of coin denominations 'coins' and a target value 'target', and returns the minimum number of additional coins required.

2. **Sort Coins**
	```cpp
	    sort(coins.begin(), coins.end());
	```
	Sorts the coins in ascending order to facilitate finding the smallest possible values that can be used to reach the target.

3. **Initialize Current Max**
	```cpp
	    int current_max = 0;
	```
	Initializes 'current_max' to zero, which tracks the largest value that can be formed with the available coins.

4. **Initialize Additions**
	```cpp
	    int additions = 0;
	```
	Initializes 'additions' to zero, which will count how many times we add the smallest missing coin.

5. **Initialize Index**
	```cpp
	    int index = 0;
	```
	Initializes 'index' to zero, used to iterate through the sorted coins.

6. **While Loop**
	```cpp
	    while (current_max < target) {
	```
	Starts a loop that continues until the 'current_max' reaches or exceeds the target.

7. **Check Coin Feasibility**
	```cpp
	        if (index < coins.size() && coins[index] <= current_max + 1) {
	```
	Checks if the current coin can be used to form the next value. If the coin is less than or equal to 'current_max + 1', it can be used.

8. **Update Current Max with Coin**
	```cpp
	            current_max += coins[index];
	```
	If the coin can be used, it is added to 'current_max', updating the largest value that can be formed.

9. **Increment Index**
	```cpp
	            index++;
	```
	Increments the index to check the next coin in the sorted array.

10. **Else Case - Add Missing Value**
	```cpp
	        } else {
	```
	If the current coin cannot be used, we add the smallest missing value (current_max + 1).

11. **Add Missing Value to Current Max**
	```cpp
	            current_max += current_max + 1;
	```
	Adds the smallest missing value to 'current_max' to ensure we progress toward the target.

12. **Increment Additions**
	```cpp
	            additions++;
	```
	Increments the 'additions' counter since we added the smallest missing value.

13. **Return Result**
	```cpp
	    return additions;
	```
	Returns the total number of coin additions made to reach the target.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The best, average, and worst case time complexities are all O(n log n) due to sorting the list of coins.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the coins list. In the best case, no additional space is required.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-coins-to-be-added/description/)

---
{{< youtube txrhznINlhM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
