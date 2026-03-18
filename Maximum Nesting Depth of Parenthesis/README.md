# 🔢 Maximum Nesting Depth of Parentheses

## 🧩 Problem Statement

Given a **valid parentheses string** `s`, return the **maximum nesting depth** of the parentheses.

The **nesting depth** is defined as the maximum number of nested parentheses at any point in the string.

---

## 🧪 Examples

### Example 1

```text
Input:
s = "(1+(2*3)+((8)/4))+1"

Output:
3
```

### Explanation:

Digit `8` is inside **3 nested parentheses**, so the depth is `3`.

---

### Example 2

```text
Input:
s = "(1)+((2))+(((3)))"

Output:
3
```

### Explanation:

Digit `3` is inside **3 nested parentheses**, so the depth is `3`.

---

## 🚀 Approach

### 💡 Key Idea

We track how deeply nested we are while traversing the string:

* `'('` → Move **one level deeper**
* `')'` → Move **one level up**
* Keep updating the **maximum depth reached**

---

## 🧠 Intuition

* Think of parentheses like **levels in a game**
* Every `'('` → go **down one level**
* Every `')'` → go **up one level**
* The deepest level reached is the answer

---

## 🧮 Algorithm

1. Initialize:

   * `p = 0` → current depth
   * `ans = 0` → maximum depth

2. Traverse each character in the string:

   * If `'('` → increment `p`
   * If `')'` → decrement `p`
   * Update `ans = max(ans, p)`

3. Return `ans`

---

## 🔍 Dry Run

For:

```text
s = "(1+(2*3)+((8)/4))+1"
```

| Character | Depth (p) | Max Depth (ans) |
| --------- | --------- | --------------- |
| (         | 1         | 1               |
| (         | 2         | 2               |
| )         | 1         | 2               |
| (         | 2         | 2               |
| (         | 3         | 3               |
| )         | 2         | 3               |
| )         | 1         | 3               |
| )         | 0         | 3               |

✅ Final Answer = **3**

---

## 💻 Code (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method to compute maximum depth of parentheses
    int maxDepth(string s) {
        int p = 0;  
        int ans = 0;

        for (char x : s) {
            // Increase depth on open parenthesis
            if (x == '(') p++;

            // Decrease depth on close parenthesis
            else if (x == ')') p--;

            // Update maximum depth encountered
            ans = max(ans, p);
        }

        return ans;
    }
};

// Main function to test the method
int main() {
    Solution sol;
    string s = "(1+(2*3)+((8)/4))+1";

    int result = sol.maxDepth(s);
    cout << "Max Depth: " << result << endl;

    return 0;
}
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n)`
  → We traverse the string once

* **Space Complexity:** `O(1)`
  → Only constant extra space is used

---

## 🎯 Summary

* Use a counter to track current depth
* Increase on `'('`, decrease on `')'`
* Keep track of maximum depth reached
* Efficient and simple single-pass solution 🚀

---

## 🏁 Conclusion

This problem is a great example of how **simple traversal + tracking state** can solve what looks like a complex nesting problem.

> Just track how deep you go — and remember the maximum!

---
