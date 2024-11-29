
+++
authors = ["grid47"]
title = "Leetcode 1405: Longest Happy String"
date = "2024-06-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1405: Longest Happy String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "8u-H6O_XQKE"
youtube_upload_date="2022-02-23"
youtube_thumbnail="https://i.ytimg.com/vi/8u-H6O_XQKE/maxresdefault.jpg"
comments = true
+++



---
You are given three integers, a, b, and c, representing the maximum occurrences of 'a', 'b', and 'c' that can appear in a string. Your task is to return the longest string that can be formed using these letters such that it does not contain the substrings 'aaa', 'bbb', or 'ccc'. The string should contain at most a occurrences of 'a', at most b occurrences of 'b', and at most c occurrences of 'c'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of three integers: a, b, and c.
- **Example:** `a = 2, b = 2, c = 5`
- **Constraints:**
	- 0 <= a, b, c <= 100
	- a + b + c > 0

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the longest possible happy string that satisfies the given conditions, or an empty string if no such string exists.
- **Example:** `"ccbccbcc"`
- **Constraints:**
	- The string should contain at most a occurrences of 'a', b occurrences of 'b', and c occurrences of 'c'.
	- The string should not contain 'aaa', 'bbb', or 'ccc' as substrings.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to construct the longest string possible with the given constraints on the occurrences of 'a', 'b', and 'c'.

- 1. Use a priority queue to manage the counts of 'a', 'b', and 'c' in decreasing order.
- 2. Add characters to the result string, ensuring that no character appears more than twice consecutively.
- 3. After each addition, update the counts and push the characters back into the priority queue if their counts are still non-zero.
{{< dots >}}
### Problem Assumptions ✅
- It is assumed that at least one of a, b, or c is greater than zero.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: a = 2, b = 2, c = 5`  \
  **Explanation:** "ccbccbcc" is a valid string because it respects the maximum occurrences for 'a', 'b', and 'c', and does not contain 'aaa', 'bbb', or 'ccc'.

- **Input:** `Input: a = 3, b = 3, c = 0`  \
  **Explanation:** "ababab" is the only valid string because there are no 'c' characters allowed, and it doesn't contain any invalid substrings.

{{< dots >}}
## Approach 🚀
We can use a greedy algorithm combined with a priority queue to keep track of the remaining counts of 'a', 'b', and 'c', ensuring we always add the most frequent character while adhering to the constraints.

### Initial Thoughts 💭
- The problem requires managing character counts while adhering to a restriction on consecutive occurrences.
- A greedy approach using a priority queue allows us to always select the character with the highest remaining count.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least one non-zero count for a, b, or c.
- Ensure the algorithm efficiently handles the case where a, b, and c are large, up to 100.
- Consider the case where one of a, b, or c is zero, and how the algorithm should handle this.
- The solution should be efficient even when a, b, and c are at their maximum values.
{{< dots >}}
## Code 💻
```cpp
string longestDiverseString(int a, int b, int c) {
    
    priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> pq;
    if(a > 0)
    pq.push({a, 'a'});
    if(b > 0)
    pq.push({b, 'b'});
    if(c > 0)
    pq.push({c, 'c'});
    
    string res = "";
    
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        res += string(min(2, it.first), it.second);
        it.first -= min(2, it.first);
        
        if(pq.empty()) break;
        auto it2 = pq.top();
        pq.pop();
        res += string(min(it.first > it2.first? 1: 2, it2.first), it2.second);
        it2.first -= min(it.first > it2.first? 1: 2, it2.first);
        
        if(it.first > 0) pq.push(it);
        if(it2.first > 0) pq.push(it2);
    }
    
    return res;
}
```

This function, `longestDiverseString`, generates the longest string possible using characters 'a', 'b', and 'c' under the constraint that no more than two consecutive characters are the same.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	string longestDiverseString(int a, int b, int c) {
	```
	Defines the method `longestDiverseString`, which takes three integers representing the counts of 'a', 'b', and 'c', and returns the longest string possible with no more than two consecutive characters being the same.

