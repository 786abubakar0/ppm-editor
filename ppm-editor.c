#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // For exit() function

int flip_horizontal(char FileName[], char OutName[])    //function to flip horizontally the picture accepting the input file and giving output file
{
         // arrays to store the code of file

	int ptr[30000][3];
	int ptr1[90000];
	int e;
	int q = -1, w = 0;
	int c[2000];
        // pointers to handle the different files
	FILE *fptr1;
	FILE *fptr2;
	FILE *fptr3;


	fptr1 = fopen(FileName, "r"); // to read
	if (fptr1 == NULL)//for condition if file not found
	{
		printf("file not found!");
		exit(1);
	}

	fptr3 = fopen(OutName, "w");//for writing
	fprintf(fptr3, "%s\n", "P3");
	fptr2 = fopen(OutName, "a");//for append in the file

	int i = 1, j = 0;
	int* maxcolor;  //storing the maximum color value
	int* column;    //for storing no of columns
	int* rows;  //for storing no of rows

	int i1, i2, i3;

	//loop until the end of file
	while ((e = fgetc(fptr1)) != EOF)
	{
		fscanf(fptr1, "%d", c);//reading the content of file
		//storing the no of columns
		if (i == 2)
		{
			fprintf(fptr2, "   0%d ", *c);
			column = c;
			i1 = *column;
		}
        //storing the no of rows
		else if (i == 3)
		{
			fprintf(fptr2, "%d\n", *c);
			rows = c;
			i2 = *rows;

		}
        //storing maximum value
		else if (i == 4)
		{
			fprintf(fptr2, "   %d\n", *c);
			maxcolor = c;
			i3 = *maxcolor;
		}
        //changing the sequence of rows
		else
		{
			j++;
			int k;
			ptr[w][q] = *c;
			q++;
			if (q == 3)
			{
				q = 0; w++;
			}

			if (k = !(j % (i1 * 3)))
			{
				fprintf(fptr2, "\n", *c);
			}

		}

		i++;

	}
	ptr[w][0] = '\0';
	int counter;

	int counter1 = 0;

	int nm = 0;
	int km = 1;
	int m1;
	int round;

	//writing the changed code into output file
	for (m1 = 0; m1<i2; m1++)

	{
		counter = 1;
		round = i1 * km;
		for (counter; counter <= (i1 * 3); counter++)
		{
			ptr1[counter1] = ptr[round - 1][nm];
			fprintf(fptr2, "%d ", ptr1[counter1]);
			nm++;
			if (nm == 3)
			{
				nm = 0;
				round--;
			}
			counter1++;
		}
		km++;
	}
//closing the file pointer
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);

	return 0;
}

/********************************************************************************************************/
int negate_red(char FileName[], char OutName[])//function for negating the red color only, accepting input file and giving changed output file
{
    //variables and file pointers
	int e;
	int c[2000];
	FILE *fptr1;
	FILE *fptr2;
	FILE *fptr3;

    //if file is not found
	fptr1 = fopen(FileName, "r");
	if (fptr1 == NULL)
	{
		printf("file not found!");
		exit(1);
	}

	fptr3 = fopen(OutName, "w");//for writing into file
	fprintf(fptr3, "%s\n", "P3");
	fptr2 = fopen(OutName, "a");
    //variables for storing column,rows and max color value
	int i = 1, j = 0;
	int* maxcolor;
	int* column;
	int* rows;

	int i1, i2, i3;
//loop until the end of file
	while ((e = fgetc(fptr1)) != EOF)
	{
		fscanf(fptr1, "%d", c);//storing file content
		if (i == 2) //for no of columns
		{
			fprintf(fptr2, "   %d ", *c);
			column = c;
			i1 = *column;
		}

		else if (i == 3)//for no of rows
		{
			fprintf(fptr2, "%d\n", *c);
			rows = c;
			i2 = *rows;
		}

		else if (i == 4)//for max color value
		{
			fprintf(fptr2, "   %d\n", *c);
			maxcolor = c;
			i3 = *maxcolor;
		}

		else        //changing the value of red color value
		{
			j++;
			int k;
			if ((j + 1) % 3 == 0)
			{
				fprintf(fptr2, "%d ", i3 - (*c));
			}
			else
			{
				fprintf(fptr2, "%d ", *c);
			}
			if (k = !(j % (i1 * 3)))
			{
				fprintf(fptr2, "\n", *c);
			}

		}

		i++;
	}
        //closing the file pointers
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
	return 0;
}

