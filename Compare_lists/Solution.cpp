bool compare_lists(SinglyLinkedListNode *header1,SinglyLinkedListNode *header2){
   SinglyLinkedListNode *temp1=header1;
   SinglyLinkedListNode *temp2=header2;
   
    if(temp1==NULL && temp2==NULL)
      return 1;
    if(temp1!=NULL && temp2==NULL){
      return 0;
    }
    if(temp1==NULL && temp2!=NULL){
      return 0;
    }
    while(temp1 && temp2){
        if(temp1->data!=temp2->data){
          return 0;
        }
        else{
          temp1=temp1->next;
          temp2=temp2->next;
        }
      }
      if((temp1==NULL) && (temp2==NULL))
        return 1;
      else
        return  0;
}
