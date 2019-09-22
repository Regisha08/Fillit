#include "fillit.h"

int             count_list(t_fig *head){
    int i=0;
    while(head!=NULL){
        i++;
        head = head->next;
    }
    return i;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void            print_list(t_fig* head){
    while (head!=NULL){
        for (int i=0;i<4;i++)
        head = head->next;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int         measure_shift_fig_side(int *xind){
    int mn=5;
    int mx=0;
    for(int i=0; i<4; i++){
        if (xind[i]<mn) mn = xind[i];
        if (xind[i]>mx) mx = xind[i];
    }
    for(int i=0; i<4; i++)
        xind[i] = xind[i]-mn;
    return(mx-mn+1);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int         shift_validate(int hash_count, int* xind, int* yind){
    int checker = measure_shift_fig_side(xind)*measure_shift_fig_side(yind);
    if (hash_count!=4) 
        return 0;
    if (checker!=6 && (checker != 4))
        return 0;
    return 1;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
t_fig*          save_fig(char* txt, int sn){
    int *xind = (int*)malloc(4*sizeof(int));
    int *yind = (int*)malloc(4*sizeof(int));
    int hash_ctr = 0;

    for(int i=0;i<20;i++){
        if (txt[i]=='#'){
            xind[hash_ctr] = i%5;
            yind[hash_ctr++] = i/5;
        }
        if (hash_ctr>4)
            return NULL;
    }
    if (shift_validate(hash_ctr, xind, yind)==0)
        return NULL;
    
    t_fig *tmp = (t_fig *)malloc(sizeof(t_fig));
    tmp->sn = sn;
    tmp->xind = xind;
    tmp->yind = yind;
    return tmp;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
t_fig*          read_figs(int fd){
    t_fig		*head=NULL;
    t_fig		*curr_fig=NULL;
    int res;
    int fig_ctr = 0;
    char buff[21];
    
    while((res = read(fd, buff, 20)) >= 0){
        if (res<19)
            return NULL;
        if (curr_fig==NULL){
            curr_fig = save_fig(buff, fig_ctr);
            head = curr_fig;
        } 
        else{
            curr_fig->next = save_fig(buff, fig_ctr);
            curr_fig = curr_fig->next;
        }
        if (curr_fig==NULL)
            return NULL;
        fig_ctr++;
        if (read(fd, buff, 1)==0)
            break;
    }
    if (res==-1)
        return NULL;
    return head;
}
