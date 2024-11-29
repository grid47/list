
+++
authors = ["grid47"]
title = "Leetcode 1170: Compare Strings by Frequency of the Smallest Character"
date = "2024-07-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1170: Compare Strings by Frequency of the Smallest Character in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Binary Search","Sorting"]
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
Define a function `f(s)` as the frequency of the lexicographically smallest character in a non-empty string `s`. For example, for `s = 'abc'`, `f(s) = 1` because the smallest character is `'a'`, appearing once. Given an array of strings `queries` and another array `words`, return an array where each entry corresponds to the number of strings in `words` where `f(W)` is greater than `f(queries[i])` for a given `i`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays of strings: `queries` and `words`.
- **Example:** `Input: queries = ["xyz", "aac"], words = ["aaa", "bbc", "cccc"]`
- **Constraints:**
	- 1 <= queries.length <= 2000
	- 1 <= words.length <= 2000
	- 1 <= queries[i].length, words[i].length <= 10
	- queries[i][j], words[i][j] consist of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** An array of integers representing the count of strings in `words` such that `f(W) > f(queries[i])` for each query.
- **Example:** `Output: [3, 2]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate `f(s)` for each string in `queries` and `words`, then compare the values to determine counts.

- Calculate `f(W)` for all strings in `words` and store the results in a sorted array.
- For each query in `queries`, compute `f(queries[i])`.
- Use binary search on the sorted `words` array to count the number of `f(W)` values greater than `f(queries[i])`.
{{< dots >}}
### Problem Assumptions ✅
- All strings are non-empty and contain only lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: queries = ["abc", "dd"], words = ["a", "bbb", "cccc"]`  \
  **Explanation:** For query 'abc', `f(abc) = 1`, and the counts of words with higher `f` are 2 (`bbb`, `cccc`). For query 'dd', `f(dd) = 2`, and only `cccc` has a higher `f`.

{{< dots >}}
## Approach 🚀
Use a frequency counting method combined with sorting and binary search to optimize comparisons.

### Initial Thoughts 💭
- The calculation of `f(s)` is straightforward by counting character frequencies.
- Sorting `words` by their `f(W)` values allows efficient comparisons using binary search.
- Precomputing and sorting `f(W)` for `words` can save computation during query evaluation.
{{< dots >}}
### Edge Cases 🌐
- Empty `queries` or `words` arrays are invalid per constraints.
- Maximum array sizes for `queries` and `words`.
- All characters in a string are the same.
- Minimal and maximal string lengths in both arrays.
{{< dots >}}
## Code 💻
```cpp
vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& w) {
    vector<int> bp(26, 0), ans(w.size(), 0), res(q.size(), 0);
    
    int j = 0;
    for(auto s: w) {
        bp= vector<int>(26, 0);
        for(char x: s) {
            bp[x - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(bp[i] > 0) {
                ans[j] = bp[i];
                break;
            }
        }
        j++;
    }
    
    sort(ans.begin(), ans.end());
    
    j = 0;
    for(auto s: q) {
        bp= vector<int>(26, 0);
        for(char x: s) {
            bp[x - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(bp[i] > 0) {
                res[j] = bp[i];
                break;
            }
        }
        j++;
    }
    // for(auto x: res)
    //     cout << x << " ";
    // cout << "\n";        
    vector<int> ret(q.size(), 0);
    for(int i = 0; i < res.size(); i++) {
        int qr = res[i];
        auto it = upper_bound(ans.begin(), ans.end(), qr);
        ret[i] = ans.end() - it;
        // cout << ret[i] << " ";
    }
    return ret;
}
```

