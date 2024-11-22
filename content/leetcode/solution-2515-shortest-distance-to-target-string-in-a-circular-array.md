
+++
authors = ["grid47"]
title = "Leetcode 2515: Shortest Distance to Target String in a Circular Array"
date = "2024-02-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2515: Shortest Distance to Target String in a Circular Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "yTpRd3yvyz0"
youtube_upload_date="2023-01-07"
youtube_thumbnail="https://i.ytimg.com/vi/yTpRd3yvyz0/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int closetTarget(vector<string>& words, string target, int s) {
        int n = words.size(), ans = INT_MAX;
        
        for(int i = 0; i < n; i++) 
            if(words[i] == target) 
                ans = min(ans, min(abs(s - i), abs(n - abs(s - i)))); 
        
        return ans == INT_MAX ? -1 : ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to find the shortest distance from a given starting position `s` to a target word in a circular list of words. Given an array of words, a target word, and a starting index `s`, the goal is to find the minimum number of steps needed to reach the target word by either moving forward or backward in the list.

### Approach

This problem can be visualized as a circular array, where after reaching the last element, you can wrap around and start from the first element again. The key idea here is to calculate the distance in both directions: moving forward and moving backward, and then select the smaller distance.

1. **Iterate through the list of words**: 
   - We will iterate through the list of words and check for occurrences of the target word. For each occurrence, we will calculate the distance from the current starting position `s` to that occurrence.
   
2. **Calculate both forward and backward distances**:
   - The distance from the starting index `s` to a word at index `i` can be calculated in two ways:
     - **Forward Distance**: This is the direct distance from `s` to `i`, which is `abs(s - i)`.
     - **Backward Distance**: Since the list is circular, if moving forward goes beyond the end of the list, we can loop back to the start. The backward distance is calculated as `abs(n - abs(s - i))`, where `n` is the total number of words in the list.

3. **Find the minimum distance**:
   - For each occurrence of the target word, compute the distance in both directions and keep track of the minimum distance.
   
4. **Return the result**:
   - If the target word is found in the list, return the minimum distance calculated. Otherwise, return `-1` indicating that the target word is not present in the list.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Variables
```cpp
int n = words.size(), ans = INT_MAX;
```
- `n`: The size of the list `words` (i.e., the number of words in the circular list).
- `ans`: This variable will store the minimum distance found. It is initialized to `INT_MAX` to ensure that any valid distance found will be smaller than this initial value.

#### Step 2: Iterate through the Words Array
```cpp
for(int i = 0; i < n; i++)
    if(words[i] == target)
        ans = min(ans, min(abs(s - i), abs(n - abs(s - i))));
```
- We loop through the array `words` using a for-loop. For each word, we check if it matches the `target` word. If it does:
  - We calculate the **forward distance** as `abs(s - i)`, where `s` is the starting index and `i` is the current index of the target word.
  - We calculate the **backward distance** as `abs(n - abs(s - i))`, which ensures that the backward traversal takes into account the circular nature of the list.
  - The minimum of these two distances is then taken using the `min()` function, and `ans` is updated with the smaller value.

#### Step 3: Return the Result
```cpp
return ans == INT_MAX ? -1 : ans;
```
- After iterating through all the words, if no target word was found (`ans` is still `INT_MAX`), we return `-1` to indicate that the target does not exist in the list.
- If the target word is found, the value of `ans` will contain the minimum distance, and we return that value.

### Example Walkthrough

#### Example 1:
**Input**:
```cpp
vector<string> words = {"hello", "world", "target", "end"};
string target = "target";
int s = 1;
```

**Execution**:
- We iterate over the list `words`:
  - For `i = 0`, the word is "hello", which doesn't match the target.
  - For `i = 1`, the word is "world", which doesn't match the target.
  - For `i = 2`, the word is "target", which matches the target.
    - Forward distance: `abs(1 - 2) = 1`.
    - Backward distance: `abs(4 - abs(1 - 2)) = abs(4 - 1) = 3`.
    - The minimum distance is `min(1, 3) = 1`.
  - For `i = 3`, the word is "end", which doesn't match the target.
- The result is `1`, as the target word is at index 2, which is 1 step away from the starting index 1.

**Output**:
```cpp
1
```

#### Example 2:
**Input**:
```cpp
vector<string> words = {"hello", "world", "target", "end"};
string target = "notfound";
int s = 1;
```

**Execution**:
- We iterate over the list `words`:
  - For `i = 0`, the word is "hello", which doesn't match the target.
  - For `i = 1`, the word is "world", which doesn't match the target.
  - For `i = 2`, the word is "target", which doesn't match the target.
  - For `i = 3`, the word is "end", which doesn't match the target.
- The target word is not found in the list.

**Output**:
```cpp
-1
```

### Complexity Analysis

#### Time Complexity:
- **Iterating over the words**: We loop over the list of words, which has a length of `n`. Thus, the time complexity for this loop is \(O(n)\).
- **For each word, calculating distances**: The `abs()` function and the `min()` function both take constant time \(O(1)\).
- **Overall Time Complexity**: The time complexity is \(O(n)\), where `n` is the number of words in the list.

#### Space Complexity:
- **No additional space used**: We only use a few variables to store the result and intermediate calculations.
- **Overall Space Complexity**: The space complexity is \(O(1)\), since we are using a constant amount of extra space.

### Conclusion

This approach efficiently solves the problem of finding the shortest distance to a target word in a circular list by utilizing basic arithmetic operations. The key insight is using the circular nature of the list and calculating both forward and backward distances. The solution works in linear time \(O(n)\) and constant space \(O(1)\), making it highly efficient for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/)

---
{{< youtube yTpRd3yvyz0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
