
+++
authors = ["grid47"]
title = "Leetcode 169: Majority Element"
date = "2024-10-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 169: Majority Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Divide and Conquer","Sorting","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/169.webp"
youtube = "M1IL4hz0QrE"
youtube_upload_date="2020-06-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/M1IL4hz0QrE/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/169.webp" 
    alt="A glowing element standing out in a sequence, symbolizing its majority status."
    caption="Solution to LeetCode 169: Majority Element Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array nums of size n, return the majority element. The majority element is the element that appears more than n // 2 times. You may assume that the majority element always exists in the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array nums of integers of size n, where 1 <= n <= 50,000 and -10^9 <= nums[i] <= 10^9.
- **Example:** `nums = [4, 4, 2, 2, 2, 4, 4]`
- **Constraints:**
	- 1 <= n <= 5 * 10^4
	- -10^9 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the majority element in the input array.
- **Example:** `Output: 4`
- **Constraints:**
	- The output will always be a valid majority element, as per the problem assumption.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the majority element in the given array.

- Initialize a variable to store the current majority element and its count.
- Iterate through the array and update the current majority element whenever necessary.
- Return the element that appears more than n // 2 times.
{{< dots >}}
### Problem Assumptions ✅
- The majority element always exists in the array.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [5, 3, 5]`  \
  **Explanation:** In this example, the element 5 appears twice, which is more than half of the array's length (3 // 2). Therefore, 5 is the majority element.

{{< dots >}}
## Approach 🚀
The approach involves iterating through the array and keeping track of the current majority element using a counter.

### Initial Thoughts 💭
- This is a problem that can be solved efficiently using a linear pass through the array, keeping track of the counts of elements.
- We can use a counter to track the frequency of the current majority element.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that there is always a majority element, so we do not need to handle the empty array case.
- For larger inputs (up to 50,000 elements), the solution should work efficiently in linear time.
- The majority element will always appear more than n // 2 times, so no need to handle cases where no majority exists.
- The solution should work in linear time and handle the maximum input size.
{{< dots >}}
## Code 💻
```cpp
int majorityElement(vector<int>& nums) {
    int e = nums[0], cnt = 1;
    map<int, int> mp;
    for(int x: nums) {
        mp[x]++;
        if(mp[x] > cnt) {
            cnt = mp[x];
            e = x;
        }
    }
    return e;
}
```

This function finds the majority element in a list, i.e., the element that appears more than half the time in the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int majorityElement(vector<int>& nums) {
	```
	Define the function 'majorityElement' that takes a vector of integers as input and returns the majority element, which appears more than half the time in the array.

2. **Variable Initialization**
	```cpp
	    int e = nums[0], cnt = 1;
	```
	Initialize two variables: 'e' (to store the majority element) and 'cnt' (to store the count of occurrences of the current majority element). Initially, set 'e' to the first element of the array and 'cnt' to 1.

3. **Data Structure Declaration**
	```cpp
	    map<int, int> mp;
	```
	Declare a map 'mp' to keep track of the frequency count of each element in the array.

4. **For Loop**
	```cpp
	    for(int x: nums) {
	```
	Iterate through each element 'x' in the array 'nums'.

5. **Frequency Update**
	```cpp
	        mp[x]++;
	```
	Increment the frequency count of element 'x' in the map.

6. **Frequency Comparison**
	```cpp
	        if(mp[x] > cnt) {
	```
	Check if the frequency of the current element 'x' is greater than the current maximum count 'cnt'.

7. **Count Update**
	```cpp
	            cnt = mp[x];
	```
	If the frequency of 'x' exceeds the current count, update 'cnt' to the new frequency of 'x'.

8. **Element Update**
	```cpp
	            e = x;
	```
	Update the majority element 'e' to the current element 'x' as it has the highest frequency so far.

9. **Return Statement**
	```cpp
	    return e;
	```
	Return the majority element 'e' that has been identified by the loop.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we only iterate through the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only use a few extra variables to store the current majority element and counter.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/majority-element/description/)

---
{{< youtube M1IL4hz0QrE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
