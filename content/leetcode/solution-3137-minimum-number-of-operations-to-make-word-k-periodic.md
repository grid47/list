
+++
authors = ["grid47"]
title = "Leetcode 3137: Minimum Number of Operations to Make Word K-Periodic"
date = "2023-12-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3137: Minimum Number of Operations to Make Word K-Periodic in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "iu8AnEQH4U8"
youtube_upload_date="2024-05-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/iu8AnEQH4U8/maxresdefault.webp"
comments = true
+++



---
You are given a string `word` of length `n`, and an integer `k` such that `k` divides `n`. In one operation, you can pick any two indices `i` and `j`, both divisible by `k`, and swap the substrings starting from `i` and `j`, each of length `k`. The goal is to transform `word` into a `k`-periodic string, meaning that the string can be represented as multiple concatenations of a substring of length `k`. Your task is to determine the minimum number of operations required to make the string `k`-periodic.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `word` and an integer `k`.
- **Example:** `Example 1:
Input: word = "abcdefabcdef", k = 3
Output: 1`
- **Constraints:**
	- 1 <= n == word.length <= 10^5
	- 1 <= k <= word.length
	- k divides word.length.
	- word consists only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations required to make the word `k`-periodic.
- **Example:** `Example 1:
Input: word = "abcdefabcdef", k = 3
Output: 1`
- **Constraints:**
	- The result must be an integer representing the minimum number of operations.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to make the word `k`-periodic with the fewest number of substring swaps.

- For each block of size `k` in the string, group the substrings and count how many times each substring appears.
- The fewer the number of unique substrings in the blocks, the fewer the swaps needed to make the word periodic.
- To minimize the operations, swap the most frequent substrings to align the other blocks.
{{< dots >}}
### Problem Assumptions ✅
- The string consists only of lowercase English letters.
- The value of k divides the length of the string.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1:`  \
  **Explanation:** In the word 'abcdefabcdef' with k=3, there are two substrings 'abc' and 'def'. Since they repeat, we need just one operation to make the word periodic by swapping the second 'abc' with the first 'def'.

- **Input:** `Example 2:`  \
  **Explanation:** In the word 'aabbccaabbcc' with k=2, there are three unique substrings: 'aa', 'bb', and 'cc'. We need to swap substrings to make them align, requiring 3 operations.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to count the frequency of substrings of length k and minimize the number of operations required to make the string k-periodic.

### Initial Thoughts 💭
- The solution involves counting the frequency of each substring and minimizing the operations based on these frequencies.
- A greedy approach could help by choosing the most frequent substrings to minimize the number of swaps.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the length of the word is at least 1.
- The solution must efficiently handle inputs where the length of the word is up to 100,000.
- Ensure that the solution works when there are multiple unique substrings or when all substrings are the same.
- Ensure that k divides the length of the word.
{{< dots >}}
## Code 💻
```cpp
int minimumOperationsToMakeKPeriodic(string s, int k) {
    
    int n = s.size();
    map<string, int> mp;
    
    for(int i = 0; i < n / k; i++) {
        mp[s.substr(i * k, k)]++;
    }
    
    int lg = 0, net = 0;
    for(auto it: mp) {
        lg = max(lg, it.second);
        net += it.second;
    }
    
    return net - lg;
    
}
```

This function calculates the minimum number of operations required to make a string `s` periodic with period `k`. It does so by counting the occurrences of substrings of length `k` and finding the most frequent substring to minimize the operations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimumOperationsToMakeKPeriodic(string s, int k) {
	```
	Defines the function `minimumOperationsToMakeKPeriodic`, which takes a string `s` and an integer `k` to determine the minimum number of operations required to make the string periodic with period `k`.

2. **Variable Initialization**
	```cpp
	    int n = s.size();
	```
	Initializes `n` to the length of the string `s` to help in determining the range for substring operations.

3. **Map Initialization**
	```cpp
	    map<string, int> mp;
	```
	Initializes a map `mp` to store substrings of length `k` as keys and their corresponding frequency as values.

4. **Loop Structure**
	```cpp
	    for(int i = 0; i < n / k; i++) {
	```
	Starts a loop that iterates through the string `s`, dividing it into segments of length `k`.

5. **Map Update**
	```cpp
	        mp[s.substr(i * k, k)]++;
	```
	For each substring of length `k` starting at index `i * k`, it updates the frequency count in the map `mp`.

6. **Variable Initialization**
	```cpp
	    
	```
	The next block of code initializes variables for calculating the final result.

7. **Variable Initialization**
	```cpp
	    int lg = 0, net = 0;
	```
	Initializes two integer variables: `lg` to store the largest frequency of any substring, and `net` to store the total number of substrings.

8. **Iteration Over Map**
	```cpp
	    for(auto it: mp) {
	```
	Starts a loop to iterate through the map `mp`, which contains the frequencies of substrings.

9. **Max Frequency Update**
	```cpp
	        lg = max(lg, it.second);
	```
	Updates `lg` with the maximum frequency of any substring in the map.

10. **Net Frequency Update**
	```cpp
	        net += it.second;
	```
	Adds the frequency of the current substring to the total count `net`.

11. **Return Statement**
	```cpp
	    return net - lg;
	```
	Returns the result of `net - lg`, which represents the minimum number of operations needed to make the string periodic.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, where n is the length of the word, since we iterate over the string and process substrings of length k.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n/k)

The space complexity is linear in terms of the number of distinct substrings of length k, which is O(n/k).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-operations-to-make-word-k-periodic/description/)

---
{{< youtube iu8AnEQH4U8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
