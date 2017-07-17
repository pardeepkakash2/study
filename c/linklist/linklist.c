#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
 
 
/* node for single linked list */
typedef struct node {
    struct node *next;
    int value;
} node_ts;
 
/* node for double linked list */
typedef struct noded {
    struct noded *next;
    struct noded *prev;
    int value;
} node_td;
 
 
/*
 * Routines for single linked list
 */
void insert_single(node_ts ** list, int value) {
    node_ts * new = malloc(sizeof(node_ts));
    new->value = value;
    new->next = NULL;
 
    /* empty */
    if (*list == NULL) {
        *list = new;
        return;
    }
    /* element becomes first. can be merged with case above */
    if ((*list)->value > value) {
        new->next = *list;
        *list = new;
        return;
    }
 
    node_ts *prev = *list;
    node_ts *ptr = (*list)->next;
    while (ptr != NULL && ptr->value < value) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = new;
    new->next = ptr;
}
 
void print_single(node_ts *list) {
    while (list != NULL) {
        printf("%d, ", list->value);
        list = list->next;
    }
    printf("\n");
}
 
void reverse_single(node_ts **list) {
 
    /* empty or one element */
    if (*list == NULL || (*list)->next == NULL) {
        return;
    }
 
    node_ts * prev = NULL;
    node_ts * current = *list;
    node_ts * next = (*list)->next;
 
    while (next != NULL) {
        current->next = prev;
        /* move ptrs forward */
        prev = current;
        current = next;
        next = next->next;
    }
    /* current points to last element */
    current->next = prev;
    *list = current;
}
 
/*
 * Routines for circular single linked list
 */
void insert_singlecircular(node_ts ** list, int value) {
 
    node_ts * new = malloc(sizeof(node_ts));
    new->value = value;
    new->next = NULL;
 
    /* empty list */
    if (*list == NULL) {
        *list = new;
        new->next = new;
        return;
    }
 
    /* place at first location */
#ifdef TRAVERSE
    if ((*list)->value > value) {
        /* if list has only one node */
        if ((*list)->next == *list) {
            new->next = *list;
            (*list)->next = new;
            *list = new;
            return;
        }
        /* if list has more nodes, get last node */
        node_t *ptr = (*list)->next;
        while (ptr->next != *list) {
            assert(ptr->next != NULL);
            ptr = ptr->next;
        }
        /* insert node */
        ptr->next = new;
        new->next = *list;
        *list = new;
        return;
    }
#else
    /* another way to insert at beginning
       without having to traverse list */
    if ((*list)->value > value) {
        memcpy(new, *list, sizeof(node_t));
        (*list)->value = value;
        (*list)->next = new;
        return;
    }
#endif
 
 
    node_ts *prev = *list;
    node_ts *ptr = (*list)->next;
    while (ptr != *list && ptr->value < value) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = new;
    new->next = ptr;
}
 
void print_singlecircular(node_ts * list) {
    node_ts * ptr = list;
    do {
        printf("%d, ", ptr->value);
        ptr = ptr->next;
    } while (ptr != list);
    printf("\n");
}
 
void reverse_singlecircular(node_ts ** list) {
 
    if (*list == NULL || (*list)->next == *list)
        return;
 
    node_ts * prev = *list;
    node_ts * current = (*list)->next;
    node_ts * next = current->next;
 
    while(current != *list) {
        current->next = prev;
        prev = current;
        current = next;
        next = next->next;
    }
    /* prev points to last element,
       current points to first */
    current->next = prev;
    *list = prev;
}
 
 
 
/*
 * Routines for double linked list
 */
void insert_double(node_td ** list, int value) {
    node_td * new = malloc(sizeof(node_td));
    new->value = value;
    new->prev = NULL;
    new->next = NULL;
 
    /* empty list */
    if (*list == NULL) {
        *list = new;
        return;
    }
 
    /* first place */
    if ((*list)->value > value) {
        new->next = *list;
        (*list)->prev = new;
        *list = new;
        return;
    }
 
    node_td *ptr = *list;
    /* looking one node ahead */
    while (ptr->next != NULL && ptr->next->value < value) {
        ptr = ptr->next;
    }
 
#ifdef TWOSTEPS
    /* place at end of list */
    if (ptr->next == NULL) {
        ptr->next = new;
        new->prev = ptr;
        return;
    }
 
    /* place new node */
    new->prev = ptr;
    new->next = ptr->next;
    /* adjust previous node */
    ptr->next = new;
    /* adjust next node */
    new->next->prev = new;
#else
    // adjust new node prev and next (ALWAYS FIRST!) 
    new->prev = ptr;
    new->next = ptr->next; // might be NULL 
    // adjust node before new
    ptr->next = new;
    // if exists, adjust node after new
    if (new->next)
       new->next->prev = new;
    /* WATCH FOR THIS MISTAKE:
    if (ptr->next) // ptr->next changed in previous line
       ptr->next->prev = new; 
    */
#endif
}
 
