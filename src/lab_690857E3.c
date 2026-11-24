#include <stdio.h>
#include <string.h>

void copy(char *psource, char *ptarget, unsigned num_char)
{
    unsigned i = 0;

    // Copy at most num_char characters from psource to ptarget
    while (i < num_char && *(psource + i) != '\0')
    {
        *(ptarget + i) = *(psource + i);
        i++;
    }

    // Append the null terminator
    *(ptarget + i) = '\0';
}

void concatenate(char *psrc1, char *psrc2, char *ptarget, unsigned buffer_size)
{
    // If buffer cannot even hold the null terminator, do nothing
    if (buffer_size == 0)
    {
        return;
    }

    // Maximum characters allowed excluding the null terminator '\0'
    unsigned max_chars = buffer_size - 1;

    // 1. Copy psrc1 into ptarget up to max_chars
    copy(psrc1, ptarget, max_chars);

    // 2. Find the length of the string currently copied into ptarget
    unsigned len1 = strlen(ptarget);

    // 3. If there is remaining space in the buffer, append psrc2
    if (max_chars > len1)
    {
        unsigned remaining_space = max_chars - len1;
        copy(psrc2, ptarget + len1, remaining_space);
    }
}

// DO NOT change the code below
#ifndef ___TEST___
int main(void)
{
    char buffer[100];
    char *source = "This is the first sentence.  ";
    char *target = "This is the second sentence.";

    concatenate(source, target, buffer, 70);

    printf("%s", buffer);
    return 0;
}
#endif
// DO NOT change the code above