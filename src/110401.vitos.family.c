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
 * Calculate the minimal distance, given a set of street numbers.
 * @param streetNumbers an array of street numbers.
 * @param n the number of street numbers.
 */
uint32_t shortestDistance(const uint32_t* const streetNumbers, const uint32_t n);


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
	 * transformed into integers.
	 */
	char buffer[4096];


   while (scanf("%u", &n) != EOF)
   {
		while (n-- > 0 && fgets(buffer, sizeof(buffer), stdin) != NULL)
		{
			/**
			 * Get the number of relatives as well as each street number.
			 */
			int i = 0;
			const char* token = buffer;
			r = atoi(token);

			for (; i < r; ++i)
			{
				token = strchr(++token, ' ');
				s[i] = atoi(token);
			}
			printf("%d\n", shortestDistance(s, r));
		}
   }
	return 0;
}


uint32_t shortestDistance(const uint32_t* const s, const uint32_t n)
{
	return 0;
}
