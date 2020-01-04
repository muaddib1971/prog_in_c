#include "main.h"

int main(void)
{
        const char* fnames[] = { "Kevin", "Patrick", "Trevor" };
        const char* lnames[] = { "Mitchell", "Holloway", "Hall" };
        const int ages[] = { 21, 21, 21 };
        int count;

        struct person_list* thelist = list_make();
        if (!thelist)
        {
                return EXIT_FAILURE;
        }

        for (count = 0; count < 3; ++count)
        {
                struct person* newp =
                    person_make(fnames[count], lnames[count], ages[count]);
                list_add(thelist, newp);
        }
        list_free(thelist);
        free(thelist);
        return EXIT_SUCCESS;
}
