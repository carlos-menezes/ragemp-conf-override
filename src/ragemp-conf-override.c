#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>

static const char *replacement_path = NULL;

__attribute__((constructor))
static void init() {
    replacement_path = getenv("CONF_JSON_PATH");
}

FILE *fopen(const char *pathname, const char *mode) {
    static FILE *(*original_fopen)(const char *, const char *) = NULL;
    if (!original_fopen) {
        original_fopen = dlsym(RTLD_NEXT, "fopen");
    }

    if (strcmp(pathname, "conf.json") == 0 && replacement_path) {
        return original_fopen(replacement_path, mode);
    }

    return original_fopen(pathname, mode);
}