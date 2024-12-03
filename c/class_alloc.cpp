#include "stdio.h"
#include "stdlib.h"
#include <sys/time.h>

class Person {
  public:
  int age;
  Person(int age)
  {
    this->age = age;
  }
};

long long time_ms()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long long ms = tv.tv_sec * 1000LL + tv.tv_usec / 1000;
    return ms;
}

int run (int r, int s) {
  long long start = time_ms();
  int e = 0;
  for(int i = 0; i < r; i++) {
    Person* p = new Person(s);
    e += p->age;
    delete p;
  }
  long long end = time_ms();
  long long took = end - start;
  printf("Took : %lld ms\n", took);
  return took;
}

int main(int argc, char** argv) {
  int r = atoi(argv[1]);
  int s = atoi(argv[2]);
  printf("Inputs : %d %d\n", r, s);
  printf("Integer type size : %ld\n", sizeof(int));
  long long sum = 0;
  long long min = 1L << 32;
  long long max = -1;
  int ts = 10;
  for(int i = 0; i < ts; i++) {
    long long t = run(r, s);
    if(t < min) min = t;
    if(t > max) max = t;
    sum += t;
  }
  double avg = ((double)sum) / ts;
  printf("Min : %lld, max : %lld, average : %f\n", min, max, avg);
}
