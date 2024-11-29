
+++
authors = ["grid47"]
title = "Leetcode 2516: Take K of Each Character From Left and Right"
date = "2024-02-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2516: Take K of Each Character From Left and Right in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "QI4kCksMru0"
youtube_upload_date="2022-12-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QI4kCksMru0/maxresdefault.webp"
comments = true
+++



---
You are given a string `s` consisting of the characters 'a', 'b', and 'c', and a non-negative integer `k`. Each minute, you can choose to take either the leftmost or the rightmost character from `s`. Your task is to determine the minimum number of minutes required to collect at least `k` occurrences of each character ('a', 'b', and 'c'). If it is not possible to collect `k` of each character, return `-1`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string `s` consisting of only the letters 'a', 'b', and 'c', and a non-negative integer `k`.
- **Example:** `s = "abcabcabc", k = 2`
- **Constraints:**
	- 1 <= s.length <= 10^5
	- s consists of only the letters 'a', 'b', and 'c'.
	- 0 <= k <= s.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of minutes required to take at least `k` of each character, or -1 if it is not possible.
- **Example:** `Output: 6`
- **Constraints:**
	- If it's not possible to take `k` of each character, return -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to compute the minimum number of minutes required to collect at least `k` occurrences of each character from the string `s`.

- Count the occurrences of each character in `s`.
- If there are less than `k` occurrences of any character ('a', 'b', or 'c'), return -1.
- Use a sliding window technique to find the minimum subarray that contains at least `k` occurrences of each character.
- Return the size of this subarray, or -1 if no such subarray exists.
{{< dots >}}
### Problem Assumptions ✅
- The input string `s` contains only the characters 'a', 'b', and 'c'.
- The integer `k` is non-negative and less than or equal to the length of the string.
{{< dots >}}
## Examples 🧩
- **Input:** `s = "abcabcabc", k = 2`  \
  **Explanation:** We need to find the shortest time to collect at least 2 occurrences of each character. By taking 3 characters from the left and 3 characters from the right, we can collect 2 'a's, 2 'b's, and 2 'c's in a total of 6 minutes.

- **Input:** `s = "aaa", k = 2`  \
  **Explanation:** Since there are no 'b' or 'c' characters in the string, it is impossible to collect at least 2 of each character, so the answer is -1.

{{< dots >}}
## Approach 🚀
The goal is to find the minimum number of minutes required to collect at least `k` of each character ('a', 'b', and 'c').

### Initial Thoughts 💭
- We can use a sliding window approach to find the shortest subarray containing the required characters.
- If we can't find a subarray with the required characters, return -1.
- The problem is essentially about finding the minimum window containing all the required characters.
{{< dots >}}
### Edge Cases 🌐
- If `s` is empty, return -1.
- Ensure the solution works efficiently for large inputs (up to 10^5 characters).
- If `k` is 0, the result should be 0 because no characters need to be collected.
- Ensure that the sliding window approach handles all edge cases.
{{< dots >}}
## Code 💻
```cpp
int takeCharacters(string s, int k) {
    
    map<char, int> mp;
    for(int i = 0; i < s.size(); i++)
        mp[s[i]]++;
    if(mp['a'] < k || mp['b'] < k || mp['c'] < k) return -1;
    
    int j = 0, mx = 0;
    for(int i = 0; i < s.size(); i++) {
        // select max window which does not decrements frq below k;
        mp[s[i]]--;
        while(j <= i && mp[s[i]] < k) {
            mp[s[j]]++;
            j++;
        }
        mx = max(mx, i - j + 1);
    }
    return s.size() - mx;
}
```

This function calculates the minimum number of characters to be removed from a string so that all characters in the string appear at least 'k' times.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int takeCharacters(string s, int k) {
	```
	Define the function `takeCharacters`, which takes a string `s` and an integer `k` as parameters, and returns the minimum number of characters to remove to make the frequency of all characters at least `k`.

2. **Map Initialization**
	```cpp
	    map<char, int> mp;
	```
	Initialize a map `mp` to store the frequency of each character in the string.

3. **Loop**
	```cpp
	    for(int i = 0; i < s.size(); i++)
	```
	Iterate through each character in the string `s`.

4. **Frequency Counting**
	```cpp
	        mp[s[i]]++;
	```
	Increment the frequency count of the current character in the map.

5. **Condition Check**
	```cpp
	    if(mp['a'] < k || mp['b'] < k || mp['c'] < k) return -1;
	```
	Check if any of the characters 'a', 'b', or 'c' appear fewer than `k` times. If true, return -1 as it's not possible to achieve the condition.

6. **Variable Initialization**
	```cpp
	    int j = 0, mx = 0;
	```
	Initialize two variables: `j` to represent the left boundary of the sliding window, and `mx` to store the maximum valid window size.

7. **Sliding Window**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	Start a second loop to iterate over the string, using a sliding window approach to find the largest window where all characters meet the frequency requirement.

8. **Decrement Frequency**
	```cpp
	        mp[s[i]]--;
	```
	Decrement the frequency of the current character as it's included in the window.

9. **Sliding Window Adjustment**
	```cpp
	        while(j <= i && mp[s[i]] < k) {
	```
	Start a while loop to move the left boundary `j` forward to maintain the frequency condition for all characters in the window.

10. **Increment Frequency**
	```cpp
	            mp[s[j]]++;
	```
	Increment the frequency of the character at the left boundary `j` since it's being excluded from the window.

11. **Window Adjustment**
	```cpp
	            j++;
	```
	Move the left boundary `j` forward to shrink the window.

12. **Max Window Size**
	```cpp
	        mx = max(mx, i - j + 1);
	```
	Update the maximum valid window size if the current window is larger than the previously found windows.

13. **Return Statement**
	```cpp
	    return s.size() - mx;
	```
	Return the number of characters to be removed, which is the total length of the string minus the size of the largest valid window.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We use a sliding window technique, which processes each character once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

We only need a fixed amount of space for the character counts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/)

---
{{< youtube QI4kCksMru0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
