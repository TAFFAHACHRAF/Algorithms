SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
   SinglyLinkedListNode *last= new SinglyLinkedListNode(data);
   if(head==NULL){
        head=last;
   }
   else{
      SinglyLinkedListNode *temp=head;
      while(temp->next!=NULL){
        temp=temp->next;
      }
      temp->next=last;
   }
   return head;
}
