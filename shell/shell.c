#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFLIMIT 144

int main(int argc, char **argv, char **envp)
{
  char *input = (char *)malloc(BUFFLIMIT);
  write(1, "Hello welcome to the shell, type 'exit' to exit\n", 50);
 while(1)
  {
    write(1, "$", 2);
    int len = 0;
    len = read(0, input, BUFFLIMIT);

    input = (char *)realloc(input, len+1);

    if(isEqual(input, "exit\n"))
      {
	exit(0);
      }
    
    char *tokens = strtok(input, " ");//using strtok from C lib since I dont have a working tokenizer. Will update when its fixed
    int rc;
    rc = fork();
    if(rc < 0)
      {
	write(1, "Failed to fork()", 20);
	exit(0);
      }

  }
  return 0;
}

int isEqual(char *str1, char *str2)
{
  while(*str1 != '\0')
    {
      if(*str1 != *str2)
	{
	  return 0;
	}
      str1++;
      str2++;
    }
  return 1;
}
