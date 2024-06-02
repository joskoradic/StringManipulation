This project is released under MIT licence
Project contains custom string manipulation functions.
I started this project because I needed safer functions for manipulating strings while using it on the microcontrollers

Copyright (c) <2018> <Josko Radic>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


int32_t string_find(uint8_t* buff_old, uint8_t* buff_new);
int32_t string_length_ver2(uint8_t* buff);
bool string_compare(uint8_t* str1, uint8_t* str2);
void str_integer_to_string(uint8_t* string_out, int32_t value);
void str_hex_to_string(uint8_t* hex, uint32_t data);
int32_t str_string_concatanate(uint8_t* existing_str, uint8_t* new_str, int32_t first_position);
int32_t str_string_add_integer(uint8_t* existing_str, int32_t integer, int32_t first_position);
void str_float_to_string(uint8_t* str, float test);
int32_t str_add_float(uint8_t* existing_str, float float_var, int32_t first_position);
int32_t string_substring(uint8_t* buff_in, uint8_t* buff_out, uint32_t start, uint32_t stop);
int32_t string_substring_to(uint8_t* buff_in, uint8_t* buff_out, int32_t start, uint8_t* end_str);
int32_t str_trim(uint8_t* buff, uint8_t* buff2);
int32_t string_substring(uint8_t* buff_in, uint8_t* buff_out, int32_t start, int32_t stop);
