// UpdateSubmit.cpp : 定义控制台应用程序的入口点。
//

#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;

int main()
{
	char firstLine[255] = "#!/bin/bash";
	char cmdLine[255] = "./$1 -2 -L 290 -H 120 -J 0.1 -h 8.0 -D 290 -r 1.5 -c 1.0e-5 -x 3.1 -b 1.6 -q 1 -R 1 -M 0.01 -U -Q -t 0.1 -T 0.05 -d 1000 -v 1513 -f 1 -G 1.0e7 -k 1.42e5 -p 1.18e-6 -g 1.4 -m 0 -s 1.82e-5 -i 0.04 -l 0.01 -I 0.0 -A 0.0 -E 2.5e6 -P 1e-4 -N 0.35 -n 8 -K";
	double K = 0.01;

	for (int i = 1; i <= 64; i++)
	{
		FILE *outputFile = NULL;
		char submitName[255] = "submit";
		char submitId[255] = { 0 };
		char submitSuffix[255] = ".sh";
		sprintf(submitId, "%d", i);
		//itoa(i, submitId, 10);
		strcat(submitName, submitId);
		strcat(submitName, submitSuffix);
		outputFile = fopen(submitName, "wt");

		fprintf(outputFile, "%s\n%s %f", firstLine,cmdLine,K);
		cout << cmdLine << " " << K << endl;

		K += 0.01;
		fclose(outputFile);
	}

	system("pause");
	return 0;
}

