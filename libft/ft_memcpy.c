#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p_base;
	size_t			i;
	unsigned char	*p_src;

	if (dest == 0 || src == 0)
		return (NULL);
	i = 0;
	p_base = dest;
	p_src = (unsigned char *)src;
	while (i < n)
	{
		*p_base = *p_src;
		p_base++;
		p_src++;
		i++;
	}
	return(dest);
}