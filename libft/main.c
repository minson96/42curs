#include "libft.h"
#include <string.h>
#include <stdio.h>
int	main()
{
	int src[] = { 1,2,3 };
    int dest[3];
 
    // 메모리 복사
    ft_memcpy(dest, src, sizeof(int) * 3);
    // memcpy(dest, src, sizeof(src)); sizeof(src)도 가능
 
    // 복사한 배열
    for (int i = 0; i < 3; ++i)
    {
        printf("%d ", src[i]);
    }
    
    printf("\n");
 
    // 복사된 배열
    for (int i = 0; i < 3; ++i)
    {
        printf("%d ", dest[i]);
    }
 
    return 0;
}