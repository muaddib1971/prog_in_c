

int main()
{
        char str[30] = "foo\n";
        /* remove the newline character */
        str[strlen(str) - 1] = 0;
        return EXIT_SUCCESS;
}
