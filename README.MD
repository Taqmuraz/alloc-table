Linux (x64), Ubuntu, Intel(R) Core(TM) m3-8100Y CPU @ 1.10GHz

1.1 GHz 2 cores, 4 GB RAM

Running tests on single thread

Allocating integer arrays
| test                                    | Java 17 new[]               | C GCC malloc              |
| --                                      | --                          |  --                       |
| array of 16 integers 10 000 times       | 0-1ms, average 0.9ms        | 1-2ms, average 1.2ms      |
| array of 32 integers 10 000 times       | 1-3ms, average 1.7ms        | 1-3ms, average 1.7ms      |
| array of 1024 integers 10 000 times     | 6-26ms, average 12ms        | 21-46ms, average 26ms     |
| array of 2048 integers 10 000 times     | 9-53ms, average 22ms        | 24-52ms, average 28ms     |
| array of 16 integers 100 000 times      | 0-9ms, average 2ms          | 6-23ms, average 9ms       |
| array of 32 integers 100 000 times      | 0-14ms, average 3ms         | 10-15ms, average 11ms     |
| array of 1024 integers 100 000 times    | 0-113ms, average 16ms       | 234-1156ms, average 654ms |
| array of 2048 integers 100 000 times    | 0-223ms, average 26ms       | 216-1376ms, average 568ms |

Allocating instance of the class Person with one integer field.
| test                                | Java 17 new Person(n)       | C++ G++ new Person(n)     |
| --                                  | --                          | --                        |
| allocating 100 000 instances        | 0-6ms, average 1.3ms        | 4-8ms, average 5ms        |
| allocating 1 000 000 instances      | 0-11ms, average 2ms         | 43-69ms, average 47ms     |
| allocating 1 000 000 000 instances  | 22-50ms, average 28ms       | process terminated        |
