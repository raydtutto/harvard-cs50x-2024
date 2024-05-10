# Merge sort

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

In merge sort, the idea of the algorithm is to sort smaller arrays
and then combine those arrays together (merge them) in sorted
order.

Pseudocode:

```
- Sort the left half of the array (assuming n > 1)
- Sort the right half of the array (assuming n > 1)
- Merge the two halves together
```

Let's sort the left half of the array:

<img src="img/32.png" alt="1">

Let's divide the left half of the array:

<img src="img/33.png" alt="2">

Let's sort it the left half of the left half of the array:

<img src="img/34.png" alt="3">

Go back to the remaining right half:

<img src="img/35.png" alt="4">

Let's divide, then go to the left half of this right half of the array and sort it:

<img src="img/36.png" alt="5">

Let's sort the last element in the left half:

<img src="img/37.png" alt="5">

Merge two halves together by deciding which has the lower element. Place that element in a first position
of the new hypothetical 2-element array:

<img src="img/38.png" alt="5">

Compare `2` against `nothing` and place it in the last array:

<img src="img/39.png" alt="5">

Now we need to merge all elements in the left half:

<img src="img/40.png" alt="5">

Compare first element of the left part `5` and the first element of the right part `1`.
It's `1`, so it becomes the first element of the new 3-element array:

<img src="img/41.png" alt="5">

Compare first element of the left part `5` and the first element of the right part `2`.
Place this element after the first element of the new 3-element array. Do the same to the last element:

<img src="img/42.png" alt="5">

We have sorted the left part of the array.

...

Now we have to go to the right half and do the same steps:

<img src="img/43.png" alt="5">

So we have sorted the right and the left half of the array.

Let's merge those halves by comparing the first element of the left part and the first element of the right part.

`1` < `3`

So the first element of the 6-element array is `1`:

<img src="img/44.png" alt="5">

Let's compare the first element of the left part and the first element of the right part again:

`2` < `3`

<img src="img/45.png" alt="5">

...

Do the same to other elements:

<img src="img/46.png" alt="5">

Sorted complete.

> #### Worst case scenario `O(n log n)`
> We have to split n elements up and then recombine them, effectively doubling the sorted sub-arrays as we build
> them up. (combining sorted 1-element arrays into 2-element arrays, combining sorted 2-element arrays into
> 4-element arrays…).

> #### Best case scenario `Ω(n log n)`
> The array is already perfectly sorted. But we still have to split and recombine it back together with this algorithm.

