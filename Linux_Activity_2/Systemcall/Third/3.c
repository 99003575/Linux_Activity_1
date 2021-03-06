#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int file, bytes;
	char ch[16384];
    int characters, words, lines;
	file=open("doc1.txt",O_RDONLY);

	if(file<0)
	{
		perror("open");
		exit(1);
	}

   
    words = 0,lines = 0;
    while(bytes = read(file,ch,sizeof(ch)))
    {
        for(int i=0;i<bytes;i++)
        {
            //Check new line
            if (ch[i] == '\n')
               lines++;

            //Check words */
            if (ch[i] == ' ' || ch[i] == '\t' || ch[i] == '\n')
               words++;
        }
        characters = bytes;
    }

    printf("Number of characters : %d\n", characters);
    printf("Number of words      : %d\n", words);
    printf("Number of lines      : %d\n", lines);


    //Close files to release resources
    close(file);

    return 0;
}
