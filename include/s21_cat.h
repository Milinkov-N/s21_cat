#ifndef S21_CAT_H_
#define S21_CAT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#define true 1
#define false 0

typedef int bool_t;

typedef struct options {
  bool_t num_nonblank;
  bool_t mark_eol;
  bool_t num_all;
  bool_t squeeze_blank;
  bool_t mark_tabs;
  bool_t mark_nonprintable;
} options_t;

typedef enum option_enum {
    OPT_INVLAID = -1,
    OPT_NUM_NONBLANK,
    OPT_MARK_EOL,
    OPT_NUM_ALL,
    OPT_SQUEEZE_BLANK,
    OPT_MARK_TABS,
    OPT_MARK_NONPRINTABLE,
} optvar_t;

/* @brief Reads file and writes it contents in `outbuf` variable
 * @param filename: Name of file to read
 * @param outbuf: Out buffer for file contents (dynamically allocated, should be
 * nullptr when passed)
 * @return `size_t` Bytes read
 */
size_t read_file(const char* filename, char* outbuf);

/* @brief Determines if given string is an cli option (starts with '-' or '--')
 * @param str: Input string to be analyzed
 * @return `bool_t` Boolean if its option or not
 */
bool_t is_opt(const char* str);

/* @brief Determines if given string is an long cli option (starts with '-')
 * @param str: Input string to be analyzed
 * @return `bool_t` Boolean if its long option or not
 */
bool_t is_longopt(const char* str);

/* @brief Determines if given string is an short cli option (starts with '--')
 * @param str: Input string to be analyzed
 * @return `bool_t` Boolean if its short option or not
 */
bool_t is_shortopt(const char* str);

/* @brief Determines if a given character is a valid option
 * @param ch: Input character
 * @return `optvar_t` Corresponding enum variant
 */
optvar_t shortopt_lookup(const char ch);

/* @brief Determines if a given string is a valid option
 * @param str: Input string
 * @return `optvar_t` Corresponding enum variant
 */
optvar_t longopt_lookup(const char* str);

#ifdef __cplusplus
}
#endif

#endif  // S21_CAT_H_
