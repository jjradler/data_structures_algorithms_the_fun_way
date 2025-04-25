# NOTES: Dynamic Data Structures

2025/04/25

## Arrays and their Limits:

This is particularly useful to study as, frankly, `C++` standard library’s tools for working with arrays in any substantial way are… frustrating. Typically, one has to roll their own or pass additional data unless you use a specific library like the `array.h` library in more recent versions of `C++`. 

Here I’ll roll my own tools for arrays just to go through the exercise, but also we will get into when it might be appropriate to consider a different structure like a *linked list* despite the additional cost to data storage due to having to keep track of both the data values *and* their links. 

### Array Doubling: 

A common technique for dealing with running out of space in pre-allocated array memory (cough, cough, `C`… ) is *array doubling*. It’s very simply copying the current contents of an array over to a new array of double length to open up more space to append elements. 

As one would imagine, this can get very expensive for large arrays. 

In pseudocode, we might double an existing array like this: 

``` pseudocode
ArrayDouble(Array: old_array): 
	Int: length = length of the old_array
	Array: new_array = empty array of size (length * 2)
	Int: j = 0
  WHILE j < length: 
  	new_array[j] - old_array[j]
  	j = j + 1
  RETURN new_array (or a pointer to the new array as the case may be in C/C++...)
```

Another solution might be to use more-or-less random memory cells as allocated by the OS but creating links between them (some sort of… “linked” list???) This will require breaking out pointers (\*cracks knuckles\*). 

### Pointers and References: 

This right here is why we need pointers. Sometimes you have to sprinkle your allocated data all over the place, and the only way to keep track of it all is to “point” to them. That’s essentially all pointers are in this context, which… makes a lot more sense to me than someone saying: 

> A pointer is a variable that stores only the addresses of an item in computer memory.

No shade on the author, he’s actually the one who suggests using linked lists as an ideal case for illustrating why pointers are useful and not just overly complex anachronisms or arcane incantations for summoning eldritch horrors from computer RAM… but I digress.

Indeed, the Author himself addresses this directly in the very next paragraph.  

> The astute reader may ask, “What is the purpose of a variable that simply points to another location in memory? I thought the variable’s name already served this function. Why not store your data in the variable like a normal person? Why do you always have to make things so complicated?” Don’t listen to the skeptics. Pointers are the essential ingredient in dynamic data structures, as we’ll see shortly.
>
> Kubica, Jeremy. Data Structures the Fun Way: An Amusing Adventure with Coffee-Filled Examples (p. 30). (Function). Kindle Edition. 

They’re also useful for passing around large or unwieldy data sets between various functions or other structures in a program. Instead of copying everything every time you use it, just point to where it can be viewed (accessed) by everyone else. 

Simple, right? Kubica uses the example of a large, complex set of documents in an office that everyone needs to have access to. Instead of making a huge book of copies for everyone involved in a project, you store a master copy somewhere in the office and leave notes for other people where they can find what they need if they need to access it. 

Null Pointers… they denote that a given pointer isn’t currently pointing to anything valid or useful. It just doesn’t point to anything yet. 

**Pointers in Different Languages:** `C` and `C++` provide an uncomfortable (and sometimes complicated) degree of access and usage of pointers more or less directly. `Python` and others use *references* that look like normal variables syntactically but allow the reference of another variable (the first word that comes to mind for me is ‘aliases’). 

Sometimes the pointer syntax can be gnarly and confusing (cough, cough, `C` again…)

### Linked Lists: 

Simplest dynamic data structures and fancy cousin to the humble `Array`. They are *ordered* lists (*e.g.,* accessing and indexing follows the order the elements were inserted.) where a *node* represents a cell in the list and each node has a *link* (a pointer!) to the next node after it. 

Pythonistas will probably start to think about `iterators` now, I imagine. I certainly did. 

A basic linked list consists of a collection of nodes. These nodes have a structure like: 

``` pseudocode
LinkedListNode{
	Type: value
	LinkedListNode: next pointer
}
```

Linked lists do, however take additional memory: for an array of size $K$, storing values of $N$ bytes in each cell, our array is of size $K \times N$ bytes. Linked Lists have an additional pointer on *each node* that might be $M$ bytes in size, thus a linked list will require $K\times(M + N)$ bytes. Unless the pointer values are much smaller than the cell sizes of a corresponding array, the overhead increase is significant!

But, as with everything else, this overhead increase provides comparably significant increases to flexibility of the structure. 

Why? 

Arrays need contiguous blocks of memory cells. Linked Lists do not. 

Arrays need possibly costly doubling or shifting techniques to insert, delete, or manipulate their contents. Linked Lists do not. 

In other words, a Linked List can grab any old random memory cell that’s assigned to it by the OS and still function just as well, unlike those *prima donna* Arrays that require potentially large contiguous cells in memory.

A program will typically keep track of a linked list by keeping a single pointer at the *head* of the list (the beginning) and then iterating through the links to get to the node of interest. 

```pseudocode
LinkedListLookup(LinkedListNode: head, Int: element_number):
	LinkedListNode: current = head
	Int: count = 0
	
	WHILE count < element_number AND current != NULL:
		current = current.next
		count = count + 1
	return current
```

How does this work, exactly? 

(insert discussion)

Implementing this might look like constructing a linked-list class comprised of nodes and linked-list operations like `lookup`, `insert`, `remove`, or `append`. I think the best way to internalize this is to build something like this, including the class for `Node`, in `C++` using the most basic libraries available (essentially, rolling our own again.)

The buildout will start with: 

1. Basic Node class construction. 
2. Linked List class construction. 
3. Adding lookup methods to the linked list. 
4. Adding insert and remove to the linked list.
5. Adding append to the linked list. 
6. Adding some diagnostic methods like size() for actually using the thing. 

