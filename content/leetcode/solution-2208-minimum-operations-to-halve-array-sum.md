
+++
authors = ["grid47"]
title = "Leetcode 2208: Minimum Operations to Halve Array Sum"
date = "2024-03-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2208: Minimum Operations to Halve Array Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "4HrGj7pwQww"
youtube_upload_date="2022-03-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/4HrGj7pwQww/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int halveArray(vector<int>& nums) {
        int n = nums.size();
        double sum = 0;
        priority_queue<double, vector<double>, less<double>> pq;
        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
            sum += nums[i];
        }
        
        sum = sum / 2;
        
        double tmp = 0;
        int cnt = 0;
        while(tmp < sum && !pq.empty()) {

            double x = (pq.top() / 2);
            tmp += x;

            pq.pop();
            pq.push(x);

            cnt++;
        }
        
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement
The problem requires reducing the sum of an array `nums` by halving its elements until the total sum is reduced to at least half of its original value. You are to return the number of operations (halving the largest element at each step) required to achieve this goal.

### Approach
This problem can be efficiently tackled using a **priority queue (max heap)**, which allows us to repeatedly halve the largest element in the array. By halving the largest element in each step, we ensure that the sum decreases as quickly as possible. We will keep track of the sum and continue the process until the sum is reduced to half of its initial value.

The idea is:
1. Calculate the total sum of the array.
2. Using a priority queue (max heap), repeatedly halve the largest element and update the sum.
3. Continue halving the largest element until the sum is reduced to half.
4. Return the number of halving operations required.

### Code Breakdown (Step by Step)

1. **Initialize Variables:**
   ```cpp
   int n = nums.size();
   double sum = 0;
   priority_queue<double, vector<double>, less<double>> pq;
   ```
   - `n`: Stores the size of the array `nums`.
   - `sum`: A variable to store the total sum of all elements in the array. It will be later divided by 2 to calculate the target sum.
   - `pq`: A max heap (priority queue) to store the elements in decreasing order. This will allow us to access and modify the largest element at each step.

2. **Populating the Priority Queue and Calculating the Total Sum:**
   ```cpp
   for(int i = 0; i < n; i++) {
       pq.push(nums[i]);
       sum += nums[i];
   }
   ```
   - Loop through the array `nums`, push each element into the priority queue, and calculate the total sum of the elements.

3. **Calculate the Target Sum:**
   ```cpp
   sum = sum / 2;
   ```
   - The target sum is half of the total sum, which is the point at which we stop halving elements.

4. **Halving the Largest Element:**
   ```cpp
   double tmp = 0;
   int cnt = 0;
   while(tmp < sum && !pq.empty()) {
       double x = (pq.top() / 2);
       tmp += x;
       pq.pop();
       pq.push(x);
       cnt++;
   }
   ```
   - `tmp`: A variable to track the reduced sum after each halving operation.
   - `cnt`: A counter to track the number of halving operations performed.
   - Inside the `while` loop:
     - We keep halving the largest element (`pq.top()`).
     - Add the halved value to `tmp`.
     - After halving, replace the top element in the priority queue with its halved value to ensure the next largest element is ready for halving.
     - Continue this process until the sum is reduced to at least half of the original value, or the priority queue is empty.
   - For each halving, increment the counter `cnt`.

5. **Return the Number of Operations:**
   ```cpp
   return cnt;
   ```
   - After the loop completes, return the number of halving operations performed to achieve the target sum.

### Complexity

#### Time Complexity:
- **O(n log n)**: 
  - The time complexity is dominated by the operations on the priority queue:
    - Inserting each element into the priority queue takes O(log n), and we do this `n` times.
    - Each halving operation involves popping and pushing an element from the priority queue, each of which takes O(log n) time.
  - Therefore, the overall time complexity is O(n log n).

#### Space Complexity:
- **O(n)**: 
  - We store all `n` elements in the priority queue, so the space complexity is O(n), where `n` is the number of elements in the array.

### Conclusion
This solution efficiently solves the problem using a max heap to perform the halving operations on the largest elements of the array. The priority queue allows us to always access and modify the largest element in logarithmic time, making this approach both effective and efficient. By continuing the halving process until the sum is reduced to half, we ensure the minimal number of operations to reach the target sum. The time complexity of O(n log n) is optimal for problems involving repeated access and modification of the largest element in a collection, making this approach suitable for large input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-operations-to-halve-array-sum/description/)

---
{{< youtube 4HrGj7pwQww >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
