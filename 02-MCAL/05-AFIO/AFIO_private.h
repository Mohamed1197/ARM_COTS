/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :        22/07/2022        ********************/
/**************** SWC     :          AFIO            ********************/
/**************** Version :           1.0            ********************/
/************************************************************************/

#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

typedef struct{
    volatile u32 EVCR      ;
    volatile u32 MAPR      ;
    volatile u32 EXTICR[4] ;
    volatile u32 MAPR2     ;

}AFIO_t;

#define AFIO ((volatile AFIO_t *) 0x40010000 )


#endif