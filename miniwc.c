#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <FILENAME>\n", argv[0]);
        return 1;
    }

    FILE *fd = fopen(argv[1], "r");

    if (fd == NULL)
    {
        perror("Error opening file.\n");
        return 1;
    }

    int characters = 0;
    int words = 0;
    int lines = 0;
    int in_word = 0;
    int ch;

    while ((ch = fgetc(fd)) != EOF)
    {
        characters++;

        if (ch == "\n")
        {
            lines++;
        }

        if (isspace(ch) == 0)
        {
            in_word = 0;
        }
        else if(in_word == 0)
        {
            in_word = 1;
            words++;
        }
    }

    fclose(fd);

    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);
    return 0;
}