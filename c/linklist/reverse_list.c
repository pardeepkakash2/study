struct node {
        struct node *next;
        void *data;
};
void reverse(struct node *head) {
        // if list empty or one element, nothing to reverse
        if (head->next == NULL || head->next->next == NULL)
                return;
        struct node *temp;
        struct node *current = head->next->next;
        struct node *prev = head->next;
        prev->next = NULL; // first (after head) becomes last
        while (current != NULL) {
                temp = current->next;
                current->next = prev; // reverse list
                prev = current;
                current = temp;
        }
        head->next = prev; // last becomes first
}
