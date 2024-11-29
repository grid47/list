
+++
authors = ["grid47"]
title = "Leetcode 2531: Make Number of Distinct Characters Equal"
date = "2024-02-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2531: Make Number of Distinct Characters Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MoYeUVe-xPY"
youtube_upload_date="2023-01-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/MoYeUVe-xPY/maxresdefault.webp"
comments = true
+++



---
You are given two strings, `word1` and `word2`. In each move, you swap one character from `word1` with one from `word2`. Determine if it is possible to make the number of distinct characters in both strings equal with exactly one swap.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings `word1` and `word2`.
- **Example:** `"abcc", "aab"`
- **Constraints:**
	- 1 <= word1.length, word2.length <= 10^5
	- Both word1 and word2 consist of only lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a boolean value indicating whether it is possible to make the number of distinct characters in both strings equal with exactly one swap.
- **Example:** `true`
- **Constraints:**
	- The output will be either `true` or `false`.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine if it is possible to make the number of distinct characters in both strings equal with exactly one swap.

- Count the distinct characters in both strings `word1` and `word2`.
- For each character in `word1` and `word2`, attempt to swap characters and check if the number of distinct characters in both strings becomes equal.
- Return `true` if a swap results in equal distinct character counts, otherwise return `false`.
{{< dots >}}
### Problem Assumptions ✅
- You are guaranteed that both strings contain only lowercase English letters.
{{< dots >}}
## Examples 🧩
- **Input:** `"ac", "b"`  \
  **Explanation:** In this case, swapping any characters between the two strings will not make the number of distinct characters in both strings equal.

- **Input:** `"abcc", "aab"`  \
  **Explanation:** After swapping index 2 of `word1` with index 0 of `word2`, both strings will have 3 distinct characters.

- **Input:** `"abcd", "efgh"`  \
  **Explanation:** Both strings already have 4 distinct characters, so swapping any character will not affect the result.

{{< dots >}}
## Approach 🚀
The approach involves counting the distinct characters in both strings and then checking if swapping any characters can equalize the distinct character count.

### Initial Thoughts 💭
- We need to efficiently check the distinct characters in both strings.
- The solution needs to handle large strings, so an O(n) solution for checking distinct characters is ideal.
{{< dots >}}
### Edge Cases 🌐
- The strings will not be empty, as the length of both strings is at least 1.
- Ensure that the solution handles strings with lengths up to 100,000 characters.
- Handle cases where all characters in one or both strings are the same.
- The solution should be optimized for time complexity, given the constraints of up to 100,000 characters.
{{< dots >}}
## Code 💻
```cpp
bool isItPossible(string w1, string w2) {
    
    map<char, int> ma1, ma2;
    for(int x: w1)
        ma1[x]++;
    for(int x: w2)
        ma2[x]++;
    
    for(auto it1: ma1) {
        for(auto it2: ma2) {
            map<char, int> d1 = ma1, d2 = ma2;
            d1[it2.first]++;
            d2[it1.first]++;
            
            d1[it1.first]--;
            d2[it2.first]--;
            
            if(d1[it1.first] == 0)
                d1.erase(it1.first);
            if(d2[it2.first] == 0)
                d2.erase(it2.first);
            
            if(d1.size() == d2.size()) return true;
        }
    }
    return false;
}
```

The 'isItPossible' function checks if two strings 'w1' and 'w2' can be made anagrams by swapping characters between the two. It uses maps to count character occurrences and then attempts to match the counts.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isItPossible(string w1, string w2) {
	```
	The function 'isItPossible' is defined, accepting two strings 'w1' and 'w2'. It will return a boolean value indicating whether it's possible to make the strings anagrams by swapping characters.

2. **Variable Initialization**
	```cpp
	    map<char, int> ma1, ma2;
	```
	Two maps, 'ma1' and 'ma2', are initialized to count the occurrences of characters in 'w1' and 'w2' respectively.

3. **Loop**
	```cpp
	    for(int x: w1)
	```
	A for loop begins to iterate over the characters of the string 'w1'.

4. **Map Operation**
	```cpp
	        ma1[x]++;
	```
	For each character in 'w1', the corresponding count is incremented in the map 'ma1'.

5. **Loop**
	```cpp
	    for(int x: w2)
	```
	A similar loop starts for the string 'w2', iterating over each character.

6. **Map Operation**
	```cpp
	        ma2[x]++;
	```
	For each character in 'w2', the corresponding count is incremented in the map 'ma2'.

7. **Loop**
	```cpp
	    for(auto it1: ma1) {
	```
	A for loop begins to iterate over each element of 'ma1' (character-frequency pair).

8. **Loop**
	```cpp
	        for(auto it2: ma2) {
	```
	A nested for loop begins to iterate over each element of 'ma2' (character-frequency pair).

9. **Variable Assignment**
	```cpp
	            map<char, int> d1 = ma1, d2 = ma2;
	```
	Two temporary maps 'd1' and 'd2' are created as copies of 'ma1' and 'ma2'. These will be modified during the comparison.

10. **Map Update**
	```cpp
	            d1[it2.first]++;
	```
	The count of the character from 'it2' in 'd1' is incremented.

11. **Map Update**
	```cpp
	            d2[it1.first]++;
	```
	Similarly, the count of the character from 'it1' in 'd2' is incremented.

12. **Map Update**
	```cpp
	            d1[it1.first]--;
	```
	The count of the character from 'it1' in 'd1' is decremented.

13. **Map Update**
	```cpp
	            d2[it2.first]--;
	```
	Similarly, the count of the character from 'it2' in 'd2' is decremented.

14. **Condition Check**
	```cpp
	            if(d1[it1.first] == 0)
	```
	A check is performed to see if the frequency of the character 'it1.first' in 'd1' is zero.

15. **Map Operation**
	```cpp
	                d1.erase(it1.first);
	```
	If the frequency is zero, the character 'it1.first' is removed from 'd1'.

16. **Condition Check**
	```cpp
	            if(d2[it2.first] == 0)
	```
	A similar check is performed for the character 'it2.first' in 'd2'.

17. **Map Operation**
	```cpp
	                d2.erase(it2.first);
	```
	If the frequency is zero, the character 'it2.first' is removed from 'd2'.

18. **Condition Check**
	```cpp
	            if(d1.size() == d2.size()) return true;
	```
	If the sizes of 'd1' and 'd2' are equal, it means the strings can be rearranged to form anagrams by swapping characters. The function returns true.

19. **Return Statement**
	```cpp
	    return false;
	```
	If no matching swaps were found after all iterations, the function returns false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the length of the strings since we perform operations that are linear in nature.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the use of maps for counting characters.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/make-number-of-distinct-characters-equal/description/)

---
{{< youtube MoYeUVe-xPY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
