# 📚 Longest Common Prefix

## 📌 Problem Statement

Given an array of strings, find the **longest common prefix** among all the strings.

If there is **no common prefix**, return an empty string `""`.

---

## 📝 Example 1

### Input

```text
["flower","flow","flight"]
```

### Output

```text
"fl"
```

### Explanation

All strings start with **"fl"**, so the longest common prefix is:

```text
fl
```

---

## 📝 Example 2

### Input

```text
["dog","racecar","car"]
```

### Output

```text
""
```

### Explanation

No common prefix exists.

---

# 💡 Intuition

Instead of comparing every string with every other string,

we first **sort the array**.

After sorting:

- The **smallest** string comes first.
- The **largest** string comes last.

If these two strings share a common prefix, then **every string between them must also share that prefix**.

So we only need to compare the **first** and **last** strings.

---

# ✅ C++ Solution

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string> arr) {

        if (arr.empty())
            return "";

        sort(arr.begin(), arr.end());

        string first = arr[0];
        string last = arr[arr.size() - 1];

        string ans = "";

        int minlength = min(first.size(), last.size());

        for (int i = 0; i < minlength; i++) {

            if (first[i] != last[i])
                break;

            ans += first[i];
        }

        return ans;
    }
};
```

---

# 🔍 Step-by-Step Explanation

## Step 1: Check if the Array is Empty

```cpp
if(arr.empty())
    return "";
```

### Why?

If there are no strings, then there is no common prefix.

Example

```text
Input

[]

Output

""
```

---

## Step 2: Sort the Array

```cpp
sort(arr.begin(), arr.end());
```

Sorting arranges the strings in **lexicographical (dictionary) order**.

### Example

Before Sorting

```text
flower
flow
flight
```

After Sorting

```text
flight
flow
flower
```

### Diagram

```
Before

flower
flow
flight

        │
        ▼

After Sorting

flight
flow
flower
```

---

## Step 3: Store the First and Last Strings

```cpp
string first = arr[0];
string last = arr[arr.size() - 1];
```

After sorting

```text
first = "flight"

last = "flower"
```

Diagram

```
flight
   ↑

flow

flower
      ↑
```

We only compare these two strings.

---

## Step 4: Create an Empty Answer String

```cpp
string ans = "";
```

Initially

```text
ans = ""
```

The common prefix will be stored here.

---

## Step 5: Find the Minimum Length

```cpp
int minlength = min(first.size(), last.size());
```

### Why?

We only compare characters up to the shorter string.

Example

```text
first = "flow"

last = "flower"

Minimum Length = 4
```

---

## Step 6: Compare Characters

```cpp
for(int i = 0; i < minlength; i++)
```

Compare characters one by one.

---

### First Character

```
flight
^

flower
^
```

```text
f == f
```

Answer

```text
f
```

---

### Second Character

```
flight
 ^

flower
 ^
```

```text
l == l
```

Answer

```text
fl
```

---

### Third Character

```
flight
  ^

flower
  ^
```

Characters

```text
i

o
```

Different

Stop comparing.

---

## Step 7: Return the Answer

```cpp
return ans;
```

Output

```text
fl
```

---

# 📊 Dry Run

### Input

```text
["flower","flow","flight"]
```

After Sorting

```text
["flight","flow","flower"]
```

### Comparison Table

| Index | First String | Last String | Match | Answer |
|------:|--------------|-------------|:-----:|--------|
| 0 | f | f | ✅ | f |
| 1 | l | l | ✅ | fl |
| 2 | i | o | ❌ | Stop |

Final Answer

```text
fl
```

---

# 🎯 Visual Explanation

### Input

```text
flower
flow
flight
```

↓

Sort

```text
flight
flow
flower
```

↓

Compare

```
flight
flower
```

```
f ✔

↓

l ✔

↓

i ✘ o
```

↓

Answer

```text
fl
```

---

# 📝 Example 2

### Input

```text
["dog","racecar","car"]
```

### After Sorting

```text
car
dog
racecar
```

Compare

```
car
^

racecar
^
```

Characters

```text
c != r
```

Return

```text
""
```

---

# 🤔 Why Compare Only the First and Last Strings?

Suppose

```text
apple
application
apply
apt
```

After sorting

```text
apple
application
apply
apt
```

Compare

```text
apple

apt
```

Common Prefix

```text
ap
```

Every string between them also starts with **"ap"**.

So checking the first and last strings is enough.

---

# 🌟 Complete Flow Diagram

```
Input Strings

flower
flow
flight

        │
        ▼

Sort the Array

flight
flow
flower

        │
        ▼

Take First String

flight

Take Last String

flower

        │
        ▼

Compare Characters

f == f ✔

↓

l == l ✔

↓

i != o ✘

↓

Stop

↓

Answer = fl
```

---

# ⏱ Time Complexity

Sorting

```text
O(n log n)
```

Comparing first and last strings

```text
O(m)
```

where `m` is the length of the smaller string.

### Total

```text
O(n log n + m)
```

---

# 💾 Space Complexity

Only a few extra variables are used.

```text
O(1)
```

(ignoring the internal space used by the sorting algorithm)

---

# ✅ Key Points

- Check if the array is empty.
- Sort the array.
- Compare only the first and last strings.
- Stop when characters don't match.
- Store matching characters in the answer.
- Return the longest common prefix.

---

# 📌 Summary

✔ Sort the strings.

✔ Compare the first and last string.

✔ Add matching characters to the answer.

✔ Stop at the first mismatch.

✔ Return the answer.

### Complexity

- **Time Complexity:** `O(n log n + m)`
- **Space Complexity:** `O(1)`
