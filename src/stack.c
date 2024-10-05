//https://stackoverflow.com/questions/18883590/push-and-pop-using-array-of-doubles
#define STACK_FULL   -2
#define STACK_EMPTY -1
#define NORMAL          0

int push(double stack[], double value, double **top, int sizemax)
{
    if (*top - stack < sizemax)
    {
        **top = value;
        ++*top;
        return NORMAL;
    }
    return STACK_FULL;
}

int pop(double stack[], double **top, double *result)
{
    if (*top - stack > 0)
    {
        --*top;
        *result = **top;
        return NORMAL;
    }
    return STACK_EMPTY;
}
