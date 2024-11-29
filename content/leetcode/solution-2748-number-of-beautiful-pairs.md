
+++
authors = ["grid47"]
title = "Leetcode 2748: Number of Beautiful Pairs"
date = "2024-02-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2748: Number of Beautiful Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "mjceDBNh7vg"
youtube_upload_date="2023-07-01"
youtube_thumbnail="https://i.ytimg.com/vi/mjceDBNh7vg/maxresdefault.jpg"
comments = true
+++



---
You are given an array 'nums' containing integers. A pair of indices 'i, j' is considered beautiful if the first digit of nums[i] and the last digit of nums[j] are coprime. Two numbers are coprime if their greatest common divisor (GCD) is 1, i.e., 'gcd(x, y) == 1'. Your task is to find the total number of beautiful pairs in nums.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You will be given an array of integers 'nums'. Each element in 'nums' is an integer with 1 to 4 digits.
- **Example:** `nums = [4, 15, 33, 17]`
- **Constraints:**
	- 2 <= nums.length <= 100
	- 1 <= nums[i] <= 9999
	- nums[i] % 10 != 0

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of beautiful pairs in the given array.
- **Example:** `For nums = [4, 15, 33, 17], the output is 6.`
- **Constraints:**
	- The output is an integer representing the number of beautiful pairs.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify all pairs i, j such that the first digit of nums[i] and the last digit of nums[j] are coprime.

- Iterate over all possible pairs of indices i, j where i < j.
- Extract the first digit of nums[i] and the last digit of nums[j].
- Check if the GCD of the first digit and last digit is 1 using the 'gcd' function.
- Count the pairs where GCD is 1.
{{< dots >}}
### Problem Assumptions ✅
- The input will always contain valid integers in the range 1 to 9999.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [4, 15, 33, 17]`  \
  **Explanation:** You need to check every possible pair (i, j) where i < j and verify if the first digit of nums[i] and the last digit of nums[j] are coprime. The GCD of these digits should be 1.

{{< dots >}}
## Approach 🚀
We use a brute force approach to check every possible pair of indices in the array. For each pair, we extract the first digit of the first number and the last digit of the second number, and check if their GCD is 1.

### Initial Thoughts 💭
- The task requires checking pairs of digits, which is computationally feasible with a brute-force approach.
- Since the array length is limited to 100, checking all pairs is manageable.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least 2 elements, so this case won't occur.
- If nums has 100 elements, the brute-force approach will check at most 4950 pairs, which is feasible within the given constraints.
- The last digit of any number in nums will never be 0, ensuring valid inputs for checking GCD.
- Ensure that nums[i] does not end with a zero.
{{< dots >}}
## Code 💻
```cpp
int countBeautifulPairs(vector<int>& nums) {
int cnt[10] = {}, res = 0;
for(int i = 0; i < nums.size(); ++i) {
    for (int n = 1; n < 10; ++n)
        if (gcd(n, nums[i] % 10) == 1)
            res += cnt[n];
    while (nums[i] >= 10)
        nums[i] /= 10;
    ++cnt[nums[i]];
}
return res;
}
```

This function counts the number of pairs of numbers in `nums` such that the greatest common divisor (gcd) of the last digit of the first number and any number between 1 and 9 is 1. The function maintains a count of occurrences of each last digit to optimize the process.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countBeautifulPairs(vector<int>& nums) {
	```
	Defines the function `countBeautifulPairs`, which takes a vector `nums` containing integers and returns an integer representing the count of 'beautiful' pairs.

2. **Variable Initialization**
	```cpp
	int cnt[10] = {}, res = 0;
	```
	Initializes an array `cnt` of size 10 to count occurrences of digits (last digits of numbers) and a variable `res` to store the result (the number of beautiful pairs).

3. **Outer Loop**
	```cpp
	for(int i = 0; i < nums.size(); ++i) {
	```
	Iterates over each element in the `nums` array to process each number.

4. **Inner Loop**
	```cpp
	    for (int n = 1; n < 10; ++n)
	```
	For each number in `nums`, this loop iterates through numbers `n` from 1 to 9 and checks the greatest common divisor (gcd) with the last digit of the current number.

5. **GCD Condition**
	```cpp
	        if (gcd(n, nums[i] % 10) == 1)
	```
	Checks if the gcd of `n` and the last digit of `nums[i]` is 1, meaning that the pair (last digit of `nums[i]`, `n`) is 'beautiful.'

6. **Increment Result**
	```cpp
	            res += cnt[n];
	```
	If the gcd condition is satisfied, the result `res` is incremented by the count of previous numbers in `nums` whose last digit is `n`.

7. **While Loop for Last Digit Extraction**
	```cpp
	    while (nums[i] >= 10)
	```
	This while loop reduces the current number `nums[i]` by removing its last digit repeatedly until it becomes a single-digit number.

8. **Last Digit Removal**
	```cpp
	        nums[i] /= 10;
	```
	Divides `nums[i]` by 10 to remove its last digit.

9. **Update Count**
	```cpp
	    ++cnt[nums[i]];
	```
	Increments the count of occurrences for the last digit of the current number `nums[i]` in the `cnt` array.

10. **Return Statement**
	```cpp
	return res;
	```
	Returns the final result `res`, which represents the number of beautiful pairs found in the `nums` array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2) where n is the length of nums.
- **Average Case:** O(n^2).
- **Worst Case:** O(n^2).

We check each pair of indices (i, j), which leads to O(n^2) time complexity.

### Space Complexity 💾
- **Best Case:** O(1).
- **Worst Case:** O(1).

We only use a few variables to store intermediate results, so the space complexity is constant.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-beautiful-pairs/description/)

---
{{< youtube mjceDBNh7vg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
