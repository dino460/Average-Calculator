#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


#define SETVALUES "set\0"
#define SETWEIGHTS "stw\0"
#define SETSAMPLESIZE "sps\0"
#define RESETVALUES "rsv\0"
#define RESETWEIGHTS "rsw\0"
#define RESETALL "rsa\0"

#define READVALUESFROMFILE "rvf\0"
#define READWEIGHTSFROMFILE "rwf\0"

#define SHOWSAMPLESIZE "shs\0"
#define SHOWVALUES "shv\0"
#define SHOWWEIGHTS "shw\0"
#define SHOWALL "sha\0"

#define AVERAGE "avg\0"
#define WEIGHTEDAVERAGE "wav\0"
#define STDDEVIATION "std\0"
#define BIGVALUE "bvl\0"
#define SMALLVALUE "svl\0"

#define HIDEWARNINGS "hid\0"
#define EXIT "q\0"
#define HELP "h\0"
#define RESETSCREEN "rsc\0"


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


float Average(float values[], int size)
{
	float resultingAverage = 0;

	for (int i = 0; i < size; i++)
	{
		resultingAverage += values[i];
	}

	return resultingAverage / size;
}

float WeightedAverage(float values[], float weights[], int size)
{
	float resultingAverage = 0;

	for (int i = 0; i < size; i++)
	{
		resultingAverage += values[i] * weights[i];
	}

	float weightSum = 0;

	for (int i = 0; i < size; i++)
	{
		weightSum += weights[i];
	}

	return resultingAverage / weightSum;
}

float StandardDeviation(float values[], int size)
{
	float average = Average(values, size);
	float standardDeviation = 0;

	for (int i = 0; i < size; i++)
	{
		standardDeviation += pow((values[i] - average), 2);
	}

	return sqrt(standardDeviation / size);
}


float GreatestValue(float values[], int size)
{	
	float greatestValue = -INFINITY;

	for (int i = 0; i < size; i++)
	{
		if (values[i] > greatestValue) greatestValue = values[i];
	}

	return greatestValue;
}

float SmallestValue(float values[], int size)
{	
	float smallestValue = INFINITY;

	for (int i = 0; i < size; i++)
	{
		if (values[i] < smallestValue) smallestValue = values[i];
	}

	return smallestValue;
}


void SetValues(float values[], int size)
{
	for (int i = 0; i < size; i++)
	{
		scanf("%f", &values[i]);
	}
}


void SetNewArraySize(float** arrayToReset, int size)
{
	*arrayToReset = realloc(*arrayToReset, size * sizeof(float));
}


void PrintTitle()
{
	printf("    __  ___      ____  _       ______                 __  _         \n");  
	printf("   /  |/  /_  __/ / /_(_)     / ____/_  ______  _____/ /_(_)___  ____ \n");
	printf("  / /|_/ / / / / / __/ /_____/ /_  / / / / __ \\/ ___/ __/ / __ \\/ __ \\ \n");
	printf(" / /  / / /_/ / / /_/ /_____/ __/ / /_/ / / / / /__/ /_/ / /_/ / / / /\n");
	printf("/_/  /_/\\__,_/_/\\__/_/     /_/    \\__,_/_/ /_/\\___/\\__/_/\\____/_/ /_/ \n");
	printf("   ______      __           __      __                                \n");
	printf("  / ____/___ _/ /______  __/ /___ _/ /_____  _____                    \n");
	printf(" / /   / __ `/ / ___/ / / / / __ `/ __/ __ \\/ ___/                    \n");
	printf("/ /___/ /_/ / / /__/ /_/ / / /_/ / /_/ /_/ / /                        \n");
	printf("\\____/\\__,_/_/\\___/\\__,_/_/\\__,_/\\__/\\____/_/  v1.0.0\n");
	printf("\n\n~By Raphael Zoega~\n");
}

void PrintCommands()
{
	printf(" ______________________________________________________________________\n");
	printf("|                                                                      |\n");
	printf("| FUNCTION                                                       CODE  |\n");
	printf("| ==================================================================== |\n");
	printf("| SET SAMPLE VALUES -------------------------------------------- '%s' |\n", SETVALUES);
	printf("|    > Prompts user input for sample values                            |\n");
	printf("| SET WEIGHT VALUES -------------------------------------------- '%s' |\n", SETWEIGHTS);
	printf("|    > Prompts user input for weight values                            |\n");
	printf("| SET SAMPLE SIZE ---------------------------------------------- '%s' |\n", SETSAMPLESIZE);
	printf("|    > Prompts user input for new sample/weight size                   |\n");
	printf("| RESET SAMPLE VALUES ------------------------------------------ '%s' |\n", RESETVALUES);
	printf("| RESET WEIGHT VALUES ------------------------------------------ '%s' |\n", RESETWEIGHTS);
	printf("| RESET ALL VALUES --------------------------------------------- '%s' |\n", RESETALL);
	printf("| ==================================================================== |\n");
	printf("| AVERAGE ------------------------------------------------------ '%s' |\n", AVERAGE);
	printf("| WEIGHTED AVERAGE --------------------------------------------- '%s' |\n", WEIGHTEDAVERAGE);
	printf("|    > Prompts user input for weight values                            |\n");
	printf("| STANDARD DEVIATION ------------------------------------------- '%s' |\n", STDDEVIATION);
	printf("| GREATEST VALUE ----------------------------------------------- '%s' |\n", BIGVALUE);
	printf("| SMALLEST VALUE ----------------------------------------------- '%s' |\n", SMALLVALUE);
	printf("| ==================================================================== |\n");
	printf("| READ VALUES FROM FILE ---------------------------------------- '%s' |\n", READVALUESFROMFILE);
	printf("| READ WEIGHTS FROM FILE --------------------------------------- '%s' |\n", READWEIGHTSFROMFILE);
	printf("| ==================================================================== |\n");
	printf("| TOGGLE HIDE WARNINGS ----------------------------------------- '%s' |\n", HIDEWARNINGS);
	printf("| RESET CONSOLE ------------------------------------------------ '%s' |\n", RESETSCREEN);
	printf("| REQUEST HELP --------------------------------------------------- '%s' |\n", HELP);
	printf("| TERMINATE PROGRAM ---------------------------------------------- '%s' |\n", EXIT);
	printf("|______________________________________________________________________|\n\n");
}


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