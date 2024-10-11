#include <any>                // Type-safe containers for single values (C++17)
#include <array>              // Fixed-size array
#include <atomic>             // Atomic operations
#include <barrier>            // Barrier synchronization (C++20)
#include <bit>                // Bit manipulations (C++20)
#include <bitset>             // Bitset manipulation
#include <chrono>             // Time utilities
#include <cinttypes>          // Fixed-size integer types
#include <climits>            // Limits of integral types
#include <cmath>              // Mathematical functions
#include <complex>            // Complex number support
#include <condition_variable> // Condition variable for thread synchronization
#include <coroutine>          // Coroutine support (C++20)
#include <csetjmp>            // Non-local jumps
#include <csignal>            // Signal handling
#include <cstdarg>            // Variable arguments handling
#include <cstddef>            // Common types
#include <cstdint>            // Fixed-width integer types
#include <cstdio>             // C-style input/output
#include <cstdlib>            // General utilities
#include <cstring>            // C-style string handling
#include <deque>              // Double-ended queue
#include <exception>          // Exception handling
#include <execution>          // Parallel algorithm execution policies (C++17)
#include <filesystem>         // File system operations (C++17)
#include <fstream>            // File input/output
#include <future>             // Asynchronous operations
#include <iomanip>            // IO manipulators
#include <ios>                // Base class for streams
#include <istream>            // Input stream classes
#include <iterator>           // Iterators
#include <limits>             // Numeric limits
#include <list>               // Doubly linked list
#include <locale>             // Localization
#include <map>                // Map (associative container)
#include <memory>             // Dynamic memory management
#include <memory_resource>    // Polymorphic memory resources (C++17)
#include <mutex>              // Mutexes
#include <new>                // Dynamic memory management (new/delete)
#include <numeric>            // Numeric algorithms
#include <optional>           // Optional values (C++17)
#include <ostream>            // Output stream classes
#include <queue>              // Queue (FIFO) and priority queue
#include <random>             // Random number generation
#include <ratio>              // Compile-time rational arithmetic
#include <regex>              // Regular expressions
#include <scoped_allocator>   // Scoped memory allocator
#include <set>                // Set (associative container)
#include <shared_mutex>       // Shared mutex
#include <span>               // Span (C++20)
#include <sstream>            // String stream classes
#include <stack>              // Stack (LIFO)
#include <stdexcept>          // Standard exceptions
#include <streambuf>          // Stream buffer classes
#include <string>             // String handling
#include <string_view>        // String view (C++17)
#include <system_error>       // System error support
#include <thread>             // Thread support
#include <tuple>              // Tuples
#include <type_traits>        // Type traits
#include <typeindex>          // Type index for runtime type identification
#include <typeinfo>           // Type identification
#include <unordered_map>      // Unordered map (hash table)
#include <unordered_set>      // Unordered set (hash table)
#include <utility>            // Utility functions
#include <valarray>           // Valarray
#include <variant>            // Variant type (C++17)
#include <version>            // Feature-testing macros (C++20)
#include <numbers>            // Mathematical constants (C++20)
#include <latch>              // Latch synchronization (C++20)
#include <semaphore>          // Semaphore synchronization (C++20)
#include <compare>            // Three-way comparison (C++20)
#include <concepts>           // Concepts for templates (C++20)
#include <ranges>             // Range-based operations (C++20)
#include <syncstream>         // Synchronized output stream (C++20)
#include <source_location>    // Source location (C++20)
#include <barrier>            // Barrier synchronization primitive (C++20)
#include <bit>                // Bitwise operations (C++20)
#include <compare>            // Three-way comparison (C++20)
#include <concepts>           // Concepts for generic programming (C++20)
#include <ranges>             // Range-based algorithms and views (C++20)
#include <semaphore>          // Semaphore synchronization primitive (C++20)
#include <latch>              // Latch synchronization primitive (C++20)
#include <numbers>            // Mathematical constants (C++20)
#include <execution>          // Parallel algorithm execution policies (C++17)
#include <filesystem>         // File system operations (C++17)
#include <any>                // Type-safe containers for single values (C++17)
#include <charconv>           // Conversion between characters and integers (C++17)
#include <memory_resource>    // Polymorphic memory resource (C++17)
#include <variant>            // Discriminated union type (C++17)
#include <algorithm>          // Standard algorithms (sort, max, min, etc.)
#include <array>              // std::array (fixed-size array)
#include <bitset>             // Bitset manipulation
#include <cassert>            // Assert function for debugging
#include <cctype>             // Character handling functions (isalpha, isdigit)
#include <cerrno>             // Error codes (errno)
#include <cfenv>              // Floating-point environment
#include <cfloat>             // Floating-point limits
#include <chrono>             // Time utilities (duration, time points)
#include <cinttypes>          // Fixed size integer types formatting
#include <climits>            // Limits of data types (CHAR_MIN, INT_MAX)
#include <clocale>            // Localization functions
#include <cmath>              // Mathematical functions (sqrt, pow, etc.)
#include <codecvt>            // Unicode conversion facets (C++11)
#include <complex>            // Complex number functions
#include <condition_variable> // Thread synchronization (C++11)
#include <csetjmp>            // Non-local jumps (setjmp, longjmp)
#include <csignal>            // Signal handling
#include <cstdarg>            // Handling variable arguments (va_list)
#include <cstddef>            // Standard definitions (size_t, NULL, etc.)
#include <cstdint>            // Fixed width integer types (int8_t, uint64_t)
#include <cstdio>             // C-style I/O functions (printf, scanf)
#include <cstdlib>            // General utilities (memory allocation, process control)
#include <cstring>            // C-style string manipulation (strcpy, strcat)
#include <ctime>              // Time manipulation (time, difftime)
#include <deque>              // Double-ended queue
#include <exception>          // Exception handling (try, throw, catch)
#include <fstream>            // File stream classes (ifstream, ofstream)
#include <functional>         // Function objects and function pointers
#include <future>             // Asynchronous operations (async, future)
#include <iomanip>            // IO manipulators (setprecision, setw)
#include <ios>                // Base class for input-output streams
#include <iosfwd>             // Forward declarations of iostream classes
#include <iostream>           // Standard input-output stream (cin, cout)
#include <istream>            // Input stream classes
#include <iterator>           // Iterator utilities
#include <limits>             // Numeric limits (numeric_limits)
#include <list>               // Doubly linked list
#include <locale>             // Localization utilities
#include <map>                // Sorted associative containers (std::map)
#include <memory>             // Dynamic memory management (smart pointers)
#include <mutex>              // Mutual exclusion primitives (C++11)
#include <new>                // Dynamic memory management (new, delete)
#include <numeric>            // Numeric algorithms (accumulate, inner_product)
#include <optional>           // Optional value (C++17)
#include <ostream>            // Output stream classes
#include <queue>              // FIFO queue and priority queue
#include <random>             // Random number generation
#include <ratio>              // Compile-time rational arithmetic
#include <regex>              // Regular expressions (C++11)
#include <scoped_allocator>   // Scoped memory allocator
#include <set>                // Sorted associative containers (std::set)
#include <shared_mutex>       // Shared ownership mutex (C++17)
#include <sstream>            // String stream classes (std::stringstream)
#include <stack>              // Stack (LIFO)
#include <stdexcept>          // Standard exceptions (out_of_range, runtime_error)
#include <streambuf>          // Stream buffer classes
#include <string>             // String manipulation (std::string)
#include <string_view>        // String view (C++17)
#include <system_error>       // System error support (std::error_code)
#include <thread>             // Thread support (C++11)
#include <tuple>              // Tuple (multiple values in one object)
#include <type_traits>        // Compile-time type information
#include <typeindex>          // Runtime type information
#include <typeinfo>           // Runtime type identification
#include <unordered_map>      // Unordered associative containers (hash map)
#include <unordered_set>      // Unordered associative containers (hash set)
#include <utility>            // Utility functions (std::move, std::swap)
#include <valarray>           // Class for representing arrays of values
#include <variant>            // Variant type (C++17)
#include <vector>             // Dynamic array (std::vector)
#include <fstream>            // File input-output stream
#include <future>             // Asynchronous operations
#include <atomic>             // Atomic operations (thread safety)
#include <charconv>           // Character conversions (C++17)
#include <coroutine>          // Coroutine support (C++20)
#include <span>               // View of a contiguous sequence of objects (C++20)
#include <source_location>    // Represents a location in the source code (C++20)
#include <stop_token>         // Stopping mechanisms for threads (C++20)
#include <syncstream>         // Synchronized output stream (C++20)
#include <version>            // Feature-testing macros (C++20)
