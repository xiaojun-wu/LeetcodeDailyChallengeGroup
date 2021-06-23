        /*
        imaging if left to right is a queue,
        there are "1 2 3 4 5" numbers in queue.
        cur is 1, how to reverse them?
        put the cur->next to the front of queue until cur at the end of queue.
        step1:
        2 1 3 4 5
        step2:
        3 2 1 4 5
        step3:
        4 3 2 1 5
        step4:
        5 4 3 2 1
        */
        ListNode *preHead = new ListNode(0),*pre = preHead, *cur, *temp;
        preHead->next = head;
        for(int i = 1;i < left;i++)
            pre = pre->next;
        cur = pre->next;
        for(int i = left;i < right;i++){
            temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return preHead->next;