# Data structures

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

We have learned 4 different ways to store sets of data:
- Arrays
- Linked lists
- Hash tables
- Tries

There are even some variations on these (trees and heaps, quite similar to tries, stacks and queues
quite similar to arrays or linked lists, etc.) but this will generally cover most of what
we’re looking at in C.

> - How do all of these data structures measure up?
> - How do you know which to choose for your situation?

Usually it’s a matter of weighing the pros against the cons.

---

## Array

✅ **Pros**:

- **Lookup is great** – random access, constant time;
- Relatively **easy to sort**;
- Relatively **small size-wise**.

❌ **Cons**:
- **Insertion is bad** – lots of shifting to fit an element in the middle (insertion only works good for appending at the end of the list);
- **Deletion is bad** – lots of shifting after removing an element (deletion from the end is ok);
- **No size flexibility**, stuck with a fixed size (can't grow and shrink).

---

## Linked list

✅ **Pros**:
- **Insertion is easy** – just tack onto the front;
- **Deletion is easy** – once you find the element (no need to shift elements, just freeing the node).

❌ **Cons**:
- **Lookup is bad** – have to rely on linear search (no random access like an array has);
- Relatively **difficult to sort** – unless you’re willing to compromise on superfast insertion and instead sort
  as you construct;
- Relatively **small size-wise** (not as small as arrays).

--- 

## Hash table

✅ **Pros**:
- **Insertion is a two-step process** – hash, then add;
- **Deletion is easy** – once you find the element;
- **Lookup is on average better** than with linked lists because you have the benefit of a real-world constant factor.

❌ **Cons**:
- **Not an ideal data structure** if sorting is the goal – just use an array;
- Can run the **gamut of size**.

---

## Trie

- **Insertion is complex** – a lot of dynamic memory allocation, **but gets easier** as you go;

✅ **Pros**:
- **Deletion is easy** – just free a node;
- **Lookup is fast** – not quite as fast as an array, but almost;
- **Already sorted** – sorts as you build in almost all situations;

❌ **Cons**:
- Rapidly **becomes huge**, even with very little data present, not great if space is at a premium.