# Common DS in C

this is a repo where i attempt to recreate common data-structures in C from scratch, mostly the managing of each DS is done via functions, the functions naming will follow a template being `{ds_name}_{function}` and each function will take a pointer to the target DS as it's first arguments, i will also try to add docs to each ana every function and datatype to ensure that nothing is ambagious

---

## Vectors

a vector is an array that grows dynamically, unlike other arrays that are of fixe-sizes, a vector grows, of course it's not that simple.

inside a vector is an internal array, when this array is full, the vector will reallocate the space of that array to allow it to accept more elements, so we will have to constantly expand and manage the array.

another challenge is i want to allow the vector to store user-defined types, such as structs and so on

as per the functionality i want to have the following functions:

- new: creates a new vector
- drop_vector: release the vector and the internal array
- push: appends to the end
- pop: removes from the end
- at: returns the element at a given index, and possibly allow the use of negative value
- index: returns the index of the first occurrence of the given element
- \_resize: hidden, it will expand/shrink the internal array on demand, won't be accessible by the user

i also wanted to add `contains` but `index` will do that job instead

---

## Singly-linked list

very similar to the dynamic array, except this time each node points to the next one, unlike arrays, structs and vectors, linked lists are not stored in contiguous memory, each node is somewhere different.

we traverse the list by reading the pointer to the next node in the list, the last one (tail) points to `NULL`

for the singly-linked list list i want it to have the following:

- new: create a new linked list
- append: push a new node at the end -new tail-
- add: push a node at a certain index
- delete: drops a node, links it's previous to it's next
- index: the index of a node
- at: return the node at a certain index
