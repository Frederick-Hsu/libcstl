/*
 *  The implementation of string test.
 *  Copyright (C)  2008 2009  Wangbo
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *  Author e-mail: activesys.wb@gmail.com
 *                 activesys@sina.com.cn
 */

/** include section **/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "cstring.h"
#include "test_string.h"

/** local constant declaration and local macro section **/

/** local data type declaration and local struct, union, enum section **/

/** local function prototype section **/
static void _printstring(const string_t* cpt_string);

/** exported global variable definition section **/

/** local global variable definition section **/

/** exported function implementation section **/
void test_basic_string(void)
{
}

void test_string(int argc, char* argv[])
{
    /*create_string                     */
    {
        string_t* pt_string = create_string();
        if(pt_string == NULL)
        {
            return;
        }
        string_init(pt_string);
        _printstring(pt_string);
        string_destroy(pt_string);
    }
    /*string_init                       */
    /*string_init_cstr                  */
    {
        string_t* pt_string = create_string();
        if(pt_string == NULL)
        {
            return;
        }
        string_init_cstr(pt_string, "libcstl-2.0.0");
        _printstring(pt_string);
        string_destroy(pt_string);
    }
    /*string_init_subcstr               */
    {
        string_t* pt_string = create_string();
        if(pt_string == NULL)
        {
            return;
        }
        string_init_subcstr(pt_string, "libcstl-2.0.0", NPOS);
        _printstring(pt_string);
        string_destroy(pt_string);
    }
    /*string_init_char                  */
    {
        string_t* pt_string = create_string();
        if(pt_string == NULL)
        {
            return;
        }
        string_init_char(pt_string, 8, 'h');
        _printstring(pt_string);
        string_destroy(pt_string);
    }
    /*string_init_copy                  */
    {
        string_t* pt_string = create_string();
        string_t* pt_stringex = create_string();
        if(pt_string == NULL || pt_stringex == NULL)
        {
            return;
        }
        string_init_cstr(pt_stringex, "activesys.wb@gmail.com");
        _printstring(pt_stringex);
        string_init_copy(pt_string, pt_stringex);
        _printstring(pt_string);
        string_destroy(pt_string);
        string_destroy(pt_stringex);
    }
    /*string_init_copy_substring        */
    {
        string_t* pt_string = create_string();
        string_t* pt_stringex = create_string();
        if(pt_string == NULL || pt_stringex == NULL)
        {
            return;
        }
        string_init_cstr(pt_stringex, "China");
        _printstring(pt_stringex);
        string_init_copy_substring(pt_string, pt_stringex, 1, NPOS);
        _printstring(pt_string);
        string_destroy(pt_string);
        string_destroy(pt_stringex);
    }
    /*string_init_copy_range            */
    {
        string_t* pt_string = create_string();
        string_t* pt_stringex = create_string();
        if(pt_string == NULL || pt_stringex == NULL)
        {
            return;
        }
        string_init_cstr(pt_stringex, "CHINA");
        _printstring(pt_stringex);
        string_init_copy_range(pt_string, string_begin(pt_stringex), string_end(pt_stringex));
        _printstring(pt_string);
        string_destroy(pt_string);
        string_destroy(pt_stringex);
    }
    /*string_destroy                    */
    /*string_c_str                      */
    {
        string_t* pt_string = create_string();
        if(pt_string == NULL)
        {
            return;
        }
        string_init_cstr(pt_string, "LIBCSTL-CSTRING");
        _printstring(pt_string);
        printf("c_str : %s\n", string_c_str(pt_string));
        printf("data  : %s\n", string_data(pt_string));
        string_destroy(pt_string);
    }
    /*string_data                       */
    /*string_copy                       */
    {
        string_t* pt_string = create_string();
        char sz_buf[31] = {'\0'};
        if(pt_string == NULL)
        {
            return;
        }
        string_init_cstr(pt_string, "test_string.c");
        _printstring(pt_string);
        string_copy(pt_string, sz_buf, 0, 0);
        puts(sz_buf);
        string_copy(pt_string, sz_buf, 5, 0);
        puts(sz_buf);
        memset(sz_buf, '\0', 31);
        string_copy(pt_string, sz_buf, 13, 0);
        puts(sz_buf);
        memset(sz_buf, '\0', 31);
        string_copy(pt_string, sz_buf, 40, 0);
        puts(sz_buf);
        memset(sz_buf, '\0', 31);
        string_copy(pt_string, sz_buf, NPOS, 0);
        puts(sz_buf);

        memset(sz_buf, '\0', 31);
        string_copy(pt_string, sz_buf, 0, 5);
        puts(sz_buf);
        memset(sz_buf, '\0', 31);
        string_copy(pt_string, sz_buf, 6, 5);
        puts(sz_buf);
        memset(sz_buf, '\0', 31);
        string_copy(pt_string, sz_buf, 8, 5);
        puts(sz_buf);
        memset(sz_buf, '\0', 31);
        string_copy(pt_string, sz_buf, 40, 5);
        puts(sz_buf);
        memset(sz_buf, '\0', 31);
        string_copy(pt_string, sz_buf, NPOS, 5);
        puts(sz_buf);
        string_destroy(pt_string);
    }
    /*string_size                       */
    /*string_length                     */
    /*string_empty                      */
    /*string_max_size                   */
    /*string_capacity                   */
    /*string_at                         */
    {
        string_t* pt_string = create_string();
        if(pt_string == NULL)
        {
            return;
        }
        string_init_cstr(pt_string, "CHINA");
        _printstring(pt_string);
        printf("%c\n", *string_at(pt_string, 0));
        printf("%c\n", *string_at(pt_string, 4));
        printf("%c\n", *string_at(pt_string, string_length(pt_string)));
        *string_at(pt_string, 4) = 'K';
        _printstring(pt_string);
        string_destroy(pt_string);
    }
    /*string_equal                      */
    {
        string_t* pt_string1 = create_string();
        string_t* pt_string2 = create_string();
        if(pt_string1 == NULL || pt_string2 == NULL)
        {
            return;
        }
        string_init(pt_string1);
        string_init(pt_string2);
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("equal : %d, not equal : %d, ",
            string_equal(pt_string1, pt_string2), string_not_equal(pt_string1, pt_string2));
        printf("less : %d, less equal : %d, ",
            string_less(pt_string1, pt_string2), string_less_equal(pt_string1, pt_string2));
        printf("great : %d, great equal : %d\n",
            string_great(pt_string1, pt_string2), string_great_equal(pt_string1, pt_string2));

        string_assign_cstr(pt_string1, "abc");
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("equal : %d, not equal : %d, ",
            string_equal(pt_string1, pt_string2), string_not_equal(pt_string1, pt_string2));
        printf("less : %d, less equal : %d, ",
            string_less(pt_string1, pt_string2), string_less_equal(pt_string1, pt_string2));
        printf("great : %d, great equal : %d\n",
            string_great(pt_string1, pt_string2), string_great_equal(pt_string1, pt_string2));

        string_assign_cstr(pt_string2, "abc");
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("equal : %d, not equal : %d, ",
            string_equal(pt_string1, pt_string2), string_not_equal(pt_string1, pt_string2));
        printf("less : %d, less equal : %d, ",
            string_less(pt_string1, pt_string2), string_less_equal(pt_string1, pt_string2));
        printf("great : %d, great equal : %d\n",
            string_great(pt_string1, pt_string2), string_great_equal(pt_string1, pt_string2));

        string_assign_cstr(pt_string1, "opq");
        string_assign_cstr(pt_string2, "xyz");
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("equal : %d, not equal : %d, ",
            string_equal(pt_string1, pt_string2), string_not_equal(pt_string1, pt_string2));
        printf("less : %d, less equal : %d, ",
            string_less(pt_string1, pt_string2), string_less_equal(pt_string1, pt_string2));
        printf("great : %d, great equal : %d\n",
            string_great(pt_string1, pt_string2), string_great_equal(pt_string1, pt_string2));

        string_assign_cstr(pt_string1, "mn");
        string_assign_cstr(pt_string2, "mno");
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("equal : %d, not equal : %d, ",
            string_equal(pt_string1, pt_string2), string_not_equal(pt_string1, pt_string2));
        printf("less : %d, less equal : %d, ",
            string_less(pt_string1, pt_string2), string_less_equal(pt_string1, pt_string2));
        printf("great : %d, great equal : %d\n",
            string_great(pt_string1, pt_string2), string_great_equal(pt_string1, pt_string2));

        string_assign_cstr(pt_string1, "u");
        string_assign_cstr(pt_string2, "abcdefghijklmnopqrstuvwxyz");
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("equal : %d, not equal : %d, ",
            string_equal(pt_string1, pt_string2), string_not_equal(pt_string1, pt_string2));
        printf("less : %d, less equal : %d, ",
            string_less(pt_string1, pt_string2), string_less_equal(pt_string1, pt_string2));
        printf("great : %d, great equal : %d\n",
            string_great(pt_string1, pt_string2), string_great_equal(pt_string1, pt_string2));

        string_destroy(pt_string1);
        string_destroy(pt_string2);
    }
    /*string_not_equal                  */
    /*string_less                       */
    /*string_less_equal                 */
    /*string_great                      */
    /*string_great_equal                */
    /*string_equal_cstr                 */
    {
        string_t* pt_string = create_string();
        if(pt_string == NULL)
        {
            return;
        }
        string_init(pt_string);
        _printstring(pt_string);
        puts("");
        printf("equal : %d, not equal : %d, ",
            string_equal_cstr(pt_string, ""), string_not_equal_cstr(pt_string, ""));
        printf("less : %d, less equal : %d, ",
            string_less_cstr(pt_string, ""), string_less_equal_cstr(pt_string, ""));
        printf("great : %d, great equal : %d\n",
            string_great_cstr(pt_string, ""), string_great_equal_cstr(pt_string, ""));

        string_assign_cstr(pt_string, "abc");
        _printstring(pt_string);
        puts("");
        printf("equal : %d, not equal : %d, ",
            string_equal_cstr(pt_string, ""), string_not_equal_cstr(pt_string, ""));
        printf("less : %d, less equal : %d, ",
            string_less_cstr(pt_string, ""), string_less_equal_cstr(pt_string, ""));
        printf("great : %d, great equal : %d\n",
            string_great_cstr(pt_string, ""), string_great_equal_cstr(pt_string, ""));

        _printstring(pt_string);
        puts("abc");
        printf("equal : %d, not equal : %d, ",
            string_equal_cstr(pt_string, "abc"), string_not_equal_cstr(pt_string, "abc"));
        printf("less : %d, less equal : %d, ",
            string_less_cstr(pt_string, "abc"), string_less_equal_cstr(pt_string, "abc"));
        printf("great : %d, great equal : %d\n",
            string_great_cstr(pt_string, "abc"), string_great_equal_cstr(pt_string, "abc"));

        string_assign_cstr(pt_string, "opq");
        _printstring(pt_string);
        puts("xyz");
        printf("equal : %d, not equal : %d, ",
            string_equal_cstr(pt_string, "xyz"), string_not_equal_cstr(pt_string, "xyz"));
        printf("less : %d, less equal : %d, ",
            string_less_cstr(pt_string, "xyz"), string_less_equal_cstr(pt_string, "xyz"));
        printf("great : %d, great equal : %d\n",
            string_great_cstr(pt_string, "xyz"), string_great_equal_cstr(pt_string, "xyz"));

        string_assign_cstr(pt_string, "mn");
        _printstring(pt_string);
        puts("mno");
        printf("equal : %d, not equal : %d, ",
            string_equal_cstr(pt_string, "mno"), string_not_equal_cstr(pt_string, "mno"));
        printf("less : %d, less equal : %d, ",
            string_less_cstr(pt_string, "mno"), string_less_equal_cstr(pt_string, "mno"));
        printf("great : %d, great equal : %d\n",
            string_great_cstr(pt_string, "mno"), string_great_equal_cstr(pt_string, "mno"));

        string_assign_cstr(pt_string, "u");
        _printstring(pt_string);
        puts("abcdefghijklmnopqrstuvwxyz");
        printf("equal : %d, not equal : %d, ",
            string_equal_cstr(pt_string, "abcdefghijklmnopqrstuvwxyz"),
            string_not_equal_cstr(pt_string, "abcdefghijklmnopqrstuvwxyz"));
        printf("less : %d, less equal : %d, ",
            string_less_cstr(pt_string, "abcdefghijklmnopqrstuvwxyz"),
            string_less_equal_cstr(pt_string, "abcdefghijklmnopqrstuvwxyz"));
        printf("great : %d, great equal : %d\n",
            string_great_cstr(pt_string, "abcdefghijklmnopqrstuvwxyz"),
            string_great_equal_cstr(pt_string, "abcdefghijklmnopqrstuvwxyz"));

        string_destroy(pt_string);
    }
    /*string_not_equal_cstr             */
    /*string_less_cstr                  */
    /*string_less_equal_cstr            */
    /*string_great_cstr                 */
    /*string_great_equal_cstr           */
    /*string_compare                    */
    {
        string_t* pt_string1 = create_string();
        string_t* pt_string2 = create_string();
        if(pt_string1 == NULL || pt_string2 == NULL)
        {
            return;
        }
        string_init(pt_string1);
        string_init(pt_string2);
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("compare : %d\n", string_compare(pt_string1, pt_string2));

        string_assign_cstr(pt_string1, "abc");
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("compare : %d\n", string_compare(pt_string1, pt_string2));

        string_assign_cstr(pt_string2, "abc");
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("compare : %d\n", string_compare(pt_string1, pt_string2));

        string_assign_cstr(pt_string1, "opq");
        string_assign_cstr(pt_string2, "xyz");
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("compare : %d\n", string_compare(pt_string1, pt_string2));

        string_assign_cstr(pt_string1, "mn");
        string_assign_cstr(pt_string2, "mno");
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("compare : %d\n", string_compare(pt_string1, pt_string2));

        string_assign_cstr(pt_string1, "u");
        string_assign_cstr(pt_string2, "abcdefghijklmnopqrstuvwxyz");
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("compare : %d\n", string_compare(pt_string1, pt_string2));
        string_destroy(pt_string1);
        string_destroy(pt_string2);
    }
    /*string_compare_substring_string   */
    {
        string_t* pt_string1 = create_string();
        string_t* pt_string2 = create_string();
        if(pt_string1 == NULL || pt_string2 == NULL)
        {
            return;
        }
        string_init(pt_string1);
        string_init(pt_string2);
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("compare : %d\n",
            string_compare_substring_string(pt_string1, 0, NPOS, pt_string2));

        string_assign_cstr(pt_string1, "abcdefghijklmnopqrstuvwxyz");
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("compare : %d\n",
            string_compare_substring_string(pt_string1, 0, 0, pt_string2));

        string_assign_cstr(pt_string2, "abc");
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("compare : %d\n",
            string_compare_substring_string(pt_string1, 0, 1, pt_string2));

        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("compare : %d\n",
            string_compare_substring_string(pt_string1, 0, 3, pt_string2));

        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("compare : %d\n",
            string_compare_substring_string(pt_string1, 0, 5, pt_string2));

        string_assign_cstr(pt_string2, "xyz");
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("compare : %d\n",
            string_compare_substring_string(pt_string1, 15, 3, pt_string2));

        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("compare : %d\n",
            string_compare_substring_string(pt_string1, 23, 3, pt_string2));

        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("compare : %d\n",
            string_compare_substring_string(pt_string1, 23, NPOS, pt_string2));

        string_assign_cstr(pt_string2, "u");
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("compare : %d\n",
            string_compare_substring_string(pt_string1, 0, NPOS, pt_string2));

        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("compare : %d\n",
            string_compare_substring_string(pt_string1, 20, NPOS, pt_string2));

        string_destroy(pt_string1);
        string_destroy(pt_string2);
    }
    /*string_compare_substring_substring*/
    {
        string_t* pt_string1 = create_string();
        string_t* pt_string2 = create_string();
        if(pt_string1 == NULL || pt_string2 == NULL)
        {
            return;
        }
        string_init(pt_string1);
        string_init(pt_string2);
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("compare : %d\n",
            string_compare_substring_substring(pt_string1, 0, NPOS, pt_string2, 0, NPOS));

        string_assign_cstr(pt_string1, "abcdefghijklmnopqrstuvwxyz");
        string_assign_cstr(pt_string2, "abcdefghijklmnopqrstuvwxyz");
        _printstring(pt_string1);
        _printstring(pt_string2);
        printf("compare : %d\n",
            string_compare_substring_substring(pt_string1, 0, 0, pt_string2, 0, 0));
        printf("compare : %d\n",
            string_compare_substring_substring(pt_string1, 0, 3, pt_string2, 0, 0));
        printf("compare : %d\n",
            string_compare_substring_substring(pt_string1, 0, NPOS, pt_string2, 0, 0));
        printf("compare : %d\n",
            string_compare_substring_substring(pt_string1, 0, 0, pt_string2, 0, 12));
        printf("compare : %d\n",
            string_compare_substring_substring(pt_string1, 0, 0, pt_string2, 0, NPOS));
        printf("compare : %d\n",
            string_compare_substring_substring(pt_string1, 3, 5, pt_string2, 3, 5));
        printf("compare : %d\n",
            string_compare_substring_substring(pt_string1, 3, NPOS, pt_string2, 3, 5));
        printf("compare : %d\n",
            string_compare_substring_substring(pt_string1, 20, 5, pt_string2, 20, NPOS));
        printf("compare : %d\n",
            string_compare_substring_substring(pt_string1, 20, NPOS, pt_string2, 20, 100));

        string_destroy(pt_string1);
        string_destroy(pt_string2);
    }
    /*string_compare_cstr               */
    {
        string_t* pt_string = create_string();
        if(pt_string == NULL)
        {
            return;
        }
        string_init(pt_string);
        _printstring(pt_string);
        puts("");
        printf("compare : %d\n", string_compare_cstr(pt_string, ""));

        string_assign_cstr(pt_string, "abc");
        _printstring(pt_string);
        puts("");
        printf("compare : %d\n", string_compare_cstr(pt_string, ""));

        _printstring(pt_string);
        puts("abc");
        printf("compare : %d\n", string_compare_cstr(pt_string, "abc"));

        string_assign_cstr(pt_string, "opq");
        _printstring(pt_string);
        puts("xyz");
        printf("compare : %d\n", string_compare_cstr(pt_string, "xyz"));

        string_assign_cstr(pt_string, "mn");
        _printstring(pt_string);
        puts("mno");
        printf("compare : %d\n", string_compare_cstr(pt_string, "mno"));

        string_assign_cstr(pt_string, "u");
        _printstring(pt_string);
        puts("abcdefghijklmnopqrstuvwxyz");
        printf("compare : %d\n", string_compare_cstr(pt_string, "abcdefghijklmnopqrstuvwxyz"));
        string_destroy(pt_string);
    }
    /*string_compare_substring_cstr     */
    {
        string_t* pt_string = create_string();
        if(pt_string == NULL)
        {
            return;
        }
        string_init(pt_string);
        _printstring(pt_string);
        puts("");
        printf("compare : %d\n",
            string_compare_substring_cstr(pt_string, 0, NPOS, ""));

        string_assign_cstr(pt_string, "abcdefghijklmnopqrstuvwxyz");
        _printstring(pt_string);
        puts("");
        printf("compare : %d\n",
            string_compare_substring_cstr(pt_string, 0, 0, ""));

        _printstring(pt_string);
        puts("abc");
        printf("compare : %d\n",
            string_compare_substring_cstr(pt_string, 0, 1, "abc"));

        _printstring(pt_string);
        puts("abc");
        printf("compare : %d\n",
            string_compare_substring_cstr(pt_string, 0, 3, "abc"));

        _printstring(pt_string);
        puts("abc");
        printf("compare : %d\n",
            string_compare_substring_cstr(pt_string, 0, 5, "abc"));

        _printstring(pt_string);
        puts("xyz");
        printf("compare : %d\n",
            string_compare_substring_cstr(pt_string, 15, 3, "xyz"));

        _printstring(pt_string);
        puts("xyz");
        printf("compare : %d\n",
            string_compare_substring_cstr(pt_string, 23, 3, "xyz"));

        _printstring(pt_string);
        puts("xyz");
        printf("compare : %d\n",
            string_compare_substring_cstr(pt_string, 23, NPOS, "xyz"));

        _printstring(pt_string);
        puts("u");
        printf("compare : %d\n",
            string_compare_substring_cstr(pt_string, 0, NPOS, "u"));

        _printstring(pt_string);
        puts("u");
        printf("compare : %d\n",
            string_compare_substring_cstr(pt_string, 20, NPOS, "u"));

        string_destroy(pt_string);
    }
    /*string_compare_substring_subcstr  */
    {
        string_t* pt_string = create_string();
        if(pt_string == NULL)
        {
            return;
        }
        string_init(pt_string);
        _printstring(pt_string);
        puts("");
        printf("compare : %d\n",
            string_compare_substring_subcstr(pt_string, 0, NPOS, "", NPOS));

        string_assign_cstr(pt_string, "abcdefghijklmnopqrstuvwxyz");
        _printstring(pt_string);
        puts("abcdefghijklmnopqrstuvwxyz");
        printf("compare : %d\n",
            string_compare_substring_subcstr(pt_string, 0, 0, "abcdefghijklmnopqrstuvwxyz", 0));
        printf("compare : %d\n",
            string_compare_substring_subcstr(pt_string, 0, 3, "abcdefghijklmnopqrstuvwxyz", 0));
        printf("compare : %d\n",
            string_compare_substring_subcstr(pt_string, 0, NPOS, "abcdefghijklmnopqrstuvwxyz", 0));
        printf("compare : %d\n",
            string_compare_substring_subcstr(pt_string, 0, 0, "abcdefghijklmnopqrstuvwxyz", 12));
        printf("compare : %d\n",
            string_compare_substring_subcstr(pt_string, 0, 0, "abcdefghijklmnopqrstuvwxyz", NPOS));
        printf("compare : %d\n",
            string_compare_substring_subcstr(pt_string, 3, 5, "defghijklmnopqrstuvwxyz", 5));
        printf("compare : %d\n",
            string_compare_substring_subcstr(pt_string, 3, NPOS, "defghijklmnopqrstuvwxyz", 5));
        printf("compare : %d\n",
            string_compare_substring_subcstr(pt_string, 20, 5, "uvwxyz", NPOS));
        printf("compare : %d\n",
            string_compare_substring_subcstr(pt_string, 20, NPOS, "uvwxyz", 100));

        string_destroy(pt_string);
    }
    /*string_substr                     */
    {
        string_t* pt_string = create_string();
        string_t* pt_stringex = NULL;
        if(pt_string == NULL)
        {
            return;
        }
        string_init_cstr(pt_string, "abcdef");
        _printstring(pt_string);
        pt_stringex = string_substr(pt_string, 0, NPOS);
        _printstring(pt_stringex);
        string_destroy(pt_string);
        string_destroy(pt_stringex);
    }
    /*string_connect                    */
    {
        string_t* pt_string1 = create_string();
        string_t* pt_string2 = create_string();
        if(pt_string1 == NULL || pt_string2 == NULL)
        {
            return;
        }
        string_init(pt_string1);
        string_init(pt_string2);
        _printstring(pt_string1);
        _printstring(pt_string2);
        string_connect(pt_string1, pt_string2);
        _printstring(pt_string1);
        string_assign_cstr(pt_string2, "abc");
        _printstring(pt_string2);
        string_connect(pt_string1, pt_string2);
        _printstring(pt_string1);
        string_assign_cstr(pt_string2, "");
        _printstring(pt_string2);
        string_connect(pt_string1, pt_string2);
        _printstring(pt_string1);
        string_assign_cstr(pt_string2, "xyz");
        _printstring(pt_string2);
        string_connect(pt_string1, pt_string2);
        _printstring(pt_string1);
        string_destroy(pt_string1);
        string_destroy(pt_string2);
    }
    /*string_connect_cstr               */
    {
        string_t* pt_string = create_string();
        if(pt_string == NULL)
        {
            return;
        }
        string_init(pt_string);
        string_connect_cstr(pt_string, "");
        _printstring(pt_string);
        string_connect_cstr(pt_string, "abc");
        _printstring(pt_string);
        string_connect_cstr(pt_string, "");
        _printstring(pt_string);
        string_connect_cstr(pt_string, "xyz");
        _printstring(pt_string);
        string_destroy(pt_string);
    }
    /*string_connect_char               */
    {
        string_t* pt_string = create_string();
        if(pt_string == NULL)
        {
            return;
        }
        string_init(pt_string);
        string_connect_char(pt_string, 'a');
        _printstring(pt_string);
        string_connect_char(pt_string, 'b');
        _printstring(pt_string);
        string_connect_char(pt_string, 'c');
        _printstring(pt_string);
        string_destroy(pt_string);
    }
    /*string_find                       */
    {
        string_t* pt_string = create_string();
        string_t* pt_stringex = create_string();
        if(pt_string == NULL ||pt_stringex == NULL)
        {
            return;
        }
        string_init(pt_string);
        string_init(pt_stringex);
        _printstring(pt_string);
        _printstring(pt_stringex);
        printf("%u\n", string_find(pt_string, pt_stringex, 0));
        printf("%u\n", string_find(pt_string, pt_stringex, 1));
        printf("%u\n", string_find(pt_string, pt_stringex, 4));

        string_assign_cstr(pt_stringex, "abc");
        _printstring(pt_string);
        _printstring(pt_stringex);
        printf("%u\n", string_find(pt_string, pt_stringex, 0));

        string_assign_cstr(pt_string, "abcdefghijklmnopqrstuvwxyz");
        string_assign_cstr(pt_stringex, "");
        _printstring(pt_string);
        _printstring(pt_stringex);
        printf("%u\n", string_find(pt_string, pt_stringex, 0));
        printf("%u\n", string_find(pt_string, pt_stringex, 10));
        printf("%u\n", string_find(pt_string, pt_stringex, 100));

        string_assign_cstr(pt_stringex, "mno");
        _printstring(pt_string);
        _printstring(pt_stringex);
        printf("%u\n", string_find(pt_string, pt_stringex, 0));
        printf("%u\n", string_find(pt_string, pt_stringex, 5));
        printf("%u\n", string_find(pt_string, pt_stringex, 20));
        printf("%u\n", string_find(pt_string, pt_stringex, 100));
        printf("%u\n", string_find(pt_string, pt_stringex, NPOS));

        string_assign_cstr(pt_string, "aaa");
        string_assign_cstr(pt_stringex, "aaaaa");
        _printstring(pt_string);
        _printstring(pt_stringex);
        printf("%u\n", string_find(pt_string, pt_stringex, 0));
        string_destroy(pt_string);
        string_destroy(pt_stringex);
    }
    /*string_find_cstr                  */
    {
        string_t* pt_string = create_string();
        if(pt_string == NULL)
        {
            return;
        }
        string_init(pt_string);

        _printstring(pt_string);
        puts("");
        printf("%u\n", string_find_cstr(pt_string, "", 0));
        printf("%u\n", string_find_cstr(pt_string, "", 1));
        printf("%u\n", string_find_cstr(pt_string, "", 5));

        _printstring(pt_string);
        puts("abc");
        printf("%u\n", string_find_cstr(pt_string, "abc", 0));

        string_assign_cstr(pt_string, "abcdefghijklmnopqrstuvwxyz");
        _printstring(pt_string);
        puts("");
        printf("%u\n", string_find_cstr(pt_string, "", 0));
        printf("%u\n", string_find_cstr(pt_string, "", 10));
        printf("%u\n", string_find_cstr(pt_string, "", 100));

        _printstring(pt_string);
        puts("mno");
        printf("%u\n", string_find_cstr(pt_string, "mno", 0));
        printf("%u\n", string_find_cstr(pt_string, "mno", 5));
        printf("%u\n", string_find_cstr(pt_string, "mno", 20));
        printf("%u\n", string_find_cstr(pt_string, "mno", 100));
        printf("%u\n", string_find_cstr(pt_string, "mno", NPOS));

        string_assign_cstr(pt_string, "aaa");
        _printstring(pt_string);
        puts("aaaaa");
        printf("%u\n", string_find_cstr(pt_string, "aaaaa", 0));

        string_destroy(pt_string);
    }
    /*string_find_subcstr               */
    {
        string_t* pt_string = create_string();
        if(pt_string == NULL)
        {
            return;
        }
        string_init(pt_string);
        _printstring(pt_string);
        puts("");
        printf("%u\n", string_find_subcstr(pt_string, "", 0, 0));
        printf("%u\n", string_find_subcstr(pt_string, "", 0, 3));
        printf("%u\n", string_find_subcstr(pt_string, "", 0, NPOS));
        printf("%u\n", string_find_subcstr(pt_string, "", 1, 0));
        printf("%u\n", string_find_subcstr(pt_string, "", NPOS, 0));
        printf("%u\n", string_find_subcstr(pt_string, "", 1, 3));
        printf("%u\n", string_find_subcstr(pt_string, "", NPOS, 3));
        _printstring(pt_string);
        puts("abcdefghijklmnopqrstrvwxyz");
        printf("%u\n", string_find_subcstr(pt_string, "abcdefghijklmnopqrstrvwxyz", 0, 0));
        printf("%u\n", string_find_subcstr(pt_string, "abcdefghijklmnopqrstrvwxyz", 0, 3));
        printf("%u\n", string_find_subcstr(pt_string, "abcdefghijklmnopqrstrvwxyz", 0, NPOS));
        printf("%u\n", string_find_subcstr(pt_string, "abcdefghijklmnopqrstrvwxyz", 1, 0));
        printf("%u\n", string_find_subcstr(pt_string, "abcdefghijklmnopqrstrvwxyz", NPOS, 0));
        printf("%u\n", string_find_subcstr(pt_string, "abcdefghijklmnopqrstrvwxyz", 1, 3));
        printf("%u\n", string_find_subcstr(pt_string, "abcdefghijklmnopqrstrvwxyz", NPOS, 3));
        string_assign_cstr(pt_string, "abcdefghijklmnopqrstrvwxyz");
        _printstring(pt_string);
        puts("abcdefghijklmnopqrstrvwxyz");
        printf("%u\n", string_find_subcstr(pt_string, "abcdefghijklmnopqrstrvwxyz", 0, 0));
        printf("%u\n", string_find_subcstr(pt_string, "abcdefghijklmnopqrstrvwxyz", 0, 3));
        printf("%u\n", string_find_subcstr(pt_string, "abcdefghijklmnopqrstrvwxyz", 0, NPOS));
        printf("%u\n", string_find_subcstr(pt_string, "abcdefghijklmnopqrstrvwxyz", 1, 0));
        printf("%u\n", string_find_subcstr(pt_string, "abcdefghijklmnopqrstrvwxyz", NPOS, 0));
        printf("%u\n", string_find_subcstr(pt_string, "abcdefghijklmnopqrstrvwxyz", 1, 3));
        printf("%u\n", string_find_subcstr(pt_string, "abcdefghijklmnopqrstrvwxyz", NPOS, 3));
        string_destroy(pt_string);
    }
    /*string_find_char                  */
    {
        string_t* pt_string = create_string();
        if(pt_string == NULL)
        {
            return;
        }
        string_init(pt_string);
        _printstring(pt_string);
        puts("o");
        printf("%u\n", string_find_char(pt_string, 'o', 0));
        printf("%u\n", string_find_char(pt_string, 'o', 10));
        printf("%u\n", string_find_char(pt_string, 'o', NPOS));
        string_assign_cstr(pt_string, "abcdefghijklmnopqrstrvwxyz");
        _printstring(pt_string);
        puts("o");
        printf("%u\n", string_find_char(pt_string, 'o', 0));
        printf("%u\n", string_find_char(pt_string, 'o', 10));
        printf("%u\n", string_find_char(pt_string, 'o', 20));
        printf("%u\n", string_find_char(pt_string, 'o', NPOS));
        string_destroy(pt_string);
    }
    /*string_rfind                      */
    /*string_rfind_cstr                 */
    /*string_rfind_subcstr              */
    /*string_rfind_char                 */
    /*string_find_first_of              */
    /*string_find_first_of_cstr         */
    /*string_find_first_of_subcstr      */
    /*string_find_first_of_char         */
    /*string_find_first_not_of          */
    /*string_find_first_not_of_cstr     */
    /*string_find_first_not_of_subcstr  */
    /*string_find_first_not_of_char     */
    /*string_find_last_of               */
    /*string_find_last_of_cstr          */
    /*string_find_last_of_subcstr       */
    /*string_find_last_of_char          */
    /*string_find_last_not_of           */
    /*string_find_last_not_of_cstr      */
    /*string_find_last_not_of_subcstr   */
    /*string_find_last_not_of_char      */
    /*string_begin                      */
    /*string_end                        */
    /*string_clear                      */
    /*string_swap                       */
    /*string_reserve                    */
    /*string_resize                     */
    /*string_push_back                  */
    /*string_assign                     */
    /*string_assign_substring           */
    /*string_assign_cstr                */
    /*string_assign_subcstr             */
    /*string_assign_char                */
    /*string_assign_range               */
    /*string_append                     */
    /*string_append_substring           */
    /*string_append_cstr                */
    /*string_append_subcstr             */
    /*string_append_char                */
    /*string_append_range               */
    /*string_insert                     */
    /*string_insert_n                   */
    /*string_insert_string              */
    /*string_insert_substring           */
    /*string_insert_cstr                */
    /*string_insert_subcstr             */
    /*string_insert_char                */
    /*string_insert_range               */
    /*string_erase                      */
    /*string_erase_range                */
    /*string_erase_substring            */
    /*string_replace                    */
    /*string_replace_substring          */
    /*string_replace_cstr               */
    /*string_replace_subcstr            */
    /*string_replace_char               */
    /*string_range_replace              */
    /*string_range_replace_substring    */
    /*string_range_replace_cstr         */
    /*string_range_replace_subcstr      */
    /*string_range_replace_char         */
    /*string_replace_range              */
    /*string_output                     */
    /*string_input                      */
    /*string_getline                    */
    /*string_getline_delimiter          */

    argc = 0;
    argv = NULL;
}

void test_string_getline(void)
{
}

/** local function implementation section **/
static void _printstring(const string_t* cpt_string)
{
    assert(cpt_string != NULL);
    printf("===================================\n");
    printf("empty : %d, size : %d, length : %d, capacity : %d, max size : %u\nc_str : %s\n",
        string_empty(cpt_string), string_size(cpt_string), string_length(cpt_string),
        string_capacity(cpt_string), string_max_size(cpt_string), string_c_str(cpt_string));
}

/** eof **/

