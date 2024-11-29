
+++
authors = ["grid47"]
title = "Leetcode 2900: Longest Unequal Adjacent Groups Subsequence I"
date = "2024-01-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2900: Longest Unequal Adjacent Groups Subsequence I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Dynamic Programming","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "IJzs5-NDAxc"
youtube_upload_date="2023-10-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/IJzs5-NDAxc/maxresdefault.webp"
comments = true
+++



---
You are given two arrays: `words` (a list of distinct strings) and `groups` (a binary array where each element corresponds to an entry in `words`). Your task is to select the longest alternating subsequence of words, where each consecutive word has a different corresponding group value. For each pair of consecutive words in the subsequence, the corresponding values in `groups` must be different.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays: `words` (a list of distinct strings) and `groups` (a binary array of integers corresponding to each word).
- **Example:** `["apple","banana","cherry"]`
- **Constraints:**
	- 1 <= n <= 100
	- 1 <= words[i].length <= 10
	- groups[i] is either 0 or 1
	- words consists of distinct strings

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the longest alternating subsequence of words, where adjacent elements have non-matching corresponding group values in `groups`.
- **Example:** `["apple","banana"]`
- **Constraints:**
	- The output should be a valid subsequence from the given `words` array.

{{< dots >}}
### Core Logic 🔍
**Goal:** Select the longest alternating subsequence from `words` where consecutive words have different group values.

- Initialize an empty list `ans` to store the subsequence.
- Initialize a variable `flag` to -1 to track the last added group's value.
- Iterate through the `words` array.
- For each word, if its group value is different from `flag`, add it to `ans` and update `flag`.
{{< dots >}}
### Problem Assumptions ✅
- The input contains distinct words.
- The group array has a corresponding entry for each word in `words`.
{{< dots >}}
## Examples 🧩
- **Input:** `["apple","banana","cherry"]`  \
  **Explanation:** We start by picking the first word and alternating between different group values. We skip consecutive words with the same group.

{{< dots >}}
## Approach 🚀
Iterate through the `words` array, keeping track of the most recent group value and adding words to the result list if their group differs from the last added word.

### Initial Thoughts 💭
- The problem involves iterating through the list of words and checking the group values to maintain an alternating sequence.
- We can solve this efficiently in one pass by keeping track of the last group used.
{{< dots >}}
### Edge Cases 🌐
- The input is guaranteed to have at least one word.
- For large inputs, the algorithm should handle up to 100 elements in `words` efficiently.
- If all words belong to the same group, the result will contain only one word.
- The constraints guarantee that the solution will work within the limits provided.
{{< dots >}}
## Code 💻
```cpp
vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
    // Edges 0->1 / 1 -> 0, start has no conseq
    vector<string>ans;
    int flag=-1;
    for(int i=0;i<n;i++){
        if(groups[i]!=flag){
            flag=groups[i];
            ans.push_back(words[i]);
        }
    }
    return ans;
}
```

This function processes a list of words and groups, returning the longest subsequence where words in the same group are adjacent. The sequence is built by checking the changes in group assignments.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
	```
	This line defines a function that takes the number of words, a list of words, and a list of group identifiers. It returns a vector of strings representing the longest subsequence of words grouped together.

2. **Variable Initialization**
	```cpp
	    vector<string>ans;
	```
	This line initializes an empty vector 'ans' to store the result, which will be the longest subsequence of words.

3. **Variable Initialization**
	```cpp
	    int flag=-1;
	```
	This line initializes a variable 'flag' to -1. It will be used to track the current group identifier and detect changes between groups.

4. **Loop**
	```cpp
	    for(int i=0;i<n;i++){
	```
	This loop iterates through all words in the input list. The index 'i' is used to access each word and group.

5. **Condition Check**
	```cpp
	        if(groups[i]!=flag){
	```
	This condition checks if the current word belongs to a different group than the previous word (tracked by 'flag').

6. **Group Assignment**
	```cpp
	            flag=groups[i];
	```
	If the condition is true, the 'flag' is updated to the current group's identifier.

7. **Action**
	```cpp
	            ans.push_back(words[i]);
	```
	If the group changes, the current word is added to the result vector 'ans'.

8. **Return**
	```cpp
	    return ans;
	```
	This line returns the result vector 'ans', which contains the longest subsequence of words grouped together.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we process each word in the `words` array once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) as we store the result in the `ans` list.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/)

---
{{< youtube IJzs5-NDAxc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
