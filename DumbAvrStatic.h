#ifndef DUMB_AVR_STATIC_H
#define DUMB_AVR_STATIC_H

//avr-g++ is stupid so we need to add this for static variables in functions
extern "C"
{
   __extension__ typedef int __guard __attribute__((mode (__DI__)));
   int __cxa_guard_acquire(__guard *g) { return !*(char *)(g); };
   void __cxa_guard_release (__guard *g) { *(char *)g = 1; };
   void __cxa_guard_abort (__guard *) { };
}

#endif
