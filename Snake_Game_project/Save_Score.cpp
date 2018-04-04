#include "Save_Score.h"
void loadFile(SaveScore onePlayer[3], SaveScore twoPlayer[3]) // 0 is easy mode, 1 is hard mode, 2 is god mode
{
	FILE *fp = fopen(File_Name, "rt");
	if (fp == NULL) exit(EXIT_FAILURE);
	int eof = 0;
	while (eof != EOF){
		char Section[15];
		fgets(Section, 15, fp);

		if (!strcmp(Section, "One Player:\n")){
			fgets(Section, 15, fp);
			fgets(onePlayer[0].name, 30, fp);
			eof = fscanf(fp, "%d", &onePlayer[0].score);
			eof = fscanf(fp, "%c");

			fgets(Section, 15, fp);
			fgets(onePlayer[1].name, 30, fp);
			eof = fscanf(fp, "%d", &onePlayer[1].score);
			eof = fscanf(fp, "%c");

			fgets(Section, 15, fp);
			fgets(onePlayer[2].name, 30, fp);
			eof = fscanf(fp, "%d", &onePlayer[2].score);
			eof = fscanf(fp, "%c");
		}
		if (!strcmp(Section, "Two Player:\n")){
			fgets(Section, 15, fp);
			fgets(twoPlayer[0].name, 30, fp);
			eof = fscanf(fp, "%d", &twoPlayer[0].score);
			eof = fscanf(fp, "%c");

			fgets(Section, 15, fp);
			fgets(twoPlayer[1].name, 30, fp);
			eof = fscanf(fp, "%d", &twoPlayer[1].score);
			eof = fscanf(fp, "%c");

			fgets(Section, 15, fp);
			fgets(twoPlayer[2].name, 30, fp);
			eof = fscanf(fp, "%d", &twoPlayer[2].score);
			eof = fscanf(fp, "%c");
		}
	}
	for (int i = 0; i < 3; i++){
		onePlayer[i].name[strlen(onePlayer[i].name) - 1] = '\0';
		twoPlayer[i].name[strlen(twoPlayer[i].name) - 1] = '\0';
	}
}

void saveFile(SaveScore onePlayer[3], SaveScore twoPlayer[3])
{
	FILE *fp = fopen(File_Name, "wt");
	if (!fp) exit(EXIT_FAILURE);

	fprintf(fp, "One Player:\n");
	fprintf(fp, ">>>Easy mode\n");
	fputs(onePlayer[0].name, fp);
	fprintf(fp, "\n%d\n", onePlayer[0].score);

	fprintf(fp, ">>>Hard mode\n");
	fputs(onePlayer[1].name, fp);
	fprintf(fp, "\n%d\n", onePlayer[1].score);

	fprintf(fp, ">>>God mode\n");
	fputs(onePlayer[2].name, fp);
	fprintf(fp, "\n%d\n", onePlayer[2].score);

	fprintf(fp, "Two Player:\n");
	fprintf(fp, ">>>Easy mode\n");
	fputs(twoPlayer[0].name, fp);
	fprintf(fp, "\n%d\n", twoPlayer[0].score);

	fprintf(fp, ">>>Hard mode\n");
	fputs(twoPlayer[1].name, fp);
	fprintf(fp, "\n%d\n", twoPlayer[1].score);

	fprintf(fp, ">>>God mode\n");
	fputs(twoPlayer[2].name, fp);
	fprintf(fp, "\n%d", twoPlayer[2].score);
}

bool checkScore(SaveScore onePlayer[3], SaveScore twoPlayer[3], int &vMode, int &pMode, int &Score, int Player)
{
	if (pMode == 1){
		if (vMode == 1 && Score > onePlayer[0].score) //Easy Mode
		{
			onePlayer[0].score = Score;
			getName(onePlayer[0].name, 1, Player);
			return true;
		}
		if (vMode == 2 && Score > onePlayer[1].score) // Hard Mode
		{
			onePlayer[1].score = Score;
			getName(onePlayer[1].name, 1, Player);
			return true;
		}
		if (vMode == 3 && Score > onePlayer[2].score) // God Mode
		{
			onePlayer[2].score = Score;
			getName(onePlayer[2].name, 1, Player);
			return true;
		}
	}
	else{
		if (vMode == 1 && Score > twoPlayer[0].score) //Easy Mode
		{
			twoPlayer[0].score = Score;
			getName(twoPlayer[0].name, 2, Player);
			return true;
		}
		if (vMode == 2 && Score > twoPlayer[1].score) // Hard Mode
		{
			twoPlayer[1].score = Score;
			getName(twoPlayer[1].name, 2, Player);
			return true;
		}
		if (vMode == 3 && Score > twoPlayer[2].score) // God Mode
		{
			twoPlayer[2].score = Score;
			getName(twoPlayer[2].name, 2, Player);
			return true;
		}
	}
	return false;
}
