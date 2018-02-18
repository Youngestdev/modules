/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

extern "C" {
    #include "../../../simple/bootsrc/includes/simple.h"
}

extern "C" {

    SIMPLE_API void init_full_tick(SimpleState *sState);

    SIMPLE_API void init_simple_module(SimpleState *sState)
    {
        printf("Hello it works");
    }

}