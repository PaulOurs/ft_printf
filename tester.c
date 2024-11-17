#include <stdio.h>
#include <limits.h>
#include "./includes/ft_printf.h"

int	main(void)
{
	int		ft_len;
	int		org_len;
	char	*null_str = NULL;
	void	*ptr = &ft_len;

	// Basic tests
	printf("\n	=== Basic Tests ===\n");
	org_len = printf("	Simple string\n");
	ft_len = ft_printf("	Simple string\n");
	printf("	Lengths: printf=%d, ft_printf=%d\n\n", ft_len, org_len);

	// Character tests
	printf("	=== Character Tests ===\n");
	printf("	   (printf) Char tests: %c %c %c\n", 'a', '\t', 127);
	ft_printf("	(ft_printf) Char tests: %c %c %c\n\n", 'a', '\t', 127);

	// String tests
	printf("	=== String Tests ===\n");
	printf("	   (printf) String tests: '%s' '%s' '%s'\n", "Hello", "", null_str);
	ft_printf("	(ft_printf) String tests: '%s' '%s' '%s'\n\n", "Hello", "", null_str);

	// Pointer tests
	printf("	=== Pointer Tests ===\n");
	printf("	   (printf) Pointer tests: %p %p %p\n", ptr, NULL, (void *)0xFFFF);
	ft_printf("	(ft_printf) Pointer tests: %p %p %p\n\n", ptr, NULL, (void *)0xFFFF);

	// Integer tests
	printf("	=== Integer Tests ===\n");
	printf("	   (printf) Int tests: %d %d %d %d\n", 0, -42, INT_MAX, INT_MIN);
	ft_printf("	(ft_printf) Int tests: %d %d %d %d\n\n", 0, -42, INT_MAX, INT_MIN);
	printf("	   (printf) Int tests (i): %i %i %i %i\n", 0, -42, INT_MAX, INT_MIN);
	ft_printf("	(ft_printf) Int tests (i): %i %i %i %i\n\n", 0, -42, INT_MAX, INT_MIN);

	// Unsigned tests
	printf("	=== Unsigned Tests ===\n");
	printf("	   (printf) Unsigned tests: %u %u %u\n", 0, 42, UINT_MAX);
	ft_printf("	(ft_printf) Unsigned tests: %u %u %u\n\n", 0, 42, UINT_MAX);

	// Hexadecimal tests
	printf("	=== Hexadecimal Tests ===\n");
	printf("	   (printf) Hex tests (lower): %x %x %x\n", 0, 42, 0xDEADBEEF);
	ft_printf("	(ft_printf) Hex tests (lower): %x %x %x\n\n", 0, 42, 0xDEADBEEF);
	printf("	   (printf) Hex tests (upper): %X %X %X\n", 0, 42, 0xDEADBEEF);
	ft_printf("	(ft_printf) Hex tests (upper): %X %X %X\n\n", 0, 42, 0xDEADBEEF);

	// Percent sign tests
	printf("	=== Percent Tests ===\n");
	printf("	   (printf) Percent tests: %% %%\n");
	ft_printf("	(ft_printf) Percent tests: %% %%\n\n");

	// Mixed tests
	printf("	=== Mixed Tests ===\n");
	printf("	   (printf) Mixed: %c %s %p %d %i %u %x %X %%\n", 'A', "test", ptr, -42, 42, 42, 42, 42);
	ft_printf("	(ft_printf) Mixed: %c %s %p %d %i %u %x %X %%\n", 'A', "test", ptr, -42, 42, 42, 42, 42);

	return (0);
}
