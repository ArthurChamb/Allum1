/*
** lines.c for lines_allum1 in /home/XXXXXX/Rendu/C_Prog_Elem/CPE_2015_Allum1
**
** Made by Arthur XXXXXX
** Login   <XXXXXX@epitech.net>
**
** Started on  Thu Feb 18 13:19:16 2016 Arthur XXXXXX
** Last update Sun Feb 21 18:59:01 2016 Arthur XXXXXX
*/

void	display_all(char *spaces, char *lines)
{
  int	n;
  int	i;
  int	e;
  int	nb;

  n = 4;
  i = 0;
  e = 4;
  my_putstr("*********\n");
  while (n != 0)
    {
      my_putchar('*');
      display_spaces(spaces[i]);
      display_match(lines[i]);
      spaces_add(lines, nb, i, e);
      display_spaces(spaces[i]);
      my_putstr("*\n");
      n = n - 1;
      i++;
      e++;
    }
  my_putstr("*********\n");
}

int	spaces_add(char *lines, int nb, int i, int e)
{
  if (lines[i] != lines[e] || lines[i] == 7)
    {
      nb = lines[e] - lines[i];
      while (nb != 0)
	{
	  my_putchar(' ');
	  nb = nb - 1;
	}
    }
}

int	display_match(int nb)
{
  int	i;

  i = 0;
  while (i < nb)
    {
      my_putchar('|');
      i = i + 1;
    }
  return (i);
}

int	display_spaces(int nb)
{
  int	i;

  i = 0;
  while (i != nb)
    {
      my_putchar(' ');
      i = i + 1;
    }
  return (0);
}

int	display_lines(char *lines)
{
  char	*spaces;
  int	nb;

  if ((spaces = my_malloc(4)) == 'NULL')
    return (0);
  spaces[0] = 3;
  spaces[1] = 2;
  spaces[2] = 1;
  spaces[3] = 0;
  display_all(spaces, lines);
}
