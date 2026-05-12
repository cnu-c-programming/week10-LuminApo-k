#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[100];
    int score;
    struct Student *next;
};

void add(struct Student **head, char name[], int score) {
    struct Student *new_node = (struct Student *)malloc(sizeof(struct Student));
    struct Student *cur;

    strcpy(new_node->name, name);
    new_node->score = score;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    cur = *head;

    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = new_node;
}

void delete(struct Student **head, char name[]) {
    struct Student *cur = *head;
    struct Student *prev = NULL;

    while (strcmp(cur->name, name) != 0) {
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL) {
        *head = cur->next;
    } else {
        prev->next = cur->next;
    }

    free(cur);
}

void print(struct Student *head) {
    struct Student *cur = head;

    while (cur != NULL) {
        printf("%s %d\n", cur->name, cur->score);
        cur = cur->next;
    }
}

void free_all(struct Student *head) {
    struct Student *cur = head;
    struct Student *next;

    while (cur != NULL) {
        next = cur->next;
        free(cur);
        cur = next;
    }
}

int main(void) {
    struct Student *head = NULL;
    char command[20];
    char name[100];
    int score;

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &score);
            add(&head, name, score);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            delete(&head, name);
        } else if (strcmp(command, "print") == 0) {
            print(head);
        } else if (strcmp(command, "quit") == 0) {
            free_all(head);
            break;
        }
    }

    return 0;
}
