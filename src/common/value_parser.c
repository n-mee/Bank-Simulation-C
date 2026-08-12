#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include "cli/displays.h"
#include "common/value_parser.h"

ParsedStringResult string_parser(const char* text, char* out_str, size_t size_limit) {
    if (text == NULL || out_str == NULL || size_limit == 0) {
        return ERR_STRING_NULL_PTR;
    }

    while (*text == ' ' || *text == '\t' || *text == '\n') text++;

    if (*text == '\0') {
        *out_str = '\0';
        return ERR_EMPTY_STRING;
    }

    size_t t_len = strlen(text);

    while (t_len > 0 && (text[t_len - 1] == ' ' || text[t_len - 1] == '\t' || text[t_len - 1] == '\n')) {
        t_len--;
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

ParseExitResult amount_parser(const char* text, long long* out_n) {
    char* end = NULL;
    errno = 0;

    long long dollar  = strtoll(text, &end, 10);

    if (end == text) return ERR_NULL_PTR;
    if (errno == ERANGE) return ERR_OVERFLOW;
    if (dollar < 0) return ERR_NEGATIVE;

    long long cents = 0;

    if (*end == '.') {
        char* cents_firstval = end + 1;
        char* cents_endval = NULL;

        cents = strtoll(cents_firstval, &cents_endval, 10);

        if (cents_endval == cents_firstval) return ERR_NULL_PTR;
        if (cents < 0 || cents > 99) return ERR_TRAILING_GARBAGE;

        if (cents_endval - cents_firstval == 1) {
            cents *= 10;
        }

        end = cents_endval;
    }

    while(*end == ' ' || *end == '\t' || *end == '\n') end++;
    if(*end != '\0') return ERR_TRAILING_GARBAGE;

    *out_n = (dollar * 100) + cents;
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