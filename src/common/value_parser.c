#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cli/displays.h"
#include "common/value_parser.h"

void get_string_prompt(const char* prompt, char* output_buffer, int buffer_size) {
    while (true) {
        printf("%s", prompt);
        if (fgets(output_buffer, buffer_size, stdin) != NULL) {
            if (strchr(output_buffer, '\n') == NULL) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF); 
            }
            output_buffer[strcspn(output_buffer, "\n")] = '\0';
            if (strlen(output_buffer) > 0) {
                return;
            }
        }
        empty_string_input();
    }
}

ParsedStringResult string_parser(const char* text, char* out_str, size_t size_limit) {
    if (text == NULL || text == NULL || size_limit == 0) {
        return ERR_STRING_NULL_PTR;
    }

    while (*text == ' ' || *text == '\t' || *text == '\n') text++;

    if (*text == '\0') {
        *out_str = '\0';
        return ERR_EMPTY_STRING;
    }

    size_t t_len = strlen(text);

    while (t_len > 0 && (text[t_len - 1] == ' ' || text[t_len - 1] == '\t' || text[t_len - 1] == '\n')) {
        text --;
    }

    if (t_len >= size_limit) return ERR_EXCEEDED_MAX_SIZE;

    strncpy(out_str, text, t_len);
    out_str[t_len] = '\0';

    return PARSED_STRING_SUCCESS;
}


ParseExitResult int_parser(const char* text, int* out_n) {
    char* end = NULL;
    long value = strtol(text, &end, 10);

    if (end == text) return ERR_NULL_PTR;

    while(*end == ' ' || *end == '\t' || *end == '\n') end++;
    if(*end != '\0') return ERR_TRAILING_GARBAGE;

    *out_n = (int)value;
    return PARSE_SUCCESS;
}

ParseExitResult double_parser(const char* text, double* out_n) {
    char* end = NULL;
    long value = strtod(text, &end);

    if (end == text) return ERR_NULL_PTR;

    while(*end == ' ' || *end == '\t' || *end == '\n') end++;
    if(*end != '\0') return ERR_TRAILING_GARBAGE;

    *out_n = (double)value;
    return PARSE_SUCCESS;
}

YesNoResult yn_parser(const char* text, bool* out_v) {
    char buffer[16];
    size_t buf_size = strlen(text);

    if (buf_size >= sizeof(buffer)) return ERR_INPUT_EXCEED_RANGE;

    for (size_t i = 0; i < buf_size; i++) buffer[i] = (char)tolower((unsigned char)text[i]);
    buffer[buf_size] = '\0';

    if (strcmp(buffer, "yes") == 0 || strcmp(buffer, "y") == 0) { *out_v = true; return YN_SUCCESS; }
    if (strcmp(buffer, "no") == 0 || strcmp(buffer, "n") == 0) { *out_v = false; return YN_SUCCESS; }
    return ERR_INVALID_INPUT;
}