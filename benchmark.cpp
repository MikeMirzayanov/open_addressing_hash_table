#include "oaht.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <ctime>
#include <cassert>
#include <cstdint>

using namespace std;
using namespace oaht;

const int N = 5000000;
int64_t keys[N];

template <typename _Map>
void test(const char* name) {
    srand(97);
    for (size_t i = 0; i < N; i++)
        keys[i] = (static_cast<int64_t>(rand()) << 48) ^ (static_cast<int64_t>(rand()) << 32)
            ^ (rand() << 16) ^ rand();

    clock_t start_clock = clock();

    _Map m;

    for (size_t i = 0; i < N; i++)
        m[keys[i]] = keys[i] * keys[i];

    for (size_t i = 0; i < N; i++)
        assert(keys[i] * keys[i] == m[keys[i]]);

    for (size_t i = 0; i < N; i++) {
        assert(m.count(keys[i]) == 1);
        assert(m.count(keys[i] + 1) == 0);
    }

    cout << name << " takes " << ((clock() - start_clock) * 1000.0 / CLOCKS_PER_SEC) << endl;
}

int main() {
    test<map<int64_t, int64_t>>("std::map");
    test<unordered_map<int64_t, int64_t>>("std::unordered_map");
    test<hash_map<int64_t, int64_t>>("oaht::hash_map");
}
