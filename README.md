# sllist
Programmer's library for manupulate Single Linked List
Prototypes of functions in sllist.h
Code of functions in sllist.cpp

<h1>Features</h1>
Examples of uses in main.cpp
User functions in myFuncts.h (prototypes) and code in myFuncts.cpp (code)
The make command produce test executable ./testSLL

<h1>Functions</h1>
  <h2>Create a new list</h2>
  Returns a pointer to a new, empty list. If allocation fails, returns nullptr.<br>
  sllist* sllist_create(void)
  
  <h2>Destroy a list</h2>
  Frees the memory of the list struct and all associated nodes.<br>
  void sllist_destroy(sllist* theIdx)

  <h2>Prepend a node to the list</h2>
  Adds a node to the front of the list. If allocation fails, returns -1, otherwise returns 0.<br>
  int sllist_push_front(sllist* theIdx, void* theData)
  
  <h2>Append node to a list</h2>
  Adds a node to the end of the list. If allocation fails, returns -1, otherwise returns 0.<br>
  int sllist_push_back(sllist* theIdx, void* theData)
  
  <h2>Extract the first node</h2>
  Remove the first node from the linked list, save a pointer to the data, free the node (but do not free the data itself), and return a pointer to the data so that it can be used. If the list is empty, returns nullptr.<br>
  void* sllist_pop_front(sllist* theIdx)
  
  <h2>Extract the last node</h2>
  Remove the last node from the linked list, save a pointer to the data, free the node (but do not free the data itself), and return a pointer to the data so that it can be used. If the list is empty, returns nullptr.<br>
  void* sllist_pop_back(sllist* theIdx);
  
  <h2>Step through a list</h2>
  Changes the current node to the node after the current node. Returns 1 if the current node is nullptr.<br>
  int sllist_step(sllist* theIdx)
  
  <h2>Access data by index</h2>
  Returns a pointer to the payload of the node at the location specified by the passed index value. The passed index value is interpreted as an offset from index zero, the first node of the list. Returns nullptr if the list is empty or the index is out of range.<br>
  void* sllist_read_index(sllist* theIdx, int theRow)
  
  <h2>Insert a node after the node at the specified index</h2>
  Adds a node after the passed node. If allocation fails, returns -1. If the node doesn't exist in the list, returns 1. Otherwise, returns 0.<br>
  int sllist_insert_after(sllist* theIdx, int theRow, void* theData)
  
  <h2>Extract a node after the node at the specified index</h2>
  Remove the specified node from the linked list, save a pointer to the data, free the node (but do not free the data itself), and return a pointer to the data so that it can be used. If the list is empty or the node doesn't exist in the list, returns nullptr. Attempting to extract after the tail will also return nullptr.<br>
  void* sllist_extract_after(sllist* myIdx, int theRow)
  
<h1>Acknowledgements</h1>
Very largely inspired by a "code review" on <a href="https://codereview.stackexchange.com/questions/26732/singly-linked-list-library">StackExchange</a>.
