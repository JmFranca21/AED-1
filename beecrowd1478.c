#include <stdio.h>

int main ()
{

	int tamanho, linha, coluna;

	while (1)
	{

		scanf("%hd", &tamanho);
		int m[tamanho][tamanho];

		if (tamanho == 0)
			return 0;

		for(linha = 0; linha < tamanho; linha++)
			for(coluna = 0; coluna < tamanho; coluna++)
			{
				if (linha == coluna)
					m[linha][coluna] = 1;
				if (linha < coluna)
					m[linha][coluna] = coluna - linha + 1;
				if (linha > coluna)
					m[linha][coluna] = linha - coluna + 1;
			}


		for (linha = 0; linha < tamanho; linha++)
		{
			for (coluna = 0; coluna < tamanho; coluna++)
			{
				if (coluna == 0)
					printf("%3hd", m[linha][coluna]);
				else
					printf(" %3hd", m[linha][coluna]);

			}

			printf("\n");
		}

		printf("\n");

	}
}