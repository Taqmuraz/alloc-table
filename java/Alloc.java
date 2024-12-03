
public class Alloc {
  static int e;
  interface Allocator {
    int[] allocate(int size);
  }
  static long run (int r, int s, Allocator a) {
    long start = System.currentTimeMillis();
    for (int i = 0; i < r; i++) {
      int[] b = a.allocate(s);
      e += b[0];
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
    Allocator allocator = i -> {
      int[] arr = new int[i];
      arr[0] = 1;
      return arr;
    };
    for (int i = 0; i < ts; i++) {
      long t = run(r, s, int[]::new);
      sum += t;
      if(t < min) min = t;
      if(t > max) max = t;
    }
    double avg = ((double)sum) / ts;
    System.out.printf("Min : %d, max : %d, average : %f, e: %d\n", min, max, avg, e);
  }
}
