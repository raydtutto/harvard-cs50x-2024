# Selection search

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

In selection sort, the idea of the algorithm is to find the
smallest unsorted element and add it to the end of the
sorted list.

Pseudocode:

```
Repeat until no unsorted elements remain:
• Search the unsorted part of the data to find the smallest value
• Swap the smallest found value with the first element of the unsorted part
```

We have an unsorted array.

Let's find the smallest value in the array:

<img src="img/28.png" alt="1">

Swap the smallest element with the first element:

<img src="img/29.png" alt="2">

We can indicate that `1` is sorted:

<img src="img/30.png" alt="2">

...

Repeat till the last element that is the smallest one left:

<img src="img/31.png" alt="3">

We can make a statement now: the array is sorted.

> #### Worst case scenario `O(n2)`
> We have to iterate over each of the `n` elements of the array (to find the smallest unsorted element) and we must
> repeat this process n times, since only one element gets sorted on each pass.

> #### Best case scenario `Ω(n2)`
> Exactly the same! There’s no way to guarantee the array is sorted until we go through this process
> for all the elements.