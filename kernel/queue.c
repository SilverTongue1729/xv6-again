#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "defs.h"

void popfront(queue *a)
{
    for (int i = 0; i < a->end - 1; i++)
    {
        a->n[i] = a->n[i + 1];
    }
    a->end--;
    return;
}
void pushback(queue *a, struct proc *x)
{
    if (a->end == NPROC)
    {
        panic("Error!");
        return;
    }
    a->n[a->end] = x;
    a->end++;
    return;
}
struct proc *front(queue *a)
{
    if (a->end == 0)
    {
        return 0;
    }
    return a->n[0];
}
int size(queue *a)
{
    return a->end;
}
void delete (queue *a, uint pid)
{
    int flag = 0;
    for (int i = 0; i < a->end; i++)
    {
        if (pid == a->n[i]->pid)
        {
            flag = 1;
        }
        if (flag == 1 && i != NPROC)
        {
            a->n[i] = a->n[i + 1];
        }
    }
    a->end--;
    return;
}