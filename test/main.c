#include "../include/ft_printf.h"
#include "ft_colors.h"
#include <limits.h>

#define START ft_putstr(RED "--> " CYN "ft_printf: " reset)
#define MIDDLE printf(RED "< %d\n" reset, len);printf(RED "--> " MAG "   printf: " reset)
#define END printf(RED "< %d\n" reset, len);

void	test_string_only(char *format, int test)
{
	int len;
	
	printf(BGRN "\ntest__%d:\n", test);
	START;		
	len = ft_printf("%s", format);
	MIDDLE;
	len = printf("%s", format);
	END;
}

void	test_string_1_arg(char *format, char *s1,int test)
{
	int len;
	
	printf(BGRN "\ntest__%d:\n", test);
	START;		
	len = ft_printf(format, s1);
	MIDDLE;
	len = printf(format, s1);
	END;
}

void	test_string_3_arg(char *format, char *s1, char *s2, char *s3, int test)
{
	int len;
	
	printf(BGRN "\ntest__%d:\n", test);
	START;		
	len = ft_printf(format, s1, s2, s3);
	MIDDLE;
	len = printf(format, s1, s2, s3);
	END;
}

void	test_char_1_arg(char *format, int c, int test)
{
	int len;
	
	printf(BGRN "\ntest__%d:\n", test);
	START;		
	len = ft_printf(format, c);
	MIDDLE;
	len = printf(format, c);
	END;
}

void	test_hex_1_arg(char *format, int nb, int test)
{
	int len;
	
	printf(BGRN "\ntest__%d:\n", test);
	START;		
	len = ft_printf(format, nb);
	MIDDLE;
	len = printf(format, nb);
	END;
}

void	test_ptr_1_arg(char *format, void *ptr, int test)
{
	int len;
	
	printf(BGRN "\ntest__%d:\n", test);
	START;		
	len = ft_printf(format, ptr);
	MIDDLE;
	len = printf(format, ptr);
	END;
}

void	test_dec_1_arg(char *format, int nb, int test)
{
	int len;
	
	printf(BGRN "\ntest__%d:\n", test);
	START;		
	len = ft_printf(format, nb);
	MIDDLE;
	len = printf(format, nb);
	END;
}

int	main(void)
{
	int test = 0;
	// void *ptr = NULL;
	
	printf(BBLU "\nHello printf !!!\n" reset);
	/*
	test++;		test_string_only("print withtou arguments", test);				// 1		
	test++;		test_string_only("", test);										// 2
	test++;		test_string_only("\t", test);									// 3
	test++;		test_string_only(NULL, test);									// 4
	test++;		test_string_1_arg("42 %s", "quebec" ,test);						// 5
	test++;		test_string_1_arg("42 %s", "" ,test);							// 6
	test++;		test_string_1_arg("42 %s", NULL ,test);							// 7
	test++;		test_string_3_arg("%s %s %s", "42", "Quebec", "!!" ,test);		// 8
	test++;		test_string_3_arg("%s %s %s", "42", "", "!!" ,test);			// 9
	test++;		test_string_3_arg("%s %s %s", NULL, "Quebec", "!!" ,test);		// 10
	test++;		test_char_1_arg("%c", 'c' ,test);								// 11
	test++;		test_char_1_arg("%c", 0 ,test);									// 12
	test++;		test_char_1_arg("%c", -128 ,test);								// 13
	test++;		test_char_1_arg("%c", 50 ,test);								// 14
	test++;		test_char_1_arg("%c", 567 ,test);								// 15
	test++;		test_char_1_arg("%c", '\t' ,test);								// 16
	test++;		test_hex_1_arg("%x", 0 ,test);									// 17
	test++;		test_hex_1_arg("%X", 256 ,test);								// 18
	test++;		test_hex_1_arg("%x", INT_MAX ,test);							// 19
	test++;		test_hex_1_arg("%X", 15 ,test);									// 20
	test++;		test_hex_1_arg("%x", 16 ,test);									// 21
	test++;		test_hex_1_arg("%x", 17 ,test);									// 22
	test++;		test_hex_1_arg("%X", 1500 ,test);								// 23
	test++;		test_hex_1_arg("%x", 150000 ,test);								// 24
	test++;		test_ptr_1_arg("%p", &test ,test);								// 25
	test++;		test_ptr_1_arg("%p", NULL ,test);								// 26
	test++;		test_dec_1_arg("%d", 0 ,test);									// 27
	test++;		test_dec_1_arg("%d", 1 ,test);									// 28
	test++;		test_dec_1_arg("%d", 16 ,test);									// 29
	test++;		test_dec_1_arg("%d", 512 ,test);								// 30
	test++;		test_dec_1_arg("%d", INT_MAX ,test);							// 31
	test++;		test_dec_1_arg("%d", -1 ,test);									// 32
	test++;		test_dec_1_arg("%d", -16 ,test);								// 33
	test++;		test_dec_1_arg("%d", -1024 ,test);								// 34
	test++;		test_dec_1_arg("%d", INT_MIN ,test);							// 35
	test++;		test_dec_1_arg("%i", 0 ,test);									// 36
	test++;		test_dec_1_arg("%i", 1 ,test);									// 37
	test++;		test_dec_1_arg("%i", 16 ,test);									// 38
	test++;		test_dec_1_arg("%i", 512 ,test);								// 39
	test++;		test_dec_1_arg("%i", INT_MAX ,test);							// 40
	test++;		test_dec_1_arg("%i", -1 ,test);									// 41
	test++;		test_dec_1_arg("%i", -16 ,test);								// 42
	test++;		test_dec_1_arg("%i", -1024 ,test);								// 43
	test++;		test_dec_1_arg("%i", INT_MIN ,test);							// 44
	*/
	
	return 0;
}
