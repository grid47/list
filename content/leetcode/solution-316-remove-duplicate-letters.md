
+++
authors = ["grid47"]
title = "Leetcode 316: Remove Duplicate Letters"
date = "2024-10-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 316: Remove Duplicate Letters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/316.webp"
youtube = "HjvMWNHZBNI"
youtube_upload_date="2023-09-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/HjvMWNHZBNI/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/316.webp" 
    alt="A series of letters gently disappearing from a word, leaving only the unique letters softly glowing."
    caption="Solution to LeetCode 316: Remove Duplicate Letters Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a string 's', remove duplicate letters so that every letter appears once and only once. The result should be the smallest lexicographical order among all possible results.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string 's' that contains lowercase English letters.
- **Example:** `s = 'acdbac'`
- **Constraints:**
	- 1 <= s.length <= 10^4
	- s consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a string with no duplicate letters, and the smallest lexicographical order.
- **Example:** `'abcd'`
- **Constraints:**
	- The string should contain unique characters in lexicographical order.

{{< dots >}}
### Core Logic 🔍
**Goal:** To remove duplicate characters while ensuring the resulting string is lexicographically smallest.

- Traverse the string and count the frequency of each character.
- Maintain a stack to build the result string, ensuring lexicographical order by popping characters from the stack when necessary.
- Ensure that each character is only added once to the result string.
{{< dots >}}
### Problem Assumptions ✅
- The input string 's' is guaranteed to contain only lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'acdbac'`  \
  **Explanation:** Removing the duplicate 'a', 'c', and 'b' results in the lexicographically smallest string 'abcd'.

- **Input:** `s = 'zxyzyx'`  \
  **Explanation:** The lexicographically smallest string without duplicates is 'xyz'.

{{< dots >}}
## Approach 🚀
To solve this problem, use a greedy algorithm with a stack to ensure that the string is both unique and lexicographically smallest.

### Initial Thoughts 💭
- The string needs to maintain its smallest lexicographical order while removing duplicates.
- We can use a stack to build the result string, popping elements from the stack when a smaller element appears and is guaranteed to appear later.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty, as the length of the string is at least 1.
- The solution must efficiently handle strings with lengths up to 10^4.
- If the string is already unique, it should be returned unchanged.
- Ensure that the algorithm works in O(n) time to handle the upper constraint.
{{< dots >}}
## Code 💻
```cpp
string removeDuplicateLetters(string s) {

    vector<int> frq(26, 0), lidx(26, 0);

    for (int i = 0; i < s.size(); i++) {
        char x = s[i];
        frq[x - 'a']++;
        lidx[x - 'a'] = i;
    }

    vector<bool> seen(26, false);
    stack<char> st;

    for(int i = 0; i < s.size(); i++) {

        int cur = s[i] - 'a';            
        if(seen[cur]) continue;

        while(st.size() > 0 && st.top() > s[i] && i < lidx[st.top() - 'a']) {
            seen[st.top() - 'a'] = false;
            st.pop();
        }

        st.push(s[i]);
        seen[cur] = true;
    }

    string ans = "";
    while(st.size() > 0) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
```

The function removes duplicate letters from a string while maintaining the order of characters.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string removeDuplicateLetters(string s) {
	```
	This is the function definition, where a string `s` is passed as input.

2. **Initialization**
	```cpp
	    vector<int> frq(26, 0), lidx(26, 0);
	```
	Initialize two vectors: `frq` for character frequency and `lidx` for the last index of each character.

3. **Loop**
	```cpp
	    for (int i = 0; i < s.size(); i++) {
	```
	Iterate through the string `s` to populate the frequency and last index vectors.

4. **Character Processing**
	```cpp
	        char x = s[i];
	```
	Extract each character from the string during the iteration.

5. **Frequency Update**
	```cpp
	        frq[x - 'a']++;
	```
	Increment the frequency of the current character in the `frq` vector.

6. **Last Index Update**
	```cpp
	        lidx[x - 'a'] = i;
	```
	Update the last index of the current character in the `lidx` vector.

7. **Seen Initialization**
	```cpp
	    vector<bool> seen(26, false);
	```
	Initialize a `seen` vector to track whether a character has been added to the result.

8. **Stack Initialization**
	```cpp
	    stack<char> st;
	```
	Initialize a stack to build the result string by storing characters.

9. **Loop**
	```cpp
	    for(int i = 0; i < s.size(); i++) {
	```
	Loop through the string `s` again to build the result string.

10. **Character Conversion**
	```cpp
	        int cur = s[i] - 'a';
	```
	Convert the current character to its respective index based on the alphabet.

11. **Check if Seen**
	```cpp
	        if(seen[cur]) continue;
	```
	If the character has already been added to the result, skip it.

12. **Stack Processing**
	```cpp
	        while(st.size() > 0 && st.top() > s[i] && i < lidx[st.top() - 'a']) {
	```
	Check if the top character in the stack can be removed while maintaining the order.

13. **Pop Stack**
	```cpp
	            seen[st.top() - 'a'] = false;
	```
	Mark the character being removed from the stack as unseen.

14. **Pop Stack**
	```cpp
	            st.pop();
	```
	Remove the character from the stack.

15. **Add to Stack**
	```cpp
	        st.push(s[i]);
	```
	Push the current character onto the stack.

16. **Mark Seen**
	```cpp
	        seen[cur] = true;
	```
	Mark the current character as seen.

17. **String Construction**
	```cpp
	    string ans = "";
	```
	Initialize an empty string to hold the final result.

18. **Result Construction**
	```cpp
	    while(st.size() > 0) {
	```
	Pop characters from the stack and append them to the result string.

19. **Append to Result**
	```cpp
	        ans += st.top();
	```
	Append the top character from the stack to the result string.

20. **Pop Stack**
	```cpp
	        st.pop();
	```
	Remove the top character from the stack.

21. **Reverse Result**
	```cpp
	    reverse(ans.begin(), ans.end());
	```
	Reverse the result string as the characters were added in reverse order.

22. **Return Result**
	```cpp
	    return ans;
	```
	Return the final result string with no duplicate letters.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the length of the string, as each character is processed once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the stack and character frequency counts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-duplicate-letters/description/)

---
{{< youtube HjvMWNHZBNI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
