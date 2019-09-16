#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
} node;


node *create(int n)
{
    int i =0;
    node *head = NULL;
    node *tmp = NULL;
    node *p = NULL;

    for (i = 0;i <n;i++)
    {
        tmp = (node*)malloc(sizeof(node));
        printf("\nEnter :  ",i +1);
        scanf("%d",&(tmp->data));
        tmp ->next = NULL;
        if(head == NULL)
        {
            head = tmp;
        }
        else
        {
            p = head;
            while(p->next !=NULL)
                p=p->next;
            p->next = tmp;
        }
    }
    return(head);
}

void displ(node *head)
{
    node *p = head;
    hi
    while(p != NULL)
    {
        printf("\t%d->",p->data);
        p = p->next;
    }
}

int main()
{
    int n =0;
    node *HEAD = NULL;
    printf("\n How:");
    scanf("%d",&n);
    HEAD = create(n);
    displ(HEAD);
    return(0);
}
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// struct node {
//   int value;
//   struct node * next;
// };

// void reverse_inplace (struct node ** list) {
//   assert(list != NULL);
//   struct node * follow = NULL, * lead = *list;
//   while (lead != NULL) {
//     struct node * next = lead->next;
//     lead->next = follow;
//     follow = lead;
//     lead = next;
//   }
//   *list = follow;
// }

// void print (struct node const * head) {
//   printf("( ");
//   while (head) {
//     printf("%d ", head->value);
//     head = head->next;
//   }
//   printf(")");
// }

// void link (struct node * array, size_t count) {
//   struct node * follow = NULL;
//   while (count-->0) {
//     array[count].next = follow;
//     follow = &(array[count]);
//   }
// }

// void fill (struct node * list, int value, int const step) {
//   while (list != NULL) {
//     list->value = value;
//     value += step;
//     list = list->next;
//   }
// }

// int main () {
//   size_t const sizes[] = {1, 2, 6};
//   size_t const num =
//     sizeof(sizes) / sizeof(sizes[0]);
//   size_t caseId = 0;
//   for (; caseId < num; ++caseId) {
//     struct node * head =
//       malloc(sizeof(*head) * sizes[caseId]);
//     printf("Case %zu: List of size %zu\n",
//       caseId, sizes[caseId]);
//     link(head, sizes[caseId]);
//     fill(head, caseId, caseId);
//     printf("  initial: ");
//     print(head);
//     printf(" \n");
//     reverse_inplace(& head);
//     printf(" reversed: ");
//     print (head);
//     printf(" \n");
//     reverse_inplace(& head);
//     free(head);
//   }
//   printf("Case %zu: empty list \n", caseId);
//   struct node * head = NULL;
//   printf("  initial: ");
//   print(head);
//   printf(" \n");
//   reverse_inplace(& head);
//   printf("  reversed: ");
//   print(head);
//   printf(" \n");
//   return 0;
// }
// struct node 
// {
//    int          data;
//    struct node* next;
// };

// // объявить три указателя на элементы списка
// // указатель head ведет на первый элемент списка
//     struct node* head = NULL;
//     struct node* second = NULL;
//     struct node* third = NULL;
 
// // выделить память под элементы
// //  метод sizeof вычисляет размер элемента
// //  метод malloc выделяет требуемое количество памяти
// // установить указатели на выделенные фрагменты памяти
//     head   = malloc(sizeof(struct node));
//     second = malloc(sizeof(struct node));
//     third  = malloc(sizeof(struct node));
 
// // инициализировать элементы списка и связать их между собой
//     head->data = 1;
//     head->next = second;
//     second->data = 2;
//     second->next = third;
//     third->data = 3;
//     third->next = NULL;

//     int Length(struct node* head) 
// {
//     struct node* current = head;
//     int count = 0;
//     while (current != NULL) 
//     {
//             count++;
//             current = current->next;
//     }
//     return count;
// }
// struct node* AppendNode(struct node** headRef, int num) 
// {
//    struct node* current = *headRef;
//    struct node* newNode;
//    newNode = malloc(sizeof(struct node));
//    newNode->data = num;
//    newNode->next = NULL;
//    // если список пуст
//    if (current == NULL) {
//       *headRef = newNode;
//    }
//    else {
//       // иначе
//       while (current->next != NULL) {
//           current = current->next;
//       }
//       current->next = newNode;
//    }
// }

// struct list
// {
//   int field; // поле данных
//   struct list *ptr; // указатель на следующий элемент
// };

