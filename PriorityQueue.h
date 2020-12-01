#ifndef PRIORITYQUEUE_H 
#define PRIORITYQUEUE_H 
#include<iostream>

using namespace std;

#include<fstream>
#include<string>

template<class ItemType>
struct QNode {
  ItemType info;
  int priority;
  QNode<ItemType>* next;
};

class QueueOverflow{
};  

class QueueUnderflow {
};
 
template <class ItemType>
class PriorityQueue
{
public: 
  PriorityQueue();
  // Class constructor.
  
  PriorityQueue(int max);
  // Parameterized class constructor.
  
  ~PriorityQueue();
  // Class destructor.
  
  void makeEmpty();
  // Function: Initializes the queue to an empty state.
  // Post: Queue is empty.
  
  bool isEmpty() const;
  // Function: Determines whether the queue is empty.
  // Post: Function value = (queue is empty)
  
  bool isFull() const;
  // Function: Determines whether the queue is full.
  // Post: Function value = (queue is full)
  
  void enqueue(ItemType newItem, int priority);
  // Function: Adds newItem to the rear of the queue.
  // Post: If (queue is full) FullQueue exception is thrown
  //       else newItem is at rear of queue.
  
  void dequeuer(ItemType& item);
  // Function: Removes front item from the queue and returns it   
  //in item.
  // Post: If (queue is empty) EmptyQueue exception is thrown
  //       and item is undefined
  //       else front element has been removed from queue and
  //       item is a copy of removed element.
  
  int length();
  // Function: returns the number of items in the queue
  
  void printQueue(ofstream&);
  // displays QueueItems

  int peekPriority();
  //returns the item associated with the highest priority
  //if called on empty queue returns exception

  ItemType peek();
  //returns the item associated with the highest priority
  //if called on empty queue returns exception

  
private:
  QNode<ItemType>* items;
  int size;
  int maxQue;
};

#endif
