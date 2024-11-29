
+++
authors = ["grid47"]
title = "Leetcode 1387: Sort Integers by The Power Value"
date = "2024-06-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1387: Sort Integers by The Power Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Memoization","Sorting"]
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
The task is to find the kth integer in the range [lo, hi] sorted by the number of steps required to reach 1 using the Collatz conjecture rules. The power of a number is the number of steps needed to reach 1, following the rules: if the number is even, divide it by 2, and if it's odd, multiply it by 3 and add 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given three integers lo, hi, and k. The integers lo and hi represent the range of numbers to check, and k is the position of the number to return after sorting by power value.
- **Example:** `For lo = 10, hi = 15, and k = 2, the second number in the sorted list of powers is 11.`
- **Constraints:**
	- 1 <= lo <= hi <= 1000
	- 1 <= k <= hi - lo + 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the kth integer from the sorted list of integers based on their power values.
- **Example:** `For lo = 10, hi = 15, and k = 2, the output is 11.`
- **Constraints:**
	- The result will always be a valid integer within the specified range.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the number of steps (power) for each integer in the range and return the kth integer after sorting them by their power values.

- 1. Compute the power of each number in the range [lo, hi].
- 2. Sort the numbers based on their power values. If two numbers have the same power, sort them by their value.
- 3. Return the kth number from the sorted list.
{{< dots >}}
### Problem Assumptions ✅
- All integers in the range [lo, hi] will eventually transform into 1.
- The power values of all integers will fit within a 32-bit signed integer.
{{< dots >}}
## Examples 🧩
- **Input:** `For lo = 5, hi = 9, k = 3, the sorted list of powers is [8, 6, 5, 7, 9], so the third number is 5.`  \
  **Explanation:** The power of each integer in the range [5, 9] is calculated. The numbers are then sorted by their power values, and the kth number is returned.

{{< dots >}}
## Approach 🚀
To solve this problem, we will compute the power for each integer in the range [lo, hi], sort them by their power values, and return the kth element.

### Initial Thoughts 💭
- We need to calculate the Collatz steps for each number efficiently.
- Memoization can be used to store intermediate results to avoid redundant calculations.
- A recursive approach with memoization can be applied to compute the power values for each integer.
{{< dots >}}
### Edge Cases 🌐
- The input range [lo, hi] will always have at least one integer.
- The function needs to efficiently compute the power for numbers in the range up to 1000.
- Edge cases where lo and hi are the same value should be handled properly.
- The function must work efficiently within the provided input constraints.
{{< dots >}}
## Code 💻
```cpp
map<int, int> memo;

int dig(int num) {
    if(num == 1) return 0;
    if(memo.count(num)) return memo[num];
    if(num % 2 == 0)
        return memo[num] = dig(num / 2) + 1;
    return memo[num] = dig(3 * num + 1) + 1;        
}

int getKth(int lo, int hi, int k) {
    vector<pair<int,int>> ans;
    for(int i = lo; i <= hi; i++) {
        int tmp = dig(i);
        ans.push_back({tmp, i});
    }
    sort(ans.begin(), ans.end());
    return ans[k - 1].second;
}
```

This solution finds the kth number between a range [lo, hi] based on the number of steps it takes to reduce the number to 1 following the 3x + 1 sequence. It uses memoization to optimize recursive calls.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Data Structures**
	```cpp
	map<int, int> memo;
	```
	Declare a memoization map `memo` to store previously computed results for the 'dig' function, optimizing repeated calculations.

2. **Function Definition**
	```cpp
	int dig(int num) {
	```
	Define the recursive function `dig` that calculates the number of steps to reduce a number to 1 using the 3x + 1 problem's rules.

3. **Base Case**
	```cpp
	    if(num == 1) return 0;
	```
	If the number is 1, return 0 since no steps are needed.

4. **Memoization**
	```cpp
	    if(memo.count(num)) return memo[num];
	```
	Check if the result for the current number has been computed before and return it from the memoization map.

5. **Condition**
	```cpp
	    if(num % 2 == 0)
	```
	If the number is even, apply the rule `num / 2`.

6. **Recursion**
	```cpp
	        return memo[num] = dig(num / 2) + 1;
	```
	Recursively call `dig(num / 2)` and store the result in `memo[num]`, adding 1 to account for the step.

7. **Recursion**
	```cpp
	    return memo[num] = dig(3 * num + 1) + 1;        
	```
	If the number is odd, apply the rule `3 * num + 1`, recursively call `dig(3 * num + 1)`, and store the result in `memo[num]`.

8. **Function Definition**
	```cpp
	int getKth(int lo, int hi, int k) {
	```
	Define the function `getKth` to find the kth number in the range [lo, hi] based on the number of steps from `dig`.

9. **Data Structures**
	```cpp
	    vector<pair<int,int>> ans;
	```
	Declare a vector `ans` of pairs to store the computed step counts and the corresponding numbers.

10. **Loop**
	```cpp
	    for(int i = lo; i <= hi; i++) {
	```
	Loop through all numbers in the range [lo, hi].

11. **Function Call**
	```cpp
	        int tmp = dig(i);
	```
	Call the `dig` function to get the number of steps required to reduce the current number `i` to 1.

12. **Data Structures**
	```cpp
	        ans.push_back({tmp, i});
	```
	Store the result (step count `tmp` and number `i`) as a pair in the vector `ans`.

13. **Sorting**
	```cpp
	    sort(ans.begin(), ans.end());
	```
	Sort the vector `ans` based on the step count in ascending order, ensuring that the number with the fewest steps comes first.

14. **Return Statement**
	```cpp
	    return ans[k - 1].second;
	```
	Return the second element (the number) of the kth pair in the sorted vector `ans`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n), where n is the number of integers in the range [lo, hi].
- **Average Case:** O(n log n), considering sorting of the numbers based on power values.
- **Worst Case:** O(n log n), where n is the number of integers in the range and log n is the complexity of sorting.

The primary time complexity is due to sorting the numbers by their power values.

### Space Complexity 💾
- **Best Case:** O(n), for storing the memoized results and the list of integers.
- **Worst Case:** O(n), where n is the number of integers in the range [lo, hi], for storing the power values and the sorted list.

The space complexity is determined by the storage of the memoized results and the list of integers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sort-integers-by-the-power-value/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
