//lang::CwC

#pragma once

#include "object.h"
#include "queuetype.h"

/**
 * Represents a queue data structure, in which elements are ordered in a
 * first-in, first-out (FIFO) manner.
 */
class Queue : public Object {
  public:
    /**
     * Constructs a new Queue object.
     *
     * @param type the type of element that this Queue will contain
     */
    Queue(QueueType type) {}

    /**
     * Deletes this Queue object, freeing up the memory it took up.
     */
    virtual ~Queue() {}

    /**
     * Returns the type of element that will  be stored in this Queue.
     *
     * @return a QueueType indicating what type the Queue will contain
     */
    virtual QueueType getType() {}

    /**
     * Adds the given Object into this Queue, returning true if the insertion
     * was successful. We return a bool becuase although this interface does not
     * specify a maximum capacity, derived classes may wish to do so. This Queue
     * takes ownership of the given pointer and must free it in the
     * deconstructor.
     *
     * @param o the Object* to added to the Queue
     */
    bool add(Object* o) {}

    /**
     * Returns the Object at the head of the Queue, but does not remove the object 
     * or modify the head. Returns nullptr if the Queue is empty.
     * Ownership of the returned value stays with this Queue.
     *
     * @return a pointer to the element at the head of the Queue
     */
    virtual Object* peek() {}

    /**
     * Removes and returns the Object at the head of the Queue, modifying the
     * head to point to the next Object, if there is one. Returns nullptr if the
     * Queue is empty. Ownership of the popped value goes to the function that
     * called pop();
     *
     * @return a pointer to the element at the head of the Queue
     */
    Object* pop() {}

    /**
     * Returns whether this Queue is empty (has no elements)
     *
     * @return whether this Queue is empty
     */
    bool isEmpty() {}

    /**
     * Returns the size of this Queue (the number of elements)
     *
     * @return the number of elements in this Queue
     */
    size_t size() {}

    /**
     * Returns whether this Queue is equal to the given Object. This means that
     * o points to another Queue, both Queues have the same number of elements,
     * and the elements (in order) are equal.
     *
     * @param o the Object to compare to this Queue
     * @return whether this Queue is equal to the given Object
     */
    bool equals(Object* o) {}

    /**
     * Returns a unique hash code for this Queue
     *
     * @return a hash code for this Queue
     */
    int hashCode() {}

    /**
     * Returns a string literal representing this Queue.
     * The string should be surrounded by [], and consist of the output of each
     * element's toString method separated by commas and one space like so:
     *
     * [Element1, Element2, Element3]
     *
     * The elements are printed starting with the head of the Queue.
     *
     * @return a string literal representing this Queue
     */
    const char* toString() {}
};
