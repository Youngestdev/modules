
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
    /** ZIP **/
    register_block("__open_zip",open_zip_file);
    register_block("__open_zip_entry",open_zip_entry_file);
    register_block("__write_zip_entry",write_zip_entry_file);
    register_block("__fwrite_zip_entry",fwrite_zip_entry_file);
    register_block("__read_zip_entry",read_zip_entry_file);
    register_block("__fread_zip_entry",fread_zip_entry_file);
    register_block("__close_zip_entry",close_zip_entry_file);
    register_block("__extract_zip",extract_zip_file);
    register_block("__close_zip",close_zip_file);
    register_block("__total_zip_file_count",total_zip_file_count);
    register_block("__zip_entry_by_index",zip_entry_by_index);
    register_block("__extract_zip_entry",extract_zip_entry);
    /** TAR **/
}

SIMPLE_ZIP *zip_openfile(const char *zip_file, const char *open_mode) {
    return zip_open(zip_file, ZIP_DEFAULT_COMPRESSION_LEVEL, open_mode[0]);
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
	SIMPLE_API_RETCPOINTER(zip_openfile(SIMPLE_API_GETSTRING(1),SIMPLE_API_GETSTRING(2)),"SIMPLE_ZIP");
}

void open_zip_entry_file ( void *pointer )
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(SIMPLE_API_MISS2PARA);
		return ;
	}
	SIMPLE_API_IGNORECPOINTERTYPE ;
	if ( ! SIMPLE_API_ISPOINTER(1) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	if ( ! SIMPLE_API_ISSTRING(2) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	SIMPLE_API_RETNUMBER(zip_entry_open((SIMPLE_ZIP *) SIMPLE_API_GETCPOINTER(1,"SIMPLE_ZIP"),SIMPLE_API_GETSTRING(2)));
}

void write_zip_entry_file ( void *pointer )
{
	if ( SIMPLE_API_PARACOUNT != 3 ) {
		SIMPLE_API_ERROR(SIMPLE_API_MISS3PARA);
		return ;
	}
	SIMPLE_API_IGNORECPOINTERTYPE ;
	if ( ! SIMPLE_API_ISPOINTER(1) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	if ( ! SIMPLE_API_ISSTRING(2) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	if ( ! SIMPLE_API_ISNUMBER(3) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	SIMPLE_API_RETNUMBER(zip_entry_write((SIMPLE_ZIP *) SIMPLE_API_GETCPOINTER(1,"SIMPLE_ZIP"),SIMPLE_API_GETSTRING(2), (int) SIMPLE_API_GETNUMBER(3)));
}

void fwrite_zip_entry_file ( void *pointer )
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(SIMPLE_API_MISS2PARA);
		return ;
	}
	SIMPLE_API_IGNORECPOINTERTYPE ;
	if ( ! SIMPLE_API_ISPOINTER(1) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	if ( ! SIMPLE_API_ISSTRING(2) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	SIMPLE_API_RETNUMBER(zip_entry_fwrite((SIMPLE_ZIP *) SIMPLE_API_GETCPOINTER(1,"SIMPLE_ZIP"),SIMPLE_API_GETSTRING(2)));
}

void read_zip_entry_file ( void *pointer )
{
	if ( SIMPLE_API_PARACOUNT != 3 ) {
		SIMPLE_API_ERROR(SIMPLE_API_MISS3PARA);
		return ;
	}
	SIMPLE_API_IGNORECPOINTERTYPE ;
	if ( ! SIMPLE_API_ISPOINTER(1) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	if ( ! SIMPLE_API_ISPOINTER(2) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	if ( ! SIMPLE_API_ISPOINTER(3) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	SIMPLE_API_RETNUMBER(zip_entry_read((SIMPLE_ZIP *) SIMPLE_API_GETCPOINTER(1,"SIMPLE_ZIP"),(void *) SIMPLE_API_GETCPOINTER(2,"void"),(size_t *) SIMPLE_API_GETCPOINTER(3,"size_t")));
}

void fread_zip_entry_file ( void *pointer )
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(SIMPLE_API_MISS2PARA);
		return ;
	}
	SIMPLE_API_IGNORECPOINTERTYPE ;
	if ( ! SIMPLE_API_ISPOINTER(1) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	if ( ! SIMPLE_API_ISSTRING(2) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	SIMPLE_API_RETNUMBER(zip_entry_fread((SIMPLE_ZIP *) SIMPLE_API_GETCPOINTER(1,"SIMPLE_ZIP"),SIMPLE_API_GETSTRING(2)));
}

void extract_zip_file ( void *pointer )
{
	if ( SIMPLE_API_PARACOUNT != 1 ) {
		SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
		return ;
	}
	SIMPLE_API_IGNORECPOINTERTYPE ;
	if ( ! SIMPLE_API_ISPOINTER(1) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	SIMPLE_API_RETNUMBER(zip_entry_close((SIMPLE_ZIP *) SIMPLE_API_GETCPOINTER(1,"SIMPLE_ZIP")));
}

void close_zip_file ( void *pointer )
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
	zip_extract_allfiles(SIMPLE_API_GETSTRING(1),SIMPLE_API_GETSTRING(2));
}

void close_zip_entry_file ( void *pointer )
{
	if ( SIMPLE_API_PARACOUNT != 1 ) {
		SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
		return ;
	}
	SIMPLE_API_IGNORECPOINTERTYPE ;
	if ( ! SIMPLE_API_ISPOINTER(1) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	zip_close((SIMPLE_ZIP *) SIMPLE_API_GETCPOINTER(1,"SIMPLE_ZIP"));
}

void close_zip_entry_file ( void *pointer )
{
	if ( SIMPLE_API_PARACOUNT != 1 ) {
		SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
		return ;
	}
	SIMPLE_API_IGNORECPOINTERTYPE ;
	if ( ! SIMPLE_API_ISPOINTER(1) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	SIMPLE_API_RETNUMBER(zip_filescount((SIMPLE_ZIP *) SIMPLE_API_GETCPOINTER(1,"SIMPLE_ZIP")));
}

void close_zip_entry_file ( void *pointer )
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(SIMPLE_API_MISS2PARA);
		return ;
	}
	SIMPLE_API_IGNORECPOINTERTYPE ;
	if ( ! SIMPLE_API_ISPOINTER(1) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	if ( ! SIMPLE_API_ISNUMBER(2) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	SIMPLE_API_RETSTRING(zip_getfilenamebyindex((SIMPLE_ZIP *) SIMPLE_API_GETCPOINTER(1,"SIMPLE_ZIP"), (int ) SIMPLE_API_GETNUMBER(2)));
}

void close_zip_entry_file ( void *pointer )
{
const char *cZIPFile;
const char *cFile;
struct buffer_t buf = {0};

if ( SIMPLE_API_PARACOUNT != 2 ) {
	SIMPLE_API_ERROR(SIMPLE_API_MISS2PARA);
	return ;
}
if ( ! SIMPLE_API_ISSTRING(1) ) {
	SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	return ;
}
if ( ! SIMPLE_API_ISSTRING(2) ) {
	SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	return ;
}

cZIPFile = SIMPLE_API_GETSTRING(1);
cFile    = SIMPLE_API_GETSTRING(2);

struct zip_t *zip = zip_open(cZIPFile, 0, 'r');
{
	zip_entry_open(zip, cFile);
	{
		zip_entry_extract(zip, on_extract, &buf);
}
	zip_entry_close(zip);
}
zip_close(zip);

SIMPLE_API_RETSTRING2(buf.data,buf.size);

free(buf.data);
}
