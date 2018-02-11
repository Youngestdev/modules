
/* 
    Copyright (c) 2016-2018 Azeez Adewale <azeezadewale98@gmail.com"> 
    MIT License Copyright (c) 2018 simple 

*/

/* 
 * File:   archiver.c
 * Author: thecarisma
 *
 * Created on February 11, 2018, 3:27 PM
 */

#include "../../../simple/bootsrc/includes/simple.h"
#include "zip.h"
#include "archiver.h"

SIMPLE_API __declspec(dllexport)

SIMPLE_API void init_simple_module(SimpleState *sState)
{   
    register_block("__open_zip",open_zip_file);
}

typedef struct zip_t ZIP_T ;

struct buffer_t {
    char *data;
    size_t size;
};

static size_t on_extract(void *arg, unsigned long long offset, const void *data,size_t size) {
    struct buffer_t *buf = (struct buffer_t *) arg;
    buf->data = realloc(buf->data, buf->size + size + 1);
    assert(NULL != buf->data);

    memcpy(&(buf->data[buf->size]), data, size);
    buf->size += size;
    buf->data[buf->size] = 0;

    return size;
}

int on_extract_entry(const char *filename, void *arg) {
    return 0;
}

void zip_extract_allfiles(const char *cFile, const char *cFolder) {
    int arg = 2;
    zip_extract(cFile,cFolder, on_extract_entry, &arg);
}

ZIP_T *zip_openfile(const char *cFile, const char *cMode) {
    return zip_open(cFile, ZIP_DEFAULT_COMPRESSION_LEVEL, cMode[0]);
}

int zip_filescount(ZIP_T *pZip) {
    return mz_zip_reader_get_num_files((mz_zip_archive *) pZip);
}

const char *zip_getfilenamebyindex(ZIP_T *pZip,int index) {
    mz_zip_archive_file_stat info;
    if (!mz_zip_reader_file_stat((mz_zip_archive *) pZip, index-1, &info)) {
        // Cannot get information about zip archive;
        return NULL;
    }	
    return info.m_filename ;
}

void open_zip_file ( void *pointer )
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(SIMPLE_API_MISS2PARA);
		return ;
	}
	SIMPLE_API_IGNORECPOINTERTYPE ;
	if ( ! SIMPLE_API_ISSTRING(1) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	if ( ! SIMPLE_API_ISSTRING(2) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	SIMPLE_API_RETCPOINTER(zip_openfile(SIMPLE_API_GETSTRING(1),SIMPLE_API_GETSTRING(2)),"ZIP_T");
}

