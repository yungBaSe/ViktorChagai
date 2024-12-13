mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count()); // use current time as a seed
uniform_int_distribution<int> distrib(1, 10); // create distribution
int get_rand() {
    return distrib(rnd); // random from [1, 10]
}