# Assignment 2 - Part 2 - Design Explanation

For our Object class, we drew from our experience with Java's Object class. All Objects should be able to compare themselves with
other Objects via an equals() function and a hashCode() function. Additionally, Objects should be able to be converted to a string for
for use in debugging, so a toString() function was added.

We chose to design the API for a Queue, which we interpreted as a container for generic objects, accessed in a FIFO manner. Since the 
Queue must contain objects of type Object or String, and since we cannot use templates in CwC, we needed a way for a user to know what
type objects in the Queue will be. So, we added the QueueType enum class, which at present only contains OBJECT and STRING.

The constructor for a Queue must specify the type of objects it will contain, and then a user must not attempt to add objects of any
other type. One can access the Queue's type via its getType() function. Since all classes inherit from Object, all methods in the
Queue take or return Objects. However, assuming one only adds elements of one type, one can safely cast the object to the desired type.

The methods, add(), peek(), and pop(), are based on our intuitive understanding of a Queue. add() adds an element to the end of the Queue.
peek() returns, but does not remove, the element at the front of the Queue. pop() returns and removes th element at the front of the Queue. 
If one calls peek or pop on an empty Queue, an exception should be thrown.

The functions isEmpty() and size() allow the user to check the size of the Queue before trying to remove elements. Because these methods
exist, one should never call peek() or pop() on an empty Queue, which is why we throw an exception.

The remainder of the Queue API consists of methods inherited from Object.
