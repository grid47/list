
+++
authors = ["grid47"]
title = "Leetcode 1798: Maximum Number of Consecutive Values You Can Make"
date = "2024-05-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1798: Maximum Number of Consecutive Values You Can Make in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3ONSGo28_Z0"
youtube_upload_date="2021-03-20"
youtube_thumbnail="https://i.ytimg.com/vi/3ONSGo28_Z0/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array 'coins', where each element represents the value of a coin you own. You can use these coins to create sums of values starting from 0. Your task is to find the maximum number of consecutive integer values starting from 0 that you can make with your coins.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array 'coins' where each coin is represented by an integer value. You must calculate the maximum consecutive sum of values that can be made using these coins.
- **Example:** `coins = [2, 3]`
- **Constraints:**
	- 1 <= n <= 4 * 10^4
	- 1 <= coins[i] <= 4 * 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of consecutive integer values starting from 0 that you can make using the given coins.
- **Example:** `For coins = [2, 3], the output will be 4.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the maximum consecutive integers starting from 0 that can be made by summing various combinations of coin values.

- 1. Sort the array of coins.
- 2. Initialize a variable 'res' to 1, representing the initial sum 0.
- 3. Loop through the sorted array of coins. For each coin, check if it can extend the consecutive sums. If so, add it to 'res'.
{{< dots >}}
### Problem Assumptions ✅
- You can have multiple coins of the same value.
{{< dots >}}
## Examples 🧩
- **Input:** `coins = [2, 3]`  \
  **Explanation:** The coins are sorted to [2, 3]. The values that can be made starting from 0 are 0, 2, 3, and 5, giving us 4 consecutive sums.

{{< dots >}}
## Approach 🚀
To solve the problem, we first sort the coins array and use a greedy approach to calculate the maximum number of consecutive sums.

### Initial Thoughts 💭
- Sorting the coins is essential for ensuring that we can always extend the range of consecutive sums.
- The maximum consecutive sums will depend on whether the current coin value can fill in the gaps between the sums we can already form.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, return 0.
- For large inputs, ensure the algorithm runs efficiently with O(n log n) time complexity due to sorting.
- If the coins have values that are too large to consecutively extend the sums, handle these cases appropriately.
- Ensure that the solution works within the given constraints (up to 40,000 coins).
{{< dots >}}
## Code 💻
```cpp

int getMaximumConsecutive(vector<int>& coins) {
    sort(coins.begin(), coins.end());

    int res = 1;
    for(int a: coins) {
        if(a > res) break;
        // with all the coins I have I can 
        // create upto res - 1,
        // with this a, I can make upto res + a - 1
        // so next target is res += a
        res += a;
    }

    return res;
}

```

The function `getMaximumConsecutive` calculates the maximum amount of consecutive integers that can be made from a given list of coin denominations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int getMaximumConsecutive(vector<int>& coins) {
	```
	This is the function definition. The input is a vector of integers representing the coin denominations, and the output is an integer representing the maximum number of consecutive values that can be formed.

2. **Sorting**
	```cpp
	    sort(coins.begin(), coins.end());
	```
	Sort the coins array to ensure that smaller coin denominations are processed first, which helps in forming consecutive values more efficiently.

3. **Variable Initialization**
	```cpp
	    int res = 1;
	```
	Initialize a variable `res` to 1, which represents the current target value that can be formed with the available coins.

4. **Iteration**
	```cpp
	    for(int a: coins) {
	```
	Start a loop to iterate over each coin denomination in the sorted list.

5. **Condition Check**
	```cpp
	        if(a > res) break;
	```
	If the current coin denomination is greater than the target `res`, it means we can't form the consecutive value `res`, so we exit the loop.

6. **Variable Update**
	```cpp
	        res += a;
	```
	Update the `res` value by adding the current coin denomination `a`, extending the range of consecutive values we can form.

7. **Return Statement**
	```cpp
	    return res;
	```
	Return the final value of `res`, which represents the maximum number of consecutive integers that can be formed using the given coins.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the sorting step.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for storing the sorted array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/description/)

---
{{< youtube 3ONSGo28_Z0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
