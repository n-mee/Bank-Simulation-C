#ifndef INPUT_H
#define INPUT_H

int get_receiver_id_input();
double get_amount();
void get_pin(char* PIN);
int get_prompt_int(const char* prompt);
double get_prompt_double(const char* prompt);
bool get_yn_prompt(const char* prompt);

#endif