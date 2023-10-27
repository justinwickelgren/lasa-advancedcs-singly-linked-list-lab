#include <string>

struct Element {
public:
  std::string code;
  double longitude;
  double latitude;
  Element *next;
};

class Airport {
public:
  std::string code;
  double longitude;
  double latitude;
};

class LinkedList {
public:
  Element *first;
  Element *last;
  LinkedList();
  ~LinkedList();
  void add(Airport *airport);
  void clear();
  bool equals(LinkedList list);
  Element *get(int index);
  void insert(int index, Element airport);
  void exchg(int index1, int index2);
  void swap(int index1, int index2);
  bool isEmpty();
  void remove(int index);
  void set(int index, Element airport);
  int size();
};