// struct list * init(int a) // а- значение первого узла
// {
//   struct list *lst;
//   // выделение памяти под корень списка
//   lst = (struct list*)malloc(sizeof(struct list));
//   lst->field = a;
//   lst->ptr = NULL; // это последний узел списка
//   return(lst);
// }
// void listprint(list *lst)
// {
//   struct list *p;
//   p = lst;
//   do {
//     printf("%d ", p->field); // вывод значения элемента p
//     p = p->ptr; // переход к следующему узлу
//   } while (p != NULL);
// }
// Односвязный линейный список (ОЛС)
// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// #include <stdlib.h>
// #include <malloc.h>
// struct list
// {
// 	int field;
// 	struct list *ptr;
// };
// // Инициализация списка (ОЛС)
// struct list * init(int a)
// {
// 	struct list *lst;
// 	lst = (struct list*)malloc(sizeof(struct list)); // выделение памяти под корень списка
// 	lst->field = a;
// 	lst->ptr = NULL;			// это последний элемент списка
// 	return(lst);
// }
// // Добавление элемента (возвращает добавленный элемент) (ОЛС)
// struct list * addelem(list *lst, int number)
// {
// 	struct list *temp, *p;
// 	temp = (struct list*)malloc(sizeof(list)); // выделение памяти под узел списка
// 	p = lst->ptr;				// временное сохранение указателя
// 	lst->ptr = temp;			// предыдущий узел указывает на создаваемый
// 	temp->field = number;		// сохранение поля данных добавляемого узла
// 	temp->ptr = p;			// созданный узел указывает на следующий элемент
// 	return(temp);
// }

// // Удаление корня списка (возвращает новый корень) (ОЛС)
// struct list * deletehead(list *root)
// {
// 	struct list *temp;
// 	temp = root->ptr;
// 	free(root);
// 	return(temp); // новый корень списка
// }

// // Удаление элемента списка (возвращает предшествующий элемент) (ОЛС)
// struct list  * deletelem(list *lst, list *root)
// {
// 	struct list *temp;
// 	temp = root;
// 	while (temp->ptr != lst)				// просматриваем список начиная с корня
// 	{				// пока не найдем узел, предшествующий lst
// 		temp = temp->ptr;
// 	}
// 	temp->ptr = lst->ptr; // переставляем указатель
// 	free(lst);		// освобождаем память удаляемого элемента
// 	return(temp);
// }

// // Вывод элементов списка (ОЛС)
// void listprint(list *lst)
// {
// 	struct list *p;
// 	p = lst;
// 	do {
// 		printf("%d ", p->field);	// вывод значения элемента p
// 		p = p->ptr;				// переход к следующему элементу
// 	} while (p != NULL);
// }
// // Взаимообмен узлов списка (возвращает корень списка) (ОЛС)
// struct list * swap(struct list *lst1, struct list *lst2, struct list *head) {
// 	// Возвращает новый корень списка
// 	struct list *prev1, *prev2, *next1, *next2;
// 	prev1 = head;
// 	prev2 = head;
// 	if (prev1 == lst1)
// 		prev1 = NULL;
// 	else
// 		while (prev1->ptr != lst1) // поиск узла предшествующего lst1
// 			prev1 = prev1->ptr;
// 	if (prev2 == lst2)
// 		prev2 = NULL;
// 	else
// 		while (prev2->ptr != lst2) // поиск узла предшествующего lst2
// 			prev2 = prev2->ptr;
// 	next1 = lst1->ptr;  // узел следующий за lst1
// 	next2 = lst2->ptr;  // узел следующий за lst2
// 	if (lst2 == next1)	{     // обмениваются соседние узлы
// 		lst2->ptr = lst1;
// 		lst1->ptr = next2;
// 		if (lst1 != head)
// 			prev1->ptr = lst2;
// 	}
// 	else if (lst1 == next2) { // обмениваются соседние узлы
// 		lst1->ptr = lst2;
// 		lst2->ptr = next1;
// 		if (lst2 != head)
// 			prev2->ptr = lst2;
// 		}
// 	else  {		// обмениваются отстоящие узлы
// 		if (lst1 != head)
// 			prev1->ptr = lst2;
// 		lst2->ptr = next1;
// 		if (lst2 != head)
// 			prev2->ptr = lst1;
// 		lst1->ptr = next2;
// 		}
// 	if (lst1 == head)
// 		return(lst2);
// 	if (lst2 == head)
// 		return(lst1);
// 	return(head);
// }
// // Односвязный циклический список (ОЦС)
// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// #include <stdlib.h>
// #include <malloc.h>

// struct list
// {
//  int field;
//  struct list *ptr;
// };

// // Инициализация списка (ОЦС)
// struct list * init(int a)
// {
//   struct list *lst;
//   lst = (struct list*)malloc(sizeof(struct list)); // выделение памяти под корень списка
//   lst->field = a;
//   lst->ptr = lst;						// это последний элемент списка
//   return(lst);
// }

