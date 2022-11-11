#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


#include "read_line.h"

// this is a function that gets characters one by one from a file
char get_char(int fd)
{
    static char buff[BUFFER_SIZE];
    static char* ptr_buff;
    static int len = 0;
    char c;

    if(len == 0)
    {
        len = read(fd, buff, BUFFER_SIZE);
        ptr_buff = (char*)buff;
        if(len == 0)
            return (0);
    }
    c = *ptr_buff;
    ptr_buff++;
    len--;
    return c;
}

// by using the get_char function we define the read_line function
char *read_line(int fd)
{
    char c;
    char* str;
    int len;

    len = 0;
    str = malloc(BUFFER_SIZE );
    if (str == NULL)
        return (0);
    c = get_char(fd);
    while(c != '\n' && c != '\0')
    {
        str[len] = c;
        c = get_char(fd);
        len++;
    }
    str[len] = 0;
    if(c == 0 && str[0] == 0)
        return (0);
    return (str);
}

int main(){
    int fd=open("test.txt",O_RDONLY);
  // to read all the lines from our file we use the read_line function in a loop
        char * line=" ";
        int i=1;
    while (line != NULL)
	{
		line = read_line(fd);
		if (line != NULL)
			printf("line %d: %s\n", i, line);
		free(line);
		i++;
	}
    return 0;
}
