#define ook order_of_key
#define fbo find_by_order

template <class T, class H, class Comp = std::less<T>>
using omap = __gnu_pbds::tree<T, H, Comp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <typename K, typename Comp = std::less<K>>
using oset = omap<K, __gnu_pbds::null_type, Comp>;
