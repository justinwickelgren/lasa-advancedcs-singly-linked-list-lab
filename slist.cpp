/*
Class Library File
*/

#include "slist.h"
#include <stdlib.h>
#include <string>

using namespace std;
LinkedList::LinkedList() {
  first = NULL;
  last = NULL;
}

LinkedList::~LinkedList() {
  clear();
}

void LinkedList::add(Airport *airport) {
  Element *new1 = new Element;
  new1->code = airport->code;
  new1->longitude = airport->longitude;
  new1->latitude = airport->latitude;
  if (first == NULL) {
    first = new1;
    last = new1;
  } else {
    last->next = new1;
    last = new1;
  }
  delete airport;
}

void LinkedList::clear() {
  Element *current = first;
  while (current != NULL) {
    Element *next = current->next;
    delete current;
    current = next;
  }
  first = NULL;
  last = NULL;
}

bool LinkedList::equals(LinkedList list) {
  bool equals = true;
  Element *current1 = first;
  Element *current2 = list.first;
  while (current1 != NULL && current2 != NULL) {
    if (current1->code != current2->code ||
        current1->longitude != current2->longitude ||
        current1->latitude != current2->latitude) {
      equals = false;
      break;
    }
    current1 = current1->next;
    current2 = current2->next;
  }
  if (current1 != current2) {
    equals = false;
  }
  return equals;
}

Element *LinkedList::get(int index) {
  int count = 0;
  Element *current = first;
  while (count < index) {
    current = current->next;
    count++;
  }
  return current;
}

void LinkedList::insert(int index, Element airport) {
  if (index == 0) {
    Element *temp = first;
    first = &airport;
    first->next = temp;
  } else {
    Element *before = get(index - 1);
    Element *after = get(index);
    before->next = &airport;
    airport.next = after;
  }
}

void LinkedList::exchg(int index1, int index2) {
  Element *element1 = get(index1);
  Element *element2 = get(index2);
  Element temp = *element1;
  element1->code = element2->code;
  element1->longitude = element2->longitude;
  element1->latitude = element2->latitude;
  element2->code = temp.code;
  element2->longitude = temp.longitude;
  element2->latitude = temp.latitude;
}

void LinkedList::swap(int index1, int index2) {
  Element temp = *get(index1);
  set(index1, *get(index2));
  set(index2, temp);
}

bool LinkedList::isEmpty() { return first == NULL; }

void LinkedList::remove(int index) {
  if (index == 0) {
    Element *temp = first;
    first = first->next;
    delete temp;
  } else {
    Element *before = get(index - 1);
    Element *after = get(index + 1);
    before->next = after;
    delete get(index);
  }
}

void LinkedList::set(int index, Element airport) {
  Element *current = get(index);
  current->code = airport.code;
  current->longitude = airport.longitude;
  current->latitude = airport.latitude;
}

int LinkedList::size() {
  int count = 0;
  Element *current = first;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
};

// Constructor

// Destructor

// add(value)				//Adds a new value to the end of this
// list.

// clear()					//Removes all elements from this
// list.

// equals(list)				//Returns true if the two lists contain
// the same elements in the same order.

// get(index)				//Returns the element at the specified
// index in this list.

// insert(index, value)		//Inserts the element into this list before the
// specified index.

// exchg(index1, index2)		//Switches the payload data of specified
// indexex.

// swap(index1,index2)		//Swaps node located at index1 with node at
// index2

// isEmpty()				//Returns true if this list contains no
// elements.

// remove(index)			//Removes the element at the specified
// index from this list.

// set(index, value)		//Replaces the element at the specified index in
// this list with a new value.

// size()					//Returns the number of elements
// in this list.

// DO NOT IMPLEMENT >>> subList(start, length)	//Returns a new list containing
// elements from a sub-range of this list.

// DO NOT IMPLEMENT >>> toString()				//Converts the
// list to a printable string representation.