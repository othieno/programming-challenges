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
    * The number of students on the trip, of whom there can be no more than 1000.
    */
   uint32_t nStudents = 0;
   /**
    * The amount spent by each student on the trip in cents. We convert to cents so
    * that we can use integer arithmetic as opposed to floating point arithmetic,
    * which, if not properly done, adds rounding errors to the result.
    */
   uint32_t amountSpent[1000];

   while (scanf("%u", &nStudents) != EOF && nStudents)
   {
      /**
       * The total and average amounts spent for this trip.
       */
      uint32_t totalAmountSpent = 0;
      double averageAmountSpent = 0;
      /**
       * The exchanged amount spent for this trip.
       */
      double amountGiven = 0;
      double amountTaken = 0;
      double amountExchanged = 0.01;

      uint32_t i = 0;
      uint32_t* currentAmountSpent = amountSpent;
      for (; i < nStudents; ++i, ++currentAmountSpent)
      {
         uint32_t dollars, cents;
         scanf("%u.%u", &dollars, &cents);
         *currentAmountSpent = (dollars * 100) + cents;
         totalAmountSpent += *currentAmountSpent;
      }
      averageAmountSpent = totalAmountSpent / (double)nStudents;
      /**
       * Calculate the exchanged amount.
       */
      for (currentAmountSpent = amountSpent; nStudents-- > 0; ++currentAmountSpent)
      {
         const int32_t dAmountSpent = averageAmountSpent - *currentAmountSpent;
         if (dAmountSpent < 0)
            amountTaken -= dAmountSpent;
         else
            amountGiven += dAmountSpent;
      }
      amountExchanged *= (amountTaken > amountGiven) ? amountTaken : amountGiven;
      printf("$%.2f\n", amountExchanged);
   }
   return 0;
}
