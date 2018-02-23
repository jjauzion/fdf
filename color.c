#include <stdio.h>

int		ft_rgb2tsv(int rgb, int *t, int *s, int *v);
int		ft_tsv2rgb(int t, int s, int v);

int	main()
{
	int rgb;
	int t;
	int s;
	int v;

	rgb = 0x9a5700;
	ft_rgb2tsv(rgb, &t, &s, &v);
	printf(" 1: rgb = %#x ; t = %d ; s = %d ; v = %d\n", rgb, t, s, v);
	rgb = ft_tsv2rgb(t, s, v);
	printf(" 2: rgb = %#x ; t = %d ; s = %d ; v = %d\n", rgb, t, s, v);
}
