#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#include "./headers/calcfunctions.h"
#include "./headers/gui.h"


#ifdef _WIN32
void ClearScreen()
{
	system("cls");
}

#else // !_WIN32
void ClearScreen()
{
	system("clear");
}
#endif


int main()
{
	int SAMPLESIZE = 5;
	float *values = (float *) malloc(SAMPLESIZE*sizeof(float));
	float *weights = (float *) malloc(SAMPLESIZE*sizeof(float));

	int firstRun = 1;
	int weightInputed = 0;
	int hideWarnings = 0;

	int inputSize = 20;
	char input[inputSize];

	ClearScreen();
	PrintTitle();
	PrintCommands();
	printf("< SAMPLE SIZE: %i >", SAMPLESIZE);
	printf("\n\n");

	do
	{
		if (firstRun && !hideWarnings)
		{
			printf("Sample values are not set!\n");
		}
		if (!weightInputed && !hideWarnings)
		{
			printf("Weight values are not set!\n");
		}

		printf(": ");
		scanf("%s", input);

		for (int i = 0; i < inputSize; i++) input[i] = tolower(input[i]);

		if (strcmp(input, SETVALUES) == 0)
		{
			if (firstRun) firstRun = 0;
			printf ("Type values...\n");
			printf(" > ");
			SetValues(values, SAMPLESIZE);
		}
		else if (strcmp(input, SETWEIGHTS) == 0)
		{
			if (!weightInputed) weightInputed = 1;
			printf ("Type weights...\n");
			printf(" > ");
			SetValues(weights, SAMPLESIZE);
		}
		else if (strcmp(input, AVERAGE) == 0)
		{
			printf(">>> Average: %.2f <<<\n", Average(values, SAMPLESIZE));
		}
		else if (strcmp(input, WEIGHTEDAVERAGE) == 0)
		{
			if (!weightInputed)
			{
				printf ("Type weights...\n");
				printf(" > ");
				SetValues(weights, SAMPLESIZE);
				weightInputed = 1;
			}

			printf(">>> Weighted Average: %.2f <<<\n", WeightedAverage(values, weights, SAMPLESIZE));
		}
		else if (strcmp(input, STDDEVIATION) == 0)
		{
			printf(">>> Standard Deviation: %.2f <<<\n", StandardDeviation(values, SAMPLESIZE));
		}
		else if (strcmp(input, BIGVALUE) == 0)
		{
			printf(">>> Greatest Value: %.2f <<<\n", GreatestValue(values, SAMPLESIZE));
		}
		else if (strcmp(input, SMALLVALUE) == 0)
		{
			printf(">>> Smallest Value: %.2f <<<\n", SmallestValue(values, SAMPLESIZE));
		}
		else if (strcmp(input, HELP) == 0)
		{
			printf("\n\n");
			PrintCommands();
		}
		else if (strcmp(input, RESETSCREEN) == 0)
		{
			ClearScreen();
			PrintTitle();
			PrintCommands();

			printf("< SAMPLE SIZE: %i >", SAMPLESIZE);

			printf("\n");
		}
		else if (strcmp(input, SHOWALL) == 0)
		{
			printf("\n< SAMPLE SIZE: %i >", SAMPLESIZE);
			printf("\nVALUES: ");
			for (int i = 0; i < SAMPLESIZE; i++) printf("%.2f, ", values[i]);

			printf("\nWEIGHTS: ");
			for (int i = 0; i < SAMPLESIZE; i++) printf("%.2f, ", weights[i]);

			printf("\n");
		}
		else if (strcmp(input, SHOWVALUES) == 0)
		{
			printf("\nVALUES: ");
			for (int i = 0; i < SAMPLESIZE; i++) printf("%.2f, ", values[i]);
		}
		else if (strcmp(input, SHOWWEIGHTS) == 0)
		{
			printf("\nWEIGHTS: ");
			for (int i = 0; i < SAMPLESIZE; i++) printf("%.2f, ", weights[i]);
		}
		else if (strcmp(input, SHOWSAMPLESIZE) == 0)
		{
			printf("\n< SAMPLE SIZE: %i >", SAMPLESIZE);
		}
		else if (strcmp(input, SETSAMPLESIZE) == 0)
		{
			firstRun = 1;
			weightInputed = 0;

			printf ("Type new sample size...\n");
			printf(" > ");
			int newSampleSize = 0;
			scanf("%i", &newSampleSize);

			if (newSampleSize > 1)
			{
 				SetNewArraySize(&values, SAMPLESIZE);
 				SetNewArraySize(&weights, SAMPLESIZE);

 				printf("\n< SAMPLE SIZE: %i >\n", SAMPLESIZE);
 			}
 			else
 			{
 				printf("Sample size must be at least 2.\n");
 			}
		}
		else if (strcmp(input, RESETVALUES) == 0)
		{
			firstRun = 1;
			SetNewArraySize(&values, SAMPLESIZE);
		}
		else if (strcmp(input, RESETWEIGHTS) == 0)
		{
			weightInputed = 0;
			SetNewArraySize(&weights, SAMPLESIZE);
		}
		else if (strcmp(input, RESETALL) == 0)
		{
			firstRun = 1;
			weightInputed = 0;
			SetNewArraySize(&values, SAMPLESIZE);
			SetNewArraySize(&weights, SAMPLESIZE);
		}
		else if (strcmp(input, HIDEWARNINGS) == 0)
		{
			hideWarnings = !hideWarnings;
		}
		else if (strcmp(input, READVALUESFROMFILE) == 0)
		{
			printf("Type file name (including ...\nMake sure the file is in the same directory as .out file.\n > ");
			scanf("%s", input);
			
			FILE *valueFile;
			char fileInputs[SAMPLESIZE];

			valueFile = fopen(input, "r");
			for (int i = 0; i < SAMPLESIZE; i++)
			{
				fscanf(valueFile, "%f", &values[i]);
			}

			fclose(valueFile);

			firstRun = 0;
		}
		else if (strcmp(input, READWEIGHTSFROMFILE) == 0)
		{
			printf("\nType file name (including extension)...\nMake sure the file is in the same directory as .out file.\n > ");
			scanf("%s", input);
			
			FILE *valueFile;
			char fileInputs[SAMPLESIZE];

			valueFile = fopen(input, "r");
			for (int i = 0; i < SAMPLESIZE; i++)
			{
				fscanf(valueFile, "%f", &weights[i]);
			}

			fclose(valueFile);

			weightInputed = 1;
		}
		else if (strcmp(input, EXIT) != 0)
		{
			printf("Unknown command.\n");
		}

		printf("\n");

		//input[0] = "\0";
	}
	while (strcmp(input, EXIT) != 0);

	free(values);
	free(weights);

	return 0;
}