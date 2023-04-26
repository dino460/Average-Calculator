#include <stdio.h>
#include "./headers/gui.h"

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