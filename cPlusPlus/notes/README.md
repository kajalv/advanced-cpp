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

# Notes on Copy Constructor

In a custom object - the assignment operator performs a shallow copy. This becomes a problem when there are pointers.
We may not want to copy the pointer itself, it may get deallocated and invalidated, etc.
So we need to overload the copy constructor and assignment operator in this case.

# STL

Deque (pronounced deck) - double ended queue, can push to front as well as back

# Rule of Three

If you define any one of a copy constructor or = or destructor, you should implement all three.
