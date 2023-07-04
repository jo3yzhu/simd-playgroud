#include <immintrin.h>
#include <simd-algorithm/float_sum.h>

namespace simd_playground {

    float vector_sum(float const* data, size_t n) {
        __m128 var1 = _mm_setzero_ps();
        __m128 var2 = _mm_setzero_ps();

        size_t i;
        for (i = 0; i + 8 < n; i += 8) {
            var1 = _mm_add_ps(var1, _mm_load_ps(data + i));
            var2 = _mm_add_ps(var2, _mm_load_ps(data + i + 4));
        }

        var1 = _mm_add_ps(var1, var2);
        var1 = _mm_add_ps(var1, var1);
        var1 = _mm_add_ps(var1, var1);

        for (; i < n; ++i) {
            var1 = _mm_add_ss(var1, _mm_load_ss(data + i));
        }

        return _mm_cvtss_f32(var1);
    }

    float scalar_sum(float const* data, size_t n) {
        float result = 0.0f;
        for (size_t i = 0; i < n; ++i) {
            result += data[i];
        }
        return result;
    }
}  // namespace simd_playground