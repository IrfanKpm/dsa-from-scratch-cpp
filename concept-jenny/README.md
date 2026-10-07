<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>DSA Implementation Problems - Checklist</title>

    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            max-width: 900px;
            margin: 30px auto;
            padding: 0 20px;
        }

        h1 {
            text-align: center;
        }

        h2 {
            margin-top: 30px;
            border-bottom: 1px solid #ccc;
            padding-bottom: 5px;
        }

        ol {
            padding-left: 30px;
        }

        li {
            margin: 8px 0;
        }

        label {
            cursor: pointer;
        }

        input[type="checkbox"] {
            margin-right: 8px;
        }
    </style>
</head>

<body>

    <h1>DSA Implementation Problems</h1>

    <h2>Arrays</h2>
    <ol>
        <li><label><input type="checkbox" checked>Implement an array with declaration and initialization.</label></li>
        <li><label><input type="checkbox" checked>Implement array traversal.</label></li>
        <li><label><input type="checkbox" checked>Implement insertion into an array at a given position.</label></li>
        <li><label><input type="checkbox" checked>Implement deletion from an array at a given position.</label></li>
        <li><label><input type="checkbox" checked>Implement a 2D array and perform basic operations.</label></li>
        <li><label><input type="checkbox" checked>Access and manipulate a 2D array using pointers.</label></li>
    </ol>

    <h2>Linked Lists</h2>
    <ol start="7">
        <li><label><input type="checkbox">Implement a singly linked list with node creation and display.</label></li>
        <li><label><input type="checkbox">Implement insertion in a singly linked list at beginning, end, and specified position.</label></li>
        <li><label><input type="checkbox">Implement deletion from a singly linked list from beginning, end, and specified position.</label></li>
        <li><label><input type="checkbox">Find the length of a singly linked list iteratively.</label></li>
        <li><label><input type="checkbox">Reverse a singly linked list iteratively.</label></li>
        <li><label><input type="checkbox">Implement a doubly linked list.</label></li>
        <li><label><input type="checkbox">Implement insertion in a doubly linked list at beginning, end, and specified position.</label></li>
        <li><label><input type="checkbox">Implement deletion from a doubly linked list from beginning, end, and specified position.</label></li>
        <li><label><input type="checkbox">Reverse a doubly linked list.</label></li>
        <li><label><input type="checkbox">Implement a circular singly linked list.</label></li>
        <li><label><input type="checkbox">Implement insertion in a circular linked list.</label></li>
        <li><label><input type="checkbox">Implement deletion from a circular linked list from beginning, end, and specified position.</label></li>
        <li><label><input type="checkbox">Reverse a circular linked list.</label></li>
        <li><label><input type="checkbox">Implement a doubly circular linked list.</label></li>
        <li><label><input type="checkbox">Implement insertion in a doubly circular linked list.</label></li>
        <li><label><input type="checkbox">Implement deletion from a doubly circular linked list.</label></li>
    </ol>

    <h2>Stacks</h2>
    <ol start="23">
        <li><label><input type="checkbox">Implement a stack using an array with push, pop, and peek.</label></li>
        <li><label><input type="checkbox">Implement a stack using a linked list.</label></li>
        <li><label><input type="checkbox">Implement infix-to-postfix conversion using a stack.</label></li>
        <li><label><input type="checkbox">Implement infix-to-prefix conversion using a stack.</label></li>
        <li><label><input type="checkbox">Evaluate a postfix expression using a stack.</label></li>
        <li><label><input type="checkbox">Evaluate a prefix expression using a stack.</label></li>
        <li><label><input type="checkbox">Convert prefix to infix using a stack.</label></li>
        <li><label><input type="checkbox">Convert postfix to infix using a stack.</label></li>
        <li><label><input type="checkbox">Implement an expression tree.</label></li>
        <li><label><input type="checkbox">Construct an expression tree from a postfix expression.</label></li>
    </ol>

    <h2>Queues</h2>
    <ol start="33">
        <li><label><input type="checkbox">Implement a queue using an array.</label></li>
        <li><label><input type="checkbox">Implement a queue using a linked list.</label></li>
        <li><label><input type="checkbox">Implement a circular queue using an array.</label></li>
        <li><label><input type="checkbox">Implement a circular queue using a linked list.</label></li>
        <li><label><input type="checkbox">Implement a queue using two stacks.</label></li>
        <li><label><input type="checkbox">Implement a deque using a circular array.</label></li>
    </ol>

    <h2>Binary Trees</h2>
    <ol start="39">
        <li><label><input type="checkbox">Implement a binary tree.</label></li>
        <li><label><input type="checkbox">Implement binary tree representation using an array.</label></li>
        <li><label><input type="checkbox">Implement inorder traversal of a binary tree.</label></li>
        <li><label><input type="checkbox">Implement preorder traversal of a binary tree.</label></li>
        <li><label><input type="checkbox">Implement postorder traversal of a binary tree.</label></li>
        <li><label><input type="checkbox">Construct a binary tree from preorder and inorder traversals.</label></li>
        <li><label><input type="checkbox">Construct a binary tree from postorder and inorder traversals.</label></li>
        <li><label><input type="checkbox">Construct a binary tree from preorder and postorder traversals.</label></li>
    </ol>

    <h2>Binary Search Trees</h2>
    <ol start="47">
        <li><label><input type="checkbox">Implement a Binary Search Tree (BST).</label></li>
        <li><label><input type="checkbox">Implement insertion in a BST.</label></li>
        <li><label><input type="checkbox">Implement deletion in a BST.</label></li>
        <li><label><input type="checkbox">Construct a BST from a preorder traversal.</label></li>
        <li><label><input type="checkbox">Construct a BST from a postorder traversal.</label></li>
    </ol>

    <h2>AVL Trees</h2>
    <ol start="52">
        <li><label><input type="checkbox">Implement an AVL tree.</label></li>
        <li><label><input type="checkbox">Implement AVL insertion with LL, RR, LR, and RL rotations.</label></li>
        <li><label><input type="checkbox">Implement AVL deletion with rebalancing.</label></li>
    </ol>

    <h2>Red-Black Trees</h2>
    <ol start="55">
        <li><label><input type="checkbox">Implement a Red-Black Tree.</label></li>
        <li><label><input type="checkbox">Implement insertion in a Red-Black Tree with rotations and recoloring.</label></li>
        <li><label><input type="checkbox">Implement deletion in a Red-Black Tree with rebalancing.</label></li>
    </ol>

    <h2>Splay Trees</h2>
    <ol start="58">
        <li><label><input type="checkbox">Implement a Splay Tree.</label></li>
        <li><label><input type="checkbox">Implement insertion in a Splay Tree using bottom-up splaying.</label></li>
        <li><label><input type="checkbox">Implement deletion in a Splay Tree using bottom-up splaying.</label></li>
        <li><label><input type="checkbox">Implement deletion in a Splay Tree using top-down splaying.</label></li>
    </ol>

    <h2>B-Trees</h2>
    <ol start="62">
        <li><label><input type="checkbox">Implement a B-Tree.</label></li>
        <li><label><input type="checkbox">Implement insertion in a B-Tree of order 3.</label></li>
        <li><label><input type="checkbox">Implement insertion in a B-Tree of order 4.</label></li>
        <li><label><input type="checkbox">Implement insertion in a B-Tree of order 5.</label></li>
        <li><label><input type="checkbox">Implement B-Tree deletion with node merging and borrowing.</label></li>
    </ol>

    <h2>B+ Trees</h2>
    <ol start="67">
        <li><label><input type="checkbox">Implement insertion in a B+ Tree.</label></li>
        <li><label><input type="checkbox">Implement deletion in a B+ Tree.</label></li>
        <li><label><input type="checkbox">Construct a B+ Tree of order 5.</label></li>
    </ol>

    <h2>Graphs</h2>
    <ol start="70">
        <li><label><input type="checkbox">Implement graph representation using an adjacency matrix.</label></li>
        <li><label><input type="checkbox">Implement graph representation using an adjacency list.</label></li>
        <li><label><input type="checkbox">Implement Breadth-First Search (BFS).</label></li>
        <li><label><input type="checkbox">Implement Depth-First Search (DFS).</label></li>
        <li><label><input type="checkbox">Implement DFS edge classification.</label></li>
        <li><label><input type="checkbox">Implement Prim's algorithm for Minimum Spanning Tree.</label></li>
        <li><label><input type="checkbox">Implement Kruskal's algorithm for Minimum Spanning Tree.</label></li>
        <li><label><input type="checkbox">Detect a cycle in a directed graph.</label></li>
        <li><label><input type="checkbox">Detect a cycle in an undirected graph.</label></li>
        <li><label><input type="checkbox">Implement topological sorting of a directed graph.</label></li>
        <li><label><input type="checkbox">Find all connected components of an undirected graph.</label></li>
        <li><label><input type="checkbox">Find all bridges/cut edges in a graph.</label></li>
        <li><label><input type="checkbox">Implement Dijkstra's shortest-path algorithm.</label></li>
        <li><label><input type="checkbox">Implement the Bellman-Ford shortest-path algorithm.</label></li>
        <li><label><input type="checkbox">Implement the Floyd-Warshall all-pairs shortest-path algorithm.</label></li>
    </ol>

    <h2>Searching</h2>
    <ol start="85">
        <li><label><input type="checkbox">Implement linear search.</label></li>
        <li><label><input type="checkbox">Implement binary search on a sorted array.</label></li>
    </ol>

    <h2>Sorting</h2>
    <ol start="87">
        <li><label><input type="checkbox">Implement Bubble Sort.</label></li>
        <li><label><input type="checkbox">Implement Insertion Sort.</label></li>
        <li><label><input type="checkbox">Implement Selection Sort.</label></li>
        <li><label><input type="checkbox">Implement Quick Sort.</label></li>
        <li><label><input type="checkbox">Implement Merge Sort.</label></li>
        <li><label><input type="checkbox">Implement a Max Heap with insertion and deletion.</label></li>
        <li><label><input type="checkbox">Implement Heap Sort using heapify.</label></li>
        <li><label><input type="checkbox">Implement Shell Sort.</label></li>
        <li><label><input type="checkbox">Implement Counting Sort.</label></li>
        <li><label><input type="checkbox">Implement Radix Sort.</label></li>
    </ol>

    <h2>Hashing</h2>
    <ol start="97">
        <li><label><input type="checkbox">Implement a hash table using separate chaining.</label></li>
        <li><label><input type="checkbox">Implement a hash table using linear probing.</label></li>
        <li><label><input type="checkbox">Implement a hash table using quadratic probing.</label></li>
        <li><label><input type="checkbox">Implement a hash table using double hashing.</label></li>
    </ol>

    <h2>Greedy Algorithms</h2>
    <ol start="101">
        <li><label><input type="checkbox">Implement Huffman Coding using a greedy approach.</label></li>
        <li><label><input type="checkbox">Implement Huffman Coding when character probabilities or frequencies are given.</label></li>
    </ol>

    <h2>Dynamic Programming</h2>
    <ol start="103">
        <li><label><input type="checkbox">Implement Fibonacci using recursion with memoization.</label></li>
        <li><label><input type="checkbox">Implement Fibonacci using tabulation.</label></li>
        <li><label><input type="checkbox">Implement Fibonacci using space optimization.</label></li>
        <li><label><input type="checkbox">Solve Climbing Stairs using recursion.</label></li>
        <li><label><input type="checkbox">Solve Climbing Stairs using memoization.</label></li>
        <li><label><input type="checkbox">Solve Climbing Stairs using tabulation.</label></li>
        <li><label><input type="checkbox">Solve Climbing Stairs using space optimization.</label></li>
        <li><label><input type="checkbox">Solve Min Cost Climbing Stairs using recursion.</label></li>
        <li><label><input type="checkbox">Solve Min Cost Climbing Stairs using memoization.</label></li>
        <li><label><input type="checkbox">Solve Min Cost Climbing Stairs using tabulation.</label></li>
        <li><label><input type="checkbox">Solve Min Cost Climbing Stairs using space optimization.</label></li>
        <li><label><input type="checkbox">Implement different approaches to distinguish recursion from dynamic programming.</label></li>
        <li><label><input type="checkbox">Implement the 0/1 Knapsack problem using dynamic programming.</label></li>
        <li><label><input type="checkbox">Implement the Unbounded Knapsack problem using dynamic programming.</label></li>
    </ol>

</body>
</html>
