
/* 
	Copyright (c) 2016-2018 Azeez Adewale <azeezadewale98@gmail.com"> 
	MIT License Copyright (c) 2017 simple 

*/

/* 
 * File:   mathic.h 
 * Author: thecarisma
 *
 * Created on Febuary 7, 2018, 3:23 AM
 */

#include "../../../simple/bootsrc/includes/simple.h"
#include "mathic.h"


SIMPLE_API void init_simple_module(SimpleState *sState)
{   
    register_block("sin",math_sin);
    register_block("cos",math_cos);
    register_block("an",math_tan);
    register_block("asin",math_asin);
    register_block("acos",math_acos);
    register_block("atan",math_atan);
    register_block("atan2",math_atan2);
    register_block("sinh",math_sinh);
    register_block("cosh",math_cosh);
    register_block("tanh",math_tanh);
    register_block("exp",math_exp);
    register_block("log",math_log);
    register_block("log10",math_log10);
    register_block("ceil",math_ceil);
    register_block("floor",math_floor);
    register_block("fabs",math_fabs);
    register_block("pow",math_pow);
    register_block("sqrt",math_sqrt);
    register_block("unsigned",math_unsigned);
    register_block("decimals",math_decimals);
    register_block("murmur3hash",math_murmur3hash);
}

