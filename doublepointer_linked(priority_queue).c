#include <stdlib.h>
#include <stdio.h>

typedef struct l {
    int p;      // Priority
    int d;      // Data
    struct l *next;
} q;

// Function prototypes
void enq(q **, q **);
void deq(q **, q **);
void dis(q **, q **);

int main() {
    int ch;
    q *f = NULL, *r = NULL;
    
    do {
        printf("1: Insert\n2: Delete\n3: Display\n4: Peek\n5: Exit\n");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                enq(&r, &f);
                break;
            case 2:
                deq(&f, &r);
                break;
            case 3:
                dis(&f, &r);
                break;
            case 4:
                // Implement peek functionality if needed
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(ch != 5);
    
    // Free remaining nodes
    while (f != NULL) {
        q *temp = f;
        f = f->next;
        free(temp);
    }

    return 0;
}

void enq(q **r, q **f) {
    q *p = (q *)malloc(sizeof(q));
    if (p != NULL) {
        int x, pt;
        printf("Enter data: ");
        scanf("%d", &x);
        printf("Enter priority: ");
        scanf("%d", &pt);
        p->d = x;
        p->p = pt;
        p->next = NULL;

        if (*f == NULL) {
            *f = *r = p;
        } else {
            (*r)->next = p;
            *r = p;
        }
    } else {
        printf("Memory allocation failed\n");
    }
}

void deq(q **f, q **r) {
    if (*f == NULL) {
        printf("Underflow\n");
        return;
    }

    q *prev = NULL, *curr = *f, *highest = *f;
    q *highestPrev = NULL;

    // Find the node with the highest priority
    while (curr != NULL) {
        if (curr->p > highest->p) {
            highest = curr;
            highestPrev = prev;
        }
        prev = curr;
        curr = curr->next;
    }

    // Remove the highest priority node
    if (highestPrev == NULL) {
        *f = highest->next;
    } else {
        highestPrev->next = highest->next;
    }

    if (highest == *r) {
        *r = highestPrev;
    }

    printf("Removed data: %d\n", highest->d);
    free(highest);
}

void dis(q **f, q **r) {
    if (*f == NULL) {
        printf("Queue is empty\n");
        return;
    }

    q *temp = *f;
    while (temp != NULL) {
        printf("Data: %d, Priority: %d\n", temp->d, temp->p);
        temp = temp->next;
    }
}
