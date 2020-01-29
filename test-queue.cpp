//lang::Cpp

#include <iostream>
#include <exception>
#include "queue.h"
#include "queuetype.h"

void FAIL() {   exit(1);    }
void OK(const char* m) { 
    std::cout << "OK: " << m << std::endl;
}
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }

void testGetType() {
    Queue* q1 = new Queue(QueueType::OBJECT);
    t_true(q1->getType() == QueueType::OBJECT);
    Queue* q2 = new Queue(QueueType::STRING);
    t_true(q2->getType() == QueueType::STRING);
    OK("getType()");
    delete q1;
    delete q2;
}

void testAdd() {
    Queue* q1 = new Queue(QueueType::OBJECT);
    Object* obj = new Object();
    bool added = q1->add(obj);
    t_true(added);
    OK("add()"); 
    delete q1;
}

void testPeekOnEmpty() {
    Queue* q1 = new Queue(QueueType::OBJECT);
    t_true(q1->size() == 0);
    t_true(q1->peek() == nullptr);
    OK("peek() on empty Queue");
    delete q1;
}

void testPeek() {
    Queue* q1 = new Queue(QueueType::OBJECT);
    Object* obj1 = new Object();

    q1->add(obj1);
    t_true(q1->size() == 1);

    Object* obj = q1->peek();

    t_true(obj->equals(obj1));
    t_true(q1->size() == 1);

    OK("peek()");
    delete q1;
}

void testPopOnEmpty() {
    Queue* q1 = new Queue(QueueType::OBJECT);
    t_true(q1->size() == 0);
    t_true(q1->pop() == nullptr);
    OK("pop() on empty Queue");
    delete q1;
}

void testPop() {
    Queue* q1 = new Queue(QueueType::OBJECT);
    Object* obj1 = new Object();

    q1->add(obj1);
    t_true(q1->size() == 1);

    Object* obj = q1->pop();

    t_true(obj->equals(obj1));
    t_true(q1->size() == 0);

    OK("pop()");
    delete obj;
    delete q1;
}

void testIsEmpty() {
    Queue* q1 = new Queue(QueueType::OBJECT);
    Object* obj1 = new Object();
    t_true(q1->isEmpty());
    q1->add(obj1);
    t_false(q1->isEmpty());
    OK("isEmpty()");
    delete q1;
}

void testSize() {
    Queue* q1 = new Queue(QueueType::OBJECT);
    Object* obj1 = new Object();
    Object* obj2 = new Object();
    t_true(q1->size() == 0);
    q1->add(obj1);
    t_true(q1->size() == 1);
    q1->add(obj2);
    t_true(q1->size() == 2);
    q1->pop();
    t_true(q1->size() == 1);
    q1->pop();
    t_true(q1->size() == 0);

    OK("size()");
    delete q1;
}

void testEquals() {
    Queue* q1 = new Queue(QueueType::OBJECT);
    Queue* q2 = new Queue(QueueType::OBJECT);
    Queue* q3 = q1;

    t_true(q1->equals(q2)); // empty queues are equal
    t_true(q1->equals(q3)); // same pointer

    Object* obj1 = new Object();
    q1->add(obj1);
    t_false(q1->equals(q2));
    OK("equals()");
    delete q2;
    delete q1;
}

void testToString() {
    Queue* q1 = new Queue(QueueType::OBJECT);
    std::string s = q1->toString();
    t_true(s == "[]");

    Object* obj1 = new Object();
    q1->add(obj1);
    s = q1->toString();
    t_true(s.at(0) == '[');
    t_true(s.at(s.length() - 1) == ']');

    Object* obj2 = new Object();
    q1->add(obj2);
    s = q1->toString();
    t_true(s.at(0) == '[');
    t_true(s.at(s.length() - 1) == ']');
    t_true(s.find(", ") != std::string::npos); 

    OK("toString()");
    delete q1;
}

int main() {
    testGetType();
    testAdd();
    testPeekOnEmpty();
    testPeek();
    testPopOnEmpty();
    testPop();
    testIsEmpty();
    testSize();
    testEquals();
    testToString();

    return 0;
}
