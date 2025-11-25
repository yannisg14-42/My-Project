#include <stddef.h>

int  ft_isdigit(const char *str)
{
  int  i;

  i = 0;
  while (str[i])
  {
    if (!(str[i] >= '0' && str[i] <= '9'))
      return (0);
    i++;
  }
  return (1);
}
//ft_isdigit will check all characters of the string
//and if one char is not digit, it will  return 0 immediatly
//else it continue to increment and return 1 if all characters are digit

#include <stdio.h>

int  main(int argc, const char **argv)
{
  int  detect;

  if (argc == 2)
  {
    detect = ft_isdigit(argv[1]);
    printf("%d\n", detect);
  }
  return (0);
}
