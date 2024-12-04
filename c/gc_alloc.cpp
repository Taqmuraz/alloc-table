#include "stdio.h"
#include "stdlib.h"
#include <sys/time.h>
#include <cstring>
#include <algorithm>

class Person {
  public:
  int age;
};

class Heap {
  Person* mem;
  Person* end;
  Person* peak;
  Person* temp;

public:
  Heap(int size) {
    this->mem = (Person*)malloc(sizeof(Person) * size);
    this->peak = mem;
    this->end = mem + size;
    this->temp = new Person();
  }
  Person* alloc(int age) {
    Person* h;
    if(peak < end) h = peak++;
    else h = peak = mem;
    h->age = age;
    return h;
  }
};

long long time_ms()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long long ms = tv.tv_sec * 1000LL + tv.tv_usec / 1000;
    return ms;
}

int e = 0;

int run (int r, int s, Heap* heap) {
  long long start = time_ms();
  for(int i = 0; i < r; i++) {
    Person* p = heap->alloc(s);
    e += p->age;
  }
  long long end = time_ms();
  long long took = end - start;
  printf("Took : %lld ms\n", took);
  return took;
}

int main(int argc, char** argv) {
  int r = atoi(argv[1]);
  int s = atoi(argv[2]);
  int hs = std::min(r, 1024 * 1024);
  Heap heap(hs);
  printf("Inputs : %d %d\n", r, s);
  printf("Integer type size : %ld\n", sizeof(int));
  long long sum = 0;
  long long min = 1L << 32;
  long long max = -1;
  int ts = 10;
  for(int i = 0; i < ts; i++) {
    long long t = run(r, s, &heap);
    if(t < min) min = t;
    if(t > max) max = t;
    sum += t;
  }
  double avg = ((double)sum) / ts;
  printf("Min : %lld, max : %lld, average : %f, e:%d\n", min, max, avg, e);
}
