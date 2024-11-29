
+++
authors = ["grid47"]
title = "Leetcode 3005: Count Elements With Maximum Frequency"
date = "2024-01-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3005: Count Elements With Maximum Frequency in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ydihp-cBFqw"
youtube_upload_date="2024-01-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ydihp-cBFqw/maxresdefault.webp"
comments = true
+++



---
You are given an array `nums` containing positive integers. Your task is to find the total frequency of the elements in `nums` that appear the maximum number of times. The frequency of an element is defined as the number of times that element occurs in the array. You need to return the sum of frequencies of all elements that have the maximum frequency.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `nums` of positive integers. The task is to compute the sum of the frequencies of the elements in `nums` with the maximum frequency.
- **Example:** `nums = [2, 3, 2, 4, 5, 2]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 1 <= nums[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of frequencies of elements in the array that have the maximum frequency.
- **Example:** `Output: 6`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the total frequency of the elements that appear the most frequently in the array.

- Create a frequency map to store the count of each element in the array.
- Determine the maximum frequency of any element in the array.
- Sum the frequencies of all elements that have the maximum frequency.
{{< dots >}}
### Problem Assumptions ✅
- The input will always have at least one element in the array.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [2, 3, 2, 4, 5, 2]`  \
  **Explanation:** The frequency of 2 is the highest (3 occurrences). Thus, the total frequency of the element with the highest frequency is 6 (3 + 3).

- **Input:** `Input: nums = [1, 1, 2, 2, 3, 3]`  \
  **Explanation:** All elements appear twice, so the sum of the maximum frequencies is 6 (2 + 2 + 2).

- **Input:** `Input: nums = [10, 20, 30]`  \
  **Explanation:** All elements have a frequency of 1. Thus, the sum of the maximum frequencies is 3 (1 + 1 + 1).

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a frequency map (or hash map) to count the occurrences of each element. After counting, we find the maximum frequency and sum the frequencies of all elements with that maximum count.

### Initial Thoughts 💭
- We need to efficiently count the occurrences of elements and track the maximum frequency.
- Using a frequency map allows us to count occurrences in linear time, making the solution efficient.
{{< dots >}}
### Edge Cases 🌐
- Since `nums` will always have at least one element, we don't need to handle empty input.
- Ensure that the solution works efficiently for arrays of length 100, the upper constraint.
- If all elements are distinct, the maximum frequency is 1, and we sum the frequencies of all elements.
- The array contains integers between 1 and 100, and its length is between 1 and 100.
{{< dots >}}
## Code 💻
```cpp
int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> frq;
    int mx = 0;
    for (int num : nums) {
        frq[num]++;
        mx = max(mx, frq[num]);
    }

    int cnt = 0;
    for (auto it : frq) {
        if (it.second == mx)
            cnt++;
    }

    int net = mx * cnt;

    return net;
}
```

This function finds the total number of elements with the highest frequency in the input array `nums`. It uses an unordered map to track the frequency of each element, finds the maximum frequency, counts how many elements have this frequency, and then returns the product of the maximum frequency and its count.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxFrequencyElements(vector<int>& nums) {
	```
	Defines the function `maxFrequencyElements` that takes a vector of integers `nums` and returns an integer representing the product of the maximum frequency of elements in the array and the count of such elements.

2. **Data Structure Initialization**
	```cpp
	    unordered_map<int, int> frq;
	```
	Initializes an unordered map `frq` to store the frequency of each element in the array `nums`.

3. **Variable Initialization**
	```cpp
	    int mx = 0;
	```
	Initializes the variable `mx` to store the maximum frequency found while processing the elements of `nums`.

4. **Loop Over Elements**
	```cpp
	    for (int num : nums) {
	```
	Starts a loop to iterate through each element `num` in the input vector `nums`.

5. **Update Frequency**
	```cpp
	        frq[num]++;
	```
	Increments the frequency of the current element `num` in the `frq` map.

6. **Track Maximum Frequency**
	```cpp
	        mx = max(mx, frq[num]);
	```
	Updates `mx` to hold the maximum frequency found so far by comparing the current frequency of `num` with the previous maximum.

7. **Initialize Count Variable**
	```cpp
	    int cnt = 0;
	```
	Initializes the variable `cnt` to count how many elements have the maximum frequency `mx`.

8. **Loop Over Frequency Map**
	```cpp
	    for (auto it : frq) {
	```
	Starts a loop to iterate over each key-value pair (`it`) in the frequency map `frq`.

9. **Check for Maximum Frequency**
	```cpp
	        if (it.second == mx)
	```
	Checks if the frequency of the current element (`it.second`) equals the maximum frequency `mx`.

10. **Update Count**
	```cpp
	            cnt++;
	```
	Increments the count `cnt` if the current element's frequency matches the maximum frequency.

11. **Calculate Result**
	```cpp
	    int net = mx * cnt;
	```
	Calculates the result `net` as the product of the maximum frequency `mx` and the count `cnt` of elements with that frequency.

12. **Return Result**
	```cpp
	    return net;
	```
	Returns the calculated result `net`, which represents the product of the maximum frequency and the count of elements with that frequency.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate through the array once to count frequencies and once to find the maximum frequency.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of frequencies in a map, where `n` is the number of unique elements in the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-elements-with-maximum-frequency/description/)

---
{{< youtube ydihp-cBFqw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
