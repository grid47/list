
+++
authors = ["grid47"]
title = "Leetcode 1899: Merge Triplets to Form Target Triplet"
date = "2024-05-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1899: Merge Triplets to Form Target Triplet in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "kShkQLQZ9K4"
youtube_upload_date="2021-06-13"
youtube_thumbnail="https://i.ytimg.com/vi/kShkQLQZ9K4/maxresdefault.jpg"
comments = true
+++



---
Given a list of triplets and a target triplet, determine if it is possible to update the triplets through a series of operations to match the target.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2D array `triplets`, where each element is a triplet of integers, and a target triplet `target`. You can update the triplets using a series of operations as described.
- **Example:** `triplets = [[2,5,3],[1,8,4],[1,7,5]], target = [2,7,5]`
- **Constraints:**
	- 1 <= triplets.length <= 10^5
	- triplets[i].length == target.length == 3
	- 1 <= ai, bi, ci, x, y, z <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if it's possible to form the target triplet from the given triplets through the allowed operations, otherwise return `false`.
- **Example:** `true`
- **Constraints:**
	- The output must be a boolean value indicating if the target triplet can be formed.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine if we can obtain the target triplet through the allowed operations.

- Iterate over each triplet and check if each element can potentially form the target triplet by updating other triplets.
- For each triplet, keep track of the maximum values seen so far and compare them to the target.
{{< dots >}}
### Problem Assumptions ✅
- All triplets and the target triplet are non-negative integers.
- Triplets are updated through the specified operation and no other operations are allowed.
{{< dots >}}
## Examples 🧩
- **Input:** `triplets = [[2,5,3],[1,8,4],[1,7,5]], target = [2,7,5]`  \
  **Explanation:** Through the operation on triplets, the target triplet can be formed by updating the last triplet to match the target.

{{< dots >}}
## Approach 🚀
The problem can be solved by iterating over the triplets, updating the maximum values, and checking if the target triplet can be formed.

### Initial Thoughts 💭
- The operation involves taking maximum values between corresponding elements of two triplets.
- We need to check if it's possible to form the target by applying this operation.
- We can track the maximum values as we process each triplet and compare them to the target.
{{< dots >}}
### Edge Cases 🌐
- Empty lists are not allowed in the input.
- The solution should handle up to 10^5 triplets efficiently.
- The triplets and target values are always positive integers.
- Ensure that the input meets the constraints, especially for large inputs.
{{< dots >}}
## Code 💻
```cpp

bool mergeTriplets(vector<vector<int>>& tri, vector<int>& tgt) {
    vector<int> res(3, 0);
    int n = tri.size();

    for(auto s: tri) {
        if(s[0] <= tgt[0] && s[1] <= tgt[1] && s[2] <= tgt[2]) {
            res = { max(res[0], s[0]), max(res[1], s[1]), max(res[2], s[2]) };
        }
    }
    
    return tgt == res;        
}


```

The function `mergeTriplets` checks if the target triplet `tgt` can be formed by selecting elements from the list of triplets `tri`. It iterates through `tri` and updates the result triplet if all elements of the triplet are less than or equal to the corresponding target values. Finally, it checks if the resulting triplet matches the target.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool mergeTriplets(vector<vector<int>>& tri, vector<int>& tgt) {
	```
	Define the function `mergeTriplets`, which takes a vector of triplets `tri` and a target triplet `tgt`.

2. **Initialize Result Triplet**
	```cpp
	    vector<int> res(3, 0);
	```
	Initialize the result triplet `res` with 3 zeros. This will store the maximum values from the triplets in `tri` that can contribute to the target `tgt`.

3. **Get Triplet Count**
	```cpp
	    int n = tri.size();
	```
	Get the number of triplets in `tri` and store it in `n`. This value is not used explicitly later in the function but helps describe the size of `tri`.

4. **Loop Through Triplets**
	```cpp
	    for(auto s: tri) {
	```
	Start a loop to iterate through each triplet `s` in `tri`.

5. **Condition Check**
	```cpp
	        if(s[0] <= tgt[0] && s[1] <= tgt[1] && s[2] <= tgt[2]) {
	```
	Check if all elements of the current triplet `s` are less than or equal to the corresponding elements in the target triplet `tgt`.

6. **Update Result Triplet**
	```cpp
	            res = { max(res[0], s[0]), max(res[1], s[1]), max(res[2], s[2]) };
	```
	Update the result triplet `res` with the maximum values from the current triplet `s` and the previously stored values in `res`.

7. **Return Statement**
	```cpp
	    return tgt == res;        
	```
	Return `true` if the resulting triplet `res` matches the target `tgt`, otherwise return `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution iterates through the list of triplets once, so the time complexity is linear in the size of the input.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only store the maximum values for each element in the triplets.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/merge-triplets-to-form-target-triplet/description/)

---
{{< youtube kShkQLQZ9K4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
