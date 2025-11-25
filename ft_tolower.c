#include <stddef.h>

char  *ft_tolower(char *str)
{
  size_t  i;

  i = 0;
  while (str[i])
  {
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] = str[i] + 32;
    i++;
  }
  return (str);
}
// ft_lower read the entire str except the '\0'
// if we encounter an uppercase char it is converted to lowercase
// the conversion is done by adding 32 because in ASCII uppercase char are 32 lower than lowercase

#include <stdio.h>

int  main(int argc, char **argv)
{
  char  *str;

  if (argc == 2)
  {
    str = ft_tolower(argv[1]);
    printf("%s\n", str);
  }
  return (0);
}
