
#include <iostream>
#include <immintrin.h>

void initialization_and_sub()
{
    /* Initialize the two argument vectors */
    __m256 evens    = _mm256_set_ps(2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0);
    __m256 odds     = _mm256_set_ps(1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0);

    /* Compute the difference between the two vectors */
    __m256 result   = _mm256_sub_ps(evens, odds);

    /* Display the elements of the result vector */
    float* f        = (float*)&result;
    printf("%f %f %f %f %f %f %f %f\n",
           f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
}

void multiply_and_add(__m256 a, __m256 b, __m256 c)
{
    __m256 result   =  _mm256_fmadd_ps(a, b, c);
    float* res      = (float*)&result;
    printf("%f %f %f %f %f %f %f %f\n",
           res[0], res[1], res[2], res[3], res[4], res[5], res[6], res[7]);
}

void mask()
{
    int int_array[8] = {100, 200, 300, 400, 500, 600, 700, 800};

    /* Initialize the mask vector */
    __m256i mask     = _mm256_setr_epi32(-20, -72, -48, 9, -100, -3, 5, 8);
    /* Selectively load data into the vector */
    __m256i result2  = _mm256_maskload_epi32(int_array, mask);

    /* Display the elements of the result vector */
    int*    res      = (int*)&result2;
    printf("%d %d %d %d %d %d %d %d\n",
           res[0], res[1], res[2], res[3], res[4], res[5], res[6], res[7]);
}

void multiply_add_sub_fusion()
{
    __m256d veca    = _mm256_setr_pd(6.0, 6.0, 6.0, 6.0);
    __m256d vecb    = _mm256_setr_pd(2.0, 2.0, 2.0, 2.0);
    __m256d vecc    = _mm256_setr_pd(7.0, 7.0, 7.0, 7.0);

    /* Alternately subtract and add the third vector
       from the product of the first and second vectors */
    __m256d result  = _mm256_fmaddsub_pd(veca, vecb, vecc);

    /* Display the elements of the result vector */
    double* res     = (double*)&result;
    printf("%lf %lf %lf %lf\n", res[0], res[1], res[2], res[3]);
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
    __m256 evens    = _mm256_set_ps(2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0);
    __m256 odds     = _mm256_set_ps(1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0);
    __m256 vec     = _mm256_set_ps(1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0);

    initialization_and_sub();
    multiply_and_add(evens, odds, vec);
    mask();
    multiply_add_sub_fusion();

    return 0;
}
