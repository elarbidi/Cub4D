# include "../cub3d.h"

static char    *ft_strdup_up(char *s)
{
    char    *r;
    int i;

    i = 0;
    while (s[i])
        i++;
    r = malloc(sizeof(char)* i + 1);
    if (!r)
        return (NULL);
    i = 0;
    while (s[i])
    {
        r[i] = s[i];
        i++;
    }
    r[i] = '\0';
    return (r);
}

static char    *ft_strjoin_char(char    *s, char c)
{
    char    *r;
    int i;

    i = 0;
    while (s[i])
        i++;
    r = malloc(sizeof(char) * i + 2);
    if (!r)
        return (NULL);
    i = 0;
    while (s[i])
    {
        r[i] = s[i];
        i++;
    }
    r[i] = c;
    r[i + 1] = '\0';
    free (s);
    return (r);
}

char    *gnl(int fd)
{
    char    buff;
    char *line;
    int ret;
    int i;

    i = 0;

     if (fd < 0)
        return (NULL);
    line = ft_strdup_up("");
    while ((ret = read(fd, &buff, 1)) > 0)
    {
        line = ft_strjoin_char(line, buff);
        if (buff == '\n')
            break ;
    }
    while (line[i])
        i++;
    if (i == 0 || ret == -1)
    {
        free(line);
        return(NULL);
    }
    return (line);
}
