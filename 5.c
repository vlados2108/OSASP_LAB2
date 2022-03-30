#include <stdio.h>
#include "sys/stat.h"
int main(int argc,char* argv[])
{
	struct stat file_stat;
	if (argc == 3)
	{
		FILE *file1;
		FILE *file2;
		if (file1=fopen(argv[1],"r"))
		{
			if (stat(argv[1], &file_stat))
				fprintf(stderr,"Can't link the statistic of %s with the variable\n",argv[2]);
			
			if (file2=fopen(argv[2],"w"))
			{
				if (chmod(argv[2], file_stat.st_mode))
					fprintf(stderr,"Can't copy rights of %s to %s\n",argv[1],argv[2]);
				char c;
				
				while ((c = fgetc(file1)) != EOF)
					if (fputc(c,file2) == EOF)
						fprintf(stderr,"Can't write in %s\n",argv[2]);
								
				if (fclose(file1))
				{
					fprintf(stderr,"Error:File %s doesn't close",argv[1]);
					return -1;
				}
				if (fclose(file2))
				{
					fprintf(stderr,"Error:File %s doesn't close",argv[2]);
					return -1;
				}
				return 0;
				
			}
			else
			{
				fprintf(stderr,"Error:File %s doesn't open.Check if it exists\n", argv[2]);
				return -1;
			}
		}
		else
		{
			fprintf(stderr,"Error:File %s doesn't open.Check if it exists\n", argv[1]);
			return -1;
		}
	}
	else
	{
		fputs("Invalid number of params\n1 param - File 1\n2 param - File 2\n",stderr);
		return -1;
	}
}
