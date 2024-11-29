
+++
authors = ["grid47"]
title = "Leetcode 2901: Longest Unequal Adjacent Groups Subsequence II"
date = "2024-01-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2901: Longest Unequal Adjacent Groups Subsequence II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "DJaTr0BnG1Q"
youtube_upload_date="2023-10-14"
youtube_thumbnail="https://i.ytimg.com/vi/DJaTr0BnG1Q/maxresdefault.jpg"
comments = true
+++



---
You are given an array of strings `words` and an array `groups` of equal length `n`. The task is to find the longest subsequence from `words` such that the corresponding elements in `groups` are unequal for adjacent elements in the subsequence, and the Hamming distance between consecutive strings in the subsequence is exactly 1. A string's Hamming distance with another string is the number of positions at which their characters differ. The subsequence should be returned as an array of strings in the order of the subsequence indices.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays: a string array `words` and an integer array `groups`, both of length `n`. Each element in `words` is a distinct lowercase string, and each element in `groups` is a positive integer. The strings in `words` may be of different lengths.
- **Example:** `words = ["hello", "hero", "hollow", "hi"], groups = [1, 2, 1, 3]`
- **Constraints:**
	- 1 <= n == words.length == groups.length <= 1000
	- 1 <= words[i].length <= 10
	- 1 <= groups[i] <= n
	- words consists of distinct strings
	- words[i] consists of lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the longest subsequence of strings from `words` that satisfies the conditions. The subsequence should be ordered according to the selected indices in the subsequence.
- **Example:** `For words = ["hello", "hero", "hollow", "hi"], groups = [1, 2, 1, 3], the output would be ["hello", "hollow"] because they satisfy both conditions.`
- **Constraints:**
	- The words in the subsequence should appear in the order of the indices selected.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the longest subsequence of words such that the elements in `groups` at consecutive positions are different, and the Hamming distance between consecutive strings in the subsequence is 1.

- Iterate through each string in `words` and compare it with previous strings based on the Hamming distance and the group values.
- If the current string has a Hamming distance of 1 from the previous string and the group values are different, add it to the subsequence.
- Track the length of the longest subsequence and its corresponding words.
{{< dots >}}
### Problem Assumptions ✅
- The strings in `words` are distinct.
- All strings in `words` can have different lengths.
{{< dots >}}
## Examples 🧩
- **Input:** `For words = ["cat", "bat", "rat", "mat"], groups = [1, 2, 2, 1], the valid subsequence is ["cat", "bat", "rat"]`  \
  **Explanation:** Here, words at indices 0, 1, and 2 have different groups, and the Hamming distance between consecutive strings is exactly 1.

{{< dots >}}
## Approach 🚀
The approach involves iterating through each word and checking if it can be included in the subsequence based on the conditions. A dynamic programming approach is used to keep track of the longest valid subsequences.

### Initial Thoughts 💭
- The problem requires us to compare words with others in terms of Hamming distance and group values.
- This problem can be solved with dynamic programming by maintaining a list of subsequences and updating them when a new valid word is found.
{{< dots >}}
### Edge Cases 🌐
- If the input arrays are empty, return an empty subsequence.
- Ensure that the solution works efficiently with up to 1000 words.
- Words that are identical except for one character may be valid subsequences if they belong to different groups.
- Handle large inputs efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++) dp[i].push_back(i);

    int longest_length = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (groups[i] == groups[j]) continue;
            if (words[i].size() != words[j].size()) continue;
            if (getHammingDistance(words[i], words[j]) != 1) continue;

            if ((dp[j].size() + 1) > dp[i].size()) {
                dp[i] = dp[j];
                dp[i].push_back(i);
                longest_length = max(longest_length, int(dp[i].size()));
            }
        }
    }

    vector<string> result;
    for (int i = 0; i < n; i++) {
        if (dp[i].size() == longest_length) {
            for (const int& x : dp[i]) result.push_back(words[x]);
            break;
        }
    }
    return result;
}
private:
int getHammingDistance(const string& s, const string& t) {
    int dist = 0;
    int k = s.size();
    for (int i = 0; i < k; i++) {
        if (s[i] != t[i]) dist++;
    }
    return dist;
}
```

This code defines a function to find the longest subsequence of words where each pair of words in the subsequence has a Hamming distance of 1, and they belong to different groups. It uses dynamic programming to track the longest subsequences and their lengths.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
	```
	Defines the function and initializes input parameters: n (number of words), words (the list of words), and groups (the groups of each word).

