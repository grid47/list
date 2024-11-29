
+++
authors = ["grid47"]
title = "Leetcode 2190: Most Frequent Number Following Key In an Array"
date = "2024-04-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2190: Most Frequent Number Following Key In an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "0KHTVvSX7CE"
youtube_upload_date="2022-03-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/0KHTVvSX7CE/maxresdefault.webp"
comments = true
+++



---
You are given an integer array 'nums' and an integer 'key', which is present in 'nums'. Your task is to find the integer that most frequently appears immediately after an occurrence of 'key' in the array. In other words, count how many times each integer follows 'key' and return the integer that appears the most.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array 'nums' and an integer 'key'.
- **Example:** `Input: nums = [3,1,2,3,4,3,5], key = 3`
- **Constraints:**
	- 2 <= nums.length <= 1000
	- 1 <= nums[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the integer that follows 'key' the most times in the array. The answer will be unique.
- **Example:** `Output: 3`
- **Constraints:**
	- The test cases will be generated such that the answer is unique.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the integer that follows 'key' the most times in the array.

- Iterate through the array and count how many times each integer appears immediately after an occurrence of 'key'.
- Keep track of the integer that has the highest count.
{{< dots >}}
### Problem Assumptions ✅
- The array contains at least one occurrence of 'key'.
- The solution must find the target with the maximum frequency efficiently.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [3,1,2,3,4,3,5], key = 3`  \
  **Explanation:** In the array, '3' is followed by '1' at index 1, by '4' at index 3, and by '5' at index 5. '3' appears 3 times, while no other integer follows 'key' as frequently. Thus, the output is 3.

- **Input:** `Input: nums = [2,5,2,3,5,2], key = 2`  \
  **Explanation:** In the array, '2' is followed by '5' at index 1, '3' at index 3, and another '5' at index 4. '5' follows '2' twice, while no other integer follows 'key' as frequently. Hence, the output is 5.

{{< dots >}}
## Approach 🚀
To solve this problem, we will iterate through the array and count how often each integer follows an occurrence of 'key', then return the integer with the maximum count.

### Initial Thoughts 💭
- This problem can be solved by iterating through the array and maintaining a count of the occurrences of each integer that follows 'key'.
- We can use a hash map or array to store the frequency of each integer following 'key' and then find the integer with the highest frequency.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one element after 'key', so empty inputs are not a concern.
- Ensure the solution works for arrays of size 1000.
- All elements in the array could be the same, or 'key' might be the last element, in which case no other element can follow it.
- The solution should be efficient and work within the given constraints.
{{< dots >}}
## Code 💻
```cpp
  int mostFrequent(vector<int>& nums, int key) {
int cnt[1001] = {}, res = 0;
for (int i = 1; i < nums.size(); ++i)
    if (nums[i - 1] == key && ++cnt[nums[i]] > cnt[res])
        res = nums[i];
return res;
  }
```

This function finds the most frequent number in the list 'nums' that appears immediately after a given 'key'. It uses a counting array to track the frequency of each number.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	  int mostFrequent(vector<int>& nums, int key) {
	```
	Defines the function 'mostFrequent' which takes a vector of integers 'nums' and an integer 'key' as inputs, and returns the most frequent number after occurrences of 'key'.

2. **Variable Initialization**
	```cpp
	int cnt[1001] = {}, res = 0;
	```
	Initializes an array 'cnt' to store frequencies of numbers, and a variable 'res' to track the most frequent number.

3. **Loop**
	```cpp
	for (int i = 1; i < nums.size(); ++i)
	```
	Starts a loop from the second element of the vector 'nums' to check each number and count its occurrences after the key.

4. **Condition Check**
	```cpp
	    if (nums[i - 1] == key && ++cnt[nums[i]] > cnt[res])
	```
	Checks if the previous element in the array is equal to 'key' and if the frequency of the current element is greater than the current 'res'. If true, update 'res'.

5. **Update Result**
	```cpp
	        res = nums[i];
	```
	Updates the result 'res' to the current number 'nums[i]' if it appears more frequently after 'key'.

6. **Return Statement**
	```cpp
	return res;
	```
	Returns the most frequent number after occurrences of 'key' from the vector 'nums'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the input array, because we only need to iterate through the array once.

### Space Complexity 💾
- **Best Case:** O(m)
- **Worst Case:** O(m)

The space complexity is O(m), where m is the number of distinct integers that follow 'key'. This is the space used for counting occurrences.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/description/)

---
{{< youtube 0KHTVvSX7CE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
