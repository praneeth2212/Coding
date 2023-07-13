// link https://www.interviewbit.com/problems/list-cycle/

listnode *detectCycle(listnode *A)
{
    listnode *s = A;
    listnode *f = A;
    while (f)
    {
        s = s->next;
        f = f->next;
        if (!f)
        {
            return NULL;
        }
        f = f->next;
        if (s == f)
        {
            break;
        }
    }
    if (!f)
    {
        return NULL;
    }
    f = A;
    while (s != f)
    {
        s = s->next;
        f = f->next;
    }
    return s;
}
