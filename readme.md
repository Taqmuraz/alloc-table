

Linux (x64), Ubuntu, Intel(R) Core(TM) m3-8100Y CPU @ 1.10GHz

1.1 GHz 2 cores, 4 GB RAM

Running tests on single thread.
Result format : "Xms-Yms ~Z ms" means tests took from X to Y milliseconds, and Z milliseconds in average

Allocating integer arrays
| test                           | Java 17 new[]        | C GCC malloc       | SBCL make-array   |
| --                             | --                   |  --                | --                         |
| 16 integers 10 000 times       | 0-1ms, ~0.9ms        | 1-2ms, ~1.2ms      | 0-4ms, ~0.73ms    |
| 32 integers 10 000 times       | 1-3ms, ~1.7ms        | 1-3ms, ~1.7ms      | 0-8ms, ~2.ms      |
| 1024 integers 10 000 times     | 6-26ms, ~12ms        | 21-46ms, ~26ms     | 12-40ms, ~7ms     |
| 2048 integers 10 000 times     | 9-53ms, ~22ms        | 24-52ms, ~28ms     | 12-40ms, ~19ms    |
| 16 integers 100 000 times      | 0-9ms, ~2ms          | 6-23ms, ~9ms       | 4-24ms, ~7ms      |
| 32 integers 100 000 times      | 0-14ms, ~3ms         | 10-15ms, ~11ms     | 3-8ms, ~7ms       |
| 1024 integers 100 000 times    | 0-113ms, ~16ms       | 234-1156ms, ~654ms | 147-183ms, ~155ms |
| 2048 integers 100 000 times    | 0-223ms, ~26ms       | 216-1376ms, ~568ms | 299-339ms, ~307ms |

Allocating instance of the class Person with one integer field.
| test| Java 17 new Person(n)| C++ G++ new Person(n)| C++ with pseudo GC| SBCL make-instance| SBCL make-array |
|--|--|--|--|--|--|
|100 000 instances |0-6ms, ~1.3ms|4-8ms,~5ms|0-1ms, ~0.2ms | 0-12ms, ~5ms | 0-7ms, ~4ms | 326-343ms, 333ms |
|1 000 000 instances|0-11ms, ~2ms|43-69ms, ~47ms| 1-3ms, ~1.1ms | 20-36ms, ~24ms | 31-51ms, ~38ms |
|1 000 000 000 instances|22-50ms, ~28ms|out of memory| 672-757ms, ~688ms | ~30sec | ~51sec |

