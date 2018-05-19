# Notes on catching and re-throwing exceptions:

throw; on its own causes the exception being handled by the catch block to be rethrown.
This is only useful if the function which called us (or another one further up the call stack)
needs to know about the exception and is able to handle it. If there is no suitable handler, the program will be terminated.

Usually you would catch and rethrow an exception if you need to do something at your level before letting "the higher ups"
know about the exception. For example, you might need to log the error, or release some memory allocated on the heap,
or roll back a database transaction. Another possibility is that you might need to add some information to the exception object.

Although it's good practice for a catch block to take a reference to the exception object, it's especially important
when the catch block rethrows. This avoids the risk of object slicing, in which all the derived class information
is thrown away when the object is copied. Also, if a copy of the exception is rethrown, any changes made to it in the
catch block will be lost.

You would throw std::exception if the calling code doesn't need to know the details of your low-level exception.
For example, if the exception is going to be displayed to the user, there is no point showing them obscure errors
which will be meaningless to them. Also, if the calling code doesn't know about your exception, throwing std::exception
will ensure it gets handled.

# String Manipulation

Clearing an ostringstream s - involves clearing the contents as well as resetting all flags (eg. error bits).
s.str("")
s.clear()

Checking if an ostringstream is empty (has no content):
bool isEmpty = (s.tellp() == 0); // Similar to checking the 'size'

# Bitset

Decimal to binary conversion and vice versa (string intermediate)
std::string binary = std::bitset<8>(128).to_string(); //8/16/32 bit
unsigned long decimal = std::bitset<8>(binary).to_ulong(); //or uint32_t decimal;

# Notes on Copy Constructor

In a custom object - the assignment operator performs a shallow copy. This becomes a problem when there are pointers.
We may not want to copy the pointer itself, it may get deallocated and invalidated, etc.
So we need to overload the copy constructor and assignment operator in this case.

# STL

Deque (pronounced deck) - double ended queue, can push to front as well as back

# Rule of Three

If you define any one of a copy constructor or = (assignment operator) or destructor, you should implement all three.

# Templates

Put the definition and implementation together in the header file because they are needed to compile the program.
Template works with types as required by the user.

# Function Pointers

In C++11, lambda expressions are a good alternative to function pointers.
The keyword 'virtual' signifies creation of a vtable of function pointers.

# Abstract Classes 

Cannot create an array of an abstract class, because the constructor needs to run.
But we could create an array of pointers to the abstract class.

# Functors 

Alternative to function pointers. Pass blocks of code around.
But there are some things you can do with functors that you cannot do with function pointers, and vice versa.

# Storage Class Specifiers

auto is the default. Normally don't need to specify it.

auto and trailing return types need a deep-dive!

# Range-based for loops

Have used it for arrays and vectors. But, can also be used for characters in a string.

# Smart pointers 

Unique pointers are "smart pointers" which behaves like normal pointers but handle the deallocation of memory on their own.
Prior to C++11, there was auto_ptr which is similar to unique_ptr. But now it is deprecated.
Also, we cannot use auto_ptr on arrays but we can use unique_ptr on arrays.

# Shared pointers 

Similar to smart, but they don't delete the memory associated with the objects until all pointers that point at that object have gone out of scope.
Cannot point at arrays at the moment, may change in future.

# GUI

- wxWidgets
- GTK+
- Qt Studio

# Notes 

NULL is not a keyword. C++11 has nullptr type.

# Things to note or read about 

- Reference collapsing
- Name mangling

# Notes from other resources

New in C++ 11:

- Enum classes over plain enums - because of type safety: https://stackoverflow.com/questions/18335861/why-is-enum-class-preferred-over-plain-enum
- STL - has containers, iterators, and algorithms
- Some new libraries in C++11 - regex, thread, unordered_map, array, forward_list
- Iterator categories - forward, bidirectional, random
- Overloading ostream& operator<< requires it to be a friend class
- C++ auto feature