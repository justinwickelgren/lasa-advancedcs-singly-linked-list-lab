
//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//

/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array.
 *
 */

#include "slist.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

Element *mergeSortLinkedList(Element *first);
Element *getMiddleElement(Element *first);
Element *sortedMerge(Element *a, Element *b);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main() {
  ifstream infile;
  int i = 0;
  char cNum[200];
  LinkedList airportList; // Replace array with Linked List
  int airportCount;
  // Airport* a[13500];

  infile.open("airport-codes_US.csv", ifstream::in);
  infile.ignore(1000, '\n');
  if (infile.is_open()) {
    int c = 0;
    Airport *a;
    while (infile.good()) {
      a = new Airport();
      infile.getline(cNum, 256, ',');
      a->code = string(cNum);
      infile.getline(cNum, 256, ',');
      infile.getline(cNum, 256, ',');
      infile.getline(cNum, 256, ',');
      a->longitude = atof(cNum);
      infile.getline(cNum, 256, ',');
      a->latitude = atof(cNum);
      airportList.add(a);
      i++;
      c++;
      infile.ignore(1000, '\n');
    }
    airportCount = c - 1;

    infile.close();

    airportList.first = mergeSortLinkedList(airportList.first);

    Element *current = airportList.first;

    while (current != NULL) {
      cout << current->code << " lat: " << current->latitude
           << " long: " << current->longitude << endl;
      cout << "Distance between "
           << "Austin"
           << " and " << current->code << " is "
           << distanceEarth(30.19449997, -97.66989899, current->latitude,
                            current->longitude)
           << endl;
      current = current->next;
    }

  } else {
    cout << "Error opening file";
  }
}

#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) { return (deg * pi / 180); }

//  This function converts radians to decimal degrees
double rad2deg(double rad) { return (rad * 180 / pi); }

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r) / 2);
  v = sin((lon2r - lon1r) / 2);
  return 2.0 * earthRadiusKm *
         asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

/*
        Provide sort routine on linked list
*/

Element *mergeSortLinkedList(Element *first) {
  if ((first == NULL) || (first->next == NULL)) {
    return first;
  }
  Element *middle = getMiddleElement(first);
  Element *afterMiddle = middle->next;
  middle->next = NULL;
  Element *left = mergeSortLinkedList(first);
  Element *right = mergeSortLinkedList(afterMiddle);
  return sortedMerge(left, right);
}

Element *sortedMerge(Element *a, Element *b) {
  if (a == NULL) {
    return b;
  }
  if (b == NULL) {
    return a;
  }

  if (distanceEarth(30.19449997, -97.66989899, a->latitude, a->longitude) <
      distanceEarth(30.19449997, -97.66989899, b->latitude, b->longitude)) {
    a->next = sortedMerge(a->next, b);
    return a;

  } else {
    b->next = sortedMerge(a, b->next);
    return b;
  }
}

Element *getMiddleElement(Element *first) {
  if (first == NULL) {
    return first;
  }
  Element *slow = first;
  Element *fast = first->next;
  while (fast != NULL) {
    fast = fast->next;
    if (fast != NULL) {
      slow = slow->next;
      fast = fast->next;
    }
  }
  return slow;
}