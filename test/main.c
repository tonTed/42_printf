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
	test++;		test_string_3_arg("%s %s %s", "42", "Quebec", "!!" ,test);		// 8


	return 0;
}
