// Description: O3 can greatly inflate the code, sometimes it is more profitable to change to O2
// Ofast is the strongest level
// avx2 may not be supported on Yandex.Contest, then avx or sse/2/3/4/4.1/4.2
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,bmt,lzcnt,popcnt")
// if it is necessary that the pragmas be applied strictly to one function
__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void work() {
    // do something
}