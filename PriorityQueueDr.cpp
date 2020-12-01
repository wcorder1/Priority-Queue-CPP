#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.cpp"

using namespace std;

int main() {
  
  ofstream outFile;
  ifstream inFile;
  string command;
  
  outFile.open("outFile.txt");
  inFile.open("inFile.txt");
  
  if (!outFile) {
    std::cout << "error openning output file" << endl;
    return 1;
  }
  
  string item;
  int priority;
  PriorityQueue<string> queue(10);
  int numCommands=0;  
  
  while (true) {
    
    inFile >> command;
    
    try 
      {
	if (command == "enqueue")
	  {
	    inFile >> item;
	    inFile >> priority;
	    queue.enqueue(item,priority);
	    outFile << item << " is enqueued." << endl;
	  }
	
	else if (command == "dequeue")
	  {
	    queue.dequeuer(item);
	    outFile << item << " was dequeued. " << endl;
	  }
	
	else if (command == "isEmpty")
	  {
	    if (queue.isEmpty())
	      outFile << "Queue is Empty" << endl;
	    else
	      outFile << "Queue is Not Empty" << endl;
	  }
	
	else if (command == "isFull")
	  if (queue.isFull())
	    outFile << "Queue is full" << endl;
	  else outFile << "Queue is not full" << endl;
	
	else if (command == "length")
	  outFile << "Number of items in the Queue is: " << queue.length() << endl;
	
	else if (command == "clear")
	  queue.makeEmpty();
        
	else if (command == "list")
	  queue.printQueue(outFile);
	
	else if (command == "peek") {
	  string x = queue.peek();
	  outFile << "Front item is " << x << endl;
	}  
        
	else if (command == "peekPriority") {
          int x = queue.peekPriority();
          outFile << "Priority of the front item is " << x << endl; 
        }

	else if (command == "makeEmpty") {
	  queue.makeEmpty();
	  outFile << "List is now empty." << endl;
	}
	
	else if (command == "Quit")
	  break;
	
	else outFile << " Invalid Command" << endl;
      }
    
    catch (QueueOverflow)
      
      {
	outFile << "FullQueue exception thrown" << endl;
      }
    
    catch (QueueUnderflow)
      
      {
	outFile << "EmptyQueue exception thrown" << endl;
      }
    
    numCommands++;
    
    cout <<  " Command number " << numCommands << " completed."
         << endl;
    
  }

  outFile << "Testing completed" << endl;
  cout << "Testing completed"  << endl;
  outFile.close();
  return 0;
}
