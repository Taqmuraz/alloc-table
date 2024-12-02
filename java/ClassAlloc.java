class Person {
  int age;
  Person(int age) {
    this.age = age;
  }
}
public class ClassAlloc {
  static long run (int r, int s) {
    long start = System.currentTimeMillis();
    int e = 0;
    for (int i = 0; i < r; i++) {
      Person p = new Person(s);
      e += p.age;
    }
    long end = System.currentTimeMillis();
    long took = end - start;
    System.out.printf("Time took : %d ms\n", took);
    return took;
  }
  public static void main (String[] args) {
    int r = Integer.parseInt(args[0]);
    int s = Integer.parseInt(args[1]);
    long sum = 0;
    long min = Long.MAX_VALUE;
    long max = -1;
    int ts = 10;
    for (int i = 0; i < ts; i++) {
      long t = run(r, s);
      sum += t;
      if(t < min) min = t;
      if(t > max) max = t;
    }
    double avg = ((double)sum) / ts;
    System.out.printf("Min : %d, max : %d, average : %f\n", min, max, avg);
  }
}
