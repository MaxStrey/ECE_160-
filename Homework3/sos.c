#include <stdio.h>

void init_board(void);
void draw_board(void);
int user_first(void);
int play_again(void);
int point_counter(int);
//int find_win(char);
//int middle_open(void);
//int find_corner(void);
//int find_side(void);
//void computer_move(void);
int square_valid(int);
int player1_move(void);
int player2_move(void);
void play_game(void);
char board[50][50];
char computer;
char user;
int player1var;
int player2var;
int player1_points;
int player2_points;

int main(void)
{
  while(1)
  {
    init_board();
    if (user_first())
    {
        player1var = 1;
    }
    else
    {
        player2var = 1;
    }
    play_game();
    if (!play_again())
    {
        break;
    }
  }
  return 0;
}

void init_board(void)
{
  int row, col;
  for (row = 0; row < 5; row++)
    for (col = 0; col < 5; col++)
      board[row][col] = ' ';
  return;
}

/* Display the board to standard output. */
void draw_board(void)
{
  int row, col;
  printf("\n");
  for (row = 0; row < 5; row++)
  {
    printf("   *   *   *   *   \n");
    printf(" %c * %c * %c * %c * %c \n",
       board[row][0], board[row][1], board[row][2], board[row][3], board[row][4]);
    printf("   *   *   *   *   \n");
    if (row != 4)
      printf("********************\n");
  }
  printf("\n");
  return;
}
/*
 * Ask if user wants to go first.
 * Returns 1 if yes, 0 if no.
 */
int user_first(void)
{
  char response;
  printf("Player 1, do you want to go first? (y/n) ");
  do
  {
    response = getchar();
  } while ((response != 'y') && (response != 'Y') &&
       (response != 'n') && (response != 'N'));
  if ((response == 'y') || (response == 'Y'))
    return 1;
  else
    return 0;
}
/*
 * Ask if user wants to play again.
 * Returns 1 if yes, 0 if no.
 */
int play_again(void)
{
  char response;
  printf("Do you want to play again? (y/n) ");
  do
  {
    response = getchar();
  } while ((response != 'y') && (response != 'Y') &&
       (response != 'n') && (response != 'N'));
  if ((response == 'y') || (response == 'Y'))
    return 1;
  else
    return 0;
}

/* Check if the given square is valid and empty. */
int square_valid(int square)
{
  int row, col;
  row = (square - 1) / 5;
  col = (square - 1) % 5;
  if ((square >= 1) && (square <= 25))
  {
    if (board[row][col] == ' ')
      return 1;
  }
  return 0;
}
/* Check if the given symbol has already won the game. */
int point_counter(int square)
{
  int row, col, point;
  row = (square - 1) / 5;
  col = (square - 1) % 5;
  point = 0;
  
  if (board[row][col] == 'o')
  {
      if (board[row + 1][col] == 's')
      {
          if (board[row - 1][col] == 's')
          {
              point++;
          }
      }
  }
  return point;
}

/* Choose a move for the computer. */
/*void computer_move(void)
{
  int square;
  int row, col;
  square = find_win(computer);
  if (!square)
    square = find_win(user);
  if (!square)
    square = middle_open();
  if (!square)
    square = find_corner();
  if (!square)
    square = find_side();
  printf("\nI am choosing square %d!\n", square);
  row = (square - 1) / 5;
  col = (square - 1) % 5;
  board[row][col] = computer;
  return;
}
*/
/* Have the user choose a move. */
int player1_move(void)
{
  int point = 0;
  int square;
  char letter;
  int row, col;
  do
  {
    printf("Player 1, Enter a square: ");
    scanf("%d", &square);
    fflush(stdin);
    printf("Enter s or o in lowercase: ");
    scanf("%c", &letter);
    user = letter;
  } while (!square_valid(square));
  row = (square - 1) / 5;
  col = (square - 1) % 5;
  board[row][col] = user;
  if (board[row][col] == 'o')
  {
    
    
    if (board[row + 1][col] == 's' && board[row - 1][col] == 's')
    {
        point++;
    }
    if (board[row][col + 1] == 's' && board[row][col - 1] == 's')
    {
        point++;
    }
    if (board[row + 1][col + 1] == 's' && board[row - 1][col - 1] == 's')
    {
        point++;
    }
    if (board[row - 1][col + 1] == 's' && board[row + 1][col + 1] == 's')
    {
        point++;
    }
  }
  if (board[row][col] == 's')
  {
      // looking for sides of the square
      if (board[row + 1][col] == 'o' && board[row + 2][col] == 's')
      {
          point++;
      }
      if (board[row - 1][col] == 'o' && board[row - 2][col] == 's')
      {
          point++;
      }
      if (board[row][col + 1] == 'o' && board[row][col + 2] == 's')
      {
          point++;
      }
      if (board[row][col - 1] == 'o' && board[row][col - 2] == 's')
      {
          point++;
      }
      // looking for corners of the square
      if (board[row + 1][col + 1] == 'o' && board[row + 2][col + 2] == 's')
      {
          point++;
      }
      if (board[row + 1][col - 1] == 'o' && board[row + 2][col - 2] == 's')
      {
          point++;
      }
      if (board[row - 1][col - 1] == 'o' && board[row - 2][col - 2] == 's')
      {
          point++;
      }
      if (board[row - 1][col + 1] == 'o' && board[row - 2][col + 2] == 's')
      {
          point++;
      }
  }
  player1_points += point;
  if (point>0)
	  return 1;
  else
	  return 0;
}

