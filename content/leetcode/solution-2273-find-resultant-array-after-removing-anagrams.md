
+++
authors = ["grid47"]
title = "Leetcode 2273: Find Resultant Array After Removing Anagrams"
date = "2024-03-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2273: Find Resultant Array After Removing Anagrams in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "AdiW8KjFiyg"
youtube_upload_date="2022-05-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/AdiW8KjFiyg/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed string array `words`, where each element of `words[i]` consists of lowercase English letters. In one operation, you can delete any word `words[i]` if it is an anagram of the previous word `words[i-1]`. Repeat this operation until no more deletions are possible. Your task is to return the list of words after performing all possible operations.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single list of strings `words`, each representing a word of lowercase English letters.
- **Example:** `words = ['abcd', 'abdc', 'dabc', 'xyz', 'zyx']`
- **Constraints:**
	- 1 <= words.length <= 100
	- 1 <= words[i].length <= 10
	- words[i] consists of lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the final list of words after all possible operations are performed.
- **Example:** `Output: ['abcd', 'xyz']`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To remove words that are anagrams of the previous word in the list by repeatedly checking adjacent words.

- Iterate through the list of words.
- For each word, check if it is an anagram of the previous word. If so, remove the current word.
- Repeat until no more words can be removed.
{{< dots >}}
### Problem Assumptions ✅
- The words are non-empty, and every string contains only lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `words = ['abcd', 'abdc', 'dabc', 'xyz', 'zyx']`  \
  **Explanation:** In this example, 'abdc' and 'dabc' are anagrams of 'abcd', so they are deleted. Similarly, 'zyx' is an anagram of 'xyz' and is deleted. The final result is ['abcd', 'xyz'].

- **Input:** `words = ['cat', 'tac', 'act', 'dog']`  \
  **Explanation:** All words except 'dog' are anagrams of each other and can be deleted, resulting in ['dog'] as the final answer.

{{< dots >}}
## Approach 🚀
The problem can be solved by iterating through the list of words and checking whether each word is an anagram of the previous one. We can utilize sorting or frequency count of characters to identify anagrams.

### Initial Thoughts 💭
- We need to check if adjacent words are anagrams.
- A simple approach is to sort the characters of each word and compare the sorted strings. If two words are anagrams, they will have the same sorted version.
{{< dots >}}
### Edge Cases 🌐
- An empty list of words should return an empty list.
- For large inputs, the solution should handle lists with up to 100 words and each word being up to 10 characters long.
- Words that are already distinct, where no operations are performed.
- The solution must work within the provided constraints for both time and space.
{{< dots >}}
## Code 💻
```cpp
vector<string> removeAnagrams(vector<string>& A) {
    vector<string> ans;
    int n= size(A);
    for(int i=0;i<n;){
        int j=i+1;
        while( j<n and isang(A[i],A[j]) ) j++;
        ans.push_back(A[i]);
        i=j;
    }
    return ans;
}
//function for checking if two string are anagrams or not
bool isang(string p,string q){
    vector<int> cnt(26);
    int res=0;
    for(auto i:p) cnt[i-'a']++;
    for(auto i:q) cnt[i-'a']--;         
    for(auto i:cnt) if(i!=0) return false;
    return true;
}
```

This code defines a function `removeAnagrams` that removes consecutive anagrams from a list of strings. It also includes a helper function `isang` that checks whether two strings are anagrams of each other by comparing the frequency of each character.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<string> removeAnagrams(vector<string>& A) {
	```
	This is the function header for `removeAnagrams`, which takes a reference to a vector of strings `A` and returns a vector of strings after removing consecutive anagrams.

2. **Variable Initialization**
	```cpp
	    vector<string> ans;
	```
	Initializes an empty vector `ans` to store the results (strings after removing anagrams).

3. **Variable Initialization**
	```cpp
	    int n= size(A);
	```
	Initializes `n` to the size of the input vector `A`, which is the number of strings in the list.

4. **Loop Start**
	```cpp
	    for(int i=0;i<n;){
	```
	Starts a loop to iterate over the vector `A` and process each string while checking for consecutive anagrams.

5. **Variable Initialization**
	```cpp
	        int j=i+1;
	```
	Initializes `j` to `i+1`, which will be used to check the next string in the vector `A`.

6. **Inner Loop**
	```cpp
	        while( j<n and isang(A[i],A[j]) ) j++;
	```
	Uses a while loop to find consecutive anagrams. The function `isang` is used to check if `A[i]` and `A[j]` are anagrams. If they are, it increments `j`.

7. **Result Update**
	```cpp
	        ans.push_back(A[i]);
	```
	Pushes the current string `A[i]` into the result vector `ans` because it is not an anagram of the previous string.

8. **Pointer Update**
	```cpp
	        i=j;
	```
	Updates `i` to `j`, moving the pointer to the next string after the consecutive anagrams are removed.

9. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the vector `ans`, which contains the strings with consecutive anagrams removed.

10. **Function Declaration**
	```cpp
	bool isang(string p,string q){
	```
	This is the function header for `isang`, which checks if two strings `p` and `q` are anagrams.

11. **Variable Initialization**
	```cpp
	    vector<int> cnt(26);
	```
	Initializes a vector `cnt` of size 26 to store the frequency count of each character (assuming lowercase English letters).

12. **Variable Initialization**
	```cpp
	    int res=0;
	```
	Initializes `res` to zero, though it is not used in the function and could be removed.

13. **Count Characters**
	```cpp
	    for(auto i:p) cnt[i-'a']++;
	```
	Iterates over each character in string `p` and increments the corresponding position in the `cnt` vector to count the frequency of each character.

14. **Count Characters**
	```cpp
	    for(auto i:q) cnt[i-'a']--;         
	```
	Iterates over each character in string `q` and decrements the corresponding position in the `cnt` vector to account for the characters in `q`.

15. **Anagram Check**
	```cpp
	    for(auto i:cnt) if(i!=0) return false;
	```
	Checks the `cnt` vector to see if there are any non-zero values. If there are, it means the strings are not anagrams, and the function returns `false`.

16. **Return Statement**
	```cpp
	    return true;
	```
	If all counts are zero, the function returns `true`, indicating the strings are anagrams.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n * m log m)
- **Worst Case:** O(n * m log m)

The worst-case time complexity is O(n * m log m), where n is the number of words and m is the maximum length of a word. Sorting each word takes O(m log m) time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n * m)

The space complexity is O(n * m) due to the space required for storing the sorted words.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/description/)

---
{{< youtube AdiW8KjFiyg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
