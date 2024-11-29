
+++
authors = ["grid47"]
title = "Leetcode 1936: Add Minimum Number of Rungs"
date = "2024-04-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1936: Add Minimum Number of Rungs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "f_KA5C_13Oc"
youtube_upload_date="2021-07-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/f_KA5C_13Oc/maxresdefault.webp"
comments = true
+++



---
You are at the bottom of a ladder with several rungs already placed. The distance between consecutive rungs should not exceed a given value 'dist'. If the gap between any two rungs exceeds 'dist', you can insert additional rungs to make the ladder climbable. Return the minimum number of rungs that need to be added.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two parameters: a list of integers 'rungs', where each element represents the height of a rung, and an integer 'dist' which represents the maximum allowed distance between consecutive rungs.
- **Example:** `rungs = [2, 5, 8, 14], dist = 3`
- **Constraints:**
	- 1 <= rungs.length <= 10^5
	- 1 <= rungs[i] <= 10^9
	- 1 <= dist <= 10^9
	- rungs is strictly increasing.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of rungs that need to be added to make the ladder climbable.
- **Example:** `2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the minimum number of rungs that must be inserted to ensure that the gap between any two consecutive rungs does not exceed the maximum allowed distance 'dist'.

- Iterate through the rungs and check the distance between each consecutive pair.
- If the gap is greater than 'dist', calculate how many rungs need to be added to fill the gap.
- Accumulate the total number of rungs that need to be added.
{{< dots >}}
### Problem Assumptions ✅
- The rungs are always strictly increasing.
- The ladder can have gaps larger than the maximum climbing distance, requiring additional rungs to be inserted.
{{< dots >}}
## Examples 🧩
- **Input:** `rungs = [2, 5, 8, 14], dist = 3`  \
  **Explanation:** There is a gap of 3 between rung 5 and rung 8. This gap exceeds the allowed distance, so we need to insert two rungs (at heights 11 and 12) to make the ladder climbable. Hence, the answer is 2.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to iterate over the rungs and check the gap between each consecutive pair. If the gap is larger than the allowed climbing distance, we calculate how many rungs to add to fill the gap.

### Initial Thoughts 💭
- The number of rungs that need to be added can be calculated by dividing the gap by the allowed distance and rounding up.
- We will process each gap one by one, and accumulate the number of rungs to be added.
{{< dots >}}
### Edge Cases 🌐
- If there are no rungs, the ladder cannot be climbed, so the number of rungs to add is zero.
- The solution should efficiently handle large input sizes, with up to 100,000 rungs.
- If the gap between any two rungs is exactly 'dist', no new rungs need to be added.
- The solution should run in linear time relative to the number of rungs to handle the upper limit efficiently.
{{< dots >}}
## Code 💻
```cpp

int rec(int cur, int idx, int dist, vector<int> &node) {
    if(cur + dist >= node[node.size() - 1]) return 0;
    
    if(cur + dist < node[idx]) {
        cur += dist;
        return 1 + rec(cur, idx, dist, node);
        
    } else {
        cur = node[idx];
        return rec(cur, idx + 1, dist, node);
    }
}

int addRungs(vector<int>& node, int dist) {
    int cur = 0, idx = 0, res = 0;
    
    int prv = 0;
    
    for(int i = 0; i < node.size(); i++) {
        if(node[i] - prv > dist) {
            res += (node[i] - prv - 1) / dist;
        }
        prv = node[i];
    }
    
    // while(cur + dist < node[node.size() - 1]) {
    //     if(cur + dist < node[idx]) {
    //         cur += dist;
    //         res++;
    //     } else {
    //         cur = node[idx];
    //         idx++;
    //     }
    // }
    
    return res;//rec(cur, idx, dist, node);
    
}
```

The code is an implementation of a recursive function to calculate the number of rungs needed to bridge gaps between elements in the input array `node`, where `dist` is the maximum gap between two rungs. It also provides an iterative version that calculates the total number of required rungs.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int rec(int cur, int idx, int dist, vector<int> &node) {
	```
	Define the recursive function `rec` that takes the current position (`cur`), the current index (`idx`), the maximum distance (`dist`), and the list of positions (`node`).

2. **Condition Check**
	```cpp
	    if(cur + dist >= node[node.size() - 1]) return 0;
	```
	If the current position plus the distance exceeds or reaches the last node, return 0 as no more rungs are needed.

3. **Decision**
	```cpp
	    if(cur + dist < node[idx]) {
	```
	If the current position plus the distance is less than the current node position, continue to move forward by adding the distance.

4. **Action**
	```cpp
	        cur += dist;
	```
	Move the current position forward by the specified distance.

5. **Recursive Call**
	```cpp
	        return 1 + rec(cur, idx, dist, node);
	```
	Recursively call the function to check for the next gap after moving the current position forward.

6. **Else Condition**
	```cpp
	    } else {
	```
	If the current position plus the distance is not less than the current node, proceed to the next node.

7. **Action**
	```cpp
	        cur = node[idx];
	```
	Set the current position to the current node's position.

8. **Recursive Call**
	```cpp
	        return rec(cur, idx + 1, dist, node);
	```
	Recursively call the function, advancing the index to check the next node.

9. **Function Definition**
	```cpp
	int addRungs(vector<int>& node, int dist) {
	```
	Define the main function `addRungs`, which calculates the total number of rungs needed based on the positions in the `node` list and the given `dist`.

10. **Variable Initialization**
	```cpp
	    int cur = 0, idx = 0, res = 0;
	```
	Initialize variables: `cur` to track the current position, `idx` for the current index in the node array, and `res` for counting the required rungs.

11. **Variable Initialization**
	```cpp
	    int prv = 0;
	```
	Initialize the variable `prv` to track the previous position in the node array.

12. **Loop**
	```cpp
	    for(int i = 0; i < node.size(); i++) {
	```
	Iterate through each element in the `node` array.

13. **Condition Check**
	```cpp
	        if(node[i] - prv > dist) {
	```
	Check if the gap between the current node and the previous node exceeds the given distance.

14. **Action**
	```cpp
	            res += (node[i] - prv - 1) / dist;
	```
	Calculate how many rungs are needed to fill the gap and add that to the result.

15. **Update**
	```cpp
	        prv = node[i];
	```
	Update the previous position to the current node.

16. **Return**
	```cpp
	    return res;
	```
	Return the final result of the number of rungs required.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of rungs, because we are iterating through the rungs only once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), since we only need a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/add-minimum-number-of-rungs/description/)

---
{{< youtube f_KA5C_13Oc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
