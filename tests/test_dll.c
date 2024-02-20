#include <criterion/criterion.h>
#include <string.h>

#include "../src/dll.h"

Test(dllTests, createDll) {
    dll* result = dllCreate("hello", 0, 0, NULL, NULL);
    cr_expect(strcmp(result->val, "hello") == 0, "The resulting dll contains the wrong string.");
    dllDestroy(result);
}

Test(dllTests, appendDll) {
    dll* base_dll = dllCreate("hello", 0, 0, NULL, NULL);
    dllAppend(base_dll, "world");
    cr_expect(base_dll->next, "The node wasn't appended to the dll.");
    cr_expect(strcmp(base_dll->next->val, "world") == 0, "The appended node contains the wrong string.");
    dllDestroy(base_dll);
}

Test(dllTests, prependDll) {
    dll* base_dll = dllCreate("hello", 0, 0, NULL, NULL);
    dllPrepend(base_dll, "well");
    cr_expect(base_dll->prev, "The node wasn't prepended to the dll.");
    cr_expect(strcmp(base_dll->prev->val, "well") == 0, "The prepended node contains the wrong string.");
    dllDestroy(base_dll);
}

Test(dllTests, deleteNode) {
    dll* base_dll = dllCreate("hello", 0, 0, NULL, NULL);
    dllAppend(base_dll, "world");
    dllDeleteNode(base_dll->next);
    cr_expect(!base_dll->next, "The node still points to an address.");
    dllDestroy(base_dll);
}