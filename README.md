# Existential Types in C
This is a short proof of concept for existential types in C, i.e. having a data structure that has a private definition and only public operations on it.

The implementation is based on [Handles are the better pointers](https://floooh.github.io/2018/06/17/handles-vs-pointers.html) by [Andre Weissflog](https://twitter.com/flohofwoe) where instead of working with raw pointers to a struct, you instead move all instances of a given struct type into one place (called a _system_) and only operate with handles in the public API.

Since only handles are used publically, the implementation details of a struct can be moved into the `.c` file and thus a data structure like a `stack` can be defined safely in C without the need for forward declaring the struct and returning a pointer to a heap allocated instance, which is a common way of doing data hiding in C.

```C
// stack.h
void stack_init(); // initialize stack system
stack_id_t stack_create(size_t item_size);
void stack_destroy(stack_id_t stack_id);
void stack_push(stack_id_t stack_id, void* item);
void* stack_pop(stack_id_t stack_id);
bool stack_is_empty(stack_id_t stack_id);
```

Note: This proof of concept does not take propper care in the handling of the stack IDs.
