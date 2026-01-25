#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int copy_content(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, rd_stat, wr_stat;
	mode_t perm = S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH;
	char buffer[1024];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		return (98);
	}

	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, perm);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		close(fd_from);
		return (99);
	}

	while ((rd_stat = read(fd_from, buffer, 1024)) > 0)
	{
		wr_stat = write(fd_to, buffer, rd_stat);
		if (wr_stat != rd_stat || wr_stat == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			close(fd_from);
			close(fd_to);
			return (99);
		}
	}

	if (rd_stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close(fd_from);
		close(fd_to);
		return (98);
	}

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		close(fd_to);
		return (100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		return (100);
	}

	return (0);
}

int main(int ac, char *av[])
{
	int ret;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	ret = copy_content(av[1], av[2]);
	if (ret != 0)
		exit(ret);

	return (0);
}

