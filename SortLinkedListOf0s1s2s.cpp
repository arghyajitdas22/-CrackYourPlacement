/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

Node* sortList(Node *head)
{
    // Write your code here.
    Node* node0 = NULL;
    Node* node1 = NULL;
    Node* node2 = NULL;
    Node* temp = head;
    int cnt0=0,cnt1=0,cnt2=0;
    while(temp != NULL)
    {
        if(temp->data == 0)
        {
            ++cnt0;
            if(cnt0==1)
                node0 = temp;
        }
        if(temp->data == 1)
        {
            ++cnt1;
            if(cnt1==1)
                node1 = temp;
        }
        if(temp->data == 2)
        {
            ++cnt2;
            if(cnt2==1)
                node2 = temp;
        }
        if(cnt0==1 && cnt1==1 && cnt2==1)
            break;
        temp = temp->next;
    }
    temp = head;
    head = node0;
    Node* temp1 = node1;
    Node* temp2 = node2;
    cnt0=0;
    cnt1=0;
    cnt2=0;
    while(temp != NULL)
    {
        if(temp->data == 0)
        {
            ++cnt0;
            if(cnt0>1)
            {
                node0->next = temp;
                node0 = temp;
            }
        }
        if(temp->data == 1)
        {
            ++cnt1;
            if(cnt1>1)
            {
                node1->next = temp;
                node1 = temp;
            }
        }
        if(temp->data == 2)
        {
            ++cnt2;
            if(cnt2>1)
            {
                node2->next = temp;
                node2 = temp;
            }
        }
        temp = temp->next;
    }
    if(node0 != NULL)
        node0->next = temp1;
    if(node1 != NULL)
        node1->next = temp2;
    if(node2 != NULL)
        node2->next =NULL;
    if(node0 != NULL)
        return head;
    if(node0==NULL && node1!=NULL)
        head = temp1;
    else
        head = temp2;
    return head;
}
