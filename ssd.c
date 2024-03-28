#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void read(int lba,FILE *output) //매개변수: 위치, 파일포인터
{
	FILE* fp = fopen("nand.txt", "r+");
	

	fseek(fp, 8 * lba, 0); //파일포인터 움직이기 == 커서 움직이기

	char a[9];

	if (fp != NULL)
	{
		fgets(a, 9, fp);
	}
	fprintf(output,"%s\n", a);

}

void write(char a[],int lba) //매개변수: 문자열, 위치
{
	FILE* fp = fopen("nand.txt", "r+");


	fseek(fp, 8*lba, 0); //파일포인터 움직이기 == 커서 움직이기

	if (fp != NULL)
	{
		fprintf(fp,"%s",a);
	}

	fclose(fp);


}

int main(int argc, char* argv[])
{
	if (argc == 4) //write
	{
		char input[9] = { 0, };
		for (int i = 0; i < 8; i++)
		{
			input[i] = argv[3][2 + i];
		}
		int temp = atoi(argv[2]);
		write(input,temp);

	}
	else if (argc == 3) //read
	{
		FILE* result = fopen("result.txt", "w");
		int temp = atoi(argv[2]);
		read(temp,result);
		fclose(result);
	}
	else
	{
		printf("no");
	}



}

