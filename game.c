/*
** game.c for game_allum1 in /home/XXXXXX/Rendu/C_Prog_Elem/CPE_2015_Allum1
**
** Made by Arthur XXXXXX
** Login   <XXXXXX@epitech.net>
**
** Started on  Thu Feb 18 15:13:52 2016 Arthur XXXXXX
** Last update Sun Feb 21 19:18:45 2016 Arthur XXXXXX
*/

int	game(char *lines)
{
  int	i;

  my_putstr("Your Turn:\n");
  if (game_player1(lines) == -1)
    return (-1);
}

int	game_player1(char *lines)
{
  int	line_user;
  char	*check;
  int	i;

  if ((check = my_malloc(120)) == 'NULL')
    return (-1);
  my_putstr("Line: ");
  read(0, check, 120);
  if (check[0] < '0' || check[0] > '9')
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (-1);
    }
  line_user = my_getnbr(check);
  if (check_lines(lines, line_user) == -1)
    return (-1);
  if (game_player2(lines, line_user) == -1)
    return (-1);
}

int	game_player2(char *lines, int line_user)
{
  int	matches;
  int	tab_lines;
  char	*check;

  if ((check = my_malloc(120)) == 'NULL')
    return (-1);
  my_putstr("Matches: ");
  read(0, check, 120); /* N'oubliez de vérifier vos read si vous n'utilisez pas get_next_line */
  if (check[0] < '0' || check[0] > '9')
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (-1);
    }
  matches = my_getnbr(check);
  if (check_matches(lines, matches, line_user) == -1)
    return (-1);
  tab_lines = lines[line_user - 1];
  lines[line_user - 1] = tab_lines - matches;
  my_printf("Player removed %d match(es) from line %d\n", matches, line_user);
  return (1);
}

int	check_lines(char *lines, int line_user)
{
  if (line_user > 4 || line_user == 0)
    {
      my_putstr("Error: this line is out of range\n");
      return (-1);
    }
  else if (line_user < 0)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (-1);
    }
  else if (lines[line_user - 1] == 0)
    {
      my_putstr("Error: this line is empty\n");
      return (-1);
    }
}

int	check_matches(char *lines, int matches, int line)
{
  if (matches == 0)
    {
      my_putstr("Error: you have to remove at least one match\n");
      return (-1);
    }
  else if (matches < 0)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (-1);
    }
  if (lines[line - 1] < matches || matches > 3)
    {
      my_putstr("Error: not enough matches on this line\n");
      return (-1);
    }
}
