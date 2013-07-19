#include <stdio.h>
#include <stdint.h>

int main(int argc, char** argv)
{
	/**
	 * The input values n and m, which stand for the number of lines and columns, respectively.
	 */
	uint32_t n, m;
	/**
	 * The number of processed fields.
	 */
	uint32_t nFields = 0;
	/**
	 * The matrix describing a mine field. Since the maximum dimension of any given mine
	 * field is 100x100, this matrix will have a dimension of 101x101 at most, taking the
	 * null terminator ('\0') into account.
	 */
	char minefield[101][101];
	/**
	 * While n and m are different from zero, process the input.
	 */
	while (scanf("%u %u", &n, &m) && n && m)
	{
		/**
		 * Read the mine field.
		 */
		uint32_t i = 0;
		for (; i < n; ++i)
		{
			getchar();
			fgets(minefield[i], m + 1, stdin);
		}
		/**
		 * Process the matrix.
		 */
		if (nFields > 0)
			printf("\nField #%d:\n", ++nFields);
		else
			printf("Field #%d:\n", ++nFields);

		for (i = 0; i < n; ++i)
		{
			uint32_t j = 0;
			for (; j < m; ++j)
			{
				if (minefield[i][j] == '.')
				{
					/**
					 * Count the number of adjacent mines and write the value to the mine field.
					 */
					uint32_t nMines = 0;

					if (j > 0							 && minefield[i    ][j - 1] == '*') ++nMines;
					if (j < (m - 1)  					 && minefield[i    ][j + 1] == '*') ++nMines;
					if (i > 0 && j > 0  				 && minefield[i - 1][j - 1] == '*') ++nMines;
					if (i > 0  							 && minefield[i - 1][j    ] == '*') ++nMines;
					if (i > 0 && j < (m - 1)		 && minefield[i - 1][j + 1] == '*') ++nMines;
					if (i < (n - 1) && j > 0  		 && minefield[i + 1][j - 1] == '*') ++nMines;
					if (i < (n - 1) 					 && minefield[i + 1][j    ] == '*') ++nMines;
					if (i < (n - 1) && j < (m - 1) && minefield[i + 1][j + 1] == '*') ++nMines;

					minefield[i][j] = '0' + nMines;
				}
			}
		}
		for (i = 0; i < n; ++i)
			printf("%s\n", minefield[i]);
	}
	return 0;
}
