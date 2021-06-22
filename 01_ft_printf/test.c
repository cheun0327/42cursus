/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeekim <chaeekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:06:29 by chaeekim          #+#    #+#             */
/*   Updated: 2021/06/21 22:25:14 by chaeekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int             main()
{   
    char *s = "hello";
    char *nullString = "";
    char c = 'A';
    int i = 123;
    
    /***************************** String ***************************/
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

    /** null string **/
    printf("[%s]", nullString);
    
    /****************************** Char ****************************/
    printf("\n*** char ***\n");
    printf("[%c]\n", c);
    printf("[%10c]\n", c);
    printf("[%-10c]\n", c);
    printf("[%*c]\n", 10, c);
    printf("[%010%]\n");                           //zero padding 사용 가능
    printf("[%-010%]\n");                          //왼쪽 정렬 가능하나, zero padding 무시됨
    // --> char 은 '.', '0' 적용 안된다 = precision 지원 x, 0으로 채워 넣는거 안함

    /***************************** Decimal **************************/
    printf("\n/*** decimal ***/\n");
    // printf("[%d]\n", i);                            // 
    // printf("[%10d]\n", i);
    /** width > prec **/
    printf("[%10.5d]\n", i);                        // width > prec > len : [     00123] : prec 만큼 0으로 채우고 나머지 width 만큼 
    printf("[%10.1d]\n", i);                        // width > len > prec : [       123] : prec 무시하고 len 만큼 width 만큼 출력
    printf("[%2.1d]\n", i);                         // len > width > prec : [123] : len이 prec이랑 width보다 길면 prec width 무시
    /** prec > width **/
    printf("[%5.10d]\n", i);                        // prec > width > len : [0000000123] : 
    printf("[%1.10d]\n", i);                        // prec > len > width : [0000000123] : 
    printf("[%1.2d]\n", i);                         // len > prec > width : [123] : 
    // --> prec채우고, width채운다. len보다 짧으면 무시한다.
    
    /** '-' flag **/
    printf("/** - flag **/\n");
    printf("[%-10.5d]\n", i);                        // width > prec > len : [     00123] : prec 만큼 0으로 채우고 나머지 width 만큼 
    printf("[%-10.1d]\n", i);                        // width > len > prec : [       123] : prec 무시하고 len 만큼 width 만큼 출력
    printf("[%-2.1d]\n", i);                         // len > width > prec : [123] : len이 prec이랑 width보다 길면 prec width 무시
    
    /** '0' flag **/
    printf("/** 0 flag **/\n");
    printf("[%010.5d]\n", i);                        // width > prec > len : [     00123] : prec 만큼 0으로 채우고 나머지 width 만큼 
    printf("[%010.1d]\n", i);                        // width > len > prec : [       123] : prec 무시하고 len 만큼 width 만큼 출력
    printf("[%02.1d]\n", i);                         // len > width > prec : [123] : len이 prec이랑 width보다 길면 prec width 무시
    printf("[%05d]\n", i);                           
    /** prec > width **/
    printf("[%05.10d]\n", i);                        // prec > width > len : [0000000123] : 
    printf("[%01.10d]\n", i);                        // prec > len > width : [0000000123] : 
    printf("[%01.2d]\n", i);                         // len > prec > width : [123] : 
    
    /***************************** Pointer **************************/
    printf("\n/*** Pointer ***/\n");                
    printf("[%p]\n", &s);                           // [0x30c528440]
    printf("[%15p]\n", &s);                         // [    0x30c528440]
    printf("[%-15p]\n", &s);                        // [0x30c528440    ]
    printf("[%*p]\n", 15, &s);                      // [    0x30c528440]

    /** pointer은 prec 적용 x **/
    /** pointer은 zero padding 적용 x **/
    
    /***************************** x **************************/
    
    return 0;
}