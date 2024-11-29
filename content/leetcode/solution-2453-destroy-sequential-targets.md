
+++
authors = ["grid47"]
title = "Leetcode 2453: Destroy Sequential Targets"
date = "2024-03-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2453: Destroy Sequential Targets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "zhvKbUSFzQ8"
youtube_upload_date="2022-10-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/zhvKbUSFzQ8/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed array 'nums', where each element represents a target on a number line, and an integer 'space'. A machine is available that can destroy all targets that can be represented by the formula nums[i] + c * space, where c is a non-negative integer. You need to choose an element from 'nums' to seed the machine such that it destroys the maximum number of targets. Return the minimum value from 'nums' that can seed the machine to destroy the most targets.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array 'nums' of positive integers and an integer 'space'.
- **Example:** `nums = [4, 8, 10, 2, 3, 6], space = 3`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9
	- 1 <= space <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum value from 'nums' that can be used to seed the machine and destroy the maximum number of targets.
- **Example:** `Output: 2`
- **Constraints:**
	- Return the smallest seed value in case of a tie.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the minimum seed value from 'nums' that can destroy the maximum number of targets by utilizing the 'space' parameter.

- 1. For each target in 'nums', calculate the remainder when divided by 'space'.
- 2. Track the frequency of each remainder using a hash map.
- 3. Identify the remainder with the highest frequency, which corresponds to the seed value that can destroy the most targets.
- 4. In case of a tie (multiple remainders with the same frequency), return the smallest value that can seed the machine.
{{< dots >}}
### Problem Assumptions ✅
- The 'nums' array will always contain positive integers and there will be at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [4, 8, 10, 2, 3, 6], space = 3`  \
  **Explanation:** The remainder when each element in 'nums' is divided by 3 is: [4 % 3 = 1, 8 % 3 = 2, 10 % 3 = 1, 2 % 3 = 2, 3 % 3 = 0, 6 % 3 = 0]. The frequency of remainders is: {1: 2, 2: 2, 0: 2}. In this case, there is a tie. The smallest value with the highest frequency is 2. Thus, the answer is 2.

- **Input:** `nums = [5, 10, 15, 3, 8], space = 4`  \
  **Explanation:** The remainder when each element in 'nums' is divided by 4 is: [5 % 4 = 1, 10 % 4 = 2, 15 % 4 = 3, 3 % 4 = 3, 8 % 4 = 0]. The frequency of remainders is: {1: 1, 2: 1, 3: 2, 0: 1}. The value with the highest frequency is 3, so the answer is 3.

{{< dots >}}
## Approach 🚀
To solve this problem, we will use a hash map to store the frequency of remainders when elements in 'nums' are divided by 'space'. The goal is to find the most frequent remainder and select the smallest number associated with it.

### Initial Thoughts 💭
- We need to count how often each remainder occurs when we divide each number in 'nums' by 'space'.
- The key insight is that numbers with the same remainder when divided by 'space' can destroy similar targets, so we focus on maximizing the frequency of remainders.
{{< dots >}}
### Edge Cases 🌐
- If 'nums' is empty, return an error or handle the case as appropriate.
- The solution should handle up to 10^5 elements efficiently.
- If all elements in 'nums' have the same value, the solution should return that value.
- The solution should work efficiently with the maximum possible values for 'nums' and 'space'.
{{< dots >}}
## Code 💻
```cpp
int destroyTargets(vector<int>& nums, int space) {
    int ans = INT_MAX;
    unordered_map<int, int> mp;
    int mx = INT_MIN;
    for(int n: nums) {
        int r = n % space;
        mp[r]++;
        if(mx < mp[r]) mx = mp[r];
    }
    for(int n : nums)
    if(mx == mp[n %space]) ans = min(ans, n);
    return ans;
}
```

This function finds the smallest number from the `nums` list that has the highest frequency of remainders when divided by `space`. The number is selected based on the condition that its remainder occurs the most frequently in the list.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int destroyTargets(vector<int>& nums, int space) {
	```
	Defines the function `destroyTargets` that takes a vector of integers `nums` and an integer `space`, and returns the smallest integer from `nums` that satisfies the problem condition.

2. **Variable Initialization**
	```cpp
	    int ans = INT_MAX;
	```
	Initializes `ans` to the maximum possible value (INT_MAX) to later find the minimum value that satisfies the condition.

3. **Data Structure Initialization**
	```cpp
	    unordered_map<int, int> mp;
	```
	Initializes an unordered map `mp` to store the count of occurrences of each remainder when the elements of `nums` are divided by `space`.

4. **Variable Initialization**
	```cpp
	    int mx = INT_MIN;
	```
	Initializes `mx` to the smallest possible integer value (INT_MIN) to keep track of the maximum frequency of any remainder.

5. **First Loop (Counting Remainders)**
	```cpp
	    for(int n: nums) {
	```
	Starts a loop to iterate through each element `n` in the `nums` list.

6. **Remainder Calculation**
	```cpp
	        int r = n % space;
	```
	Calculates the remainder `r` when the element `n` is divided by `space`.

7. **Map Update**
	```cpp
	        mp[r]++;
	```
	Increments the count of the remainder `r` in the map `mp`.

8. **Frequency Update**
	```cpp
	        if(mx < mp[r]) mx = mp[r];
	```
	Updates the value of `mx` if the frequency of remainder `r` exceeds the current maximum frequency.

9. **Second Loop (Finding the Minimum)**
	```cpp
	    for(int n : nums)
	```
	Starts a second loop to iterate over the `nums` list again to find the smallest number that satisfies the condition.

10. **Condition Check**
	```cpp
	    if(mx == mp[n %space]) ans = min(ans, n);
	```
	If the frequency of the remainder of `n` matches the maximum frequency `mx`, updates `ans` to the smaller of its current value or `n`.

11. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the smallest number `ans` that satisfies the condition.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We only need to loop through the array once to calculate remainders and update the hash map.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We use additional space for the hash map to store remainders, which is proportional to the size of the input.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/destroy-sequential-targets/description/)

---
{{< youtube zhvKbUSFzQ8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
