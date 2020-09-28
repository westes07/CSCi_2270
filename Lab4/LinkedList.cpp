#include "LinkedList.h"

using namespace std;

// Add a new node to the list
void LinkedList::insert(Node* prev, int newKey){

  //Check if head is Null i.e list is empty
  if(head == NULL){
    head = new Node;
    head->key = newKey;
    head->next = NULL;
  }

  // if list is not empty, look for prev and append our node there
  else if(prev == NULL)
  {
      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = head;
      head = newNode;
  }

  else{

      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = prev->next;
      prev->next = newNode;

    }
  }


// TODO: SILVER PROBLEM
// Delete node at a particular index
bool LinkedList::deleteAtIndex(int n)
{
  bool isDeleted = false;

  if(head == NULL){
    cout<< "List is already empty"<<endl;
    return isDeleted;
  }

  // Special case to delete the head
  if (n == 0) {
    Node *temp = head;
    head = head->next;
    delete temp; 
    isDeleted = true;
    return isDeleted;           
  }

  Node *pres = head;
	Node *prev = NULL;
  int i = 0;
  while(i < n && pres != NULL){
    prev = pres;
    pres = pres->next;
    i++;
  }
  
  if (pres != NULL){
    prev->next = pres->next;
    delete pres;
    isDeleted = true;
  } else {
    cout << "List is only " << i+1 << " elements long." << endl;
  }
  
	return isDeleted;
}

// TODO: GOLD PROBLEM
// Swap the first and last nodes (don't just swap the values)
bool LinkedList::swapFirstAndLast()
{
    bool isSwapped = false;

    if(head == NULL) {
        cout << "List is empty. Cannot swap" << endl;
        return false;
    }

    // TODO (take care of the edge case when your linkedlist has just 2 nodes)
    Node* temp;
    if (head->next->next == NULL){
      temp = head->next;
      temp -> next = head;
      head -> next = NULL;
      head = temp;
      return true;
    }

    temp = head;
    while(temp->next->next != NULL){
      temp = temp->next;
    }
    Node* last = temp->next;
    last -> next = head->next;
    head -> next = NULL;
    temp -> next = head;
    head = last;
    
    isSwapped = true;
    
    return isSwapped;
}

// Print the keys in your list
void LinkedList::printList(){
  Node* temp = head;

  while(temp->next != NULL){
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}

// Search for a specified key and return a pointer to that node
Node* LinkedList::searchList(int key) {

    Node* ptr = head;
    while (ptr != NULL && ptr->key != key)
    {
        ptr = ptr->next;
    }
    return ptr;
}
