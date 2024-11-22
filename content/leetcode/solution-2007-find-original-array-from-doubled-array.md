
+++
authors = ["grid47"]
title = "Leetcode 2007: Find Original Array From Doubled Array"
date = "2024-04-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2007: Find Original Array From Doubled Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "z40B-Mr9_qk"
youtube_upload_date="2021-09-18"
youtube_thumbnail="https://i.ytimg.com/vi/z40B-Mr9_qk/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& chg) {
        
        if(chg.size() % 2) return vector<int>{};
        
        sort(chg.begin(), chg.end());
        map<int, int> mp;
        for(int i = 0; i < chg.size(); i++)
            mp[chg[i]]++;
        vector<int> ans;
        
        int i = 0;

        while((ans.size() < chg.size() / 2) && i < chg.size()) {
            
            if(chg[i] == 0) {
                if(mp[chg[i]] >= 2) {
                    mp[chg[i]] -= 2;
                    ans.push_back(chg[i]);                    
                }
                i++;
                continue;
            }
            
            if((mp.count(chg[i]) && mp.count(chg[i] * 2))) {
                ans.push_back(chg[i]);
                
                if(mp[chg[i]] == 1)
                mp.erase(chg[i]);
                else
                mp[chg[i]]--;
                
                if(mp[chg[i] * 2] == 1)
                mp.erase(chg[i] * 2);
                else
                mp[chg[i] * 2]--;                
                
                // cout << chg[i]     << " " << mp[chg[i]    ] << "\n";                
                // cout << chg[i] * 2 << " " << mp[chg[i] * 2] << "\n";
            }
            
            i++;
        }
        
        return ans.size() == chg.size() / 2? ans: vector<int>{};
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to find the original array from a modified array called `chg`. In this modified array, each element is either an element from the original array or double the value of an element from the original array. The goal is to determine if it’s possible to reconstruct the original array such that for every element `x` in the original array, `2 * x` exists in the modified array. If it's possible, we need to return the original array; otherwise, we return an empty array. 

For example, if `chg = [1, 2, 2, 4]`, we can reconstruct the original array as `[1, 2]` because for every `x` (in this case, `1` and `2`), `2 * x` (`2` and `4`) are present in `chg`.

### Approach

To solve this problem efficiently, we can follow these steps:

1. **Check the Length**: If the size of the modified array `chg` is odd, we cannot form pairs, so we immediately return an empty array.

2. **Sorting**: Sort the modified array to ensure we can easily access the smallest elements first, which helps in pairing them with their double values.

3. **Frequency Counting**: Use a map (or hash table) to count occurrences of each element in the sorted array.

4. **Building the Original Array**: Iterate through the sorted `chg` array and attempt to construct the original array:
   - If the current element is zero and it appears at least twice, we can add it to the original array.
   - For any other element, if both the element and its double exist in the frequency map, we add the element to the original array and decrease their counts accordingly.

5. **Validation**: After attempting to construct the original array, if its size is equal to half the size of the `chg` array, we return it. Otherwise, we return an empty array.

### Code Breakdown (Step by Step)

Let’s dissect the code and understand its components:

1. **Class Definition**: We define a class named `Solution` to encapsulate our method.

    ```cpp
    class Solution {
    public:
    ```

2. **Method Declaration**: The method `findOriginalArray` accepts a vector of integers (`chg`) and will return the original array.

    ```cpp
    vector<int> findOriginalArray(vector<int>& chg) {
    ```

3. **Odd Length Check**: We first check if the size of `chg` is odd. If it is, we return an empty vector because we cannot form pairs.

    ```cpp
    if(chg.size() % 2) return vector<int>{};
    ```

4. **Sorting**: We sort the `chg` array to ensure we can process elements from the smallest to the largest.

    ```cpp
    sort(chg.begin(), chg.end());
    ```

5. **Frequency Map**: We create a map `mp` to count occurrences of each element in `chg`.

    ```cpp
    map<int, int> mp;
    for(int i = 0; i < chg.size(); i++)
        mp[chg[i]]++;
    ```

6. **Result Vector Initialization**: We initialize an empty vector `ans` to store the elements of the original array.

    ```cpp
    vector<int> ans;
    ```

7. **Iterating Through `chg`**: We use a while loop to process the elements until we either construct half the size of `chg` or exhaust the elements.

    ```cpp
    int i = 0;
    while((ans.size() < chg.size() / 2) && i < chg.size()) {
    ```

8. **Handling Zeros**: If the current element is zero and its count in the map is at least two, we can add it to the original array and decrease its count by two.

    ```cpp
    if(chg[i] == 0) {
        if(mp[chg[i]] >= 2) {
            mp[chg[i]] -= 2;
            ans.push_back(chg[i]);
        }
        i++;
        continue;
    }
    ```

9. **Checking for Pairs**: For non-zero elements, we check if both the current element and its double exist in the frequency map. If they do, we add the element to the original array and decrement their counts.

    ```cpp
    if((mp.count(chg[i]) && mp.count(chg[i] * 2))) {
        ans.push_back(chg[i]);
        
        if(mp[chg[i]] == 1)
            mp.erase(chg[i]);
        else
            mp[chg[i]]--;
        
        if(mp[chg[i] * 2] == 1)
            mp.erase(chg[i] * 2);
        else
            mp[chg[i] * 2]--;                
    }
    ```

10. **Incrementing the Index**: After processing, we increment the index to move to the next element.

    ```cpp
    i++;
    ```

11. **Final Validation**: After the loop, we check if the size of `ans` equals half of the size of `chg`. If it does, we return `ans`; otherwise, we return an empty vector.

    ```cpp
    return ans.size() == chg.size() / 2 ? ans : vector<int>{};
    ```

### Complexity

The time complexity of this solution is O(n log n) due to the sorting step, where `n` is the size of the input array `chg`. The subsequent operations involving the map are linear in relation to the size of the array. The space complexity is O(n) for storing the frequency counts in the map.

### Conclusion

In conclusion, the code provides an efficient and systematic approach to reconstructing the original array from a modified version that includes both original and doubled values. By leveraging sorting and a frequency count, we can determine valid pairs without excessive comparisons. This approach ensures that we effectively explore potential pairs while maintaining clarity and efficiency. The solution elegantly handles edge cases, such as the presence of zeros, and utilizes clear logic to validate the construction of the original array. Overall, this implementation is a solid example of how to approach array manipulation problems in algorithm design, demonstrating both effectiveness and clarity in reasoning.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-original-array-from-doubled-array/description/)

---
{{< youtube z40B-Mr9_qk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
