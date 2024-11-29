
+++
authors = ["grid47"]
title = "Leetcode 1297: Maximum Number of Occurrences of a Substring"
date = "2024-06-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1297: Maximum Number of Occurrences of a Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
Given a string `s`, return the maximum number of occurrences of any substring that satisfies the following conditions: The number of unique characters in the substring must be less than or equal to `maxLetters`, and the substring length must be between `minSize` and `maxSize` inclusive.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` and three integers: `maxLetters`, `minSize`, and `maxSize`.
- **Example:** `Input: s = "abcabcabc", maxLetters = 2, minSize = 2, maxSize = 3`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- 1 <= maxLetters <= 26
	- 1 <= minSize <= maxSize <= min(26, s.length)

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of occurrences of any substring that satisfies the given conditions.
- **Example:** `Output: 2`
- **Constraints:**
	- Return an integer representing the maximum number of occurrences of a valid substring.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the maximum number of occurrences of a valid substring.

- Generate all substrings of length between `minSize` and `maxSize`.
- For each substring, check if it has unique characters less than or equal to `maxLetters`.
- Count the occurrences of valid substrings and track the maximum count.
{{< dots >}}
### Problem Assumptions ✅
- The string `s` consists of lowercase English letters only.
- The input is valid, and constraints are adhered to.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "abcabcabc", maxLetters = 2, minSize = 2, maxSize = 3`  \
  **Explanation:** The substring 'ab' appears twice in the string and satisfies the condition of having 2 unique letters and a size of 2.

- **Input:** `Input: s = "xxxyyy", maxLetters = 1, minSize = 2, maxSize = 3`  \
  **Explanation:** The substring 'xx' appears twice and satisfies the condition of having 1 unique letter and a size of 2.

{{< dots >}}
## Approach 🚀
The problem can be solved by generating all possible substrings of valid lengths and counting their occurrences. We need to ensure that only valid substrings are considered.

### Initial Thoughts 💭
- We need to generate substrings of different lengths between `minSize` and `maxSize`.
- The number of unique characters in each substring must be tracked to check if it is valid.
- A sliding window approach or hashing can be used to efficiently count occurrences of substrings while ensuring they meet the conditions.
{{< dots >}}
### Edge Cases 🌐
- The string is non-empty, as per the problem constraints.
- The solution must efficiently handle strings up to length 10^5.
- If `maxLetters` is larger than the number of unique letters in the string, all substrings are valid.
- The solution should be optimized to run within time limits for large input sizes.
{{< dots >}}
## Code 💻
```cpp
bool isPossibleDivide(vector<int>& nums, int k) {

    map<int, int> cnt;
    int n = nums.size();
    for(int num : nums)
        cnt[num]++;
    
    for(auto it : cnt) {
        int frq = it.second;
        if(frq > 0)
        for(int i = 0; i < k; i++) {

              if(cnt[it.first + i] < frq) return false;
            else cnt[it.first + i] -= frq;

        }
    }
    
    return true;
}
```

This function checks whether an array of integers can be divided into consecutive groups of size 'k'. It does so by counting the frequency of each number and then greedily forming groups of consecutive integers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isPossibleDivide(vector<int>& nums, int k) {
	```
	This is the function header, where the function is defined with two parameters: 'nums' (a vector of integers) and 'k' (the size of each group).

2. **Map Initialization**
	```cpp
	    map<int, int> cnt;
	```
	This creates a map to store the frequency of each integer in the input array 'nums'. The key is the integer, and the value is its frequency.

3. **Array Length**
	```cpp
	    int n = nums.size();
	```
	This stores the size of the input array 'nums' in the variable 'n'.

4. **Iterate Through Numbers**
	```cpp
	    for(int num : nums)
	```
	This loop iterates through each integer in the input array 'nums'.

5. **Update Frequency Map**
	```cpp
	        cnt[num]++;
	```
	This increments the frequency of the current number in the map 'cnt'.

6. **Frequency Map Iteration**
	```cpp
	
	```
	Now, we begin iterating through the frequency map to check if it is possible to form groups.

7. **Iterate Through Frequency Map**
	```cpp
	    for(auto it : cnt) {
	```
	This loop iterates through each key-value pair in the frequency map, where 'it.first' is the number and 'it.second' is its frequency.

8. **Get Frequency of Current Number**
	```cpp
	        int frq = it.second;
	```
	Extracts the frequency of the current number from the map.

9. **Frequency Check**
	```cpp
	        if(frq > 0)
	```
	Checks if the current frequency is greater than 0 before attempting to form a group.

10. **Loop for Consecutive Numbers**
	```cpp
	        for(int i = 0; i < k; i++) {
	```
	This inner loop iterates over the next 'k' consecutive numbers starting from the current number.

11. **Condition for Group Formation**
	```cpp
	
	```
	Here, we check if the group of consecutive numbers can be formed.

12. **Check for Sufficient Frequency**
	```cpp
	              if(cnt[it.first + i] < frq) return false;
	```
	If the frequency of any of the consecutive numbers is less than the required frequency, it returns false as the group cannot be formed.

13. **Update Frequency for Used Numbers**
	```cpp
	            else cnt[it.first + i] -= frq;
	```
	If the consecutive number can be used, its frequency is decreased by 'frq'.

14. **Return Statement**
	```cpp
	    return true;
	```
	If the loop completes without returning false, it means it's possible to divide the array into consecutive groups of size 'k', so we return true.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) - In the best case, no substrings need to be checked or all substrings are valid.
- **Average Case:** O(n^2) - Substring generation and uniqueness checks dominate the complexity.
- **Worst Case:** O(n^2) - In the worst case, we need to check all possible substrings for validity.

The time complexity is O(n^2) due to the need to generate and check all substrings.

### Space Complexity 💾
- **Best Case:** O(n) - Space complexity remains O(n) even in the best case.
- **Worst Case:** O(n) - Space complexity is O(n) due to storage of substring counts and temporary sets.

The space complexity is O(n) due to the temporary storage of unique substrings.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