This code defines the function `numSmallerByFrequency`, which compares the frequency of the smallest character in two lists of strings `q` and `w`, and returns a vector where each element indicates how many strings in `w` have a smaller smallest character frequency than the corresponding string in `q`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& w) {
	```
	Define the function `numSmallerByFrequency` that takes two vectors of strings `q` and `w` as input and returns a vector of integers.

2. **Variable Initialization**
	```cpp
	    vector<int> bp(26, 0), ans(w.size(), 0), res(q.size(), 0);
	```
	Initialize three vectors: `bp` to store character frequencies, `ans` to store the smallest frequency from each string in `w`, and `res` to store the smallest frequency from each string in `q`.

3. **Variable Initialization**
	```cpp
	    int j = 0;
	```
	Initialize the index `j` to 0 for traversing the `w` vector.

4. **Loop**
	```cpp
	    for(auto s: w) {
	```
	Start a loop that iterates through each string `s` in the vector `w`.

5. **Variable Initialization**
	```cpp
	        bp = vector<int>(26, 0);
	```
	Reinitialize the `bp` vector to store the frequency of characters in the current string `s`.

6. **Loop**
	```cpp
	        for(char x: s) {
	```
	Start a loop to count the occurrences of each character in the string `s`.

7. **Frequency Calculation**
	```cpp
	            bp[x - 'a']++;
	```
	Increment the count for the character `x` in the `bp` vector by adjusting it to the appropriate index (`x - 'a'`).

8. **Loop**
	```cpp
	        for(int i = 0; i < 26; i++) {
	```
	Start a loop to check each index of the `bp` vector to find the smallest frequency of any character.

9. **Conditional**
	```cpp
	            if(bp[i] > 0) {
	```
	Check if the current character has a non-zero frequency.

10. **Assignment**
	```cpp
	                ans[j] = bp[i];
	```
	Assign the smallest non-zero frequency found to the corresponding position in the `ans` vector.

11. **Flow Control**
	```cpp
	                break;
	```
	Exit the loop once the smallest frequency is assigned.

12. **Index Update**
	```cpp
	        j++;
	```
	Increment the index `j` to move to the next string in `w`.

13. **Sorting**
	```cpp
	    sort(ans.begin(), ans.end());
	```
	Sort the `ans` vector in ascending order to prepare for comparisons with `q`.

14. **Variable Initialization**
	```cpp
	    j = 0;
	```
	Reinitialize `j` to 0 for iterating over the `q` vector.

15. **Loop**
	```cpp
	    for(auto s: q) {
	```
	Start a loop that iterates through each string `s` in the vector `q`.

16. **Variable Initialization**
	```cpp
	        bp = vector<int>(26, 0);
	```
	Reinitialize the `bp` vector for the current string `s` in `q`.

17. **Loop**
	```cpp
	        for(char x: s) {
	```
	Start a loop to count the occurrences of each character in the string `s`.

18. **Frequency Calculation**
	```cpp
	            bp[x - 'a']++;
	```
	Increment the count for the character `x` in the `bp` vector by adjusting it to the appropriate index (`x - 'a'`).

19. **Loop**
	```cpp
	        for(int i = 0; i < 26; i++) {
	```
	Start a loop to check each index of the `bp` vector to find the smallest frequency of any character.

20. **Conditional**
	```cpp
	            if(bp[i] > 0) {
	```
	Check if the current character has a non-zero frequency.

21. **Assignment**
	```cpp
	                res[j] = bp[i];
	```
	Assign the smallest non-zero frequency found to the corresponding position in the `res` vector.

22. **Flow Control**
	```cpp
	                break;
	```
	Exit the loop once the smallest frequency is assigned.

23. **Index Update**
	```cpp
	        j++;
	```
	Increment the index `j` to move to the next string in `q`.

24. **Result Calculation**
	```cpp
	    vector<int> ret(q.size(), 0);
	```
	Initialize the result vector `ret` to store the final result for each string in `q`.

25. **Loop**
	```cpp
	    for(int i = 0; i < res.size(); i++) {
	```
	Start a loop to calculate the number of strings in `w` that have a smaller smallest character frequency than the corresponding string in `q`.

26. **Binary Search**
	```cpp
	        int qr = res[i];
	```
	Store the smallest frequency for the current string in `q`.

27. **Binary Search**
	```cpp
	        auto it = upper_bound(ans.begin(), ans.end(), qr);
	```
	Use binary search to find the position in the `ans` vector where `qr` can be inserted to maintain sorted order.

28. **Result Assignment**
	```cpp
	        ret[i] = ans.end() - it;
	```
	Assign the count of elements greater than `qr` in `ans` to the result vector `ret`.

29. **Return**
	```cpp
	    return ret;
	```
	Return the result vector `ret`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n + m log n) for n = |words| and m = |queries|.
- **Average Case:** O(n log n + m log n).
- **Worst Case:** O(n log n + m log n).

Precomputing and sorting `words` is O(n log n), and each query is resolved in O(log n).

### Space Complexity 💾
- **Best Case:** O(n + m).
- **Worst Case:** O(n + m) for storing `f(W)` and results.

Additional space for arrays to store computed values.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