2. **Data Structure Initialization**
	```cpp
	    vector<vector<int>> dp(n);
	```
	Initializes a 2D vector dp, where dp[i] will store the indices of the longest subsequence ending at word i.

3. **Loop Initialization**
	```cpp
	    for (int i = 0; i < n; i++) dp[i].push_back(i);
	```
	Populates the dp vector with the indices of each word, starting each subsequence with just the word itself.

4. **Variable Initialization**
	```cpp
	    int longest_length = 1;
	```
	Initializes the longest_length variable to 1, as the shortest subsequence will have at least one word.

5. **Outer Loop**
	```cpp
	    for (int i = 1; i < n; i++) {
	```
	Starts the outer loop to go through each word starting from the second word.

6. **Inner Loop**
	```cpp
	        for (int j = 0; j < i; j++) {
	```
	Starts the inner loop to compare the current word with all previous words.

7. **Condition Check**
	```cpp
	            if (groups[i] == groups[j]) continue;
	```
	Skips comparing words in the same group as they should belong to different groups.

8. **Condition Check**
	```cpp
	            if (words[i].size() != words[j].size()) continue;
	```
	Skips comparing words that are of different lengths since their Hamming distance cannot be 1.

9. **Distance Check**
	```cpp
	            if (getHammingDistance(words[i], words[j]) != 1) continue;
	```
	Skips comparing words that do not have a Hamming distance of 1.

10. **Subsequence Update**
	```cpp
	            if ((dp[j].size() + 1) > dp[i].size()) {
	```
	If adding the current word to the subsequence at dp[j] results in a longer subsequence, update dp[i].

11. **Subsequence Update**
	```cpp
	                dp[i] = dp[j];
	```
	Copy the subsequence from dp[j] to dp[i], as dp[j] gives a longer subsequence.

12. **Subsequence Update**
	```cpp
	                dp[i].push_back(i);
	```
	Add the current word's index to the subsequence at dp[i].

13. **Length Update**
	```cpp
	                longest_length = max(longest_length, int(dp[i].size()));
	```
	Update the longest subsequence length if the current subsequence at dp[i] is longer.

14. **Result Construction**
	```cpp
	    vector<string> result;
	```
	Initializes the result vector to store the words in the longest subsequence.

15. **Result Construction**
	```cpp
	    for (int i = 0; i < n; i++) {
	```
	Loops through the dp array to find the subsequence that has the longest length.

16. **Result Construction**
	```cpp
	        if (dp[i].size() == longest_length) {
	```
	Checks if the current subsequence is the longest, and if so, proceeds to construct the result.

17. **Result Construction**
	```cpp
	            for (const int& x : dp[i]) result.push_back(words[x]);
	```
	Adds the words from the longest subsequence to the result vector.

18. **Result Construction**
	```cpp
	            break;
	```
	Breaks the loop after finding the longest subsequence.

19. **Return Result**
	```cpp
	    return result;
	```
	Returns the longest subsequence of words.

20. **Private Function**
	```cpp
	private:
	```
	Marks the start of a private helper function.

21. **Helper Function**
	```cpp
	int getHammingDistance(const string& s, const string& t) {
	```
	Defines the helper function to calculate the Hamming distance between two strings.

22. **Variable Initialization**
	```cpp
	    int dist = 0;
	```
	Initializes the dist variable to count the Hamming distance.

23. **Loop Setup**
	```cpp
	    int k = s.size();
	```
	Gets the size of the strings to iterate over each character.

24. **Loop Setup**
	```cpp
	    for (int i = 0; i < k; i++) {
	```
	Starts the loop to compare characters of the two strings.

25. **Distance Calculation**
	```cpp
	        if (s[i] != t[i]) dist++;
	```
	Increments the distance for each mismatched character.

26. **Return Statement**
	```cpp
	    return dist;
	```
	Returns the calculated Hamming distance.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

In the worst case, every word is compared to every other word.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n^2)

The space complexity depends on the size of the DP table which can grow up to O(n^2) in the worst case.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/description/)

---
{{< youtube DJaTr0BnG1Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
