
+++
authors = ["grid47"]
title = "Leetcode 835: Image Overlap"
date = "2024-08-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 835: Image Overlap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "zfjBapE3Y6E"
youtube_upload_date="2020-09-06"
youtube_thumbnail="https://i.ytimg.com/vi/zfjBapE3Y6E/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGCwgTih_MA8=&rs=AOn4CLDYXzk8BIj-n6f1vDE8kuCRNpZ81A"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<int> la, lb;
        int n = img1.size();
        for(int i = 0; i < n*n; i++)
            if(img1[i/n][i%n] == 1)
            la.push_back(i/n*100+ i%n);
        for(int i = 0; i < n*n; i++)
            if(img2[i/n][i%n] == 1)
            lb.push_back(i/n*100+ i%n);
        unordered_map<int, int> mp;
        for(int i : la)
        for(int j : lb)
            mp[i-j]++;
        int res = 0;
        for(auto it: mp)
        res = max(res, it.second);
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

Given two binary images `img1` and `img2` of size `n x n`, we are tasked with finding the largest overlap of ones between the two images after performing a 2D translation. Specifically, the problem asks us to determine the maximum number of overlapping 1's when one image is translated (shifted) over the other by some amount in both the vertical and horizontal directions.

**Translation** means moving the elements of `img1` and `img2` in any direction. The goal is to calculate how many `1's` overlap between the two images after the translation.

### Approach

To solve this problem, we need to evaluate every possible translation of `img1` relative to `img2`. The key insight here is that the maximum overlap occurs when the `1's` from both images align after some translation. To efficiently calculate the maximum overlap, the solution breaks the problem into the following steps:

1. **Identify the positions of the `1` pixels**: 
   - First, extract the coordinates of all `1's` from both `img1` and `img2`. Each `1` is located at some index `(i, j)` in the matrix.

2. **Translate `img1` relative to `img2`**:
   - For each pair of positions `(x1, y1)` from `img1` and `(x2, y2)` from `img2`, calculate the vector `(dx, dy)` representing the translation required to align `(x1, y1)` with `(x2, y2)`.
   - This vector will represent a potential translation of `img1` relative to `img2`.

3. **Count overlaps**:
   - For each translation vector `(dx, dy)`, shift all the `1's` in `img1` by `(dx, dy)` and check if they align with `1's` from `img2`.
   - Use a hashmap to count the number of times each translation vector results in overlapping `1's`.

4. **Find the maximum overlap**:
   - The result is the maximum count of overlapping `1's` for any translation vector.

### Code Breakdown (Step by Step)

#### Step 1: Identifying the Positions of `1's` in `img1` and `img2`

```cpp
vector<int> la, lb;
int n = img1.size();
```
- We create two vectors `la` and `lb` to store the positions of the `1's` in `img1` and `img2`, respectively. `n` is the size of the `n x n` image.

```cpp
for(int i = 0; i < n*n; i++)
    if(img1[i/n][i%n] == 1)
        la.push_back(i/n*100 + i%n);
for(int i = 0; i < n*n; i++)
    if(img2[i/n][i%n] == 1)
        lb.push_back(i/n*100 + i%n);
```
- These loops iterate through each element in both `img1` and `img2`, checking if the element is `1`. 
- We store the positions of the `1's` in a compact form by encoding the row and column of the element into a single number (`i/n * 100 + i%n`). This encoding is used to uniquely represent the position of a `1` in the matrix.

#### Step 2: Counting Overlaps for Each Translation

```cpp
unordered_map<int, int> mp;
```
- We use a hashmap `mp` to store the count of each translation. The key is the translation vector `(dx, dy)` and the value is the number of overlaps that occur for that particular translation.

```cpp
for(int i : la)
    for(int j : lb)
        mp[i - j]++;
```
- This nested loop iterates through each combination of `1` positions from `img1` and `img2`.
- For each pair of positions `(i, j)` from `img1` and `img2`, we calculate the translation vector `(dx, dy)` as the difference between `i` and `j`. 
- We then increment the count of this translation vector in the hashmap `mp`. The key here is that the value in `mp[i - j]` represents how many overlaps occur with a specific translation.

#### Step 3: Finding the Maximum Overlap

```cpp
int res = 0;
for(auto it : mp)
    res = max(res, it.second);
```
- We iterate through the hashmap `mp` and track the maximum value. This value represents the maximum number of overlapping `1's` for any translation.

#### Step 4: Return the Result

```cpp
return res;
```
- Finally, we return the maximum overlap found.

### Complexity

#### Time Complexity

- **Extracting positions of `1's`**: In the worst case, we are iterating over all `n x n` elements in both `img1` and `img2`. This gives a time complexity of `O(n^2)` for this step.
- **Counting overlaps**: In the worst case, we will compare every pair of positions from `img1` and `img2`. If both matrices contain `m` `1's`, then there will be `O(m^2)` comparisons. 
- Given that `m` can be at most `n^2`, the overall time complexity of counting overlaps is `O(n^4)` in the worst case.

Thus, the overall time complexity of the algorithm is **O(n^4)**, which is not optimal for large images. However, the complexity can be reduced further using advanced techniques like spatial hashing or Fourier transforms.

#### Space Complexity

- We store the positions of `1's` in both `img1` and `img2` in two vectors. This requires `O(m)` space, where `m` is the number of `1's` in the images.
- We also store the translation vectors and their counts in a hashmap `mp`, which requires `O(m^2)` space in the worst case.

Therefore, the overall space complexity is **O(m^2)**, where `m` is the number of `1's` in the images.

### Conclusion

This solution efficiently finds the largest overlap of `1's` between two binary images after a translation. The algorithm works by first identifying the positions of `1's` in both images, then computing the translation vectors for each pair of positions from `img1` and `img2`, and finally counting the overlaps for each translation. The result is the translation that produces the maximum number of overlapping `1's`.

Although the algorithm's time complexity can be high (`O(n^4)`), it provides a straightforward and intuitive approach to solving the problem. For larger datasets, further optimizations using techniques like spatial hashing or Fourier transforms could be explored to reduce the time complexity.

[`Link to LeetCode Lab`](https://leetcode.com/problems/image-overlap/description/)

---
{{< youtube zfjBapE3Y6E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
