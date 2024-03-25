/*  cistack.h

    Header file for C interface to IntStack class.
*/

#ifdef __cpluscplus
extern "C"
{
#endif
    void PushStack(int x);
    int PopStack();
    void PrintStack();
#ifdef __cpluscplus
}
#endif