2. **Priority Queue Initialization**
	```cpp
	    priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> pq;
	```
	Creates a max heap (priority queue) to store characters with their respective counts, ensuring the character with the highest count is always at the top.

3. **Condition Check for 'a'**
	```cpp
	    if(a > 0)
	```
	Checks if the count of 'a' is greater than 0. If so, 'a' is pushed into the priority queue.

4. **Push 'a' to Priority Queue**
	```cpp
	    pq.push({a, 'a'});
	```
	Pushes the pair containing the count of 'a' and the character 'a' into the priority queue.

5. **Condition Check for 'b'**
	```cpp
	    if(b > 0)
	```
	Checks if the count of 'b' is greater than 0. If so, 'b' is pushed into the priority queue.

6. **Push 'b' to Priority Queue**
	```cpp
	    pq.push({b, 'b'});
	```
	Pushes the pair containing the count of 'b' and the character 'b' into the priority queue.

7. **Condition Check for 'c'**
	```cpp
	    if(c > 0)
	```
	Checks if the count of 'c' is greater than 0. If so, 'c' is pushed into the priority queue.

8. **Push 'c' to Priority Queue**
	```cpp
	    pq.push({c, 'c'});
	```
	Pushes the pair containing the count of 'c' and the character 'c' into the priority queue.

9. **String Initialization**
	```cpp
	    string res = "";
	```
	Initializes the result string `res`, which will be built by appending characters from the priority queue.

10. **Main Loop Start**
	```cpp
	    while(!pq.empty()) {
	```
	Starts a `while` loop that continues as long as there are elements in the priority queue.

11. **Pop from Priority Queue**
	```cpp
	        auto it = pq.top();
	```
	Retrieves the top element from the priority queue, which is the character with the highest remaining count.

12. **Pop from Priority Queue**
	```cpp
	        pq.pop();
	```
	Removes the top element from the priority queue.

13. **Add Characters to Result**
	```cpp
	        res += string(min(2, it.first), it.second);
	```
	Adds up to two characters of the top character to the result string.

14. **Decrease Count of Character**
	```cpp
	        it.first -= min(2, it.first);
	```
	Decreases the count of the character after adding it to the result string.

15. **Break if Empty**
	```cpp
	        if(pq.empty()) break;
	```
	Checks if the priority queue is empty. If so, the loop breaks.

16. **Pop Second Character**
	```cpp
	        auto it2 = pq.top();
	```
	Retrieves the second character (with the next highest count) from the priority queue.

17. **Pop Second Character**
	```cpp
	        pq.pop();
	```
	Removes the second element from the priority queue.

18. **Add Second Character to Result**
	```cpp
	        res += string(min(it.first > it2.first? 1: 2, it2.first), it2.second);
	```
	Adds one or two characters of the second character to the result string, based on its remaining count.

19. **Decrease Second Character Count**
	```cpp
	        it2.first -= min(it.first > it2.first? 1: 2, it2.first);
	```
	Decreases the count of the second character after adding it to the result string.

20. **Push Back Characters to Priority Queue**
	```cpp
	        if(it.first > 0) pq.push(it);
	```
	If the first character still has a count greater than 0, it is pushed back into the priority queue.

21. **Push Back Characters to Priority Queue**
	```cpp
	        if(it2.first > 0) pq.push(it2);
	```
	If the second character still has a count greater than 0, it is pushed back into the priority queue.

22. **Return Result**
	```cpp
	    return res;
	```
	Returns the resulting string that follows the constraints.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the total sum of a, b, and c, as we process each character only once.
- **Average Case:** O(n log 3), since the priority queue operations involve logarithmic time complexity for each insertion or extraction.
- **Worst Case:** O(n log 3), since the priority queue is accessed a maximum of n times.



### Space Complexity 💾
- **Best Case:** O(1), as we do not need additional space beyond the priority queue.
- **Worst Case:** O(3), since we only store a small number of values in the priority queue (3 values at most).

The space complexity is constant because we only need to store the counts of 'a', 'b', and 'c'.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-happy-string/description/)

---
{{< youtube 8u-H6O_XQKE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
