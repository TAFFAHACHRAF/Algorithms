void reversePrint(SinglyLinkedListNode* llist) {
      if(llist==NULL)
        return;
      reversePrint(llist->next);
      cout << llist->data << "\n";
}
