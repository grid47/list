
+++
authors = ["grid47"]
title = "Leetcode 2559: Count Vowel Strings in Ranges"
date = "2024-02-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2559: Count Vowel Strings in Ranges in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "hTXRevcm3kI"
youtube_upload_date="2023-02-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/hTXRevcm3kI/maxresdefault.webp"
comments = true
+++



---
Given an array of strings `words` and a list of queries, each query asks to count the number of strings in the specified range that start and end with a vowel. The vowels are 'a', 'e', 'i', 'o', and 'u'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array of strings `words` and a list of queries where each query specifies a range of indices in `words`.
- **Example:** `words = ["aba", "bcb", "ace", "aa", "e"], queries = [[0,2],[1,4],[1,1]]`
- **Constraints:**
	- 1 <= words.length <= 10^5
	- 1 <= words[i].length <= 40
	- sum(words[i].length) <= 3 * 10^5
	- 1 <= queries.length <= 10^5
	- 0 <= li <= ri < words.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of integers where each element is the count of valid strings (those starting and ending with a vowel) in the given range for each query.
- **Example:** `[2, 3, 0]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To efficiently compute the number of valid strings in the range for each query, we preprocess the input to allow fast queries.

- 1. Iterate over the words and determine if they start and end with a vowel.
- 2. Maintain a prefix sum array to quickly compute the count of valid words in any given range.
- 3. For each query, compute the difference between the prefix sums at the range boundaries.
{{< dots >}}
### Problem Assumptions ✅
- Words consist only of lowercase English letters.
- Each query is valid, i.e., 0 <= li <= ri < words.length.
{{< dots >}}
## Examples 🧩
- **Input:** `words = ["aba", "bcb", "ace", "aa", "e"], queries = [[0,2],[1,4],[1,1]]`  \
  **Explanation:** The valid strings are 'aba', 'ace', 'aa', and 'e'. The answers to the queries are 2, 3, and 0 respectively.

- **Input:** `words = ["a", "e", "i"], queries = [[0,2],[0,1],[2,2]]`  \
  **Explanation:** All the strings satisfy the condition of starting and ending with vowels. Hence, the answers to the queries are 3, 2, and 1 respectively.

{{< dots >}}
## Approach 🚀
The solution uses a prefix sum approach to efficiently calculate the number of valid words in the range of each query.

### Initial Thoughts 💭
- We need a way to quickly determine the number of valid strings in a given range.
- Prefix sums can be used to answer range queries efficiently.
{{< dots >}}
### Edge Cases 🌐
- The array `words` is guaranteed to have at least one element.
- The solution must handle queries on large arrays efficiently.
- Words of length 1 are valid only if the word itself is a vowel.
- Ensure that the solution handles large inputs efficiently with up to 100,000 queries.
{{< dots >}}
## Code 💻
```cpp
vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
    int n = words.size();
    vector<int> cnt(n, 0), ans(q.size(), 0);
    set<char> ch = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < n; i++) {
        if(ch.count(words[i][0]) && ch.count(words[i][words[i].size() -1]))
            cnt[i] = 1;
        if(i > 0) cnt[i] += cnt[i - 1];
    }
    for(int i= 0; i < q.size(); i++) {
        ans[i] = cnt[q[i][1]] - ((q[i][0] > 0)? cnt[q[i][0] - 1]: 0);
    }
    return ans;
}
```

The function 'vowelStrings' takes a vector of words and a vector of queries. For each word, it checks if it starts and ends with a vowel. It then answers each query by counting how many words between two indices meet the condition of starting and ending with a vowel.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
	```
	The function 'vowelStrings' is defined to take two parameters: a vector of words and a vector of queries. It returns a vector of integers representing the result of each query.

2. **Word Count Initialization**
	```cpp
	    int n = words.size();
	```
	The size of the 'words' vector is stored in 'n', representing the number of words to process.

3. **Vector Initialization**
	```cpp
	    vector<int> cnt(n, 0), ans(q.size(), 0);
	```
	Two vectors are initialized: 'cnt' (to keep track of cumulative counts of words starting and ending with vowels) and 'ans' (to store the result of each query).

4. **Vowel Set Initialization**
	```cpp
	    set<char> ch = {'a', 'e', 'i', 'o', 'u'};
	```
	A set 'ch' is initialized containing the vowels. This set will be used to check if a word starts and ends with a vowel.

5. **Loop Over Words**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop starts that iterates over each word in the 'words' vector.

6. **Check Start and End Vowel**
	```cpp
	        if(ch.count(words[i][0]) && ch.count(words[i][words[i].size() -1]))
	```
	This condition checks if the first and last characters of the word are vowels by checking if they exist in the 'ch' set.

7. **Update Count**
	```cpp
	            cnt[i] = 1;
	```
	If the word starts and ends with a vowel, the corresponding position in the 'cnt' vector is set to 1.

8. **Cumulative Count Update**
	```cpp
	        if(i > 0) cnt[i] += cnt[i - 1];
	```
	This updates the cumulative count for the current word by adding the previous word's count to the current word's count, ensuring that 'cnt' holds the cumulative number of valid words up to each position.

9. **Loop Over Queries**
	```cpp
	    for(int i= 0; i < q.size(); i++) {
	```
	A loop starts to process each query in the 'q' vector.

10. **Answer Query**
	```cpp
	        ans[i] = cnt[q[i][1]] - ((q[i][0] > 0)? cnt[q[i][0] - 1]: 0);
	```
	For each query, the function computes the number of valid words between the given range by using the cumulative counts stored in 'cnt'. If the starting index is greater than 0, it subtracts the cumulative count at the previous index.

11. **Return Result**
	```cpp
	    return ans;
	```
	The function returns the 'ans' vector, which contains the results for each query.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + q), where n is the number of words and q is the number of queries.
- **Average Case:** O(n + q), as we preprocess the array in O(n) time and answer each query in constant time.
- **Worst Case:** O(n + q), where n is the number of words and q is the number of queries.



### Space Complexity 💾
- **Best Case:** O(n), as the space complexity depends on the number of words.
- **Worst Case:** O(n), where n is the number of words, as we store the prefix sum array.

The space complexity is dominated by the prefix sum array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-vowel-strings-in-ranges/description/)

---
{{< youtube hTXRevcm3kI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
