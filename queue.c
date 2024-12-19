#include "queue.h"
#include <stdio.h>

int main() {
  queue_t a, b, c, d, e, f;
  a.next = &b;
  a.prev = &f;
  b.next = &c;
  b.prev = &a;
  c.next = &d;
  c.prev = &b;
  d.next = &e;
  d.prev = &c;
  e.next = &f;
  e.prev = &d;
  f.next = &a;
  f.prev = &e;

  int size;
  size = queue_size(&d);
  printf("size: %d", size);
  return 0;
}

int queue_size(queue_t *queue) {
  queue_t *pointer, *target;
  int size;
  target = queue;
  pointer = queue->next;
  size = 0;
  while (1) {
    size++;
    if (target == pointer)
      return size;
    pointer = pointer->next;
  }
}
