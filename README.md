# sllist
Programmer's library for manupulate Single Linked List<br>
Prototypes of functions in <pre>sllist.h</pre><br>
Code of functions in <pre>sllist.cpp</pre>

<h1>Features</h1>
Examples of uses in <pre>main.cpp</pre><br>
User functions in <pre>myFuncts.h</pre> (prototypes) and code in <pre>myFuncts.cpp</pre><br>
Conform to g++<br>
The <pre>make</pre> command produce test executable <pre>./testSLL</pre>

<h1>Functions</h1>
  <h2>Create a new list</h2>
  Returns a pointer to a new, empty list. If allocation fails, returns nullptr.<br>
  <pre>sllist* sllist_create(void)</pre>
  
  <h2>Destroy a list</h2>
  Frees the memory of the list struct and all associated nodes.<br>
  <pre>void sllist_destroy(sllist* theIdx)</pre>

  <h2>Prepend a node to the list</h2>
  Adds a node to the front of the list. If allocation fails, returns -1, otherwise returns 0.<br>
  <pre>int sllist_push_front(sllist* theIdx, void* theData)</pre>
  
  <h2>Append node to a list</h2>
  Adds a node to the end of the list. If allocation fails, returns -1, otherwise returns 0.<br>
  <pre>int sllist_push_back(sllist* theIdx, void* theData)</pre>
  
  <h2>Extract the first node</h2>
  Remove the first node from the linked list, save a pointer to the data, free the node (but do not free the data itself), and return a pointer to the data so that it can be used. If the list is empty, returns nullptr.<br>
  <pre>void* sllist_pop_front(sllist* theIdx)</pre>
  
  <h2>Extract the last node</h2>
  Remove the last node from the linked list, save a pointer to the data, free the node (but do not free the data itself), and return a pointer to the data so that it can be used. If the list is empty, returns nullptr.<br>
  <pre>void* sllist_pop_back(sllist* theIdx)</pre>
  
  <h2>Step through a list</h2>
  Changes the current node to the node after the current node. Returns 1 if the current node is nullptr.<br>
  <pre>int sllist_step(sllist* theIdx)</pre>
  
  <h2>Access data by index</h2>
  Returns a pointer to the payload of the node at the location specified by the passed index value. The passed index value is interpreted as an offset from index zero, the first node of the list. Returns nullptr if the list is empty or the index is out of range.<br>
  <pre>void* sllist_read_index(sllist* theIdx, int theRow)</pre>
  
  <h2>Insert a node after the node at the specified index</h2>
  Adds a node after the passed node. If allocation fails, returns -1. If the node doesn't exist in the list, returns 1. Otherwise, returns 0.<br>
  <pre>int sllist_insert_after(sllist* theIdx, int theRow, void* theData)</pre>
  
  <h2>Extract a node after the node at the specified index</h2>
  Remove the specified node from the linked list, save a pointer to the data, free the node (but do not free the data itself), and return a pointer to the data so that it can be used. If the list is empty or the node doesn't exist in the list, returns nullptr. Attempting to extract after the tail will also return nullptr.<br>
  <pre>void* sllist_extract_after(sllist* myIdx, int theRow)</pre>
  
<h1>Acknowledgements</h1>
Very largely inspired by a "code review" on <a href="https://codereview.stackexchange.com/questions/26732/singly-linked-list-library">StackExchange</a>.
