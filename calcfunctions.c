#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "./headers/calcfunctions.h"


float Average(float* values, int size)
{
	float resultingAverage = 0;

	for (int i = 0; i < size; i++)
	{
		resultingAverage += values[i];
	}

	return resultingAverage / size;
}

float WeightedAverage(float* values, float* weights, int size)
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

float StandardDeviation(float* values, int size)
{
	float average = Average(values, size);
	float standardDeviation = 0;

	for (int i = 0; i < size; i++)
	{
		standardDeviation += pow((values[i] - average), 2);
	}

	return sqrt(standardDeviation / size);
}


float GreatestValue(float* values, int size)
{	
	float greatestValue = -INFINITY;

	for (int i = 0; i < size; i++)
	{
		if (values[i] > greatestValue) greatestValue = values[i];
	}

	return greatestValue;
}

float SmallestValue(float* values, int size)
{	
	float smallestValue = INFINITY;

	for (int i = 0; i < size; i++)
	{
		if (values[i] < smallestValue) smallestValue = values[i];
	}

	return smallestValue;
}

void SetValues(float* values, int size)
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