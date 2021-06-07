/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:06:29 by chaeekim          #+#    #+#             */
/*   Updated: 2021/06/07 18:06:41 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int             main()
{   
    printf("[%-05%]\n");
    printf("[%05%]\n");
    printf("[%-5%]\n");
    
    printf("[%*d]\n", 2, 5);
    printf("[%*d]\n", 2, 115);
    
    printf("[%.2d]\n", 5);
    printf("[%.*d]\n", 2, 5);
    
    printf("[%.*s]\n", 3, "Hello");     //width 없이 precision이 있어서 prec무시??
    printf("[%-.10s]\n", "Hello");      //width 없이 precision이 있어서 prec무시
    printf("[%-10s]\n", "Hello");       //왼쪽 정렬, width = 10
    printf("[%6.10s]\n", "Hello");      //precision무시, width길이로 최종 출력
    printf("[%9.5s]\n", "abcdefg");

    printf("[%10.7d]\n", 4242);
    printf("[%-10.7d]\n", 4242);
    printf("[%10.*d]\n", 6, 4242);

    printf("[%10.*d]\n", 6, -4242);
    

    
    // printf("%-.*s\n", 10, "Hello");
    // printf("%-0.*s\n", 10, "Hello");
    
    
}