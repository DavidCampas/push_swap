#include "get_next_line.h"

char *find_new_line(char *str)
{
    if (!str)
        return (NULL);
    while (*str)
    {
        if (*str == '\n')
            return (str);
        str++;
    }
    return (NULL);
}

char *create_line(char *buffer, char *new_line)
{
    size_t line_length;
    char *line;

    if (!new_line || !buffer)
        return (NULL);
    line_length = new_line - buffer + 1; // +1 para incluir el '\n'
    line = malloc(line_length + 1); // +1 para el terminador nulo
    if (!line)
        return (NULL);
    ft_strncpy(line, buffer, line_length);
    line[line_length] = '\0'; // Asegúrate de que la línea esté terminada correctamente
    return (line);
}

char *read_add(int fd, char *buffer)
{
    char temp[BUFFER_SIZE + 1];
    ssize_t bytes_read;
    char *new_buffer;

    bytes_read = read(fd, temp, BUFFER_SIZE);
    if (bytes_read < 0)
    {
        free(buffer);
        return (NULL); // Manejo de error de lectura
    }
    else if (bytes_read == 0) // Fin de archivo
    {
        if (buffer && buffer[0] != '\0')
            return (buffer); // Devolver buffer si no está vacío
        free(buffer);
        return (NULL); // Devolver NULL si el buffer está vacío
    }
    temp[bytes_read] = '\0'; // Asegúrate de que `temp` esté terminada
    new_buffer = ft_strjoin(buffer, temp);
    free(buffer);
    return (new_buffer);
}

char *get_next_line(int fd)
{
    static char *buffer = NULL;
    char *new_line;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    // Inicializar buffer estático en NULL si es la primera llamada
    if (!buffer)
    {
        buffer = malloc(1);
        if (!buffer)
            return (NULL);
        buffer[0] = '\0'; // Asegúrate de que el buffer esté vacío inicialmente
    }

    new_line = find_new_line(buffer);
    while (!new_line)
    {
        buffer = read_add(fd, buffer);
        if (!buffer) // Manejar caso de error o EOF
            return (NULL);
        new_line = find_new_line(buffer);
    }

    line = create_line(buffer, new_line);
    if (!line)
    {
        free(buffer);
        buffer = NULL; // Limpiar buffer en caso de error
        return (NULL);
    }

    // Crear nuevo buffer a partir de la nueva línea encontrada
    char *new_buffer = (new_line[1] != '\0') ? ft_strdup(new_line + 1) : NULL;
    free(buffer);
    buffer = new_buffer; // Actualizar el buffer estático

    return (line);
}
