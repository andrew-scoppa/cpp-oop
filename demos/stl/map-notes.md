std::map is not a hashmap.
It's implemented using self-balancing trees; therefore, std::map has O(log n) lookup times.

std::unordered_map is a hashmap.
std::unordered_map has (amortized) O(1) lookup times, and it's parameterized by std::hash, which is implementation dependent.