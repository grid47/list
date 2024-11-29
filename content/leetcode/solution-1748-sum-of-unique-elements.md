
+++
authors = ["grid47"]
title = "Leetcode 1748: Sum of Unique Elements"
date = "2024-05-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1748: Sum of Unique Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "MXQyGU493vE"
youtube_upload_date="2021-02-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/MXQyGU493vE/maxresdefault.webp"
comments = true
+++



---
You are given an integer array `nums`. Your task is to find the sum of all elements that appear only once in the array. Elements that appear more than once should be excluded from the sum.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums`, where each element is a positive integer.
- **Example:** `Input: nums = [5, 7, 8, 7, 9]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 1 <= nums[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of all the unique elements in the given array.
- **Example:** `Output: 22`
- **Constraints:**
	- The result should be the sum of elements that appear exactly once in the array.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the sum of all unique elements in the array.

- 1. Create a frequency map (hashmap) to count the occurrences of each element in the array.
- 2. Iterate over the array and sum the elements that appear exactly once.
{{< dots >}}
### Problem Assumptions ✅
- The array is non-empty and contains only integers between 1 and 100.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [5, 7, 8, 7, 9]`  \
  **Explanation:** The unique elements in the array are 5, 8, and 9. Their sum is 22.

- **Input:** `Input: nums = [1, 1, 1, 1, 1]`  \
  **Explanation:** There are no unique elements in this array, so the sum is 0.

{{< dots >}}
## Approach 🚀
The approach to solving this problem is to first count the occurrences of each number in the array and then sum the numbers that appear exactly once.

### Initial Thoughts 💭
- We need an efficient way to count the occurrences of elements.
- The constraints are small enough to allow for a straightforward hashmap solution.
- We will use a hashmap to store the frequency of each element and then iterate through the hashmap to sum the unique elements.
{{< dots >}}
### Edge Cases 🌐
- The array is guaranteed to have at least one element, so this edge case is not applicable.
- Although the array can have up to 100 elements, the problem constraints are small enough that the solution can handle the largest input size efficiently.
- If all elements in the array are the same, the result should be 0.
- Ensure that the solution works efficiently even with the largest possible input size.
{{< dots >}}
## Code 💻
```cpp
int sumOfUnique(vector<int>& nums) {
    unordered_map<int,int> mpp;
    int sum= 0;
    for(int i=0; i<nums.size(); i++){
        mpp[nums[i]]++;
    }
    for(int i=0; i<nums.size(); i++){
        if(mpp[nums[i]] <= 1)
            sum+= nums[i];
    }
    return sum;
}
```

The function `sumOfUnique` calculates the sum of all unique numbers in the input vector `nums`. It uses a hash map to count the frequency of each number and adds numbers to the sum only if they appear exactly once.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int sumOfUnique(vector<int>& nums) {
	```
	This defines the function `sumOfUnique` which takes a reference to a vector of integers `nums` as input and returns the sum of the unique numbers in it.

2. **Data Structure Initialization**
	```cpp
	    unordered_map<int,int> mpp;
	```
	This initializes an unordered map `mpp` to store the frequency of each number in the vector `nums`.

3. **Variable Initialization**
	```cpp
	    int sum= 0;
	```
	This initializes an integer variable `sum` to 0, which will accumulate the sum of the unique numbers.

4. **Loop Over Vector**
	```cpp
	    for(int i=0; i<nums.size(); i++){
	```
	This loop iterates over each element in the input vector `nums`.

5. **Frequency Count**
	```cpp
	        mpp[nums[i]]++;
	```
	This line increments the count of the current element `nums[i]` in the unordered map `mpp`.

6. **Second Loop Over Vector**
	```cpp
	    for(int i=0; i<nums.size(); i++){
	```
	This loop iterates over the vector `nums` again to check the frequency of each number.

7. **Condition for Unique Numbers**
	```cpp
	        if(mpp[nums[i]] <= 1)
	```
	This checks if the current element `nums[i]` appears only once in the vector. If its frequency is less than or equal to 1, it is considered unique.

8. **Sum Update**
	```cpp
	            sum+= nums[i];
	```
	If the number is unique (appears only once), it is added to the `sum`.

9. **Return Statement**
	```cpp
	    return sum;
	```
	The function returns the sum of all unique numbers stored in the `sum` variable.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where `n` is the length of the array. In the best case, the array contains only unique elements.
- **Average Case:** O(n), since we need to process each element in the array once.
- **Worst Case:** O(n), as the time complexity is linear even in the worst case.

The time complexity is linear with respect to the length of the array.

### Space Complexity 💾
- **Best Case:** O(n), as we need space for the frequency map.
- **Worst Case:** O(n), where `n` is the length of the array, since we store the frequency of each element.

The space complexity is linear in the number of unique elements in the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-unique-elements/description/)

---
{{< youtube MXQyGU493vE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
