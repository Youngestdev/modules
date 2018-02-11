
/* 
    Copyright (c) 2016-2018 Azeez Adewale <azeezadewale98@gmail.com"> 
    MIT License Copyright (c) 2018 simple 

*/

/* 
 * File:   archiver.h
 * Author: thecarisma
 *
 * Created on February 11, 2018, 3:27 PM
 */

#ifndef ARCHIVER_H
#define ARCHIVER_H

#ifdef __cplusplus
extern "C" {
#endif
    
typedef struct zip_t ZIP_T ;

struct buffer_t {
    char *data;
    size_t size;
};

void open_zip_file ( void *pointer ) ;


#ifdef __cplusplus
}
#endif

#endif /* ARCHIVER_H */

