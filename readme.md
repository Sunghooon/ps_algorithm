# PS note

## Purpose
Solve problem regularly and leave some comments about algorithm, reminding myself.
Practice using some git commands and maintaining repository.

* update git repository
```
// at git workspace,
$ git init
$ git add .
% git commit -m "commit msg"

// update remote repository
% git push origin main
```

## Tips
* saving i/o time
```c
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
```
Unsynchronize C++ i/o `iostream` and C `stdio`, C++ can use independent buffer, becoming faster (slightly). 

Untie `cin` and `cout`, basically they are tied, ensuring clearing buffer before using.

It just can be considered in problem solving field, as it may cause unintended effect in multi-thread env, etc.

* uinsg INT_MAX, INT_MIN
```c
#include <limits.h>
```

## Ref site
* [Softeer](https://softeer.ai/index)
    * [level 1](https://github.com/Sunghooon/ps_algorithm/tree/main/softeer/lv_1)
    * [level 2](https://github.com/Sunghooon/ps_algorithm/tree/main/softeer/lv_2)
    * [level 3](https://github.com/Sunghooon/ps_algorithm/tree/main/softeer/lv_3)
* [Baekjoon](https://www.acmicpc.net/)