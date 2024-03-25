Here are some examples of algorithms in the C++ Standard Library:

- for_each, which is the default traversal algorithm.

- find_if, which is the default search algorithm.

- sort, lower_bound, and the other default sorting and searching algorithms.

To write a comparator, use strict < and use named lambdas when you can.

  auto comp = [](const widget& w1, const widget& w2)
     { return w1.weight() < w2.weight(); }

  sort( v.begin(), v.end(), comp );

  auto i = lower_bound( v.begin(), v.end(), comp );


Loops
When possible, use range-based for loops or algorithm calls, or both, instead of hand-written loops. 

copy, transform, count_if, remove_if, and others like them are much better than handwritten loops because their intent is obvious and they make it easier to write bug-free code. Also, many C++ Standard Library algorithms have implementation optimizations that make them more efficient.

Instead of old C++ like this:

  for (std::vector<string>::iterator i = strings.begin(); i != strings.end(); ++i ) {
    /* ... */
  }

  std::vector<string>::iterator i = v.begin();

  for ( ; i != v.end(); ++i ) {
    if (*i > x && *i < y) break;
  }

Use modern C++ like this:

  for_each( begin(strings), end(strings), [](string& s) {
    // ...
  } );

  auto i = find_if( begin(v), end(v),  [=](int i) { return i > x && i < y; } );

