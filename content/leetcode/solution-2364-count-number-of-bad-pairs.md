
+++
authors = ["grid47"]
title = "Leetcode 2364: Count Number of Bad Pairs"
date = "2024-03-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2364: Count Number of Bad Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "alyDgY0FCiA"
youtube_upload_date="2022-08-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/alyDgY0FCiA/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array, nums. A pair of indices (i, j) is considered a 'bad pair' if i < j and j - i is not equal to nums[j] - nums[i]. Your task is to determine the total number of bad pairs in the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single 0-indexed integer array nums, where each element represents a number in the array.
- **Example:** `nums = [2, 5, 3, 6, 7]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer, representing the total number of bad pairs in the array nums.
- **Example:** `Output: 4`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to count the number of pairs (i, j) such that i < j and j - i is not equal to nums[j] - nums[i].

- We can use a hashmap to keep track of the differences between indices and the corresponding values in the array.
- For each index i, calculate the difference j - nums[j] and use the hashmap to count how many times that difference has occurred for previous indices.
- Accumulate the count of bad pairs based on the differences.
{{< dots >}}
### Problem Assumptions ✅
- The array contains at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [2, 5, 3, 6, 7]`  \
  **Explanation:** For the given array, the bad pairs are the pairs of indices (i, j) where i < j, and the condition j - i != nums[j] - nums[i] holds. The total bad pairs in this example are 4.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves using a hashmap to track the difference between indices and their respective values efficiently.

### Initial Thoughts 💭
- To determine if a pair is bad, we need to check the difference between indices and their corresponding values.
- Using a hashmap will allow us to efficiently track and calculate the number of bad pairs.
- A hashmap will allow for constant time lookup and update, which will help in counting the bad pairs efficiently.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the input array will have at least one element, so no need to handle empty arrays.
- The solution should be efficient enough to handle arrays of size up to 100,000.
- If all the elements are the same, there will be no bad pairs, as the condition will always hold.
- Ensure the solution runs in O(n) time to handle large inputs within the constraints.
{{< dots >}}
## Code 💻
```cpp
long long countBadPairs(vector<int>& nums, long cnt = 0) {
    unordered_map<int,int> mp;
    for(int i = 0; i < nums.size(); i++)
        cnt += i - mp[i - nums[i]]++;
    return cnt;
}
```

This function counts the number of 'bad pairs' in the given vector of integers, where a bad pair is defined as a pair of indices (i, j) such that i < j and nums[i] - nums[j] != i - j.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	long long countBadPairs(vector<int>& nums, long cnt = 0) {
	```
	This is the function declaration. It initializes a variable 'cnt' to count the bad pairs.

2. **Variable Initialization**
	```cpp
	    unordered_map<int,int> mp;
	```
	This line declares an unordered map 'mp' to store the frequency of the differences between elements in the vector and their indices.

3. **Loop Start**
	```cpp
	    for(int i = 0; i < nums.size(); i++)
	```
	This starts a loop over all elements in the 'nums' vector. The loop index 'i' iterates through the elements.

4. **Count Calculation**
	```cpp
	        cnt += i - mp[i - nums[i]]++;
	```
	This line updates the 'cnt' by calculating the number of bad pairs for each index 'i'. It uses the unordered map to find how many times the difference (i - nums[i]) has occurred previously.

5. **Return Statement**
	```cpp
	    return cnt;
	```
	This returns the final count of bad pairs after iterating over all elements in the 'nums' vector.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the input array, as we are iterating over the array once and performing constant-time operations for each element.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), as we are storing differences in a hashmap, which requires space proportional to the number of unique differences.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-number-of-bad-pairs/description/)

---
{{< youtube alyDgY0FCiA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
