# Data Structures and Algorithms - C++

![Commit Activity][commit-activity-shield]
![Repo Size][repo-size-shield]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<details open="open">
  <summary><h2 style="display: inline-block">Table of Contents</h2></summary>
  <ol>
    <li><a href="#about-the-project">About the Project</a></li>
    <li><a href="#data-structures">Data Structures</a></li>
    <ol>
      <li><a href="#stack-adt">Stack ADT</a></li>
      <li><a href="#linked-list-adt">Linked List ADT</a></li>
      <li><a href="#queue-adt">Queue ADT</a></li>
      <li><a href="#double-ended-queue-deque-adt">Double-Ended Queue (Deque) ADT</a></li>
      <li><a href="#dictionary-adt">Dictionary ADT</a></li>
      <li><a href="#binary-tree-adt">Binary Tree ADT</a></li>
      <li><a href="#tree-adt">Tree ADT</a></li>
      <li><a href="#priority-queue-heap-adt">Priority Queue (Heap) ADT</a></li>
      <li><a href="#graph-adt">Graph ADT</a></li>
    </ol>
    <li><a href="#algorithms">Algorithms</a></li>
    <ol>
      <li><a href="#sorting">Sorting</a></li>
    </ol>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
  </ol>
</details>



## About The Project
This project contains my own implementation of fundamental data structures and
algorithms. It serves as an exercise to not only practice implementing the
theoretical knowledge, but also to practice writing industry-level code using 
modern C++ concepts. In no particular order, the following describes the goals
of the software  implemented in this project:
* Optimality (*i.e.* optimal space and time complexities) 
* Robustness (*i.e.* handle erroneous inputs)
* Scalability (*i.e.* design such that adding complexity to existing code is
               simple)
* Readability
  * Adhere to [Robert Martin](https://en.wikipedia.org/wiki/Robert_C._Martin)'s
    principles outlined in *Clean Code*
  * Adhere to [Google's C++ Style Guide](https://google.github.io/styleguide/cppguide.html)



## Data Structures
This section outlines the data strucutres implemented in this project. The data
structures will be grouped by abstract data type (ADT) in a respective
namespace and will all be contained within the `datastructure` namespace. For
example, the `DynamicStack` data strucutre is an implementation of the `Stack`
ADT, is contained within the `stack` namesapce, and may be used in the
following manor:
```cpp
DynamicStack<std::string> dynamic_stack =
    milesdiprata::stack::DynamicStack<std::string>();
dynamic_stack.Push("Hello, DynamicStack!");
```
Alternatively, dynamically allocating:
```cpp
Stack<std::string>* dynamic_stack =
    new milesdiprata::stack::DynamicStack<std::string>();
dynamic_stack->Push("Hello, heap-space DynamicStack!");
// ...
delete dynamic_stack;
```
However, if dynamic allocation is a must, then one should leverage smart
pointers:
```cpp
std::unique_ptr<milesdiprata::stack::Stack<std::string>> dynamic_stack =
    std::make_unique<milesdiprata::stack::DynamicStack<std::string>>();
dynamic_stack->Push("Hello, heap-space DynamicStack!");
```
These examples are simply meant to demonstrate the *implementation inheritance*
that is used in this project. In practice, the above statements are quite long
and I would personally use the `auto` keyword to save time. That is,
```cpp
// Preferred
auto dynamic_stack = milesdiprata::stack::DynamicStack<std::string>();
dynamic_stack.Push("Hello, DynamicStack!");

// If dynamic allocation is a must
auto dynamic_stack =
    std::make_unique<milesdiprata::stack::DynamicStack<std::string>>();
dynamic_stack->Push("Hello, heap-space DynamicStack!");
```


### Stack ADT
The stack ADTs are all currently implemented using *arrays*.
- [x] [Static stack](https://github.com/milesdiprata/cc-ds/blob/doc/src/milesdiprata/datastructure/stack/stack.h) (`milesdiprata::datastructure::StaticStack`)
- [x] [Dynamic stack](https://github.com/milesdiprata/cc-ds/blob/doc/src/milesdiprata/datastructure/stack/dynamic_stack.h) (`milesdiprata::datastructure::DynamicStack`)
- [x] [Static range stack](https://github.com/milesdiprata/cc-ds/blob/doc/src/milesdiprata/datastructure/stack/range_stack.h) (`milesdiprata::datastructure::StaticRangeStack`)
- [x] [Dynamic range stack](https://github.com/milesdiprata/cc-ds/blob/doc/src/milesdiprata/datastructure/stack/dynamic_range_stack.h) (`milesdiprata::datastructure::DynamicRangeStack`)


### Linked List ADT
- [ ] Singly linked list
- [ ] Doubly linked list
- [ ] Sorted linked list
- [ ] Circular linked list


### Queue ADT
#### Queue as Linked List
- [ ] Queue


### Double-Ended Queue (Deque) ADT
#### Deque as Linked List
- [ ] Deque


## Dictionary ADT
- [ ] Hash set
- [ ] Hash map


#### Binary Tree ADT
- [ ] Binary tree
- [ ] Binary search tree
- [ ] AVL (Adelson-Velsky and Landis) tree
- [ ] Red-black tree


### Tree ADT
- [ ] B-tree
- [ ] B+ tree


### Priority Queue (Heap) ADT
- [ ] Binary Heap


### Graph ADT
- [ ] Undirected graph
- [ ] Directed graph



## Algorithms


### Sorting
- [ ] Bubble sort
- [ ] Insertion sort
- [ ] Selection sort
- [ ] Merge sort
- [ ] Quick sort
- [ ] Heap sort
- [ ] Counting sort
- [ ] Radix sort


## License

Distributed under the MIT License. See `LICENSE` for more information.



## Contact

Miles di Prata - `milesdiprata3@gmail.com`

Project Link: [https://github.com/milesdiprata/cc-ds](https://github.com/milesdiprata/cc-ds)



## Acknowledgements

* [Best-README-Template](https://github.com/othneildrew/Best-README-Template)



[commit-activity-shield]: https://img.shields.io/github/commit-activity/m/milesdiprata/cc-ds?style=for-the-badge
[repo-size-shield]: https://img.shields.io/github/languages/code-size/milesdiprata/cc-ds?style=for-the-badge
[license-shield]: https://img.shields.io/github/license/milesdiprata/cc-ds.svg?style=for-the-badge
[license-url]: https://github.com/milesdiprata/cc-ds/blob/main/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/miles-di-prata-9aa746147/
