#include "../include/ft_printf.h"
#include "ft_colors.h"

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

int	main(void)
{
	int test = 0;
	// void *ptr = NULL;
	
	printf(BBLU "\nHello printf !!!\n" reset);
	
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
	test++;		test_char_1_arg("%c", -40 ,test);								// 13
	test++;		test_char_1_arg("%c", 20 ,test);								// 14
	test++;		test_char_1_arg("%c", 567 ,test);								// 15
	test++;		test_char_1_arg("%%", 567 ,test);								// 15

	return 0;
}
