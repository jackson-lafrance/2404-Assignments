/*
 * Class: SubArray
 * Purpose: Stores a collection of subscriber pointers.
 *
 * Data members:
 *   elements_ - Array containing subscriber pointers
 *   size_     - Number of subscribers currently stored
 *
 * Member functions:
 *   SubArray()          - Initializes an empty subscriber collection
 *   SubArray(const ...) - Copies subscriber pointers from another collection
 *   ~SubArray()         - Leaves the subscriber objects unchanged
 *   cleanup()           - Deletes every subscriber in the collection
 *   add()               - Adds a subscriber pointer to the end of the array
 *   print()             - Prints every subscriber in the collection
 *   size()              - Returns the number of subscribers
 *   get()               - Returns the subscriber at a given index
 */
#ifndef SUBARRAY_H
#define SUBARRAY_H

#include "Subscriber.h"
#include "defs.h"

class SubArray {
public:
  SubArray();
  SubArray(const SubArray &subArray);
  ~SubArray();
  void cleanup();
  bool add(Subscriber *subscriber);
  bool add(const SubArray &subArray);
  void print() const;
  int size() const;
  Subscriber *get(int index) const;

private:
  Subscriber *elements_[MAX_ARR_SIZE];
  int size_;
};

#endif // SUBARRAY_H
