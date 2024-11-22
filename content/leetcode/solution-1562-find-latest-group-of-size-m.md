
+++
authors = ["grid47"]
title = "Leetcode 1562: Find Latest Group of Size M"
date = "2024-06-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1562: Find Latest Group of Size M in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "jUindlyYRuA"
youtube_upload_date="2020-08-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/jUindlyYRuA/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {

        int n = arr.size();
        vector<int> len(n + 2, 0), cnt(n + 1, 0);
        
        int res = -1;
        
        for(int i = 0; i < n; i++) {
            
            int a = arr[i];
            int ll = len[a - 1];
            int rl = len[a + 1];
            len[a] = len[a - ll] = len[a + rl] = ll + rl + 1;
            
            cnt[ll]--;
            cnt[rl]--;
            
            cnt[len[a]]++;
            
            if(cnt[m] > 0) res = i + 1;
            
        }
        
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand requires determining the latest step at which a group of contiguous elements in an array can be found. Given an array `arr` that represents a sequence of steps in which elements are added to a collection, the goal is to identify the last step where there exists a contiguous segment of exactly `m` elements. The task involves dynamically tracking the lengths of contiguous segments as elements are added and identifying when these segments meet the specified size requirement.

### Approach

To solve this problem efficiently, we can leverage a combination of arrays to keep track of the lengths of contiguous segments and their counts as elements from `arr` are added. The approach can be summarized in the following steps:

1. **Initialization**: We initialize two arrays:
   - `len`: To keep track of the lengths of contiguous segments, with additional space for boundaries.
   - `cnt`: To count the number of segments of each length.

2. **Iterate Through Steps**: As we process each element in `arr`, we update the `len` array to reflect the new segment lengths created by adding that element. We also adjust the `cnt` array to account for the change in segment lengths.

3. **Update Counts**: Whenever a segment of length `m` is formed, we update the result variable to reflect the current step index.

4. **Return Result**: Finally, after processing all elements, the result will hold the latest step where a contiguous segment of size `m` was found.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the provided code, explaining each component:

- **Class Declaration**:
    The solution is encapsulated within a class named `Solution`.

```cpp
class Solution {
public:
```

- **Function Definition**:
    The `findLatestStep` function takes a vector of integers (`arr`) and an integer (`m`) as input, returning an integer that indicates the latest step with a contiguous segment of length `m`.

```cpp
int findLatestStep(vector<int>& arr, int m) {
```

- **Variable Initialization**:
    The size of `arr` is stored in `n`, and two vectors, `len` and `cnt`, are initialized. The `len` vector has a size of `n + 2` to account for boundary conditions, while `cnt` has a size of `n + 1` to count the occurrences of segment lengths.

```cpp
int n = arr.size();
vector<int> len(n + 2, 0), cnt(n + 1, 0);
int res = -1;
```

- **Iterate Through Each Step**:
    A loop iterates through each element in `arr`, processing one step at a time.

```cpp
for(int i = 0; i < n; i++) {
```

- **Access Current Element**:
    The current element being processed is stored in `a`.

```cpp
int a = arr[i];
```

- **Get Left and Right Segment Lengths**:
    The lengths of the contiguous segments to the left (`ll`) and right (`rl`) of the current element are fetched from the `len` array.

```cpp
int ll = len[a - 1];
int rl = len[a + 1];
```

- **Update Segment Lengths**:
    Update the `len` array to reflect the new segment created by adding the current element. The segment lengths are adjusted based on the left and right segment lengths.

```cpp
len[a] = len[a - ll] = len[a + rl] = ll + rl + 1;
```

- **Adjust Counts of Segment Lengths**:
    Decrement the counts of the old segment lengths in the `cnt` array and increment the count for the new segment length.

```cpp
cnt[ll]--;
cnt[rl]--;
cnt[len[a]]++;
```

- **Check for Segment of Length m**:
    If there are any segments of length `m`, update the result variable with the current step index.

```cpp
if(cnt[m] > 0) res = i + 1;
```

- **Return Statement**:
    After processing all elements, return the result indicating the latest step where a contiguous segment of size `m` was found.

```cpp
return res;
}
```

### Complexity

- **Time Complexity**: The time complexity of this algorithm is \(O(n)\), where \(n\) is the number of elements in the input array. Each step involves constant-time operations for updating segment lengths and counts.

- **Space Complexity**: The space complexity is \(O(n)\) due to the additional storage used for the `len` and `cnt` arrays.

### Conclusion

The `findLatestStep` function efficiently determines the latest step at which a contiguous segment of a specified length `m` can be found in a dynamically constructed sequence. By utilizing arrays to track segment lengths and counts, the algorithm performs updates in constant time, allowing it to operate within linear time complexity.

This solution not only highlights the utility of counting techniques and dynamic programming principles but also showcases the effectiveness of maintaining state through arrays in algorithm design. Understanding this implementation can enhance one's problem-solving skills, particularly in scenarios involving dynamic sequences and contiguous segment tracking. The algorithm serves as a strong example for developers seeking to implement similar logic in applications, particularly in competitive programming and algorithmic challenges.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-latest-group-of-size-m/description/)

---
{{< youtube jUindlyYRuA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
