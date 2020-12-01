#include <iostream>
#include "PriorityQueue.h"

using namespace std;

/* default size for the queue is 500 and
 the head of the linked list (items) is
 initially set to NULL. Also has the counter
 size to keep track of if the queue is full
 or not and give a easily obtained length*/
template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue() {
  items = NULL;
  maxQue = 500;
  size = 0;
}


/* custom size for queue is equal to max and
 the head of the linked list (items) is
 initially set to NULL */
template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue(int max) {
  items = NULL;
  maxQue = max;
  size = 0;
}


/* same logic as the destructor in the Sorted List
 */
template<class ItemType>
PriorityQueue<ItemType>::~PriorityQueue() {

  QNode<ItemType>* location;

  while (items != NULL) {
    location = items;
    items = location->next;
    delete location;
  }
}


/* Essentially runs the destructor then redefines all
 of the elements again afterwards */
template<class ItemType>
void PriorityQueue<ItemType>::makeEmpty() {

  QNode<ItemType>* location;

  while(items != NULL) {
    location = items;
    items = location->next;
    delete location;
  }

  items = new QNode<ItemType>;
  items = NULL;
  size = 0;
}


/*checks if the queue is empty by seeing if the
first value is NULL or not*/
template<class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const {
  return bool (items == NULL);
}


/*checks if queue is full by comparing counter size
to the max size of the queue*/
template<class ItemType>
bool PriorityQueue<ItemType>::isFull() const {
  QNode<ItemType>* location;

  try {
    location = new QNode<ItemType>;
    delete location;
    return false;
  }

  catch (std::bad_alloc exception) {
    return true;
    }
  return bool (size == maxQue);
}



template<class ItemType>
void PriorityQueue<ItemType>::enqueue(ItemType newItem, int priority) {

  if (isFull()) {    
    throw QueueOverflow();
  }

  QNode<ItemType>* location = items;
  QNode<ItemType>* temp;
  QNode<ItemType>* newNode;

  //readies the new node
  newNode = new QNode<ItemType>;
  newNode->info = newItem;
  newNode->priority = priority;
  newNode->next = NULL;

  //intital case for if the queue is empty
  if (isEmpty()) {
    items = newNode;
    size++;
  }

  //case for if the value being queued is less than the first value
  else if (priority < items->priority) {
    temp = items;
    items = newNode;
    items->next = temp;
    size++;
  }

  /*else statement encapsulating every other possibility, iteratres
   through the queue until either the queue is empty or it finds a 
   element of he queue with a great priority, it then inserts itself
   in the accurate spot*/
  else {
    while (location->next != NULL && priority >= location->next->priority) {
      location = location->next;
    }
    temp = location->next;
    location->next = newNode;
    location->next->next = temp;
    size++;
  }
}



template<class ItemType>
void PriorityQueue<ItemType>::dequeuer(ItemType& item) {

  QNode<ItemType>* temp;

  //exception for if there is nothing to dequeue
  if (isEmpty()) {
    throw QueueUnderflow();
  }

  //exception if there is only one item in queue
  else if (size == 1) {
    item = items->info;
    delete items;
    size--;
    items = NULL;
  }

  /*otherwise it will store the data in the second node
   in a temporary position then delete the first node and
   move the former second node to the first node then 
   decrements the size counter*/
  else {
    temp = items->next;
    item = items->info;
    delete items;
    items = temp;
    size--;
  }
  
}


  //returns size counter to give an accurate length of queue
template<class ItemType>
int PriorityQueue<ItemType>::length() {
  return size;
}


  /*iterates through the linked list using a pointer location
   and outputs the data of each node in the queue to a file*/
template<class ItemType>
void PriorityQueue<ItemType>::printQueue(ofstream& outFile) {
  
  QNode<ItemType>* location = items;

  outFile << "Queue: ";
  while (location != NULL) {
    outFile << location->info << " ";
    location = location->next;
  }
  outFile << endl;
}


//returns first node's stored data
template<class ItemType>
ItemType PriorityQueue<ItemType>::peek() {
  if (isEmpty()) {
    throw QueueUnderflow();
    }
  else {
    return items->info;
  }
}


//returns first node'ss priority
template<class ItemType>
int PriorityQueue<ItemType>::peekPriority() {
  if (isEmpty()) {
    throw QueueUnderflow();
  }
  else {
    return items->priority;
  }
}
