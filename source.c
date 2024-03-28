#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void help() {
	printf("\n==================================\n");
	printf("���� (Help) - ��� ������ ��ɾ�\n");
	printf("==================================\n\n");

	printf("1. write:\t�ش� LBA�� ���� �����մϴ�.\n\n");
	printf("\t����:\twrtie [LBA] [��]\n\n");

	printf("1. fullwrite:\t��� LBA�� ���� �����մϴ�.\n\n");
	printf("\t����:\tfullwrtie [��]\n\n");

	printf("1. read:\t�ش� LBA�� ���� �ҷ��ɴϴ�.\n\n");
	printf("\t����:\tread [LBA]\n\n");

	printf("1. fullread:\t��� LBA�� ���� �ҷ��ɴϴ�.\n\n");
	printf("\t����:\tfullread\n\n");

	printf("1. exit:\tShell�� ����˴ϴ�.\n\n");
	printf("\t����:\texit\n\n");
}

int main() {

	char name[64] = { 0, };
	while (1) {
		char str[64] = { 0, };
		fgets(str, 64, stdin);

		if (str[0] == 0) {
			continue;
		}
		else {
			strcpy(name, str);
			break;
		}
	}


	while (1) {
		printf(">>%s ", name);
		char str[64] = { 0, };
		fgets(str, 64, stdin);
		

		if (strlen(str) == 1 && str[0] == '\n') {
			printf("���� �Է� �ٽ� ����\n");
			continue;
		}
		else if (strncmp(str, "exit", 4) == 0) {
			printf("���α׷��� ����˴ϴ�.\n");
			break;
		}
		else if (strncmp(str, "write", 5) == 0) {
			char maincommand[400] = "./ssd ";
			char command[10];
			int lba =0 ;
			char val[256];

			int cnt = sscanf(str, "%s %d %s", command, &lba, val);
			if (cnt != 3) {
				printf("INVALID COMMAND\n");
				continue;
			}

			strcat(maincommand, str);
			
			system(maincommand);
		}
		else if (strncmp(str, "read", 4) == 0) {
			char maincommand[400] = "./ssd ";
			char command[10];
			int lba = 0;

			int cnt = sscanf(str, "%s %d", command, &lba);
			if (cnt != 2) {
				printf("INVALID COMMAND\n");
				continue;
			}

			strcat(maincommand, str);
			system(maincommand);
		}
		else if (strncmp(str, "fullwrite", 9) == 0) {
			char command[10];
			char val[256];

			int cnt = sscanf(str, "%s %s", command, val);
			if (cnt != 2) {
				printf("INVALID COMMAND\n");
				continue;
			}

			for (int i = 0; i < 100; i++) {
				char maincommand[400] = "./ssd write ";
				char s1[101];

				sprintf(s1, "%d", i);
				strcat(maincommand, s1);
				strcat(maincommand, " ");
				strcat(maincommand, val);
				system(maincommand);
			}
		}
		else if (strncmp(str, "fullread", 8) == 0) {
			FILE* fs = fopen("result.txt", "r");

			for (int i = 0; i < 100; i++) {
				char maincommand[400] = "./ssd read ";
				char s1[101];

				char str2[100];
				sprintf(s1, "%d", i);
				strcat(maincommand, s1);
				system(maincommand);
				fgets(str2, 9, fs);
				printf("%s\n", str2);
				fseek(fs, 0, SEEK_SET);
			}
		}
		else if (strncmp(str, "help", 4) == 0) {
			help();
		}
		else {
			printf("INVALID COMMAND\n");
			continue;
		}
	}

	return 0;
}