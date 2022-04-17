void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *temp;
    temp=head;
    while(temp!=NULL){
      cout << temp->data << "\n";
      temp=temp->next;
    }
    cout <<endl;
}
