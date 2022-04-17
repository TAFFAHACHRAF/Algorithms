int getNode(SinglyLinkedListNode* llist, int positionFromTail){
    SinglyLinkedListNode *temp=llist;
    SinglyLinkedListNode *result=llist;
    int index=0;
    while(temp != NULL){
      if(index++ > positionFromTail){
        result=result->next;
      }
      temp=temp->next;
    }
    return result->data;
}
