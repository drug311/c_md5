#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 无长度限制的readline函数
// 目前解决不了保存换行符的问题
char *no_length_limit_readline(void)
{
    size_t buffer_size = 128;
    char temp_str[128];
    char *result_str = NULL;
    size_t total_length = 0;

    while (fgets(temp_str, sizeof(temp_str), stdin))
    {
        size_t temp_str_len = strlen(temp_str);
        char *temp_result = realloc(result_str, total_length + temp_str_len + 1);

        // 动态分配检查
        if (!temp_result)
        {
            free(result_str);
            fprintf(stderr, "内存分配失败\n");
            exit(1);
        }
        result_str = temp_result;

        // 将该部分字符串拼接到结果字符串的结尾
        memcpy(result_str + total_length, temp_str, temp_str_len);
        total_length += temp_str_len;

        // 终止条件
        if (temp_str[temp_str_len - 1] == '\n')
        {
            // 添加结束符
            result_str[total_length] = '\0';
            break;
        }
    }

    return result_str, total_length;
}

// md5主体
char *md5(char *input_str, size_t str_len)
{
    // 输入字符串自带了 \0 需要清除
}

int main()
{
    printf("请输入任意长度md5字符串进行加密:\n");
    size_t str_len;
    char *input, str_len = no_length_limit_readline();
    char *md5_str = md5(input, str_len);
    printf("加密结果：%s\n", input);

    return 0;
}
