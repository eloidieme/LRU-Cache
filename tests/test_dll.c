#include <criterion/criterion.h>
#include <string.h>

#include "../src/dll.h"

Test(dll_tests, create_dll) {
    dll* result = create("hello", 0, 0, NULL, NULL);
    cr_expect(strcmp(result->val, "hello") == 0, "The resulting dll contains the wrong string.");
    destroy(result);
}

Test(dll_tests, append_dll) {
    dll* base_dll = create("hello", 0, 0, NULL, NULL);
    append(base_dll, "world");
    cr_expect(base_dll->next, "The node wasn't appended to the dll.");
    cr_expect(strcmp(base_dll->next->val, "world") == 0, "The appended node contains the wrong string.");
    destroy(base_dll);
}

Test(dll_tests, prepend_dll) {
    dll* base_dll = create("hello", 0, 0, NULL, NULL);
    prepend(base_dll, "well");
    cr_expect(base_dll->prev, "The node wasn't prepended to the dll.");
    cr_expect(strcmp(base_dll->prev->val, "well") == 0, "The prepended node contains the wrong string.");
    destroy(base_dll);
}

Test(dll_tests, delete_node) {
    dll* base_dll = create("hello", 0, 0, NULL, NULL);
    append(base_dll, "world");
    delete(base_dll->next);
    cr_expect(!base_dll->next, "The node still points to an address.");
    destroy(base_dll);
}