/********************************************************************************************************/
int negate_green(char FileName[], char OutName[])   //function for negating the green color only,accepting input file and giving changed output file
{
	int e;
	int c[2000];
	//file pointers
	FILE *fptr1;
	FILE *fptr2;
	FILE *fptr3;

	fptr1 = fopen(FileName, "r");//for reading

	if (fptr1 == NULL)  //if file not found
	{
		printf("file not found!");
		exit(1);
	}

	fptr3 = fopen(OutName, "w");//for writing
	fprintf(fptr3, "%s\n", "P3");
	fptr2 = fopen(OutName, "a");//for appending

	int i = 1, j = 0;
	int* maxcolor;//storing max color value
	int* column;//storing no of columns
	int* rows;//storing no of rows

	int i1, i2, i3;
//loop until the end of file
	while ((e = fgetc(fptr1)) != EOF)
	{
		fscanf(fptr1, "%d", c);//reading the content of file
		if (i == 2)//storing no of columns
		{
			fprintf(fptr2, "   %d ", *c);
			column = c;
			i1 = *column;
		}

		else if (i == 3)//storing no of rows
		{
			fprintf(fptr2, "%d\n", *c);
			rows = c;
			i2 = *rows;
		}
		else if (i == 4)//storing no of max color value
		{
			fprintf(fptr2, "   %d\n", *c);
			maxcolor = c;
			i3 = *maxcolor;
		}

		else        //changing the green color code
		{
			j++;
			int k;
			if ((j) % 3 == 0)
			{
				fprintf(fptr2, "%d ", i3 - (*c));
			}
			else
			{
				fprintf(fptr2, "%d ", *c);
			}
			if (k = !(j % (i1 * 3)))
			{
				fprintf(fptr2, "\n", *c);
			}
		}

		i++;
	}
//closing the file pointers
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
	return 0;
}

/********************************************************************************************************/
int negate_blue(char FileName[], char OutName[])//function for negating the blue color
{
	int e;
	int c[2000];
	//file pointers
	FILE *fptr1;
	FILE *fptr2;
	FILE *fptr3;


	fptr1 = fopen(FileName, "r");
	if (fptr1 == NULL)//if file no found
	{
		printf("file not found!");
		exit(1);
	}
//for writing and appending
	fptr3 = fopen(OutName, "w");
	fptr2 = fopen(OutName, "a");
	int k = 1;
	int i = 1, j = 0;
	//variables for columns,rows and max color value
	int* maxcolor;
	int* column;
	int* rows;

	int i1, i2, i3;
//loop until the end of file
	while ((e = fgetc(fptr1)) != EOF)
	{
		fscanf(fptr1, "%d", c);
		if (i == 2)//no of columns
		{

			column = c;
			i1 = *column;
			fprintf(fptr2, "   %d ", *column);

		}

		else if (i == 3)//no of rows
		{
			fprintf(fptr2, "%d\n", *c);
			rows = c;
			i2 = *rows;
		}
		else if (i == 4)//max color value
		{
			fprintf(fptr2, "   %d\n", *c);
			maxcolor = c;
			i3 = *maxcolor;
		}

		else    //changing the only blue color code
		{

			j++;

			if ((j - 1) % 3 == 0)
			{

				if (i == 1)
				{
					column = c;
					i1 = *column;
					fprintf(fptr2, "   %d ", *column);
				}
				else {
					fprintf(fptr2, "%d ", i3 - (*c));
				}
			}
			else
			{
				fprintf(fptr2, "%d ", *c);
			}
			if (k = !(j % (i1 * 3)))
			{
				fprintf(fptr2, "\n", *c);
			}

		}

		i++;
	}
//closing file pointers
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
	return 0;
}
/********************************************************************************************************/

