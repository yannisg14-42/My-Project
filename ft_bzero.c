#include <stddef.h>

void  ft_bzero(void *s, size_t n)
{
  size_t  i;
  
  i = 0;
  while (s[i] != '\0')
  {
    s[i] = '\0';
    i++;
  }
}
// ft_bzero place n zero-valued bytes in the area pointed to by s
// void *s means generix pointer so it can point to any type of variable

#include <stdio.h>

int  main(int argc, char **argv)
{
  char  str[10];

  if (argc == 2)
  {
    str = ft_bzero(argv[1], 10);
  }
  return (0);
}
