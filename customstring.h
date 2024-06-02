
#include "types.h"

typedef enum e_str_result {
	RESULT_OK = 0x0000,
	INVALID_PARAM_1 = 0x0001,
	INVALID_PARAM_2 = 0x0002,
	INVALID_PARAM_3 = 0x0004,
	BUFFER_SIZE_ERROR = 0x0008
}t_str_result;


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
