#include <stdio.h>
int main(int argc, char *argv[])
{
	if ( argc == 2)
	{
		FILE *file;
		if (file = fopen(argv[1],"w"))
		{
			char c;
			while (c != '*') {
				if ((c = fgetc(stdin)) == EOF) {
					fputs("Can't read symbol\n",stderr);
					return -1;
				}
				else if (c != '*') fputc(c,file);
			}  

			if (fclose(file)) {
				fputs("Can't close file\n",stderr);
		        	return -1;
			} else return 0;
		}
		else
		{
			fputs("Inalid parametr\nThere must be one parametr - name of File",stderr);

			return -1;
		}
	}
	else
	{
		fputs("Inalid number of params\nThere must be one parametr - name of File",stderr);
	}
}
