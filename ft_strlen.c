int  ft_strlen(char *str)
{
  int  i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
//ft_strlen keep incrementing in the string and stop at the '\0'
//then at the end return an integer i that is the length of the string

#include <stdio.h>

int  main(int argc, char **argv)
{
  int  i;
  int  length;
  int  n;

  n = 1;
  length = ft_strlen(argv[n]);
  while (n < argc)
  {
    i = 0;
    while (argv[n][i])
    {
      ft_strlen(argv[n][i]);
      i++;
    }
    printf("the length of the string is %d\n", length);
  }
  return (0);
}
