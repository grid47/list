
+++
authors = ["grid47"]
title = "Leetcode 1310: XOR Queries of a Subarray"
date = "2024-06-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1310: XOR Queries of a Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1Q4lxfSlbPs"
youtube_upload_date="2024-09-13"
youtube_thumbnail="https://i.ytimg.com/vi/1Q4lxfSlbPs/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        int n = arr.size();
        vector<int> xr(n +1,0);
        for(int i = 1; i < n +1; i++)
            xr[i] = xr[i - 1] ^ arr[i - 1];
        vector<int> res;
        for(int i = 0; i < q.size(); i++) {
            auto &v = q[i];
            res.push_back(xr[v[1]+1] ^ xr[v[0]]);
         }
        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
The task is to process multiple XOR range queries on an array `arr`. Given `arr` and a list of queries `q`, each query specifies two indices `[L, R]`. For each query, we need to find the XOR of elements in `arr` from index `L` to `R`, inclusive. The goal is to answer all queries efficiently.

### Approach
The solution leverages the concept of **prefix XOR arrays** to quickly calculate the XOR for any subarray in constant time. In a prefix XOR array:
- The XOR up to any index `i` is stored in `xr[i+1]`, where `xr[i+1]` contains the XOR of all elements from the start of `arr` up to `i`.
- Using this, the XOR for any subarray `[L, R]` can be computed as `xr[R+1] ^ xr[L]`. This works because elements from the start to `L-1` cancel out, leaving only the XOR from `L` to `R`.

### Code Breakdown (Step by Step)

1. **Define the Class and Method**:
   - The method `xorQueries` takes in the integer vector `arr` and the list of queries `q`. It returns a vector containing the XOR results for each query.

   ```cpp
   class Solution {
   public:
       vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
   ```

2. **Initialize and Populate the Prefix XOR Array**:
   - `xr` is a prefix XOR array initialized with size `n + 1`, where `n` is the length of `arr`.
   - `xr[i]` stores the XOR of all elements in `arr` from the start up to `i-1`. By initializing `xr[0] = 0`, it allows us to calculate the XOR of any subarray directly.
   - A loop populates `xr` such that `xr[i] = xr[i-1] ^ arr[i-1]`.

   ```cpp
           int n = arr.size();
           vector<int> xr(n + 1, 0);
           for(int i = 1; i < n + 1; i++)
               xr[i] = xr[i - 1] ^ arr[i - 1];
   ```

3. **Process Each Query Using the Prefix XOR Array**:
   - The `res` vector stores results for each query.
   - For each query `q[i] = [L, R]`, the XOR from `L` to `R` is calculated as `xr[R+1] ^ xr[L]`. This operation uses the properties of XOR to get the result for the subarray in constant time.

   ```cpp
           vector<int> res;
           for(int i = 0; i < q.size(); i++) {
               auto &v = q[i];
               res.push_back(xr[v[1] + 1] ^ xr[v[0]]);
           }
   ```

4. **Return the Results**:
   - The method returns `res`, which contains the XOR results for all queries.

   ```cpp
           return res;
       }
   };
   ```

### Complexity Analysis

- **Time Complexity**: \(O(n + m)\), where \(n\) is the length of `arr` and \(m\) is the number of queries. Calculating the prefix XOR array requires \(O(n)\), and each query is processed in \(O(1)\), totaling \(O(m)\) for \(m\) queries.
- **Space Complexity**: \(O(n)\) for storing the prefix XOR array.

### Conclusion
This solution optimally answers each XOR query using a prefix XOR array to achieve constant-time lookup for any subarray XOR. This technique significantly reduces computational complexity compared to directly computing the XOR for each subarray, making it ideal for scenarios with a large number of queries or large arrays. The solution is efficient, scalable, and leverages bitwise operations effectively, showcasing an advanced approach to handling XOR queries in linear time.

[`Link to LeetCode Lab`](https://leetcode.com/problems/xor-queries-of-a-subarray/description/)

---
{{< youtube 1Q4lxfSlbPs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
