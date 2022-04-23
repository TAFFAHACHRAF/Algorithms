ReverseDoublyLinkedListe(DoublyLinkedListe *llist){
	DoublyLinkedListe *temp=NULL,curr=llist;
	while(curr != NULL){
		temp=curr->prev;
		curr->curr->next;
		curr->next=temp;
		curr=curr->prev;
	}
	if(temp != NULL)
	   llist=temp->prev;
	   
	return llist;
}
