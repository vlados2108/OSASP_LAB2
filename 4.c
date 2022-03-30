#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	if (argc == 3)
	{	
		int N = atoi(argv[2]);
		if (N<0)
			fputs("Second param must be above or equale to 0\n",stderr);
		else
		{
			FILE *file;
			if (file = fopen(argv[1],"r"))
			{
				int i =0;
				char c; 
				while (!feof(file))
				{
					if (N == 0)
					{
						c = getc(file);
						if (c != EOF)
							putc(c,stdout);
					}	
					else
					{
						if (N == i)
						{
							char key = getc(stdin);
							while (key != 10) 
								key = getc(stdin);
							i = 0;
						}
						c = getc(file);
						if (c != EOF)
							putc(c,stdout);
						if (c == '\n')
							i++;
					}
				}
				if (fclose(file))
				{
					fputs("Error:File doesn't close",stderr);
					return -1;
				}
				else return 0;
			}
			else
			{
				fputs("Can't open file\n",stderr);
			}
		}
	}
	else
	{
		fputs("Incorrect number of params\nFirst param - name of file\nSecond param - amount of strings to output by\n",stderr);
	}
	
}
