
+++
authors = ["grid47"]
title = "Leetcode 1814: Count Nice Pairs in an Array"
date = "2024-05-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1814: Count Nice Pairs in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "qUNprFiUKyw"
youtube_upload_date="2021-04-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/qUNprFiUKyw/maxresdefault.webp"
comments = true
+++



---
You are given an array of non-negative integers. A pair of indices (i, j) is nice if nums[i] + rev(nums[j]) equals nums[j] + rev(nums[i]). Return the number of nice pairs modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array nums with non-negative integers.
- **Example:** `nums = [12, 21, 34, 43]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of nice pairs of indices modulo 10^9 + 7.
- **Example:** `Output: 2`
- **Constraints:**
	- The output should be an integer, modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** Count the number of nice pairs (i, j) in the array that satisfy the condition nums[i] + rev(nums[j]) = nums[j] + rev(nums[i]).

- For each number in the array, calculate the difference between nums[i] and rev(nums[i]).
- Use a hash map to count how many times each difference occurs.
- For each difference count greater than 1, calculate how many pairs of indices can be formed.
- Return the total number of nice pairs modulo 10^9 + 7.
{{< dots >}}
### Problem Assumptions ✅
- All numbers are non-negative integers.
- The solution must be efficient due to the large input size.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [12, 21, 34, 43]`  \
  **Explanation:** In this case, the pairs (0,1) and (2,3) are nice because the sum of each pair and their reversed numbers are equal.

- **Input:** `nums = [5, 100, 100, 500]`  \
  **Explanation:** The only nice pair is (1,2), where nums[1] + rev(nums[2]) = nums[2] + rev(nums[1]).

{{< dots >}}
## Approach 🚀
The solution is based on calculating the difference between each number and its reverse, and counting how often each difference appears. This allows us to find how many pairs satisfy the condition.

### Initial Thoughts 💭
- The problem involves calculating the reverse of each number and comparing differences.
- A brute force solution would be too slow, so an optimized approach using hash maps is necessary.
- By using a hash map to count occurrences of each difference, we can efficiently calculate the number of pairs.
{{< dots >}}
### Edge Cases 🌐
- The array will not be empty based on the problem constraints.
- The algorithm should efficiently handle inputs where nums.length is up to 10^5.
- When nums[i] is 0, rev(0) is also 0.
- The input numbers are always non-negative and between 0 and 10^9.
{{< dots >}}
## Code 💻
```cpp
int countNicePairs(vector<int>& nums) {
    
    unordered_map<int, long> mp;
    for(auto &n: nums) mp[n - rev(n)]++;
    
    int mod = 1000000007;
    long count = 0;
    
    for(auto &it: mp) 
    count = (count + (it.second * (it.second - 1))/ 2) % mod;
    
    return count;
}

int rev(int x) {
    int revNum = 0;
    while(x) revNum = revNum * 10 + (x%10), x /= 10;
    return revNum;
}
```

The function `countNicePairs` calculates the number of nice pairs in an array of integers. A nice pair is defined as a pair of indices (i, j) such that the value of the element at index i minus the reverse of the value of the element at index i is equal to the value at index j minus the reverse of the value at index j. This is achieved using a hash map to store the frequency of these differences. The function `rev` is used to reverse the digits of a number.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countNicePairs(vector<int>& nums) {
	```
	This defines the function `countNicePairs` which takes a vector of integers `nums` as input and returns the count of nice pairs.

2. **Map Initialization**
	```cpp
	    unordered_map<int, long> mp;
	```
	An unordered map `mp` is initialized to store the frequency of the differences between a number and its reverse.

3. **Frequency Calculation**
	```cpp
	    for(auto &n: nums) mp[n - rev(n)]++;
	```
	This loop iterates over each number `n` in the `nums` vector, calculates the difference between `n` and its reversed value, and increments the corresponding frequency in the map `mp`.

4. **Modulo Definition**
	```cpp
	    int mod = 1000000007;
	```
	A variable `mod` is defined to store the value of `1000000007`, which is commonly used to avoid overflow in large number calculations.

5. **Count Initialization**
	```cpp
	    long count = 0;
	```
	The variable `count` is initialized to 0. This will store the total number of nice pairs.

6. **Count Calculation Loop**
	```cpp
	    for(auto &it: mp) 
	```
	This loop iterates over each entry in the unordered map `mp`, where `it.second` represents the frequency of a particular difference.

7. **Combination Formula**
	```cpp
	    count = (count + (it.second * (it.second - 1))/ 2) % mod;
	```
	This line calculates the number of pairs for the current frequency `it.second` using the combination formula `n * (n - 1) / 2`, and adds it to the total `count`, taking the modulo `mod` to avoid overflow.

8. **Return Statement**
	```cpp
	    return count;
	```
	This returns the total number of nice pairs found.

9. **Reversal Function Definition**
	```cpp
	int rev(int x) {
	```
	This defines the helper function `rev` which takes an integer `x` as input and returns its reverse.

10. **Reversal Initialization**
	```cpp
	    int revNum = 0;
	```
	A variable `revNum` is initialized to store the reversed number.

11. **Reversal Logic**
	```cpp
	    while(x) revNum = revNum * 10 + (x%10), x /= 10;
	```
	This loop reverses the digits of the number `x` by extracting the last digit (x % 10) and adding it to `revNum`, then dividing `x` by 10.

12. **Return Reversed Number**
	```cpp
	    return revNum;
	```
	This returns the reversed number `revNum`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of elements in the array, as we iterate over the array and perform constant-time operations for each element.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), where n is the number of elements in the array, as we store the differences in a hash map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-nice-pairs-in-an-array/description/)

---
{{< youtube qUNprFiUKyw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
