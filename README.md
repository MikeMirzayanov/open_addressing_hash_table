### Open addressing hash table on C++

Hope see here full-featured C++-container implementing fast and compact open addressing hash table on C++.

Proof-of-concept (see benchmark.cpp) shows that such map can be 3x faster than `std::unordered_map`.

API should be very like to `std::unordered_map`, so approximate roadmap is:

1. One more template type parameter `class Pred = std::equal_to<Key>`
1. Member function `at`
1. Member function `clear`
1. Member function `empty`
1. Member function `insert`
1. Member function `equal_range`
1. Member function `swap`
1. Member function `operator=`
1. Member functions `load_factor`, `max_load_factor`, `rehash`, `reserve`
1. Constant members
1. Member types: `difference_type`, `hasher`, `key_type`, `mapped_type`, `reference`, `size_type`, `value_type`, `pointer`, `const_reference`, `key_equal`
1. Iterators: member types `iterator`, `const_iterator`, member functions `begin`, `end`, `cbegin`, `cend`
1. Member function `emplace`
1. Member function `emplace_hint`
1. Relational operators
1. Non-member function overload: swap
1. Move semantics
