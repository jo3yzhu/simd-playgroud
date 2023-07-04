#include <algorithm>
#include <vector>
#include <random>
#include <memory>
#include <cstddef>
#include <simd-algorithm/float_sum.h>

int main() {
    const auto n = size_t(8192);
    auto x = std::vector<float>(n);
    std::generate(x.begin(), x.end(), [uni = std::uniform_real_distribution<float>(), rng = std::mt19937()]() mutable { return uni(rng); });

    auto vector_result = simd_algorithm::vector_sum(x.data(), n);
    auto scalar_result = simd_algorithm::scalar_sum(x.data(), n);

    return 0;
}