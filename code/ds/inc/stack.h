//
// Created by admin on 25-6-18.
//

#ifndef STACK_H
#define STACK_H

#include <dl_list.h>

typedef dl_list stack;
typedef dl_list stack_node;

#define stack_push      dl_list_insert_back()
#define stack_pop       dl_list_remove_back()
#define stack_peek(V)   (V)->tail

#endif //STACK_H
