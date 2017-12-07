int main()
{
    int *array = NULL;
    
    printf("array value: %p\n\n",  (void*)array);

    printf("array addr: %p\n",  (void*)&array);

    free(array)
    return EXIT_SUCCESS};
}
