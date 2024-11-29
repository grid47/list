
+++
authors = ["grid47"]
title = "Leetcode 2904: Shortest and Lexicographically Smallest Beautiful String"
date = "2024-01-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2904: Shortest and Lexicographically Smallest Beautiful String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FhAuoztsceo"
youtube_upload_date="2023-10-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/FhAuoztsceo/maxresdefault.webp"
comments = true
+++



---
You are given a binary string `s` and a positive integer `k`. A substring of `s` is considered 'beautiful' if it contains exactly `k` occurrences of '1'. Your task is to return the lexicographically smallest substring of the shortest length that has exactly `k` '1's. If no such substring exists, return an empty string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary string `s` and a positive integer `k`. The length of the string `s` is at least 1 and at most 100, and `k` is a positive integer such that `1 <= k <= s.length`.
- **Example:** `s = '11010101', k = 3`
- **Constraints:**
	- 1 <= s.length <= 100
	- 1 <= k <= s.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the lexicographically smallest beautiful substring of the shortest length that contains exactly `k` '1's, or an empty string if no such substring exists.
- **Example:** `'10101'`
- **Constraints:**
	- If no beautiful substring exists, return an empty string.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the lexicographically smallest substring that contains exactly `k` '1's.

- 1. Iterate through the binary string `s` while maintaining a count of '1's.
- 2. Whenever the count reaches `k`, check if the current substring is valid and potentially update the result if it is the shortest or lexicographically smaller than any previous valid substring.
- 3. Return the lexicographically smallest substring with the minimum length, or an empty string if no such substring is found.
{{< dots >}}
### Problem Assumptions ✅
- The input string `s` contains only '0's and '1's.
- The integer `k` is valid, i.e., `1 <= k <= s.length`.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: '11010101', k = 3`  \
  **Explanation:** In this case, the valid substrings with exactly 3 '1's are ['11010101', '1010101', '010101', '10101']. The shortest substring is '10101', which is also the lexicographically smallest substring.

- **Input:** `Input: '11100', k = 2`  \
  **Explanation:** Here, the valid substrings with exactly 2 '1's are ['11100', '110', '11']. The shortest valid substring is '11'.

{{< dots >}}
## Approach 🚀
To solve the problem, iterate through the string `s` while counting the occurrences of '1'. Each time the count reaches `k`, check for a valid substring and compare it with previous substrings to keep track of the shortest and lexicographically smallest one.

### Initial Thoughts 💭
- We need to keep track of the position of the '1's in the string and check substrings whenever the count of '1's reaches `k`.
- We can use a sliding window approach to find substrings efficiently by expanding and contracting the window while maintaining the count of '1's.
{{< dots >}}
### Edge Cases 🌐
- If the string `s` contains no '1's and `k` > 0, return an empty string.
- Handle strings up to the maximum length of 100 efficiently.
- Consider the case where `k` is equal to the length of `s`.
- Ensure that the algorithm works within the given constraints and edge cases.
{{< dots >}}
## Code 💻
```cpp
string shortestBeautifulSubstring(string s, int k) {
    
    int n = s.size();
    string ans = "";
    int j = 0, cnt = 0;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1') cnt++;

        while( j < n && cnt == k )
        {
            string tmp = s.substr(j, i - j + 1);

            if(ans.size()==0 || tmp.size() < ans.size()) ans = tmp;
            else if(tmp.size() == ans.size()) ans = min(ans, tmp);

            if(s[j] == '1') cnt--;

            j++;
        }
    }

    return ans;        
    
}
```

This function returns the shortest substring that contains exactly `k` occurrences of the character '1'. It uses a sliding window approach to find the optimal solution.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string shortestBeautifulSubstring(string s, int k) {
	```
	Defines the function `shortestBeautifulSubstring` which takes a string `s` and an integer `k`, and returns the shortest substring containing exactly `k` occurrences of the character '1'.

2. **Variable Initialization**
	```cpp
	    int n = s.size();
	```
	Initializes variable `n` to store the size of the input string `s`.

3. **String Initialization**
	```cpp
	    string ans = "";
	```
	Initializes an empty string `ans` to store the result of the shortest beautiful substring.

4. **Variable Initialization**
	```cpp
	    int j = 0, cnt = 0;
	```
	Initializes two variables: `j` as the starting index for the sliding window and `cnt` to count the number of '1's in the current window.

5. **Loop Initialization**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Starts a loop to iterate through the string `s` from index 0 to `n - 1`.

6. **Count '1's**
	```cpp
	        if(s[i] == '1') cnt++;
	```
	Increments the count `cnt` each time the character '1' is encountered in the string.

7. **Sliding Window**
	```cpp
	        while( j < n && cnt == k )
	```
	Checks if the current window contains exactly `k` occurrences of '1'. If true, proceeds to the next step to evaluate the substring.

8. **Sliding Window Body**
	```cpp
	        {
	```
	Begins the inner loop to handle the case when there are exactly `k` '1's in the current window.

9. **Substring Extraction**
	```cpp
	            string tmp = s.substr(j, i - j + 1);
	```
	Extracts the current substring from index `j` to `i`.

10. **Shortest Substring Update**
	```cpp
	            if(ans.size()==0 || tmp.size() < ans.size()) ans = tmp;
	```
	If `ans` is empty or the length of `tmp` is smaller than the length of `ans`, update `ans` to the value of `tmp`.

11. **Substring Comparison**
	```cpp
	            else if(tmp.size() == ans.size()) ans = min(ans, tmp);
	```
	If the length of `tmp` is equal to the length of `ans`, select the lexicographically smallest string between `ans` and `tmp`.

12. **Count Update**
	```cpp
	            if(s[j] == '1') cnt--;
	```
	Decrements the count `cnt` when the character at index `j` is '1', as it will be excluded from the window when `j` is incremented.

13. **Window Slide**
	```cpp
	            j++;
	```
	Increments `j` to shrink the window from the left side.

14. **Sliding Window End**
	```cpp
	        }
	```
	Ends the inner `while` loop after adjusting the sliding window.

15. **Return Result**
	```cpp
	    return ans;        
	```
	Returns the shortest beautiful substring stored in `ans`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), as we iterate through the string once, checking substrings efficiently.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) in the worst case when storing substrings and results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/description/)

---
{{< youtube FhAuoztsceo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