int player2_move(void)
{
  int square;
  char letter;
  int row, col;
  int point  = 0;
  do
  {
    printf("Player 2, Enter a square: ");
    scanf("%d", &square);
    fflush(stdin);
    printf("Enter s or o in lowercase: ");
    scanf("%c", &letter);
    computer = letter;
  } while (!square_valid(square));
  row = (square - 1) / 5;
  col = (square - 1) % 5;
  board[row][col] = computer;
  if (board[row][col] == 'o')
  {
    if (board[row + 1][col] == 's' && board[row - 1][col] == 's')
    {
        point++;
    }
    if (board[row][col + 1] == 's' && board[row][col - 1] == 's')
    {
        point++;
    }
    if (board[row + 1][col + 1] == 's' && board[row - 1][col - 1] == 's')
    {
        point++;
    }
    if (board[row - 1][col + 1] == 's' && board[row + 1][col + 1] == 's')
    {
        point++;
    }
  }
  if (board[row][col] == 's')
  {
      // looking for sides
      if (board[row + 1][col] == 'o' && board[row + 2][col] == 's')
      {
          point++;
      }
      if (board[row - 1][col] == 'o' && board[row - 2][col] == 's')
      {
          point++;
      }
      if (board[row][col + 1] == 'o' && board[row][col + 2] == 's')
      {
          point++;
      }
      if (board[row][col - 1] == 'o' && board[row][col - 2] == 's')
      {
          point++;
      }
      // looking for corners
      if (board[row + 1][col + 1] == 'o' && board[row + 2][col + 2] == 's')
      {
          point++;
      }
      if (board[row + 1][col - 1] == 'o' && board[row + 2][col - 2] == 's')
      {
          point++;
      }
      if (board[row - 1][col - 1] == 'o' && board[row - 2][col - 2] == 's')
      {
          point++;
      }
      if (board[row - 1][col + 1] == 'o' && board[row - 2][col + 2] == 's')
      {
          point++;
      }
  }
  player2_points += point;
  if (point>0)
	  return 1;
  else
	  return 0;
}

/* Loop through 9 turns or until somebody wins. */
void play_game(void)
{
  int turn=0;
  int result;
  int player;
  if (player1var == 1)
	  player = 1;
  else
	  player = 2;
  
  while (turn<25)
  {
    /* Check if turn is even or odd 
       to determine which player should move. */
    if (player == 1)
	{
        result = player1_move();
		if (!result)
			player = 2;
	}
    else
	{
        result = player2_move();
		if (!result)
			player = 1;
    }
    draw_board();
    printf("player1 points = %d\n", player1_points);
    printf("player2 points = %d\n\n", player2_points);
    
	turn++;
  }
  if (player1_points > player2_points) 
    {
      printf("\nPlayer 1 wins!\n\n");
      return;
    }
    else if (player2_points > player1_points) 
    {
      printf("\nPlayer 2 wins!\n\n");
      return;
    }
  else 
  {
    printf("\nThe game is a draw.\n\n");
  }
  return;
}