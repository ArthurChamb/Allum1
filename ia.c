/*
** ia.c for ia_allum1 in /home/XXXXXX/Rendu/C_Prog_Elem/CPE_2015_Allum1
**
** Made by Arthur XXXXXX
** Login   <XXXXXX@epitech.net>
**
** Started on  Fri Feb 19 19:29:39 2016 Arthur XXXXXX
** Last update Sat Feb 20 18:16:37 2016 Arthur XXXXXX
*/

int	ia(char *lines)
{
  my_putstr("AI’s turn...\n");
  ia_choice(lines);
}

int	ia_choice(char *lines)
{
  if (ia_three(lines) == 1)
    return (0);
  if (lines[3] == 7)
    if (ia_base(lines) == 1)
      return (0);
  if (ia_four(lines) == 1)
    return (0);
}

int	ia_base(char *lines)
{
  int	i;

  i = 0;
  if (lines[0] == 1)
    {
      lines[0] = 0;
      my_putstr("AI removed 1 match(es) from line 1\n");
      return (1);
    }
  else if (lines[1] != 0)
    {
      i = 3 - lines[1];
      lines[1] = 0;
      i = 3 - i;
      my_printf("AI removed %d match(es) from line 2\n", i);
      return (1);
    }
  return (0);
}

int	ia_three(char *lines)
{
  int	i;

  i = 0;
  if (lines[2] > 3)
    {
      i = lines[2] - 3;
      lines[2] = 3;
      my_printf("AI removed %d match(es) from line 3\n", i);
      return (1);
    }
  else if (lines[2] == 3 || lines[2] == 2)
    {
      i = lines[2] - 1;
      lines[2] = 1;
      my_printf("AI removed %d match(es) from line 3\n", i);
      return (1);
    }
  else if (lines[2] == 1)
    {
      lines[2] = lines[2] - 1;
      my_printf("AI removed 1 match(es) from line 3\n");
      return (1);
    }
  return (0);
}

int	ia_four(char *lines)
{
  int	i;

  i = 0;
  if (lines[3] > 3)
    {
      lines[3] = lines[3] - 3;
      my_printf("AI removed 3 match(es) from line 4\n");
      return (1);
    }
  else if (lines[3] == 3 || lines[3] == 2)
    {
      i = lines[3] - 1;
      lines[3] = 1;
      my_printf("AI removed %d match(es) from line 4\n", i);
      return (1);
    }
  else if (lines[3] == 1)
    {
      lines[3] = lines[3] - 1;
      my_printf("AI removed 1 match(es) from line 4\n");
      return (1);
    }
  return (0);
}
