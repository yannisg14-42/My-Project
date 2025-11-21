int  ft_atoi(char *str)
{
  int  i;
  int  sign;
  int  nb;

  i = 0;
  while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
  {
    i++;
  }
  sign = 1;
  while (str[i] == '+' || str[i] == '-')
  {
    if (str[i] == '-')
    {
      sign = sign * (-1);
    }
    else
    {

    }
    i++;
  }
  nb = 0;
  while (str[i] >= '0' && str[i] <= '9')
  {
    nb = (nb * 10) + (str[i] - '0');
    i++;
  }
  return (sign * nb);
}

int ft_iterative_factorial(int nb)
{
  int  fact;

  if (nb < 0)
    return (0);
  if (nb == 0)
    return (1);
  fact = 1;
  while (nb >= 1)
  {
    if ((2147483647 / nb) < fact)
      return (0);
    else
      fact = fact * nb;
    nb--;
  }
  return (fact);
}

#include <stdio.h>

int  main(int argc, char **argv)
{
  int  i;
  int  nb;
  int  fact;
  
  i = 0;
  nb = ft_atoi(argv[1]);
  fact = ft_iterative_factorial(nb);
  if (argc == 2)
  {
    while (argv[1][i])
    {
      ft_iterative_factorial(nb);
      i++;
    }
  }
  printf("%d\n", fact);
}
