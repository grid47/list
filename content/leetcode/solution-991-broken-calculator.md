
+++
authors = ["grid47"]
title = "Leetcode 991: Broken Calculator"
date = "2024-07-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 991: Broken Calculator in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XIiLnBV664A"
youtube_upload_date="2021-02-21"
youtube_thumbnail="https://i.ytimg.com/vi/XIiLnBV664A/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue >= target) return startValue - target;
        
        if(target % 2 == 0) return 1 + brokenCalc(startValue, target / 2);
        
        return 1 + brokenCalc(startValue, target +1);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the minimum number of operations required to convert a given **start value** to a **target value**. The allowed operations are:
1. **Multiply by 2**.
2. **Subtract 1**.

You need to determine the least number of operations to transform the **start value** into the **target value**. In this problem, the transformation may involve both increasing and decreasing the target value, using a combination of these operations.

### Approach

To solve this problem, we need to work backwards from the **target value** to the **start value**. This strategy is commonly used in problems where operations may work in both directions. By reversing the operations, we can determine the fewest steps needed to reach the target.

#### Key Observations:
1. If the target value is **greater than** or equal to the start value, the problem reduces to simply subtracting the start value from the target value (`target - startValue`), because we can always decrease the target to match the start value in `target - startValue` steps.
2. If the target value is **less than** the start value, the solution becomes more complicated. We need to think about whether we can multiply the target by 2 or subtract 1 from the target to move towards the start value.
3. If the target is **even**, the reverse operation of multiplying by 2 is dividing by 2. Hence, we can keep dividing the target by 2 until we can't.
4. If the target is **odd**, the only option is to add 1 (because adding 1 will turn an odd number into an even one, which can then be halved in the next step).

Using these observations, we can recursively transform the target back to the start value using a greedy approach:
- If the target is even, we divide the target by 2.
- If the target is odd, we add 1 to the target.

This leads us to a solution where we reduce the target value step by step, keeping track of the number of operations required.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        // Base case: if the startValue is greater than or equal to the target
        if(startValue >= target) return startValue - target;
        
        // If the target is even, divide the target by 2
        if(target % 2 == 0) return 1 + brokenCalc(startValue, target / 2);
        
        // If the target is odd, increment the target by 1
        return 1 + brokenCalc(startValue, target + 1);
    }
};
```

#### Step-by-Step Explanation:

1. **Base Case**:
   - First, we check if the `startValue` is greater than or equal to the `target`. In this case, we don't need to do anything but subtract 1 repeatedly, so the number of operations required is simply the difference between `startValue` and `target`.
   - If `startValue >= target`, return `startValue - target`.

2. **Recursive Case**:
   - If the `target` is even, it means that the last operation we performed was multiplying by 2. To reverse this, we divide the `target` by 2 and add 1 to the operation count.
   - If `target % 2 == 0`, return `1 + brokenCalc(startValue, target / 2)`.

   - If the `target` is odd, the only valid operation is to add 1 (since subtracting 1 from an odd number would make it even, which can then be halved in subsequent operations). We add 1 to the `target` and continue recursively.
   - If `target % 2 != 0`, return `1 + brokenCalc(startValue, target + 1)`.

3. **Recursive Nature**:
   - The recursive function reduces the problem by halving the target when it's even, or by incrementing it when it's odd. This reduces the problem size by a factor of 2 or 1 step at a time.
   - The recursion continues until the base case (`startValue >= target`) is reached.

### Example Walkthrough:

#### Example 1: `startValue = 2, target = 10`

1. **First Step**: `target = 10` (even) → divide by 2 → `target = 5`, operation count: 1
2. **Second Step**: `target = 5` (odd) → add 1 → `target = 6`, operation count: 2
3. **Third Step**: `target = 6` (even) → divide by 2 → `target = 3`, operation count: 3
4. **Fourth Step**: `target = 3` (odd) → add 1 → `target = 4`, operation count: 4
5. **Fifth Step**: `target = 4` (even) → divide by 2 → `target = 2`, operation count: 5

We now have reached the `startValue` with 5 operations.

#### Example 2: `startValue = 3, target = 12`

1. **First Step**: `target = 12` (even) → divide by 2 → `target = 6`, operation count: 1
2. **Second Step**: `target = 6` (even) → divide by 2 → `target = 3`, operation count: 2

We now have reached the `startValue` with 2 operations.

### Time and Space Complexity Analysis

#### Time Complexity:

The time complexity of this solution depends on the number of recursive calls required to reduce the `target` to the `startValue`.

- **Recursive Calls**: In the worst case, each recursive call either divides the `target` by 2 (when the `target` is even) or increments the `target` by 1 (when the `target` is odd). This results in a logarithmic reduction of the target value when the target is even.
- **Worst-Case Time Complexity**: Since each operation reduces the target in some form, the time complexity of the recursion is **O(log(target))**.

#### Space Complexity:

- **Space Complexity**: Since we are using recursion, each recursive call consumes space on the call stack. The depth of recursion is **O(log(target))**, as the target is halved in each recursive step. Therefore, the space complexity is also **O(log(target))**.

### Conclusion

This solution provides an efficient way to calculate the minimum number of operations required to transform the `startValue` into the `target`. By recursively reducing the target value (either by dividing by 2 or adding 1), we ensure that the solution is optimal and works in logarithmic time. The use of recursion allows the solution to be both simple and effective, leveraging the properties of even and odd numbers to determine the minimal transformation path. The time and space complexities of the solution are logarithmic, making it suitable for large input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/broken-calculator/description/)

---
{{< youtube XIiLnBV664A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
