
+++
authors = ["grid47"]
title = "Leetcode 1471: The k Strongest Values in an Array"
date = "2024-06-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1471: The k Strongest Values in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "5Hie-4QPNtI"
youtube_upload_date="2020-06-07"
youtube_thumbnail="https://i.ytimg.com/vi/5Hie-4QPNtI/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class cmp {
    public:
     bool operator() (pair<float,int> &a, pair<float, int> &b) {
        if(a.first == b.first) return a.second < b.second;
        else return a.first < b.first;
    }
};

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        float m;
        if(n & 1) {
            m = arr[n / 2];
        } else {
            m = arr[n/2-1];
        }
        priority_queue<pair<float, int>, vector<pair<float, int>>, cmp> pq;
        
        for(int i = 0; i < n; i++) {
            // cout << abs(arr[i] - m) << " " << arr[i] << " ";
            pq.push({abs(arr[i] - m), arr[i]});
        }
        vector<int> res;
        while(k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The objective of this problem is to find the `k` strongest elements in an array. The "strength" of an element is defined as the absolute difference between the element and the median of the array. The median is determined as the middle value of the sorted array, or the average of the two middle values when the array has an even length. The final output should be a list of the `k` strongest elements, sorted in descending order.

### Approach

To achieve the goal, we can break the solution into the following steps:

1. **Sorting the Array**: First, we sort the input array to easily compute the median.

2. **Finding the Median**: The median is determined based on whether the number of elements in the array is odd or even.

3. **Calculating Strength**: For each element in the array, calculate its strength, which is the absolute difference from the median.

4. **Using a Custom Comparator**: Utilize a custom comparator to prioritize elements with greater strength. In cases where two elements have the same strength, we should prioritize the larger element.

5. **Selecting the Strongest Elements**: Extract the top `k` strongest elements from a max-heap (priority queue) based on the computed strengths.

6. **Sorting the Result**: Finally, the selected `k` strongest elements should be sorted in descending order before returning.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the provided code:

1. **Custom Comparator Class**:
   ```cpp
   class cmp {
   public:
       bool operator() (pair<float,int> &a, pair<float, int> &b) {
           if(a.first == b.first) return a.second < b.second;
           else return a.first < b.first;
       }
   };
   ```

   - The custom comparator `cmp` is defined to compare pairs of float and int. The first element is the strength (absolute difference from the median), and the second element is the actual value.
   - The comparator ensures that when two elements have the same strength, the one with the higher value is prioritized.

2. **Class Declaration**:
   ```cpp
   class Solution {
   public:
   ```

   - The solution class encapsulates the functionality for finding the strongest elements.

3. **Main Function**:
   ```cpp
   vector<int> getStrongest(vector<int>& arr, int k) {
   ```

   - The `getStrongest` function takes a vector of integers `arr` and an integer `k` as input, returning a vector of the `k` strongest elements.

4. **Sorting the Array**:
   ```cpp
   sort(arr.begin(), arr.end());
   ```

   - The input array is sorted in ascending order, which is essential for finding the median.

5. **Finding the Median**:
   ```cpp
   int n = arr.size();
   float m;
   if(n & 1) {
       m = arr[n / 2];
   } else {
       m = arr[n/2-1];
   }
   ```

   - The size of the array `n` is determined. The median is then computed:
     - If `n` is odd, the median is the middle element.
     - If `n` is even, the median is the element before the middle.

6. **Priority Queue Initialization**:
   ```cpp
   priority_queue<pair<float, int>, vector<pair<float, int>>, cmp> pq;
   ```

   - A max-heap priority queue `pq` is initialized to store pairs of strength and the corresponding element.

7. **Calculating Strength**:
   ```cpp
   for(int i = 0; i < n; i++) {
       pq.push({abs(arr[i] - m), arr[i]});
   }
   ```

   - For each element in the array, its strength (absolute difference from the median) is calculated and pushed into the priority queue.

8. **Selecting the Strongest Elements**:
   ```cpp
   vector<int> res;
   while(k--) {
       res.push_back(pq.top().second);
       pq.pop();
   }
   ```

   - The top `k` strongest elements are extracted from the priority queue and added to the result vector `res`.

9. **Returning the Result**:
   ```cpp
   return res;
   ```

   - Finally, the function returns the vector containing the strongest elements.

### Complexity

- **Time Complexity**: The overall time complexity of this solution is \(O(n \log n + k \log k)\):
  - \(O(n \log n)\) for sorting the array.
  - \(O(n \log n)\) for inserting elements into the priority queue.
  - \(O(k \log k)\) for extracting the top `k` elements from the priority queue.

- **Space Complexity**: The space complexity is \(O(n)\) due to the storage of the priority queue and the result vector.

### Conclusion

The provided solution effectively identifies the `k` strongest elements from an input array by leveraging sorting and a priority queue. This solution not only showcases an efficient approach to finding and sorting elements based on their strength relative to the median but also demonstrates good practices in using custom comparators for priority queues.

Key highlights of this approach include:

1. **Efficiency**: The method optimally balances sorting and retrieval of the strongest elements.
2. **Clarity**: The structured breakdown of steps makes the code easy to follow and understand.
3. **Custom Comparator**: The use of a custom comparator for the priority queue ensures the desired ordering of elements based on their strengths and values.

Overall, this solution serves as an excellent reference for tackling similar problems involving array manipulations and prioritization in competitive programming and algorithmic challenges.

[`Link to LeetCode Lab`](https://leetcode.com/problems/the-k-strongest-values-in-an-array/description/)

---
{{< youtube 5Hie-4QPNtI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
