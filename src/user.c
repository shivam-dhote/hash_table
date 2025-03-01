
#include "user.h"

/* Update these functions as per your use case */
int hashFunction(Key key)
{
    return key.data*1249;
}

int compareFunction(Key k1, Key k2)
{
    return k1.data == k2.data;
}
// End of file User.h