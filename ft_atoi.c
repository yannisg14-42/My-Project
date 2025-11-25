#include <stddef.h>

int  ft_atoi(const char *str)
{
  size_t  i; // size_t guaranteedd to hold any array index and is not signed 
  int  sign;
  int  number;

  i = 0;
  while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
    i++;
  sign = 1;
  while (str[i] == '+' || str[i] == '-')
  {
    if (str[i] == '-')
      sign *= -1;
    i++;
  }
  number = 0;
  while (str[i] >= '0' && str[i] <= '9')
  {
    number = (number * 10) + (str[i] - '0');
    i++;
  }
  return (sign * number);
}

// ft_atoi should check for any type of space according to isspace
// after that the sign variable that define the polarity will always be multiplied by -1 when we encounter a '-'
// then finaly the last formula get all the number in the string by converting the char into an int and adding to the previous number multiplied by 10

#include <stdio.h>

int  main(int argc, const char **argv)
{
 int  number;

 if (argc == 2)
 {
   number = ft_atoi(argv[1]);
   printf("extracted number is %d\n", number);
 }
 return (0);
}