void math_sin ( void *pPointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) ) {
            SIMPLE_API_RETNUMBER(sin(SIMPLE_API_GETNUMBER(1)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_cos ( void *pPointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) ) {
            SIMPLE_API_RETNUMBER(cos(SIMPLE_API_GETNUMBER(1)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_tan ( void *pPointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) ) {
            SIMPLE_API_RETNUMBER(tan(SIMPLE_API_GETNUMBER(1)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_asin ( void *pPointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) ) {
            SIMPLE_API_RETNUMBER(asin(SIMPLE_API_GETNUMBER(1)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_acos ( void *pPointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) ) {
            SIMPLE_API_RETNUMBER(acos(SIMPLE_API_GETNUMBER(1)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_atan ( void *pPointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) ) {
            SIMPLE_API_RETNUMBER(atan(SIMPLE_API_GETNUMBER(1)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_atan2 ( void *pPointer )
{
    if ( SIMPLE_API_PARACOUNT != 2 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS2PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) && SIMPLE_API_ISNUMBER(2) ) {
            SIMPLE_API_RETNUMBER(atan2(SIMPLE_API_GETNUMBER(1),SIMPLE_API_GETNUMBER(2)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_sinh ( void *pPointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) ) {
            SIMPLE_API_RETNUMBER(sinh(SIMPLE_API_GETNUMBER(1)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_cosh ( void *pPointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) ) {
            SIMPLE_API_RETNUMBER(cosh(SIMPLE_API_GETNUMBER(1)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_tanh ( void *pPointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) ) {
            SIMPLE_API_RETNUMBER(tanh(SIMPLE_API_GETNUMBER(1)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_exp ( void *pPointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) ) {
            SIMPLE_API_RETNUMBER(exp(SIMPLE_API_GETNUMBER(1)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_log ( void *pPointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) ) {
            SIMPLE_API_RETNUMBER(log(SIMPLE_API_GETNUMBER(1)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_log10 ( void *pPointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) ) {
            SIMPLE_API_RETNUMBER(log10(SIMPLE_API_GETNUMBER(1)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_ceil ( void *pPointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) ) {
            SIMPLE_API_RETNUMBER(ceil(SIMPLE_API_GETNUMBER(1)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_floor ( void *pPointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) ) {
            SIMPLE_API_RETNUMBER(floor(SIMPLE_API_GETNUMBER(1)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_fabs ( void *pPointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) ) {
            SIMPLE_API_RETNUMBER(fabs(SIMPLE_API_GETNUMBER(1)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_pow ( void *pPointer )
{
    if ( SIMPLE_API_PARACOUNT != 2 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS2PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) && SIMPLE_API_ISNUMBER(2) ) {
            SIMPLE_API_RETNUMBER(pow(SIMPLE_API_GETNUMBER(1),SIMPLE_API_GETNUMBER(2)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_sqrt ( void *pPointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) ) {
            SIMPLE_API_RETNUMBER(sqrt(SIMPLE_API_GETNUMBER(1)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_unsigned ( void *pPointer )
{
    unsigned int nNum1,nNum2  ;
    double nNum3  ;
    const char *cStr  ;
    if ( SIMPLE_API_PARACOUNT != 3 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS3PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISSTRING(3) ) {
            nNum1 = (unsigned int) SIMPLE_API_GETNUMBER(1) ;
            nNum2 = (unsigned int ) SIMPLE_API_GETNUMBER(2) ;
            cStr = SIMPLE_API_GETSTRING(3) ;
            if ( strcmp(cStr,">>") == 0 ) {
                    nNum3 = nNum1 >> nNum2 ;
            }
            else if ( strcmp(cStr,"<<") == 0 ) {
                    nNum3 = nNum1 << nNum2 ;
            }
            else if ( strcmp(cStr,"+") == 0 ) {
                    nNum3 = nNum1 + nNum2 ;
            }
            else if ( strcmp(cStr,"-") == 0 ) {
                    nNum3 = nNum1 - nNum2 ;
            }
            else if ( strcmp(cStr,"*") == 0 ) {
                    nNum3 = nNum1 * nNum2 ;
            }
            else if ( strcmp(cStr,"/") == 0 ) {
                    if ( nNum2 != 0 ) {
                            nNum3 = nNum1 / nNum2 ;
                    }
                    else {
                            SIMPLE_API_ERROR(SIMPLE_VM_ERROR_DIVIDEBYZERO);
                            return ;
                    }
            }
            else if ( strcmp(cStr,"^") == 0 ) {
                    nNum3 = nNum1 ^ nNum2 ;
            }
            else if ( strcmp(cStr,"<") == 0 ) {
                    nNum3 = nNum1 < nNum2 ;
            }
            else if ( strcmp(cStr,">") == 0 ) {
                    nNum3 = nNum1 > nNum2 ;
            }
            else if ( strcmp(cStr,"<=") == 0 ) {
                    nNum3 = nNum1 <= nNum2 ;
            }
            else if ( strcmp(cStr,">=") == 0 ) {
                    nNum3 = nNum1 >= nNum2 ;
            }
            else if ( strcmp(cStr,"=") == 0 ) {
                    nNum3 = nNum1 == nNum2 ;
            }
            else if ( strcmp(cStr,"!=") == 0 ) {
                    nNum3 = nNum1 != nNum2 ;
            }
            else if ( strcmp(cStr,"&") == 0 ) {
                    nNum3 = nNum1 & nNum2 ;
            }
            else if ( strcmp(cStr,"|") == 0 ) {
                    nNum3 = nNum1 | nNum2 ;
            }
            else if ( strcmp(cStr,"~") == 0 ) {
                    nNum3 = ~ nNum1 ;
            } else {
                    SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
                    return ;
            }
            SIMPLE_API_RETNUMBER(nNum3);
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

void math_decimals ( void *pPointer )
{
    int nNum1  ;
    if ( SIMPLE_API_PARACOUNT == 1 ) {
            if ( SIMPLE_API_ISNUMBER(1) ) {
                    nNum1 = (int) SIMPLE_API_GETNUMBER(1) ;
                    if ( (nNum1 >= 0) && (nNum1 <= 14) ) {
                            ((VM *) pPointer)->nDecimals = nNum1 ;
                    }
                    else {
                            SIMPLE_API_ERROR(SIMPLE_VM_ERROR_BADDECIMALNUMBER);
                    }
            } else {
                    SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
            }
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARACOUNT);
    }
}
/* Hash */

void math_murmur3hash ( void *pPointer )
{
    unsigned int nResult  ;
    if ( SIMPLE_API_PARACOUNT != 2 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS2PARA);
            return ;
    }
    if ( SIMPLE_API_ISSTRING(1) && SIMPLE_API_ISNUMBER(2) ) {
            nResult = simple_murmur3_32(SIMPLE_API_GETSTRING(1),SIMPLE_API_GETSTRINGSIZE(1),SIMPLE_API_GETNUMBER(2));
            SIMPLE_API_RETNUMBER(nResult);
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}

