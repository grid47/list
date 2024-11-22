
+++
authors = ["grid47"]
title = "Leetcode 2943: Maximize Area of Square Hole in Grid"
date = "2024-01-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2943: Maximize Area of Square Hole in Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PwzZ9UVWqBk"
youtube_upload_date="2023-11-25"
youtube_thumbnail="https://i.ytimg.com/vi/PwzZ9UVWqBk/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        vector<int>h;
        vector<int>v;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        for(auto i:hBars)
            h.push_back(i);
        for(auto i:vBars)
            v.push_back(i);
        int mv=1,mh=1;
        int c=1;
        for(int i=1;i<h.size();i++)
        {   
            
            if(h[i]==h[i-1]+1)
                c++;
            else
                c=1;
            mh=max(mh,c);
        }
        c=1;
        for(int i=1;i<v.size();i++)
        {   
            if(v[i]==v[i-1]+1)
                c++;
            else
                c=1;
            mv=max(mv,c);
        }
        int x=min(mh+1,mv+1);
        return x*x;
    }
};
{{< /highlight >}}
---

### Problem Statement:
Given a grid with vertical and horizontal bars, the task is to find the maximum area of a square hole that can be formed. A hole is formed by selecting horizontal and vertical bars such that the distance between consecutive bars on both axes is at least 1 unit. The goal is to maximize the area of the square formed by these distances.

Specifically, we are given:
- `n`: the number of horizontal bars.
- `m`: the number of vertical bars.
- `hBars`: an array representing the positions of the horizontal bars.
- `vBars`: an array representing the positions of the vertical bars.

You need to calculate the largest square area that can be formed within the grid defined by these bars. The square’s sides should lie between two consecutive bars on both the horizontal and vertical axes.

### Approach:
To solve the problem, we need to focus on the following key observations:
1. **Consecutive Bars**: The size of the square formed between two consecutive bars is determined by the minimum distance between any two bars (both horizontally and vertically). If the horizontal bars are too close together, the maximum square's side length will be limited by them, and similarly for vertical bars.
   
2. **Sort and Calculate Gaps**: By sorting the arrays of horizontal (`hBars`) and vertical (`vBars`) bars, we can easily compute the maximum distance between consecutive bars. The distance between two consecutive bars is simply the difference between their positions.

3. **Maximize Square's Side**: The largest square hole will be constrained by the maximum gap between consecutive horizontal bars and the maximum gap between consecutive vertical bars. The side length of the square is limited by the smaller of these two values, since both the width and height of the square need to fit within the available gaps.

4. **Result**: Once we determine the maximum possible side length of the square, we can compute the area of the square, which is simply the square of the side length.

### Code Breakdown (Step by Step):

#### 1. **Sorting the Bars**:
First, we sort both `hBars` (horizontal bars) and `vBars` (vertical bars) to ensure that we can calculate the distances between consecutive bars easily.

```cpp
sort(hBars.begin(), hBars.end());
sort(vBars.begin(), vBars.end());
```

#### 2. **Copying Sorted Bars into Separate Vectors**:
We copy the sorted bars into separate vectors `h` and `v`. While this step isn't strictly necessary (since we could work with the sorted input directly), it is done here for clarity.

```cpp
vector<int> h;
vector<int> v;
for(auto i:hBars)
    h.push_back(i);
for(auto i:vBars)
    v.push_back(i);
```

#### 3. **Calculating Maximum Horizontal Gap**:
We now calculate the largest gap between consecutive horizontal bars. We initialize `mh` (maximum horizontal gap) to 1 because the smallest possible gap is at least 1 (as bars are placed at distinct positions).

Then, we iterate over the sorted horizontal bars and calculate the gap between each pair of consecutive bars. If the gap between two consecutive bars is 1, we increase the count `c`. Otherwise, we reset `c` to 1.

```cpp
int mh = 1;
int c = 1;
for (int i = 1; i < h.size(); i++) {
    if (h[i] == h[i-1] + 1)
        c++;
    else
        c = 1;
    mh = max(mh, c);
}
```

#### 4. **Calculating Maximum Vertical Gap**:
Similarly, we calculate the largest gap between consecutive vertical bars using the same logic as for the horizontal bars. We initialize `mv` (maximum vertical gap) to 1 and iterate through the sorted vertical bars.

```cpp
int mv = 1;
c = 1;
for (int i = 1; i < v.size(); i++) {
    if (v[i] == v[i-1] + 1)
        c++;
    else
        c = 1;
    mv = max(mv, c);
}
```

#### 5. **Calculating the Maximum Square Area**:
After finding the maximum consecutive gaps horizontally (`mh`) and vertically (`mv`), we calculate the side length of the largest square that can be formed. The side length of the square is the minimum of `mh + 1` and `mv + 1` because the square's side length is constrained by the smaller of these two values.

Finally, we return the area of the square, which is the square of the side length.

```cpp
int x = min(mh + 1, mv + 1);
return x * x;
```

### Complexity:

#### Time Complexity:
- Sorting the horizontal bars takes \(O(n \log n)\), where `n` is the number of horizontal bars.
- Sorting the vertical bars takes \(O(m \log m)\), where `m` is the number of vertical bars.
- Calculating the maximum gap between consecutive horizontal bars takes \(O(n)\), and similarly, calculating the maximum gap between vertical bars takes \(O(m)\).

Thus, the overall time complexity is dominated by the sorting step and is:
\[
O(n \log n + m \log m)
\]

#### Space Complexity:
- We use additional space for the `h` and `v` vectors to store the sorted bars. Therefore, the space complexity is \(O(n + m)\), where `n` and `m` are the number of horizontal and vertical bars, respectively.

### Conclusion:
The solution efficiently calculates the maximum area of a square that can be formed between the horizontal and vertical bars. The key idea is to find the maximum gap between consecutive bars in both dimensions, and the side length of the square is limited by the smaller of these two gaps. This solution leverages sorting and linear scanning to achieve the result in optimal time.

#### Key Points:
- The largest square's side length is determined by the maximum gap between consecutive bars in both horizontal and vertical directions.
- The time complexity is \(O(n \log n + m \log m)\), where `n` and `m` are the sizes of the input arrays.
- The space complexity is \(O(n + m)\), as we store the sorted bars in separate vectors.


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/)

---
{{< youtube PwzZ9UVWqBk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
