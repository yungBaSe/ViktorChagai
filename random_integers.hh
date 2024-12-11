namespace random{
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count()); // в качестве сида использует время
uniform_int_distribution<int> distrib(1, 10); // создать распределение
int get_rand() {
    return distrib(rnd); // получить рандомное число из заданного в распределении отрезка 
}
};