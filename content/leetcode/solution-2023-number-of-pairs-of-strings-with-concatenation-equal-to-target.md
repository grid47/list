
+++
authors = ["grid47"]
title = "Leetcode 2023: Number of Pairs of Strings With Concatenation Equal to Target"
date = "2024-04-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2023: Number of Pairs of Strings With Concatenation Equal to Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "dEwKOofWa3U"
youtube_upload_date="2021-10-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/dEwKOofWa3U/maxresdefault.webp"
comments = true
+++



---
You are given an array of digit strings `nums` and a target digit string `target`. Count the number of valid pairs of indices `(i, j)` where `i != j` such that the concatenation of `nums[i]` and `nums[j]` equals `target`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `nums` of digit strings and a target digit string `target`.
- **Example:** `nums = ["123", "4", "12", "34"], target = "1234"`
- **Constraints:**
	- 2 <= nums.length <= 100
	- 1 <= nums[i].length <= 100
	- 2 <= target.length <= 100
	- nums[i] and target consist of digits.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of valid pairs of indices `(i, j)` where `i != j` such that `nums[i] + nums[j] == target`.
- **Example:** `Output: 2`
- **Constraints:**
	- The valid pairs must not have the same index for both `i` and `j`.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find all pairs of strings `nums[i]` and `nums[j]` such that their concatenation equals the target.

- 1. Create a frequency map to count occurrences of strings in `nums` that are smaller than `target` in length.
- 2. Loop through the frequency map and check if the prefix of `target` matches each string in `nums`.
- 3. If a valid prefix is found, find the corresponding suffix in the `nums` array and update the count of valid pairs.
{{< dots >}}
### Problem Assumptions ✅
- All strings in `nums` and the `target` contain only digits and are non-empty.
- The solution should efficiently handle arrays with up to 100 elements.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = ["123", "4", "12", "34"], target = "1234"`  \
  **Explanation:** The valid pairs are (0, 1) for "123" + "4" and (2, 3) for "12" + "34".

- **Input:** `nums = ["1", "1", "1"], target = "11"`  \
  **Explanation:** There are 6 valid pairs: (0, 1), (1, 0), (0, 2), (2, 0), (1, 2), (2, 1).

{{< dots >}}
## Approach 🚀
We can solve this problem by checking each pair of strings in `nums` and checking if their concatenation equals `target`.

### Initial Thoughts 💭
- Using a frequency map allows us to efficiently check pairs.
- By checking for valid prefixes and suffixes, we avoid the need for checking every possible pair of strings.
{{< dots >}}
### Edge Cases 🌐
- If `nums` is empty, return 0.
- Make sure the solution handles arrays of size 100 efficiently.
- If the `target` contains very large values or repetitive patterns, the solution should still work efficiently.
- Avoid out-of-bounds errors and make sure the solution handles all possible cases.
{{< dots >}}
## Code 💻
```cpp
int numOfPairs(vector<string>& nums, string target) {
    unordered_map<string, int> freq;
    for(auto num : nums) if(num.size() < target.size()) freq[num]++;

    int res = 0;
    for(auto [s, frq]: freq) {
        if(target.find(s) == 0) {
            if(s + s == target) 
            res += frq * (frq - 1);
            else
            res  += frq * freq[target.substr(s.size())];
        }
    }
    return res;
}
```

This function calculates the number of valid pairs in a list of strings that, when concatenated, form the target string. It uses an unordered map to store the frequency of strings smaller than the target string and checks for pairs that can form the target string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numOfPairs(vector<string>& nums, string target) {
	```
	This defines the function 'numOfPairs', which takes a vector of strings 'nums' and a target string 'target'. It will return the number of valid pairs of strings that concatenate to form the target string.

2. **Variable Initialization**
	```cpp
	    unordered_map<string, int> freq;
	```
	This initializes an unordered map 'freq' to store the frequency of strings in 'nums' that are shorter than the target string.

3. **Loop Over Input**
	```cpp
	    for(auto num : nums) if(num.size() < target.size()) freq[num]++;
	```
	This loop iterates through each string in 'nums'. If the string's size is smaller than the target string, it increases its frequency in the 'freq' map.

4. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	This initializes an integer 'res' to store the final result, which will be the count of valid pairs.

5. **Iterating Through Frequencies**
	```cpp
	    for(auto [s, frq]: freq) {
	```
	This loop iterates over each entry in the 'freq' map, where 's' is the string and 'frq' is its frequency.

6. **Prefix Check**
	```cpp
	        if(target.find(s) == 0) {
	```
	This checks if the string 's' is a prefix of the target string (i.e., 's' starts at the beginning of the target string).

7. **Self-Pair Check**
	```cpp
	            if(s + s == target) 
	```
	This checks if the string 's' repeated twice matches the target string.

8. **Count Self-Pairs**
	```cpp
	            res += frq * (frq - 1);
	```
	This adds the number of valid self-pairs to the result. If 's + s == target', the number of pairs is calculated using the formula 'frq * (frq - 1)', where 'frq' is the frequency of 's'.

9. **Else Case**
	```cpp
	            else
	```
	This else statement handles the case where 's' is a prefix but not equal to the target string when repeated.

10. **Count Valid Pairs**
	```cpp
	            res  += frq * freq[target.substr(s.size())];
	```
	This adds to the result the number of valid pairs where the remaining part of the target string (after removing 's') can be found in the 'freq' map.

11. **Return Statement**
	```cpp
	    return res;
	```
	This returns the result 'res', which is the total count of valid pairs of strings that concatenate to form the target string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n * m)
- **Worst Case:** O(n * m)

We iterate through the array of strings and use a frequency map to find matching pairs, where `n` is the number of strings and `m` is the average length of strings.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is proportional to the size of the frequency map, which stores strings from the `nums` array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/description/)

---
{{< youtube dEwKOofWa3U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
