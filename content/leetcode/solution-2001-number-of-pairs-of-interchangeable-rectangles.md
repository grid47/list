
+++
authors = ["grid47"]
title = "Leetcode 2001: Number of Pairs of Interchangeable Rectangles"
date = "2024-04-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2001: Number of Pairs of Interchangeable Rectangles in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "lEQ8ZlLOuyQ"
youtube_upload_date="2021-09-12"
youtube_thumbnail="https://i.ytimg.com/vi/lEQ8ZlLOuyQ/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> mp;
        long long cnt = 0;
        for(auto r: rectangles) {
            double x = (double)r[0]/ r[1];
            if(mp.find(x) != mp.end()) cnt += mp[x];
            mp[x]++;
        }

        // int cnt = 0;
        // for(auto &it: mp) 
        // {
            // cout << it.second << ' ';
            // cnt = cnt + it.second * (it.second -1 ) / 2;
        // }

        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves finding the number of interchangeable rectangles from a given list of rectangles, defined by their width and height. Two rectangles are considered interchangeable if they have the same aspect ratio, which is the ratio of their width to their height. The challenge is to efficiently count how many pairs of rectangles share the same aspect ratio from a potentially large input set.

### Approach

To solve this problem, we can use a hash map (or unordered map) to store the frequency of each unique aspect ratio encountered as we iterate through the list of rectangles. The aspect ratio of each rectangle is calculated by dividing its width by its height. As we process each rectangle:

1. We compute its aspect ratio.
2. We check if this aspect ratio has been seen before:
   - If it has, we can form new pairs of interchangeable rectangles with all previously encountered rectangles having the same aspect ratio.
   - We increment our count of pairs accordingly.
3. We then update the frequency of the current aspect ratio in our hash map.

This allows us to count the pairs in a single pass through the list of rectangles, making the solution efficient and straightforward.

### Code Breakdown (Step by Step)

Let’s dive into the code and break it down into its core components:

1. **Class Definition**: We define a class named `Solution` which contains our method for counting interchangeable rectangles.

    ```cpp
    class Solution {
    public:
    ```

2. **Method Declaration**: The method `interchangeableRectangles` takes a vector of rectangles (each represented as a pair of integers for width and height) as input and returns the total count of interchangeable rectangle pairs as a long long integer.

    ```cpp
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    ```

3. **Data Structures**: We initialize an unordered map `mp` to store the frequency of each unique aspect ratio and a variable `cnt` to count the total number of interchangeable pairs.

    ```cpp
    unordered_map<double, int> mp;
    long long cnt = 0;
    ```

4. **Iterating Through Rectangles**: We use a range-based for loop to iterate through each rectangle in the input list.

    ```cpp
    for(auto r: rectangles) {
    ```

5. **Calculating Aspect Ratio**: For each rectangle, we calculate its aspect ratio by dividing its width (`r[0]`) by its height (`r[1]`). This ratio is stored as a double.

    ```cpp
    double x = (double)r[0] / r[1];
    ```

6. **Counting Pairs**: We check if the calculated aspect ratio already exists in our map:
   - If it does, we add the count of rectangles with the same aspect ratio (stored in `mp[x]`) to `cnt` because each of these represents a potential pair with the current rectangle.
   - We then increment the count of this aspect ratio in the map.

    ```cpp
    if(mp.find(x) != mp.end())
        cnt += mp[x]; // Increment cnt by the number of rectangles with the same ratio
    mp[x]++; // Increase the count of this ratio in the map
    ```

7. **Returning the Result**: After processing all rectangles, we return the total count of interchangeable rectangle pairs.

    ```cpp
    return cnt;
    }
    ```

### Complexity

The time complexity of this algorithm is O(n), where n is the number of rectangles. This is because we traverse the list of rectangles once and perform constant time operations (hash map lookups and insertions) for each rectangle. The space complexity is also O(n) in the worst case if all rectangles have unique aspect ratios.

### Conclusion

In conclusion, the provided code efficiently counts the number of interchangeable rectangles based on their aspect ratios. By leveraging a hash map to track the frequency of each unique ratio, we can quickly determine how many pairs can be formed with previously seen rectangles. This approach not only simplifies the counting process but also ensures that the solution remains optimal even for large inputs. The logic is straightforward, making it easy to understand how rectangles are processed and counted based on their geometric properties. Thus, this solution effectively combines mathematical insight with efficient data structures to solve the problem of counting interchangeable rectangles in a clean and efficient manner.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/description/)

---
{{< youtube lEQ8ZlLOuyQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
