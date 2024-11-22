
+++
authors = ["grid47"]
title = "Leetcode 2211: Count Collisions on a Road"
date = "2024-03-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2211: Count Collisions on a Road in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Cy_E7rABX_U"
youtube_upload_date="2022-03-20"
youtube_thumbnail="https://i.ytimg.com/vi/Cy_E7rABX_U/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countCollisions(string dir) {
        int l = 0, r = dir.size() - 1;
        int n = dir.size();
        while(l < n && dir[l] == 'L')
            l++;
        
        while(r >= 0 && dir[r] == 'R')
            r--;
        
        int cnt = 0;
        for(int i = l; i <= r; i++)
            if(dir[i] != 'S')
                cnt++;
        
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement
The problem asks us to calculate the number of collisions that happen in a traffic scenario where cars are moving in different directions. The cars can either move to the left ('L'), to the right ('R'), or stay still ('S'). A collision occurs when two cars are facing towards each other, meaning one car is moving left ('L') and the other is moving right ('R'). We are to count how many collisions happen as cars move towards each other.

### Approach
The solution can be efficiently implemented by:
1. Scanning from both ends of the string to skip over cars that are not involved in collisions.
2. Identifying the region in the string where collisions are possible, i.e., between cars moving in opposite directions.
3. Counting the number of collisions based on the positions of these cars.
   
To solve this, we:
- First skip any cars moving to the left at the beginning (`L` characters).
- Then skip any cars moving to the right at the end (`R` characters).
- The remaining cars in between are the ones that may collide. For these, we check if they are either moving left ('L') or right ('R') and count them as collisions.

### Code Breakdown (Step by Step)

1. **Initialize Pointers:**
   ```cpp
   int l = 0, r = dir.size() - 1;
   int n = dir.size();
   ```
   - `l` and `r` are pointers that will be used to scan from the left and right ends of the string, respectively.
   - `n` stores the size of the string `dir`.

2. **Skipping Cars Moving Left at the Beginning:**
   ```cpp
   while(l < n && dir[l] == 'L')
       l++;
   ```
   - We increment `l` while the character at position `l` is 'L'. This is because cars moving left at the start won't collide with any other cars, as they are already moving in the opposite direction.

3. **Skipping Cars Moving Right at the End:**
   ```cpp
   while(r >= 0 && dir[r] == 'R')
       r--;
   ```
   - We decrement `r` while the character at position `r` is 'R'. These cars are also not involved in collisions as they are already moving away from the center of the traffic.

4. **Counting Collisions:**
   ```cpp
   int cnt = 0;
   for(int i = l; i <= r; i++)
       if(dir[i] != 'S')
           cnt++;
   ```
   - We iterate from `l` to `r`, which marks the region where collisions can occur.
   - For each car in this region, if it is either 'L' or 'R' (not 'S'), it indicates a collision with another car.
   - Each such car contributes to the collision count, and we increment `cnt` accordingly.

5. **Return the Collision Count:**
   ```cpp
   return cnt;
   ```
   - Finally, after counting the collisions, we return the result stored in `cnt`.

### Complexity

#### Time Complexity:
- **O(n)**: 
  - The solution involves a linear scan of the string `dir`. First, we increment `l` and decrement `r` to find the valid collision region. Then, we iterate over the remaining cars to count the collisions. Since each operation (increment, decrement, and iteration) takes constant time, the overall time complexity is O(n), where `n` is the size of the string `dir`.

#### Space Complexity:
- **O(1)**: 
  - The space complexity is O(1) as we are only using a few variables (`l`, `r`, `cnt`) to track the positions and the result. We do not use any additional space that scales with the input size.

### Conclusion
This solution is efficient and simple, providing an optimal way to count collisions in a traffic scenario. The two-pointer technique, combined with direct counting, ensures that the solution runs in linear time O(n), making it well-suited for large inputs. The space complexity is constant (O(1)), which ensures that the solution is memory-efficient. By focusing on the portion of the array where collisions can occur and skipping irrelevant elements, this approach is both time-efficient and space-efficient, making it ideal for solving problems of this nature.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-collisions-on-a-road/description/)

---
{{< youtube Cy_E7rABX_U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