int cop(char FileName[], char OutName[])//function for coping the content of input file to output file
{
	int e;
	int c[20000];
	//file pointers
	FILE *fptr1;
	FILE *fptr2;
	FILE *fptr3;


	fptr1 = fopen(FileName, "r");//reading
	if (fptr1 == NULL)//if file not found
	{
		printf("file not found!");
		exit(1);
	}
//for writing and appending
	fptr3 = fopen(OutName, "w");
	fprintf(fptr3, "%s\n", "P3");
	fptr2 = fopen(OutName, "a");
//variables of columns,rows and max color value
	int i = 1, j = 0;
	int* maxcolor;
	int* column;
	int* rows;

	int i1, i2, i3;
//loop until end of file
	while ((e = fgetc(fptr1)) != EOF)
	{
		fscanf(fptr1, "%d", c);//reading file content
		if (i == 2)//for columns
		{
			fprintf(fptr2, "   %d ", *c);
			column = c;
			i1 = *column;
		}

		else if (i == 3)//for rows
		{
			fprintf(fptr2, "%d\n", *c);
			rows = c;
			i2 = *rows;
		}
		else if (i == 4)//for max color value
		{
			fprintf(fptr2, "   %d\n", *c);
			maxcolor = c;
			i3 = *maxcolor;
		}

		else//writing content into output file
		{
			fprintf(fptr2, "%d ", *c);
			int k;
			if (k = !(j % (i1 * 3)))
			{
				fprintf(fptr2, "\n", *c);
			}
		}

		i++;
	}
//closing the file pointers
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
	return 0;
}
/********************************************************************************************************/
int flatten_red(char FileName[], char OutName[])//function for setting the red to 0.accepting input file and giving output file
{
	int e;
	int c[2000];
	//file pointers
	FILE *fptr1;
	FILE *fptr2;
	FILE *fptr3;


	fptr1 = fopen(FileName, "r");//reading
	if (fptr1 == NULL)//file not found
	{
		printf("file not found!");
		exit(1);
	}

	fptr3 = fopen(OutName, "w");//for writing
	fprintf(fptr3, "%s\n", "P3");
	fptr2 = fopen(OutName, "a");//for appending

	int i = 1, j = 0;
	//for variables of columns,rows and max color value
	int* maxcolor;
	int* column;
	int* rows;

	int i1, i2, i3;
//loop until end of file
	while ((e = fgetc(fptr1)) != EOF)
	{
		fscanf(fptr1, "%d", c);
		if (i == 2)//for columns
		{
			fprintf(fptr2, "   %d ", *c);
			column = c;
			i1 = *column;
		}

		else if (i == 3)//for rows
		{
			fprintf(fptr2, "%d\n", *c);
			rows = c;
			i2 = *rows;
		}

		else if (i == 4)//for max color value
		{
			fprintf(fptr2, "   %d\n", *c);
			maxcolor = c;
			i3 = *maxcolor;
		}

		else//setting red to zero
		{
			j++;
			int k;
			if ((j + 1) % 3 == 0)
			{
				fprintf(fptr2, "%d ", 0);
			}
			else
			{
				fprintf(fptr2, "%d ", *c);
			}
			if (k = !(j % (i1 * 3)))
			{
				fprintf(fptr2, "\n", *c);
			}

		}

		i++;
	}
//closing the file pointers
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
	return 0;
}
/********************************************************************************************************/
int flatten_green(char FileName[], char OutName[])//function for setting green to 0,accept input file and give changed output file
{
	int e;
	int c[2000];
	//file pointers
	FILE *fptr1;
	FILE *fptr2;
	FILE *fptr3;


	fptr1 = fopen(FileName, "r");//for reading
	if (fptr1 == NULL)//if file not found
	{
		printf("file not found!");
		exit(1);
	}
//for writing and appending
	fptr3 = fopen(OutName, "w");
	fprintf(fptr3, "%s\n", "P3");
	fptr2 = fopen(OutName, "a");
//variables for storing columns,rows and max color value
	int i = 1, j = 0;
	int* maxcolor;
	int* column;
	int* rows;

	int i1, i2, i3;
//loop until end of file
	while ((e = fgetc(fptr1)) != EOF)
	{
		fscanf(fptr1, "%d", c);
		if (i == 2)//for no of columns
		{
			fprintf(fptr2, "   %d ", *c);
			column = c;
			i1 = *column;
		}

		else if (i == 3)//for storing no of rows
		{
			fprintf(fptr2, "%d\n", *c);
			rows = c;
			i2 = *rows;
		}
		else if (i == 4)//for storing max color value
		{
			fprintf(fptr2, "   %d\n", *c);
			maxcolor = c;
			i3 = *maxcolor;
		}

		else//setting green color to 0
		{
			j++;
			int k;
			if ((j) % 3 == 0)
			{
				fprintf(fptr2, "%d ", 0);
			}
			else
			{
				fprintf(fptr2, "%d ", *c);
			}
			if (k = !(j % (i1 * 3)))
			{
				fprintf(fptr2, "\n", *c);
			}
		}

		i++;
	}
//closing file pointers
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
	return 0;
}
/********************************************************************************************************/
int flatten_blue(char FileName[], char OutName[])//function for setting blue color to zero,accept input file and give changed output file
{
	int e;
	int c[2000];
	//file pointers
	FILE *fptr1;
	FILE *fptr2;
	FILE *fptr3;


	fptr1 = fopen(FileName, "r");//reading
	if (fptr1 == NULL)//if file not found
	{
		printf("file not found!");
		exit(1);
	}
//for writing and appending
	fptr3 = fopen(OutName, "w");
	fptr2 = fopen(OutName, "a");
	int k = 1;
	int i = 1, j = 0;
	//variabiles for storing no of columns,rows and max color value
	int* maxcolor;
	int* column;
	int* rows;

	int i1, i2, i3;
//loop until end of file
	while ((e = fgetc(fptr1)) != EOF)
	{
		fscanf(fptr1, "%d", c);
		if (i == 2)//for storing no of columns
		{

			column = c;
			i1 = *column;
			fprintf(fptr2, "   %d ", *column);

		}

		else if (i == 3)//for no of rows
		{
			fprintf(fptr2, "%d\n", *c);
			rows = c;
			i2 = *rows;
		}
		else if (i == 4)//for max color value
		{
			fprintf(fptr2, "   %d\n", *c);
			maxcolor = c;
			i3 = *maxcolor;
		}
//setting the blue color to zero
		else
		{

			j++;

			if ((j - 1) % 3 == 0)
			{

				if (i == 1)
				{
					column = c;
					i1 = *column;
					fprintf(fptr2, "   %d ", *column);
				}
				else {
					fprintf(fptr2, "%d ", 0);
				}
			}
			else
			{
				fprintf(fptr2, "%d ", *c);
			}
			if (k = !(j % (i1 * 3)))
			{
				fprintf(fptr2, "\n", *c);
			}

		}
		i++;
	}
//closing the file pointers
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
	return 0;
}
/********************************************************************************************************/
int grey_scale(char FileName[], char OutName[])//function for gray scale,accept input file and give changed output file
{
	int e;
	int k;
	int c[2000];
	//file pointers
	FILE *fptr1;
	FILE *fptr2;
	FILE *fptr3;

	int average, k1, k2, k3;
	int j1 = 0;


	fptr1 = fopen(FileName, "r");//for reading
	if (fptr1 == NULL)//if file not found
	{
		printf("file not found!");
		exit(1);
	}

	fptr3 = fopen(OutName, "w");//for writing
	fprintf(fptr3, "%s\n", "P3");
	fptr2 = fopen(OutName, "a");//for appending

	int i = 1, j = 0;
//variables for no of columns,rows and max color value
	int* maxcolor;
	int* column;
	int* rows;

	int i1, i2, i3;
//loop until end of file
	while ((e = fgetc(fptr1)) != EOF)
	{

		fscanf(fptr1, "%d", c);//reading file content
		if (i == 2)//for no of columns
		{

			column = c;
			i1 = *column;
			fprintf(fptr2, "   0%d ", i1);
		}

		else if (i == 3)//for no of rows
		{
			fprintf(fptr2, "%d\n", *c);
			rows = c;
			i2 = *rows;
		}

		else if (i == 4)//for max color value
		{
			fprintf(fptr2, "   %d\n", *c);
			maxcolor = c;
			i3 = *maxcolor;
		}

		else//getting average of color values
		{
			j++;
			j1++;


			if (j == 1)
			{
				k1 = *c;
			}

			if (j == 2)
			{
				k2 = *c;
			}
			if (j == 3)
			{
				k3 = *c;
			}
			if (j == 3)//writing average value
			{
				average = (k1 + k2 + k3) / 3;
				fprintf(fptr2, "%d %d %d ", average, average, average);
				j = 0;
			}

		}

		i++;
	}
//closing file pointers
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
	return 0;
}
/********************************************************************************************************/
int main()
{
	printf("+------------------------------------+\n");
	printf("| Portable Pixmap (PPM) Image Editor |\n");
	printf("+------------------------------------+\n\n");
//string variables for file paths
	char FileName[100];
	char OutName[100];
	char c1, c2, c3, c4, c5, c6, c7, c8;
	char temp[] = "temp.ppm";//temporary file

	printf("Enter name of image file: ");
	gets(FileName);//gets input file path

	printf("Enter name of output file: ");
	gets(OutName);//get output file path

//showing choices
	printf("\nHere are you choices:\n");
	printf("\t[1] convert to greyscale\t[2] flip horizontally\n");
	printf("\t[3] negative of red\t\t[4] negative of green\t[5] negative of blue\n");
	printf("\t[6] just the reds\t\t[7] just the greens\t[8] just the blues\n \n");
//getting choices
	printf("Do you want [1]? (y/n) ");
	scanf("%c", &c1);
	printf("Do you want [2]? (y/n) ");
	fflush(stdin);
	scanf("%c", &c2);
	printf("Do you want [3]? (y/n) ");
	fflush(stdin);
	scanf("%c", &c3);
	printf("Do you want [4]? (y/n) ");
	fflush(stdin);
	scanf("%c", &c4);
	printf("Do you want [5]? (y/n) ");
	fflush(stdin);
	scanf("%c", &c5);
	printf("Do you want [6]? (y/n) ");
	fflush(stdin);
	scanf("%c", &c6);
	printf("Do you want [7]? (y/n) ");
	fflush(stdin);
	scanf("%c", &c7);
	printf("Do you want [8]? (y/n) ");
	fflush(stdin);
	scanf("%c", &c8);
//implementing the input choices
	cop(FileName, OutName);
	if (c1 == 'y')
	{
		grey_scale(OutName, temp);
		cop(temp, OutName);
	}
	if (c2 == 'y')
	{
	    flip_horizontal(OutName, temp);
		cop(temp, OutName);
	}
	if (c3 == 'y')
	{
		negate_red(OutName, temp);
		cop(temp, OutName);
	}

	if (c4 == 'y')
	{
		negate_green(OutName, temp);
		cop(temp, OutName);
	}
	if (c5 == 'y')
	{
		negate_blue(OutName, temp);
		cop(temp, OutName);
	}
	if (c6 == 'y')
	{
		flatten_red(OutName, temp);
		cop(temp, OutName);
	}
	if (c7 == 'y')
	{
		flatten_green(OutName, temp);
		cop(temp, OutName);
	}
	if (c8 == 'y')
	{
		flatten_blue(OutName, temp);
		cop(temp, OutName);
	}


	remove(temp);//removing temporary file

	return 0;
}
