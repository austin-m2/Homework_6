// Homework_6.cpp
// Austin Morris
// CS 3700

#include "stdafx.h"
#include <immintrin.h>
#include <stdio.h>


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

	__m256i int_vector = _mm256_set_epi32(1, 2, 3, 4, 5, 6, 7, 8);
	int *ptr = (int*)&int_vector;
	printf("%d %d %d %d %d %d %d %d\n", ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6], ptr[7]);

	int_vector = _mm256_setr_epi32(1, 2, 3, 4, 5, 6, 7, 8);
	ptr = (int*)&int_vector;
	printf("%d %d %d %d %d %d %d %d\n", ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6], ptr[7]);

	int i;

	int int_array[8] = { 100, 200, 300, 400, 500, 600, 700, 800 };

	/* Initialize the mask vector */
	__m256i mask = _mm256_setr_epi32(-20, -72, -48, -9, -100, 3, 5, 8);

	/* Selectively load data into the vector */
	__m256i result1 = _mm256_maskload_epi32(int_array, mask);

	/* Display the elements of the result vector */
	int* res = (int*)&result1;
	printf("%d %d %d %d %d %d %d %d\n",
		res[0], res[1], res[2], res[3], res[4], res[5], res[6], res[7]);





	__m256d veca = _mm256_setr_pd(6.0, 6.0, 6.0, 6.0);

	__m256d vecb = _mm256_setr_pd(2.0, 2.0, 2.0, 2.0);

	__m256d vecc = _mm256_setr_pd(7.0, 7.0, 7.0, 7.0);

	/* Alternately subtract and add the third vector
	from the product of the first and second vectors */
	__m256d result2 = _mm256_fmaddsub_pd(veca, vecb, vecc);

	/* Display the elements of the result vector */
	double* res2 = (double*)&result2;
	printf("%lf %lf %lf %lf\n", res2[0], res2[1], res2[2], res2[3]);




	__m256d vec1 = _mm256_setr_pd(4.0, 5.0, 13.0, 6.0);
	__m256d vec2 = _mm256_setr_pd(9.0, 3.0, 6.0, 7.0);
	__m256d neg = _mm256_setr_pd(1.0, -1.0, 1.0, -1.0);

	/* Step 1: Multiply vec1 and vec2 */
	__m256d vec3 = _mm256_mul_pd(vec1, vec2);

	/* Step 2: Switch the real and imaginary elements of vec2 */
	vec2 = _mm256_permute_pd(vec2, 0x5);

	/* Step 3: Negate the imaginary elements of vec2 */
	vec2 = _mm256_mul_pd(vec2, neg);

	/* Step 4: Multiply vec1 and the modified vec2 */
	__m256d vec4 = _mm256_mul_pd(vec1, vec2);

	/* Horizontally subtract the elements in vec3 and vec4 */
	vec1 = _mm256_hsub_pd(vec3, vec4);

	/* Display the elements of the result vector */
	double* res3 = (double*)&vec1;
	printf("%lf %lf %lf %lf\n", res3[0], res3[1], res3[2], res3[3]);




    return 0;
}

