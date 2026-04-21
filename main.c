/*
** main.c for main_allum1 in /home/XXXXXX/Rendu/C_Prog_Elem/CPE_2015_Allum1
**
** Made by Arthur XXXXXX
** Login   <XXXXXX@epitech.net>
**
** Started on  Thu Feb 18 13:15:06 2016 Arthur XXXXXX
** Last update Sun Feb 21 22:26:04 2016 Arthur XXXXXX
*/

char	*lines;

int	verify(int ac)
{
  if ((lines = my_malloc(8)) == 'NULL')
    return (0);
  lines[0] = 1;
  lines[1] = 3;
  lines[2] = 5;
  lines[3] = 7;
  lines[4] = 1;
  lines[5] = 3;
  lines[6] = 5;
  lines[7] = 7;
  if (ac != 1)
    {
      my_putstre("Error: No arguments nedded\n");
      return (-1);
    }
}

int	check(char *lines, int turn)
{
  if (lines[0] != 0)
    return (0);
  else if (lines[1] != 0)
    return (0);
  else if (lines[2] != 0)
    return (0);
  else if (lines[3] != 0)
    return (0);
  else
    {
      if (turn == 1)
	my_putstr("You lost, too bad..\n");
      if (turn == 0)
	my_putstr("I lost.. snif.. but I’ll get you next time!!\n");
      return (1);
    }
}

void	game_launcher(char *lines)
{
  int	i;

  i = 0;
  if (game(lines) == -1)
    {
      while (i != 1)
	{
	  if (game_player1(lines) != -1)
	    i = 1;
	}
    }
}

int	main(int ac, char **av)
{
  int	turn;

  if (verify(ac) == -1)
    return (-1);
  display_lines(lines);
  my_putchar('\n');
  while (1)
    {
      turn = 1;
      game_launcher(lines);
      display_lines(lines);
      if (check(lines, turn) == 1)
	return (0);
      my_putchar('\n');
      turn = 0;
      ia(lines);
      display_lines(lines);
      if (check(lines, turn) == 1)
	return (0);
      my_putchar('\n');
    }
  return (0);
}
