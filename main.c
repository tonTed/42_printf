/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:01:45 by tblanco           #+#    #+#             */
/*   Updated: 2021/10/20 00:29:18 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"
#include "include/ft_colors.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

char	*ft_getstdin(int (*f)(const char*, ...))
{
	char	*buffer;
	pid_t	pid;
	int		status;
	int		fd[2];
	int		char_read;

	buffer = (char *)malloc(sizeof(char) * ((int)BUFSIZ + 1));
	pipe(fd);
	pid = fork();
	if (pid)
	{
		wait(&status);
		char_read = read(fd[0], buffer, BUFSIZ);
		buffer[char_read] = '\0';
		return(buffer);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		f("%c\n", 'a');
		close(1);
	}
	return (NULL);
}

int main(void)
{
	// int		err	= 0;
	// int		test = 0;
	int		total_err = 0;
	int		total_test = 0;
	char	*_ft_printf;
	char	*_printf;
	
	printf("\n" BBLU "---------- TESTING START ----------" reset);
	printf("\n" UCYN "### %%c:\n" reset);

	_printf = ft_getstdin(&printf);
	_ft_printf = ft_getstdin(&printf);
	if (strcmp(_printf, _ft_printf))
		printf("expected: %s | %s :return\n", _printf, _ft_printf);
	
	if (total_err)
		printf("\n" BRED "TOTAL ERRORS: %d/%d :(" reset "\n", total_err, total_test);
	else
		printf("\n" BGRN "CONGRATS!!! YOU SUCCED %d TESTS :)" reset "\n", total_test);
	return 0;
}
