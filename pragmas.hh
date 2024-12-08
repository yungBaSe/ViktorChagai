#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,bmt,lzcnt,popcnt")
// О3 может сильно раздувать код - иногда выгоднее поменять на O2
// Ofast - самый сильный уровень, можно попробовать в крайнем случае
// avx2 может не поддерживаться на Яндекс.Контесте, тогда avx или sse/2/3/4/4.1/4.2

namespace pragmas{
// если нужно, чтобы прагмы применялись строго к одной функции
__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void work() {
    // do something
}
}