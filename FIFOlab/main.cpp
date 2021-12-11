#include <stdio.h>


enum { CMD_LENGTH,
    CMD_PRINT,
    CMD_ADDVOID,
    CMD_ADDKEY,
    CMD_ERROR,
    CMD_DELKEY,
    CMD_DELALLVOID,
} ecmd;

struct Elem {
    int key;
    Elem* next;
    Elem(Elem* e, int k) : next(e), key(k) { }
};

char cmd;
int n;
bool isEmptyQueue;
Elem *first, *last, *firstQ, *lastQ;


int parseEnum(char cmd) {
    return cmd == 'L' ? CMD_LENGTH :
           cmd == 'P' ? CMD_PRINT :
           cmd == 'A' ? CMD_ADDVOID :
           cmd == 'E' ? CMD_ADDKEY :
           cmd == 'D' ? CMD_DELKEY :
           cmd == 'G' ? CMD_DELALLVOID :
           CMD_ERROR;
}

Elem *search(int key)
{
    if(!first) return NULL;
    Elem *tmp = first;
    while(tmp->key != key && tmp != last) tmp = tmp->next;
    if (tmp->key == key) return tmp;
    else return NULL;
}

void printAll() {
    if(!firstQ || isEmptyQueue) printf("-\n");
    else {
        Elem *tmp = firstQ;
        while(tmp != lastQ) {
            printf("%d->", tmp->key);
            tmp = tmp->next;
        }
        printf("%d\n", lastQ->key);
    }
}

int totalLength()
{
    if(!first) return 0;
    int len(1);
    Elem *tmp = first;
    while(tmp->next != first) { tmp = tmp->next; len++; }
    return len;
}

void addVoid()
{
    Elem * temp = new Elem(nullptr, NULL);
    if (!first) {first = temp; last = temp;}
    else {
        last->next = temp;
        last = temp;
    }
    temp->next = first;
}

void addKey(int key)
{
    if(!last) {
        addVoid();
        firstQ = lastQ = first;
        lastQ->key = key;
    }
    else if(lastQ == nullptr) {first->key = key; firstQ = lastQ = first;}
    else if (lastQ->next != firstQ) {
        lastQ = lastQ->next;
        lastQ->key = key;
    }
    else
    {
        addVoid();
        lastQ = last;
        lastQ->key = key;
    }
}

void delKey()
{
    if(!firstQ) { printf("-\n"); isEmptyQueue = true;}
    else if(firstQ == lastQ) {
        printf("%d\n", firstQ->key);
        firstQ->key = NULL;
        firstQ = lastQ = nullptr;
        isEmptyQueue = true;
    }
    else {
        printf("%d\n", firstQ->key);
        firstQ->key = NULL;
        firstQ = firstQ->next;
    }
}

void delAllVoid() {
    if(first == nullptr) return;
    if(first == last) {
        if(first->key == NULL) {
            delete first;
            first = last = nullptr;
        }
        return;
    }
    Elem *tmp = lastQ->next;
    while(tmp != firstQ) {
        Elem * tmp2 = tmp;
        tmp = tmp->next;
        delete tmp2;
    }
    first = firstQ;
    last = lastQ;
    last->next = first;
}

int main()
{
    isEmptyQueue  = true;
    while(scanf("%c", &cmd) > 0) {
        switch (parseEnum(cmd))
        {
            case CMD_LENGTH:
                printf("%d\n", totalLength());
                break;

            case CMD_PRINT:
                printAll();
                break;

            case CMD_ADDVOID:
                addVoid();
                break;

            case CMD_ADDKEY:
                isEmptyQueue = false;
                int key;
                scanf_s("%d", &key);
                addKey(key);
                break;

            case CMD_DELKEY:
                delKey();
                break;

            case CMD_DELALLVOID:
                delAllVoid();
                break;

            case CMD_ERROR:
            default:
                break;
        }

    }
    return 0;
}