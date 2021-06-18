/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:06:29 by chaeekim          #+#    #+#             */
/*   Updated: 2021/06/18 14:56:44 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int             main()
{   
    char *s = "hello";
    /** String **/
    printf("*** String ***\n");
    /** width > precision **/
    printf("[%10.7s]\n", s);                      // width > prec > len : [     hello] : width 만큼 확보해서 출력
    printf("[%10.3s]\n", s);                      // width > len > prec : [       hel] : prec만큼 잘라주고 width 길이로 출력
    printf("[%3.1s]\n", s);                       // len > width > prec : [  h]        : prec만큼 잘라주고 width 길이로 출력
    /** width < precision **/
    printf("[%7.10s]\n", s);                      // prec > width > len : [  hello]    : prec이 len보다 커서 길이 유지, width는 prec보단 작지만 len보다는 길어서 width 길이만큼 출력
    printf("[%3.10s]\n", s);                      // prec > len > width : [hello]      : prec이 len보다 커서 길이 유지, width가 prec보단 작고 len보다 작아서 무시
    printf("[%1.3s]\n", s);                       // len > prec > width : [hel]        : prec이 len보다 작아서 무시, width도 무시
    // --> 먼저 prec으로 길이 자르고(혹은 유지) 그 길이와 width 비교해서 빈칸 출력
    
    /** '-' flag **/
    printf("[%-3.1s]\n", s); 
    printf("[%-7.10s]\n", s);
    printf("[%-3.10s]\n", s); 
    // --> width, prec 모두 체크하고 마지막에 있으면 str부터 출력한 후, 빈칸 출력
    
    /** '0' flag **/
    // 해당 없음
    
    /** '*' flag **/
    printf("[%*.*s]\n", 10, 7, s);  
    
    //printf("[%s]", s);                       // width > prec > len
    
    
    return 0;
}