
+++
authors = ["grid47"]
title = "Leetcode 2341: Maximum Number of Pairs in Array"
date = "2024-03-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2341: Maximum Number of Pairs in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "9KeeDZ6tcy4"
youtube_upload_date="2022-07-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/9KeeDZ6tcy4/maxresdefault.webp"
comments = true
+++



---
You are given an integer array `nums`. In one operation, you can choose two integers in the array that are the same and remove both. The operation is repeated as many times as possible. Return an array where the first element is the number of pairs formed, and the second element is the number of leftover integers.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` of length `n`.
- **Example:** `nums = [4, 2, 7, 4, 2, 7, 7]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 0 <= nums[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array where the first element is the number of pairs formed, and the second element is the number of leftover integers.
- **Example:** `[3, 1]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count the number of pairs and leftover elements in the input array.

- Use a frequency count to track the occurrence of each integer in the array.
- For each integer, calculate how many pairs can be formed by dividing the frequency by 2.
- Count the leftover integers, which are the remainder after pairing.
{{< dots >}}
### Problem Assumptions ✅
- The input array is valid and contains integers within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [4, 2, 7, 4, 2, 7, 7]`  \
  **Explanation:** We form pairs with the identical integers and count the number of leftover elements. This example results in 3 pairs and 1 leftover element.

{{< dots >}}
## Approach 🚀
We will count the frequency of each number and then calculate how many pairs can be formed and how many leftover elements remain.

### Initial Thoughts 💭
- We can efficiently count the frequency of each integer using a hashmap or an array.
- The problem boils down to counting pairs and calculating the leftover elements.
- We can use an array of size 101 to store the counts of each number, and then calculate the pairs and leftovers.
{{< dots >}}
### Edge Cases 🌐
- Empty input is not valid as per the problem constraints.
- The solution should efficiently handle arrays of length up to 100.
- If all elements are the same, the number of pairs will be `nums.length // 2`.
- The length of `nums` is at least 1, and the integers are between 0 and 100.
{{< dots >}}
## Code 💻
```cpp
  // even counter
  vector<int> numberOfPairs(vector<int>& nums) {
  int cnt[101] = {}, pairs = 0;
  for (int n : nums)
      pairs += ++cnt[n] % 2 == 0 ? 1 : 0;
  return { pairs, (int)nums.size() - pairs * 2 };
  }
```

This code defines a function `numberOfPairs` that counts the number of pairs in the input array `nums`. It returns a vector containing two values: the number of pairs and the remaining unpaired elements.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	  vector<int> numberOfPairs(vector<int>& nums) {
	```
	The function `numberOfPairs` takes a vector of integers `nums` as input and returns a vector of two integers: the number of pairs and the remaining unpaired elements.

2. **Variable Declaration**
	```cpp
	  int cnt[101] = {}, pairs = 0;
	```
	The array `cnt` is used to count the occurrences of each element in `nums`. `pairs` is initialized to 0 to count the number of even pairs.

3. **Loop**
	```cpp
	  for (int n : nums)
	```
	A for-each loop that iterates over each element `n` in the `nums` array.

4. **Pair Counting**
	```cpp
	      pairs += ++cnt[n] % 2 == 0 ? 1 : 0;
	```
	For each element `n`, we increment its count in `cnt[n]` and check if the count is even. If it is, we increase the `pairs` counter.

5. **Return**
	```cpp
	  return { pairs, (int)nums.size() - pairs * 2 };
	```
	The function returns a vector with two elements: the number of pairs (`pairs`) and the number of remaining unpaired elements (calculated as the total size of the array minus twice the number of pairs).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the input array `nums`, as we iterate over the array once and perform constant-time operations for each element.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only use a fixed-size array of 101 elements for the frequency count.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-pairs-in-array/description/)

---
{{< youtube 9KeeDZ6tcy4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
