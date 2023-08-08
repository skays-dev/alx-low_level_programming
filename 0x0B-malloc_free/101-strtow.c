#include <stdio.h>
#include <stdlib.h>

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
    int flag = 0, c, w = 0;

    for (c = 0; s[c] != '\0'; c++)
    {
        if (s[c] == ' ')
            flag = 0;
        else if (flag == 0)
        {
            flag = 1;
            w++;
        }
    }

    return w;
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
    char **matrix, *tmp;
    int i, k = 0, len = 0, words, c = 0, start, end;

    while (*(str + len))
        len++;

    words = count_word(str);

    if (words == 0)
        return NULL;

    matrix = (char **)malloc(sizeof(char *) * (words + 1));
    if (matrix == NULL)
        return NULL;

    for (i = 0; i <= len; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            if (c)
            {
                end = i;
                tmp = (char *)malloc(sizeof(char) * (c + 1));
                if (tmp == NULL)
                {
                    for (k = 0; k < i; k++)
                        free(matrix[k]);
                    free(matrix);
                    return NULL;
                }
                start = i - c;
                while (start < end)
                    *tmp++ = str[start++];
                *tmp = '\0';
                matrix[k] = tmp - c;
                k++;
                c = 0;
            }
        }
        else if (c++ == 0)
            start = i;
    }

    matrix[k] = NULL;

    return matrix;
}

int main(void)
{
    char **tab;
    int i;

    tab = strtow("      ALX School         #cisfun      ");
    if (tab == NULL)
    {
        printf("Error: Failed to split the string into words.\n");
        return (1);
    }

    printf("Words in the string:\n");
    for (i = 0; tab[i] != NULL; i++)
        printf("%s\n", tab[i]);

    // Free allocated memory
    for (i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);

    return 0;
}
