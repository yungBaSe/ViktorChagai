#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// ordered_set X;
// *X.find_by_order(k) - найти k-ую порядковую статистику
// X.order_of_key(n) - кол-во элементов < n 
// в остальном - все как у std::set
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;
// pref_trie base;
// base.insert("hello") - добавить строчку в бор
// auto range = base.prefix_range(x.substr(1)); - пара итераторов, образующих полуинтервал строк с заданным префиксом
struct chash { // large odd number for C
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};
gp_hash_table<ll,int,chash> h({},{},{},{},{1<<16});