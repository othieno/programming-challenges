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
#include <stdint.h>

int main(int argc, char** argv)
{
   /**
    * Input values are less than 10^6 (32-bit integers at least)
    * and greater than zero (unsigned).
    */
   uint32_t i, j;

   while (scanf("%u %u", &i, &j) != EOF)
   {
      uint32_t min = (i < j) ? i : j;
      const uint32_t max = (i != min) ? i : j;

      uint32_t maxlen = 0;
      for (; min <= max; ++min)
      {
         uint32_t n = min;
         uint32_t len = 1;
         for (; n != 1; (n = n & 1 ? (3 * n) + 1 : n >> 1), ++len) ;
         maxlen = len > maxlen ? len : maxlen;
      }
      printf("%u %u %u\n", i, j, maxlen);
   }
   return 0;
}