void reverse_double(node_td **list) {
    /* empty or one element */
    if (*list == NULL || (*list)->next == NULL) {
        return;
    }
 
    node_td * ptr = *list;
    node_td * next = (*list)->next;
 
    while (next != NULL) {
        /* reverse prev and next pointers */
        ptr->next = ptr->prev;
        ptr->prev = next;
        /* move forward */
        ptr = next;
        next = next->next;
    }
    /* make last element the first one */
    ptr->next = ptr->prev;
    ptr->prev = NULL;
    *list = ptr;
}
 
void print_double(node_td * list) {
    while (list != NULL) {
        printf("%d, ", list->value);
        list = list->next;
    }
    printf("\n");
}
 
 
/*
 * Routines for double circular linked list
 */
void insert_double_circular(node_td ** list, int value) {
    node_td * new = malloc(sizeof(node_td));
    new->value = value;
    new->next = NULL;
    new->prev = NULL;
 
    /* empty list */
    if (*list == NULL) {
        *list = new;
        new->prev = new;
        new->next = new;
        return;
    }
 
    /* insert at beggining */
    if (value < (*list)->value) {
        node_td * prev = (*list)->prev;
        /* insert new node */
        new->next = *list;
        new->prev = (*list)->prev;
        /* adjust next (previoulsy first node) */
        (*list)->prev = new;
        /* adjust previous (previously last node) */
        prev->next = new;
        /* adjust list pointer */
        *list = new;
        return;
    }
                                
 
    node_td * ptr = (*list)->next;
    node_td * prev;
    while (ptr != *list && ptr->value < value) {
        ptr = ptr->next;
    }
    prev = ptr->prev;
 
    prev->next = new;
    ptr->prev = new;
    new->next = ptr;
    new->prev = prev;
}
 
void print_double_circular(node_td * list) {
 
    if (list == NULL) {
        printf("\n");
        return;
    }
    node_td *ptr = list;
    do {
        printf("%d, ", ptr->value);
        ptr = ptr->next;
    } while (ptr != list);
    printf("\n");
}
 
void reverse_double_circular(node_td ** list) {
 
    if (*list == NULL || (*list)->next == *list)
        return;
 
    node_td *ptr = *list;
    node_td *next = ptr->next;
    while(next != *list) {
        /* switch next and prev pointers */
        ptr->next = ptr->prev;
        ptr->prev = next;
        /* move forward */
        ptr = next;
        next = next->next;
    }
    /* last element becomes first */
    ptr->next = ptr->prev;
    ptr->prev = next;
 
    *list = ptr;
}
 
int main() {
    int a[5] = {3, 1, 6, 5, 9};
    int i;
 
    // --------
    printf("testing single linked list\n");
    node_ts * singlell = NULL;
    for (i = 0; i<5; i++) {
        insert_single(&singlell, a[i]);
        print_single(singlell);
    }
    reverse_single(&singlell);
    print_single(singlell);
 
    // ----------
    printf("testing double linked list\n");
    node_td * doublell = NULL;
    for (i = 0; i<5; i++) {
        insert_double(&doublell, a[i]);
        print_double(doublell);
    }
    reverse_double(&doublell);
    print_double(doublell);
 
    // ---------
    printf("testing single circular linked list\n");
    node_ts * singlec = NULL;
    for (i = 0; i<5; i++) {
        insert_singlecircular(&singlec, a[i]);
        print_singlecircular(singlec);
    }
    reverse_singlecircular(&singlec);
    print_singlecircular(singlec);
 
    // ----------
    printf("testing double circular linked list\n");
    node_td * doublecircularll = NULL;
    for (i = 0; i<5; i++) {
        insert_double_circular(&doublecircularll, a[i]);
        print_double_circular(doublecircularll);
    }
    reverse_double_circular(&doublecircularll);
    print_double_circular(doublecircularll);
 
 
    return 0;
}
