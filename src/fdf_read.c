#include "fdf.h"

static int	count_values(char *line)
{
	int	len;

	len = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			len += 1;
			while (ft_isdigit(*line))
				line += 1;
		}
		else if (*line != ' ' && *line != '-')
			ft_puterror("Invalid characters or read error", 5);
		line += 1;
	}
	return (len);
}
static int	count_lines(t_fdf *fdf, char *argv)
{
	int	fd;
	int	len;
	int	rows;
	int	cols;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_puterror("Error opening file", 1);
	rows = 0;
	cols = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (*line == '\0')
			break ;
		len = count_values(line);
		if (len > cols)
			cols = len;
		if (cols == len)
			rows += 1;
		else
			ft_puterror("Not a valid file", 4);
		free(line);
	}
	if (close(fd) < 0)
		ft_puterror("Error closing file", 2);
	if (!(fdf->map.width = cols))
		ft_puterror("Not a valid file", 4);
	return (rows);
}

static void	get_values(t_fdf *fdf, int y, int z, char *line)
{
	int	i;
	char	**split;

	split = ft_strsplit(line, ' ');
	if (split)
	{
		i = 0;
		while (split[i] && (y != fdf->map.width))
		{
			fdf->map.values[z][y] = ft_atoi(split[i++]);
			y += 1;
		}
		free(split);
	}
}

void	fdf_read(char *argv, t_fdf *fdf)
{
	int	y;
	int	z;
	int	fd;
	char	*line;

	y = 0;
	z = 0;
	fdf->map.height = count_lines(fdf, argv);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_puterror("Error opening file!", 1);
	fdf->map.values = (int **)malloc(sizeof(int *) * fdf->map.height);
	if (fdf == NULL)
		ft_puterror("Memory Allocation failed", 3);
	while (get_next_line(fd, &line) == 1 && z != fdf->map.height)
	{
		fdf->map.values[z] = (int *)malloc(sizeof(int) * fdf->map.width);
		if (fdf->map.values[z] == NULL)
			ft_puterror("Memory ALlocation failed", 3);
		get_values(fdf, y, z, line);
		y = 0;
		z += 1;
		free(line);
	}
	if (close(fd) < 0)
		ft_puterror("Error closing file", 2);
}
