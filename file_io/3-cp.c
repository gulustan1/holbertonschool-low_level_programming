#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

int open_files(const char *file_from, const char *file_to, int *fd_from, int *fd_to)
{
	mode_t perm = S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH;

	*fd_from = open(file_from, O_RDONLY);
	if (*fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	*fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, perm);
	if (*fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		close_fd(*fd_from);
		exit(99);
	}

	return (0);
}

void copy_loop(int fd_from, int fd_to)
{
	ssize_t rd, wr;
	char buffer[BUF_SIZE];

	while ((rd = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		wr = write(fd_to, buffer, rd);
		if (wr != rd || wr == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file\n");
			close_fd(fd_from);
			close_fd(fd_to);
			exit(99);
		}
	}

	if (rd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file\n");
		close_fd(fd_from);
		close_fd(fd_to);
		exit(98);
	}
}

int main(int ac, char *av[])
{
	int fd_from, fd_to;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	open_files(av[1], av[2], &fd_from, &fd_to);
	copy_loop(fd_from, fd_to);
	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}