// // Добавление узла (возвращает предшествующий элемент) (ОЦС)
// struct list * addelem(list *lst, int number)
// {
//   struct list *temp, *p;
//   temp = (struct list*)malloc(sizeof(list)); // выделение памяти под узел списка
//   p = lst->ptr;				// временное сохранение указателя
//   lst->ptr = temp;			// предыдущий узел указывает на создаваемый
//   temp->field = number;		// сохранение поля данных добавляемого узла
//   temp->ptr = p;				// созданный узел указывает на следующий элемент
//   return(temp);
// }

// // Удаление корня (возвращает новый корень) (ОЦС)
// struct list * deletehead(list *root)
// {
//   struct list *temp;
//   temp = root->ptr;
//   free(root);
//   return(temp); // новый корень списка
// }

// // Удаление узла (возвращает предшествующий элемент) (ОЦС)
// struct list  * deletelem(list *lst, list *root)
// {
//   struct list *temp;
//   temp = root;
//   while (temp->ptr != lst)				// просматриваем список начиная с корня
//   {				// пока не найдем узел, предшествующий lst
//     temp = temp->ptr;
//   }
//   temp->ptr = lst->ptr; // переставляем указатель
//   free(lst);		// освобождаем память удаляемого элемента
//   return(temp);
// }

// // Вывод узлов списка (ОЦС)
// void listprint(list *lst)
// {
//   struct list *p;
//   p = lst;
//   do {
//   printf("%d ", p->field);	// вывод значения элемента p
//   p = p->ptr;				// переход к следующему элементу
//   } while (p != lst);
// }
// // Взаимообмен узлов списка (ОЦС)
// struct list * swap(struct list *lst1, struct list *lst2, struct list *head) 
// {
//   // Возвращает новый корень списка
//   struct list *prev1, *prev2, *next1, *next2;
//   prev1 = head;
//   prev2 = head;
//   while (prev1->ptr != lst1) // поиск узла предшествующего lst1
//  	prev1 = prev1->ptr;
//   while (prev2->ptr != lst2) // поиск узла предшествующего lst2
// 	prev2 = prev2->ptr;
//   next1 = lst1->ptr; // узел следующий за lst1
//   next2 = lst2->ptr; // узел следующий за lst2
//   if (lst2 == next1) {
// 	// обмениваются соседние узлы
// 	lst2->ptr = lst1;
// 	lst1->ptr = next2;
// 	prev1->ptr = lst2;
//   }
//   else if (lst1 == next2) {
// 	// обмениваются соседние узлы
// 	lst1->ptr = lst2;
// 	lst2->ptr = next1;
// 	prev2->ptr = lst2;
//   }
//   else {
// 	// обмениваются отстоящие узлы
// 	prev1->ptr = lst2;
// 	lst2->ptr = next1;
// 	prev2->ptr = lst1;
// 	lst1->ptr = next2;
//   }
//   if (lst1 == head)
//   	return(lst2);
//   if (lst2 == head)
// 	return(lst1);
//   return(head);
// }

// // Основная программа: поменять местами первый четный элемент с последним
// // Можно использовать как с ОЛС, так и с ОЦС
// int main()
// {
// 	struct list *head, *r, *p;
// 	int a, n;
// 	system("chcp 1251");
// 	system("cls");
// 	printf("n= ");
// 	scanf("%d",&n);
// 	head = 0;
// 	p = 0;
// 	// Создание списка
// 	for (int i = 0; i<n; i++)
// 	{
// 		printf("Введите элемент:");
// 		scanf("%d", &a);
// 		if (i == 0)
// 		{
// 			p = init(a);
// 			head = p;
// 		}
// 		else
// 			p = addelem(p, a);
// 	}
// 	// Вывод списка
// 	listprint(head);
// 	// Поиск элемента, кратного 2
// 	r = head;
// 	do
// 	{
// 		if (r->field % 2 == 0)
// 			break;
// 		r = r->ptr;
// 	} while (r != NULL);
// 	// r - первый элемент кратный 2
// 	// p - последний добавленный элемент
// 	head = swap(r, p, head);

// 	printf("\n");
// 	listprint(head);
// 	getchar(); getchar();
// 	return 0;
// }




// #include <stdio.h> 
 
// struct Node{
//   Node* next;
//   int data;
// };
 
// void push_back(Node **head, Node **last, int data){
//   Node *node = new Node;
//   node->next = NULL;
//   node->data = data;
//   if (*last != NULL)
//     (*last)->next = node;
//   *last = node;
//   if (*head == NULL)
//     *head = *last;
// }
 
// void print(Node *head){
//   while (head != NULL){
//     std::cout <data <next;
//   }
// }
 
// int main(){
//   Node *head = NULL, *last = NULL;
//   for (int i = 0; i < 100; i++){
//     push_back(&head, &last, i);
//   }
//   print(head);
//   return 0;
// }