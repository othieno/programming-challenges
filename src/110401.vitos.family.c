/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2013 Jeremy Othieno.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * Calculate the minimal sum of distances, given a set of street numbers.
 * @param streetNumbers a set of street numbers.
 * @param n the number of street numbers in the aforementioned set.
 * @returns the minimal sum of distances for a given set of street numbers.
 */
uint32_t minimalSumOfDistances(const uint32_t* const streetNumbers, const uint32_t n);
/**
 * The comparison function used to quick-sort the street numbers in ascending order.
 * @param a the first number.
 * @param b the second number.
 * @returns a positive value if a is greater than b, a negative value if a is less
 * than b, and zero otherwise.
 */
int intcompare(const void* const a, const void* const b);


int main(int argc, char** argv)
{
   /**
    * The number of test cases.
    */
   uint32_t n = 0;
   /**
    * The number of relatives per test case.
    */
   uint32_t r = 0;
   /**
    * The street numbers. There can be no more than 500 street numbers (since)
    * there aren't more than 500 relatives, and each street number is in
    * the range (0, 30'000), therefore unsigned and at least 16 bits. I'll
    * stick to 32 bits because I assume it's the word size used by the judge.
    */
   uint32_t s[500];
   /**
    * A buffer large enough to store the street numbers before they're
    * converted into integers. Suppose we have the following test case:
    * 500 29999 29999 29999 29999 29999 29999 29999 29999 ... 29999
    * where all 500 relatives live at #29999.
    * A 3004 byte buffer is required to store the input:
    * - 3 bytes for the first number (number of relatives),
    * - (500 * 5) for all street numbers,
    * - 500 bytes for the spaces in between each number,
    * - and an additional byte for the '\0' added by fgets(3).
    */
   char buffer[3004];

   while (fscanf(stdin, "%u\n", &n) != EOF)
   {
      while (n-- && fgets(buffer, sizeof(buffer), stdin) != NULL)
      {
         /**
          * Tokenise the buffer to get the number of relatives and
          * their respective street number.
          */
         uint32_t i = 0;
         const char* token = buffer;
         r = atoi(token);
         for (; i < r; ++i)
         {
            token = strchr(++token, ' ');
            s[i] = atoi(token);
         }
         /**
          * Sort the array before calculating the minimal sum of distances.
          */
         qsort(s, r, sizeof(s[0]), &intcompare);
         printf("%d\n", minimalSumOfDistances(s, r));
      }
   }
   return 0;
}


int intcompare(const void* const a, const void* const b)
{
   return *((uint32_t*)a) - *((uint32_t*)b);
}


uint32_t minimalSumOfDistances(const uint32_t* const s, const uint32_t n)
{
   /**
    * Find the street number in the center of the given test case, a.k.a. the median.
    * Note that if there's an even amount of numbers in the set, then find the value
    * that is halfway between the middle pair.
    */
   const uint32_t i = n >> 1;
   const uint32_t s_i = (n & 1) ? s[i] : ((s[i] + s[i - 1]) >> 1);
   /**
    * Once the median has been found, this should represent the street number for
    * which the sum of distances to all other relatives is minimal. All that's left is
    * to summate the distances.
    */
   const uint32_t* s_j = s;
   uint32_t distance = 0;
   for (; s_j != s + n; ++s_j)
      distance += s_i > *s_j ? s_i - *s_j : *s_j - s_i;

   return distance;
}
