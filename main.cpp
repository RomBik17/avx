
#include <iostream>
#include <immintrin.h>

//avx example
__m256 multiply_and_add(__m256 a, __m256 b, __m256 c)
{
    return _mm256_fmadd_ps(a, b, c);
}

/*
    __m128	        128-bit vector containing 4 floats
    __m128d	        128-bit vector containing 2 doubles
    __m128i	        128-bit vector containing integers
    __m256	        256-bit vector containing 8 floats
    __m256d	        256-bit vector containing 4 doubles
    __m256i	        256-bit vector containing integers


    function naming
    _mm<bit_width>_<name>_<data_type>

	ps                                  - vectors contain floats (ps stands for packed single-precision)
    pd                                  - vectors contain doubles (pd stands for packed double-precision)
    epi8/epi16/epi32/epi64              - vectors contain 8-bit/16-bit/32-bit/64-bit signed integers
    epu8/epu16/epu32/epu64              - vectors contain 8-bit/16-bit/32-bit/64-bit unsigned integers
    si128/si256                         - unspecified 128-bit vector or 256-bit vector
    m128/m128i/m128d/m256/m256i/m256d   - identifies input vector types when they're different than the type of the returned vector
*/

int main()
{
    /* Initialize the two argument vectors */
    __m256 evens = _mm256_set_ps(2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0);
    __m256 odds = _mm256_set_ps(1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0);

    /* Compute the difference between the two vectors */
    __m256 result = _mm256_sub_ps(evens, odds);

    /* Display the elements of the result vector */
    float* f = (float*)&result;
    printf("%f %f %f %f %f %f %f %f\n",
           f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);

    return 0;
}
