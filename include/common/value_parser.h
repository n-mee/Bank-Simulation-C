#ifndef VALUE_PARSER_H
#define VALUE_PARSER_H

#include "common/exit_status.h"

/**
 * @brief converts a string value into a integer
 * @param text string reference
 * @param out_n reference to pass the converted value
 * @return returns exit status code depending on operation result
 */
ParseExitResult int_parser(const char* text, int* out_n);

/**
 * @brief converts string into a double long value, mostly used in balanec
 * @param text string reference
 * @param out_n reference to pass the converted value
 * @return returns exit status code depending on operation result
 */
ParseExitResult amount_parser(const char* text, long long* out_n);

/**
 * @brief converts string 'yes' or 'no' into a boolean
 * @param text string reference
 * @param out_v reference to pass the converted value
 * @return returns exit status code depending on operation result
 */
YesNoResult yn_parser(const char* text, bool* out_v);

/**
 * @brief custom string parser that gets input
 * @param text string reference
 * @param out_str passes the string back to the reference
 * @param size_limit size limit of the str reference
 * @return exit status code depending on operation status
 */
ParsedStringResult string_parser(const char* text, char* out_str, size_t size_limit);

#endif