
+++
authors = ["grid47"]
title = "Leetcode 2053: Kth Distinct String in an Array"
date = "2024-04-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2053: Kth Distinct String in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "1KOnvGPv9Mo"
youtube_upload_date="2024-08-05"
youtube_thumbnail="https://i.ytimg.com/vi/1KOnvGPv9Mo/maxresdefault.jpg"
comments = true
+++



---
Find the k-th unique string in an array based on its first occurrence. If fewer than k unique strings exist, return an empty string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array of strings and an integer k.
- **Example:** `Input: arr = ["apple", "banana", "cherry", "banana", "apple", "date"], k = 2`
- **Constraints:**
	- 1 <= k <= arr.length <= 1000
	- 1 <= arr[i].length <= 5
	- arr[i] consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The k-th unique string based on order of appearance, or an empty string if fewer than k unique strings exist.
- **Example:** `Output: "date" for the given input arr and k.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify and return the k-th unique string.

- Iterate through the array and count the occurrences of each string.
- Filter the strings that appear only once, maintaining their original order.
- Return the k-th unique string if it exists; otherwise, return an empty string.
{{< dots >}}
### Problem Assumptions ✅
- All elements in the array are strings.
- Strings are considered case-sensitive.
- The array may contain duplicate strings.
{{< dots >}}
## Examples 🧩
- **Input:** `arr = ["apple", "banana", "cherry", "banana", "apple", "date"], k = 2`  \
  **Explanation:** Unique strings are ["cherry", "date"]. The 2nd unique string is "date".

{{< dots >}}
## Approach 🚀
Use a hash map to count occurrences, and then filter strings appearing exactly once.

### Initial Thoughts 💭
- Strings appearing multiple times can be ignored.
- Order of appearance matters for uniqueness.
- A hash map is ideal for counting occurrences efficiently.
- The result should maintain the original order of the array.
{{< dots >}}
### Edge Cases 🌐
- Input: arr = [], k = 1; Output: ""
- Input: arr contains 1000 strings with no duplicates, k = 1000; Output: Last string in arr.
- Input: arr = ["a", "b", "a"], k = 2; Output: ""
- Input: arr = ["x", "x"], k = 1; Output: ""
{{< dots >}}
## Code 💻
```cpp
string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string, int> mp;
    for (auto &s : arr)
        ++mp[s];
    for (auto &s : arr)
        if (mp[s] == 1 && --k == 0)
            return s;
    return "";
}
```

This function finds the k-th distinct string in the input list 'arr' where the string appears exactly once. The function uses an unordered map to store the frequency of each string, then traverses the list to find the k-th string that occurs only once.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string kthDistinct(vector<string>& arr, int k) {
	```
	This line declares the function 'kthDistinct' which takes a vector of strings and an integer k, and returns the k-th distinct string that appears exactly once in the list.

2. **Variable Initialization**
	```cpp
	    unordered_map<string, int> mp;
	```
	This line initializes an unordered map 'mp' to keep track of the frequency of each string in the array.

3. **Loop**
	```cpp
	    for (auto &s : arr)
	```
	This loop iterates over each string 's' in the input array 'arr'.

4. **Map Update**
	```cpp
	        ++mp[s];
	```
	For each string 's', this line increments its frequency in the unordered map 'mp'.

5. **Loop**
	```cpp
	    for (auto &s : arr)
	```
	This loop iterates again through the array 'arr', now checking each string to see if it has appeared exactly once.

6. **Condition Check**
	```cpp
	        if (mp[s] == 1 && --k == 0)
	```
	Checks if the current string appears exactly once in the array (i.e., its count in 'mp' is 1) and whether it is the k-th such string by decrementing 'k'.

7. **Return Statement**
	```cpp
	            return s;
	```
	If the current string 's' is the k-th distinct string, return it as the result.

8. **Return Statement**
	```cpp
	    return "";
	```
	If no such k-th distinct string is found, return an empty string to indicate no result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Traversing the array twice contributes to O(n) time complexity.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The hash map requires O(n) space to store frequencies of all strings.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/kth-distinct-string-in-an-array/description/)

---
{{< youtube 1KOnvGPv9Mo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
