#pragma once

#include <type_traits>

namespace my_mod {

// 需要按字段名序列化的聚合类型须显式特化为 std::true_type。
template <typename T>
struct is_reflectable : std::false_type {};

} // namespace my_mod
