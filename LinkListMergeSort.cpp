#define SWAP(a,b){ int t; t = a; a = b; b = t; }

inline int partition(E number[], int left, int right)
{
    int i, j, s;

    s = number[right];
    i = left-1;

    for(j = left; j < right; j++){
        if(number[j] <= s){
            i++;
            SWAP(number[i],number[j]);
        }
    }
    SWAP(number[i+1], number[right]);
    return i+1;
}

inline LinkedList::node* merge(LinkedList::node* left, LinkedList::node* right)
{
    LinkedList::node* mid = new LinkedList::node(0);
    LinkedList::node* temp = mid;
    while(left != NULL && right != NULL){
        if(left->data <= right->data){
            temp->next = left;
            left->prev = temp;
            temp = temp->next;
            left = left->next;
        }
        else{
            temp->next = right;
            right->prev = temp;
            temp = temp->next;
            right = right->next;
        }
    }
    if(left != NULL){
        temp->next = left;
        left->prev = temp;
    }
    if(right != NULL){
        temp->next = right;
        right->prev = temp;
    }
    temp = mid->next;
    delete mid;
    return temp;
}

inline LinkedList::node* mergeSort(LinkedList::node* head)
{
    if(head->next == NULL)
        return head;
    LinkedList::node *pHead, *qHead, *pre;
    LinkedList::node *left, *right;
    pHead = qHead = head;
    pre = NULL;
    while(qHead != NULL && qHead->next != NULL){
        qHead = qHead->next->next;
        pre = pHead;
        pHead = pHead->next;
    }
    pre->next = NULL;
    left = mergeSort(head);
    right = mergeSort(pHead);
    return merge(left,right);
}



