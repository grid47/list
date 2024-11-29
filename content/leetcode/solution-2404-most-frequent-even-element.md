
+++
authors = ["grid47"]
title = "Leetcode 2404: Most Frequent Even Element"
date = "2024-03-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2404: Most Frequent Even Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "JykfDvn2o0M"
youtube_upload_date="2022-09-11"
youtube_thumbnail="https://i.ytimg.com/vi/JykfDvn2o0M/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array `nums`. Your task is to return the most frequent even element in the array. If there is a tie (i.e., multiple even elements appear the most number of times), return the smallest one. If there is no even element, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array `nums` containing elements from 0 to 100,000.
- **Example:** `nums = [1, 3, 5, 2, 4, 4, 4]`
- **Constraints:**
	- 1 <= nums.length <= 2000
	- 0 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the most frequent even element in the array. If no even element exists, return -1.
- **Example:** `Output: 4`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the most frequent even element, and in case of a tie, return the smallest one.

- 1. Create a map (hash table) to count the frequency of each element in the array.
- 2. Loop through the map and identify the most frequent even element.
- 3. If there is a tie in frequency, select the smallest element.
- 4. If no even element is found, return -1.
{{< dots >}}
### Problem Assumptions ✅
- The input array is valid and consists only of non-negative integers.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [0, 1, 2, 2, 4, 4, 1]`  \
  **Explanation:** The even elements in the array are 0, 2, and 4. Both 2 and 4 appear the most times, but since 2 is smaller, it is returned.

- **Input:** `nums = [3, 5, 7, 9]`  \
  **Explanation:** There are no even elements in the array, so the result is -1.

- **Input:** `nums = [4, 4, 4, 9, 2, 4]`  \
  **Explanation:** The even element 4 appears most frequently, so it is returned.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a hash map to count the frequency of each element in the array and then determine the most frequent even element.

### Initial Thoughts 💭
- We can iterate over the array to count the occurrences of each element.
- We need to check if the element is even and then compare its frequency to keep track of the most frequent even element.
- Efficiently counting frequencies using a hash map and checking conditions will help us solve the problem in linear time.
{{< dots >}}
### Edge Cases 🌐
- This problem does not have an empty input case as the array length is guaranteed to be at least 1.
- The solution should efficiently handle arrays with sizes up to 2000 and elements in the range of 0 to 100,000.
- If no even element exists in the array, return -1.
- The solution must be efficient with a time complexity of O(n) due to the array's potential size.
{{< dots >}}
## Code 💻
```cpp
int mostFrequentEven(vector<int>& nums) {
    map<int, int> mp;
    for(auto n: nums) mp[n]++;
    int ans = -1, mx = -1;
    for(auto m: mp){
        if(m.first%2 == 0 && m.second > mx){
            mx = m.second;
            ans = m.first;
        }
    }
    return ans;
}
```

This function finds the most frequent even number in a given list of integers `nums`. It returns -1 if no even number is found.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int mostFrequentEven(vector<int>& nums) {
	```
	This is the function signature for `mostFrequentEven`, which takes a reference to a vector of integers `nums`.

2. **Map Initialization**
	```cpp
	    map<int, int> mp;
	```
	Initialize a map `mp` where the key is an integer from the array, and the value is its frequency of occurrence.

3. **Frequency Counting**
	```cpp
	    for(auto n: nums) mp[n]++;
	```
	Iterate through the `nums` array, counting the frequency of each number and storing it in the map `mp`.

4. **Variable Initialization**
	```cpp
	    int ans = -1, mx = -1;
	```
	Initialize variables `ans` to store the answer (set to -1 initially), and `mx` to track the maximum frequency of any number (also set to -1).

5. **Loop Through Map**
	```cpp
	    for(auto m: mp){
	```
	Loop through each key-value pair in the map `mp`, where `m.first` is the number and `m.second` is its frequency.

6. **Condition Check for Even Numbers**
	```cpp
	        if(m.first%2 == 0 && m.second > mx){
	```
	Check if the number is even (`m.first % 2 == 0`) and if its frequency `m.second` is greater than the current maximum frequency `mx`.

7. **Update Maximum Frequency**
	```cpp
	            mx = m.second;
	```
	Update the maximum frequency `mx` to the frequency of the current even number.

8. **Update Answer**
	```cpp
	            ans = m.first;
	```
	Update the answer `ans` to the current even number `m.first` with the highest frequency.

9. **Return Statement**
	```cpp
	    return ans;
	```
	Return the answer `ans`, which is the most frequent even number or -1 if no such number exists.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the array, since we only need to pass through the array once and then through the map.
- **Average Case:** O(n), as we still process each element in the array once and use the map in linear time.
- **Worst Case:** O(n), as both counting frequencies and comparing map entries are linear operations.

The solution runs in linear time, making it optimal for this problem.

### Space Complexity 💾
- **Best Case:** O(1), if there are no even elements or only one unique element in the array.
- **Worst Case:** O(n), as we store the frequency of each unique element in the array in a hash map.

The space complexity is linear, as we store the frequencies of the elements in a hash map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/most-frequent-even-element/description/)

---
{{< youtube JykfDvn2o0M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
