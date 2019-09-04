#include <malloc.h>
#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0

typedef int KeyType;
typedef int TElemType;

typedef struct BitNode
{
    TElemType data;
    struct BitNode *lchild, *rchild;
} BitNode, *BitTree;

int CreateBitree(BitTree &T, int array[], int &i)
{
    TElemType ch;

    ch = array[i];
    i++;
    if (ch == 0)
    {
        T = NULL;
    }
    else
    {
        if (!(T = (BitNode *)malloc(sizeof(BitNode))))
        {
            cout << "overflow";
            return (ERROR);
        }
        T->data = ch;
        CreateBitree(T->lchild, array, i);
        CreateBitree(T->rchild, array, i);
    }

    return (OK);
}
/* 遍历二叉树 */
int PreOrderTraverse(BitTree T)
{
    if (T)
    {
        cout << endl
             << T->data;
        if (PreOrderTraverse(T->rchild))
            if (PreOrderTraverse(T->lchild))
                return (OK);
        return (ERROR);
    }
    else
    {
        return (OK);
    }
}

int SearchBST(BitTree T, KeyType key, BitTree f, BitTree &p)
{
    if (!T)
    {
        p = f;
        return (ERROR);
    }
    else if (key == T->data)
    {
        p = T;
        return (OK);
    }
    else if (key < T->data)
    {
        SearchBST(T->lchild, key, T, p);
        /* 下面语句更规范 */
        //return SearchBST(T->lchild,key,T,p);
    }
    else
    {
        SearchBST(T->rchild, key, T, p);
        /* 下面语句更规范 */
        //return SearchBST(T->rchild,key,T,p);
    }
}

int insertBST(BitTree &T, TElemType e)
{
    BitTree p;
    if (!SearchBST(T, e, NULL, p))
    {
        BitTree s;
        s = (BitTree)malloc(sizeof(BitNode));
        s->data = e;
        s->lchild = NULL;
        s->rchild = NULL;

        if (!p)
        {
            T = s;
        }
        else if (e < p->data)
        {
            p->lchild = s;
        }
        else
        {
            p->rchild = s;
        }
        return (OK);
    }
    else
    {
        return (ERROR);
    }
}

int main(int argc, char const *argv[])
{
    BitTree T;
    int array[] = {49, 38, 13, 0, 27, 0, 0, 0, 65, 50, 0, 52, 0, 0, 76, 0, 0};
    int i = 0;
    cout << endl
         << endl
         << "InsertBST.cpp";
    CreateBitree(T, array, i);
    PreOrderTraverse(T);
    TElemType e;
    cout << endl
         << endl
         << "Please input the data to insert (eg,58):";
    cin >> e;
    if (insertBST(T, e))
        cout << e << "has been inserted to BitTree";
    else
        cout << e << "has existed and not been insterted to the BitTree";
    cout << endl
         << endl
         << "The new BiTree is as follows by PreOrderTraverse: ";
    PreOrderTraverse(T); //call PreOrderTraverse()
    cout << endl
         << endl
         << "...OK!...";

    return 0;
}
